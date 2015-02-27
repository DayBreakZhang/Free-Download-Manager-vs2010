/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsTickCount.h"

template <class ValueType, ValueType ValueUnknown, int Completeness, int Completeness2, int Validness, int MaxSize>
class vmsValueLog
{
public:
	vmsValueLog(void) {};
	~vmsValueLog(void) {};

	ValueType getCurrentMaximumValue (bool bCheckCompleteness = true) const
	{
		return getMaximumValueAmongLast (Completeness2, bCheckCompleteness);
	}

	ValueType getMaximumValue (bool bCheckCompleteness = true) const
	{
		return getMaximumValueAmongLast (m_vValues.size (), bCheckCompleteness);
	}

	ValueType getMaximumValueAmongLast (size_t cValues, bool bCheckCompleteness = false) const 
	{
		if (!cValues)
			return ValueUnknown;
		if (bCheckCompleteness && m_vValues.size () < Completeness)
			return ValueUnknown; 
		size_t nStartIndex = m_vValues.size () - min (cValues, m_vValues.size ());
		UINT64 uMaxVal = ValueUnknown;
		for (size_t i = nStartIndex; i < m_vValues.size (); i++)
		{
			if (!m_vValues [i].bValid)
				continue;
			if (uMaxVal == ValueUnknown)
				uMaxVal = m_vValues [i];
			else if (uMaxVal < m_vValues [i])
				uMaxVal = m_vValues [i];
		}
		return uMaxVal;
		
	}

	void AddValue (ValueType val)
	{
		m_vValues.push_back (val);
		if (m_vValues.size () > Validness)
		{
			for (size_t i = m_vValues.size () - Validness - 1; i < m_vValues.size (); i++)
				CheckValueValid (i);
		}
		if (m_vValues.size () > MaxSize)
			m_vValues.erase (m_vValues.begin (), m_vValues.begin () + MaxSize / 3);
	}

protected:
	void CheckValueValid (size_t nIndex)
	{
		if (m_vValues [nIndex].bValid)
			return;
		int cNearItems = 0;
		size_t nStart = nIndex > Validness ? nIndex - Validness : 0;
		size_t nEnd = nIndex + Validness;
		if (nEnd >= m_vValues.size ())
			nEnd = m_vValues.size () - 1;
		ValueType valItem = m_vValues [nIndex];
		for (size_t i = nStart; i <= nEnd; i++)
		{
			if (i == nIndex)
				continue;
			ValueType valItem2 = m_vValues [i];
			if (valItem <= valItem2)
			{
				cNearItems++;
			}
			else
			{
				if (valItem2 / (valItem2-valItem) >= 10) 
					cNearItems++;
			}
		}
		if (cNearItems >= Validness)
			m_vValues [nIndex].bValid = true;
	}

public:
	void clear ()
	{
		m_vValues.clear ();
	}

	bool empty () const {return m_vValues.empty ();}

	static ValueType getValueUnknown () {return ValueUnknown;}

	ValueType& operator [] (size_t i) {return m_vValues [i];}
	size_t size () {return m_vValues.size ();}

protected:
	struct Value
	{
		ValueType val;
		bool bValid;
		Value () : val (ValueUnknown), bValid (false) {}
		Value (const ValueType& v) : val (v), bValid (false) {}
		operator ValueType& () {return val;}
		operator ValueType () const {return val;}
	};
	std::vector <Value> m_vValues;
};

template <int iExploreDuringMin, int iExploreDuringMax, int iMinIntervalBetween, int iMaxIntervalBetween, class ValueLog>
class vmsMaximumPossibleValueExplorerBase
{
public:
	void CheckNeedStartExplore ()
	{
		if (m_bExploring)
			return;

		UINT64 tcCurrent = vmsTickCount::GetTickCount64 ();

		if (!m_tcExplore)
		{
			m_tcExplore = tcCurrent + iMinIntervalBetween*1000ui64;
			return;
		}

		if (m_tcExplore < tcCurrent)
			StartExplore ();
	}

	void CheckNeedStopExplore ()
	{
		if (!m_bExploring)
			return;

		UINT64 tcCurrent = vmsTickCount::GetTickCount64 ();

		if (tcCurrent - m_tcExploreStarted >= iExploreDuringMax*1000ui64)
		{
			StopExplore ();
			return;
		}

		if (CheckNeedStopExplore_NeedContinue ())
		{
			
			m_bEffectualExploring = true;
			m_tcExplore = tcCurrent;
			return;
		}

		if (tcCurrent >= (m_tcExplore + iExploreDuringMin*1000ui64))
		{
			StopExplore ();
			return;
		}
	}

protected:
	
	virtual bool CheckNeedStopExplore_NeedContinue () = NULL;

public:
	void ForceStartExplore ()
	{
		if (!m_bExploring)
			StartExplore ();
	}

	void ForceStopExplore ()
	{
		if (m_bExploring)
			StopExplore (true);
	}

	bool isExploring () const {return m_bExploring;}

	void Reset ()
	{
		m_tcExplore = 0;
		m_cIneffectualExplorings = 0;
		m_bExploring = false;
	}

	void ResetIneffectualExploringsCounter () 
	{
		if (!m_bExploring && m_tcExplore > (vmsTickCount::GetTickCount64 () + iMinIntervalBetween*1000ui64))
			m_tcExplore = vmsTickCount::GetTickCount64 () + iMinIntervalBetween*1000ui64;
		m_cIneffectualExplorings = 0;
	}

public:
	vmsMaximumPossibleValueExplorerBase (ValueLog *pValues, float fIntervalIncreasePow = 1.0f) : m_pValues (pValues), 
		m_tcExplore (0), m_tcExploreStarted (0),
		m_cIneffectualExplorings (0), m_bExploring (false),
		m_uMaxValueBeforeExplore (0), m_bEffectualExploring (0),
		m_fIntervalIncreasePow (fIntervalIncreasePow) {}
	virtual ~vmsMaximumPossibleValueExplorerBase () {}

protected:
	virtual bool StartExplore ()
	{
		assert (!m_bExploring);
		if (m_bExploring)
			return false;
		m_bEffectualExploring = false;
		if (m_uMaxValueBeforeExplore == ValueLog::getValueUnknown ())
			return false; 
		m_bExploring = true;
		m_tcExplore = m_tcExploreStarted = vmsTickCount::GetTickCount64 ();			
	}

	void StopExplore (bool bForcing = false)
	{
		assert (m_bExploring);
		if (!m_bExploring)
			return;
		m_bExploring = false;
		if (m_bEffectualExploring)
			m_cIneffectualExplorings = 0;
		else if (!bForcing && m_cIneffectualExplorings < BYTE_MAX)
			m_cIneffectualExplorings++;
		UINT64 uInterval = (UINT64) (iMinIntervalBetween * pow (m_cIneffectualExplorings + 1, m_fIntervalIncreasePow));
		if (uInterval > iMaxIntervalBetween)
			uInterval = iMaxIntervalBetween;
		m_tcExplore = vmsTickCount::GetTickCount64 () + uInterval*1000ui64;
	}
protected:
	ValueLog *m_pValues;
	UINT64 m_tcExplore, m_tcExploreStarted;
	BYTE m_cIneffectualExplorings;
	bool m_bExploring;
	bool m_bEffectualExploring;
	UINT64 m_uMaxValueBeforeExplore;
	float m_fIntervalIncreasePow;
};

template <int iExploreDuringMin, int iExploreDuringMax, int iMinIntervalBetween, int iMaxIntervalBetween, UINT64 uMinAdjustingValue, class ValueLog>
class vmsMaximumPossibleValueExplorer : public vmsMaximumPossibleValueExplorerBase <iExploreDuringMin, iExploreDuringMax, iMinIntervalBetween, iMaxIntervalBetween, ValueLog>
{
public:
	UINT64 getAdjustingValue () const {return m_uAdjusting;}
	vmsMaximumPossibleValueExplorer (ValueLog *pValues, float fIntervalIncreasePow = 1.0f) : 
		vmsMaximumPossibleValueExplorerBase (pValues, fIntervalIncreasePow), m_uAdjusting (0) {}

protected:
	virtual bool StartExplore ()
	{
		assert (!m_bExploring);
		if (m_bExploring)
			return false;
		m_uMaxValueBeforeExplore = m_pValues->getCurrentMaximumValue ();
		m_uAdjusting = max (uMinAdjustingValue, UINT64 (m_uMaxValueBeforeExplore * 0.2));
		return vmsMaximumPossibleValueExplorerBase::StartExplore ();
	}
	bool CheckNeedStopExplore_NeedContinue ()
	{
		UINT64 uCurrentMaxValue = m_pValues->getCurrentMaximumValue ();
		if (uCurrentMaxValue >= (m_uMaxValueBeforeExplore + UINT64 (m_uAdjusting * 0.3)) ||
			
			(m_bEffectualExploring == false && uCurrentMaxValue >= UINT64 (m_uMaxValueBeforeExplore*1.05)))
		{
			m_uAdjusting *= 2;
			return true;
		}

		return false;
	}
	UINT64 m_uAdjusting;
};

template <class ValueType, int iExploreDuringMin, int iExploreDuringMax, int iMinIntervalBetween, int iMaxIntervalBetween, class ValueLog>
class vmsMaximumPossibleValueExplorer2 : public vmsMaximumPossibleValueExplorerBase <iExploreDuringMin, iExploreDuringMax, iMinIntervalBetween, iMaxIntervalBetween, ValueLog>
{
protected:
	bool CheckNeedStopExplore_NeedContinue ()
	{
		UINT64 uCurrentMaxValue = m_pValues->getCurrentMaximumValue ();
		if (uCurrentMaxValue > (UINT64)(m_uMaxValueBeforeExplore*1.05))
		{
			
			m_uMaxValueBeforeExplore = uCurrentMaxValue;
			return true;
		}

		return false;
	}

public:
	vmsMaximumPossibleValueExplorer2 (ValueType *pValueToExplore, ValueLog *pValues, float fIntervalIncreasePow = 1.0f) : 
	  vmsMaximumPossibleValueExplorerBase (pValues, fIntervalIncreasePow),
	  m_pValueToExplore (pValueToExplore) {}
	~vmsMaximumPossibleValueExplorer2 () {}

protected:
	virtual bool StartExplore ()
	{
		assert (!m_bExploring);
		if (m_bExploring)
			return false;
		m_uMaxValueBeforeExplore = *m_pValueToExplore;
		return vmsMaximumPossibleValueExplorerBase::StartExplore ();
	}

protected:
	ValueType *m_pValueToExplore;
};