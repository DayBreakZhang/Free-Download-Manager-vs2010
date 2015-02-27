/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef PERSIST_OBJECT_INCLUDED_FILE
#define PERSIST_OBJECT_INCLUDED_FILE

#include <vector>

class vmsPersistObject;

class vmsPersistObjectsContainerBase
{
public:
	virtual size_t getPersistObjectCount () = NULL;
	virtual vmsPersistObject* getPersistObject (size_t nIndex) = NULL;
	virtual size_t findPersistObjectIndex (vmsPersistObject *pObj) = NULL;
	
	virtual void addPersistObject (vmsPersistObject*) {assert (false);}
	virtual void removePersistObject (vmsPersistObject*) {assert (false);}
	virtual void removePersistObject (size_t nIndex) {assert (false);}
	virtual void removeAllPersistObjects () {assert (false);}
};

class vmsPersistObjectsStandardContainer : public vmsPersistObjectsContainerBase
{
public:
	void addPersistObject (vmsPersistObject *pObj) 
	{
		vmsCriticalSectionAutoLock csal (m_pcsObj);
		m_vPersistObjects.push_back (pObj);
	}

	void removePersistObject (vmsPersistObject *pObj)
	{
		vmsCriticalSectionAutoLock csal (m_pcsObj);
		size_t nIndex = findPersistObjectIndex (pObj);
		if (nIndex != size_t (-1))
			removePersistObject (nIndex);
	}

	void removePersistObject (size_t nIndex)
	{
		vmsCriticalSectionAutoLock csal (m_pcsObj);
		if (nIndex >= m_vPersistObjects.size())
			return;
		m_vPersistObjects.erase (m_vPersistObjects.begin() + nIndex);
	}

	size_t findPersistObjectIndex (vmsPersistObject *pObj)
	{
		for (size_t i = 0; i < m_vPersistObjects.size (); i++)
		{
			if (m_vPersistObjects [i] == pObj)
				return i;
		}
		return size_t (-1);
	}

	size_t getPersistObjectCount () {return m_vPersistObjects.size ();}

	vmsPersistObject* getPersistObject (size_t nIndex) {return m_vPersistObjects [nIndex];}

	void removeAllPersistObjects () 
	{
		vmsCriticalSectionAutoLock csal (m_pcsObj);
		m_vPersistObjects.clear ();
	}

public:
	vmsPersistObjectsStandardContainer (LPCRITICAL_SECTION pcsObj = NULL) : m_pcsObj (pcsObj) {}
	virtual ~vmsPersistObjectsStandardContainer () {};
protected:
	std::vector <vmsPersistObject*> m_vPersistObjects;
	LPCRITICAL_SECTION m_pcsObj;
};

#define POS_DIRTY						(1)
#define POS_NOTMODIFIEDSINCELASTSAVE	(1 << 1)

class vmsPersistObject
{
public:
	vmsPersistObject();
	virtual ~vmsPersistObject();

	virtual bool isDirty(); 
	void setDirty(); 
	virtual void onStateSavedSuccessfully(); 

	
	
	
	
	
	
	virtual void getStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	
	
	
	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);

	
	virtual bool loadFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
	
	
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
	

	void resetDirty(); 

	vmsPersistObjectsContainerBase* getPersistObjectChildren () {return m_pPersistChildObjects;}
	
protected:
	
	virtual void onChildObjectLoadFinished (vmsPersistObject *pObject, bool bResult) {}
	BYTE m_bState;
	vmsCriticalSection m_csObj;
	vmsPersistObjectsContainerBase *m_pPersistChildObjects;
	vmsPersistObjectsStandardContainer m_persistChildObjects;

private:
	vmsPersistObject& operator = (vmsPersistObject &obj) {assert (false);}
};

template <class TObjectPtr>
class vmsPersistObjectsArray : 
	public vmsPersistObject, 
	protected vmsPersistObjectsContainerBase
{
public:
	void Add (TObjectPtr obj)
	{
		vmsCriticalSectionAutoLock csalStateGuardAutoLock(&m_csObj);
		m_vObj.push_back (obj);
		setDirty ();
	}

	void Delete (size_t nIndex)
	{
		vmsCriticalSectionAutoLock csalStateGuardAutoLock(&m_csObj);
		assert (nIndex < m_vObj.size());
		if (nIndex >= m_vObj.size())
			return;
		m_vObj.erase (m_vObj.begin () + nIndex);
		setDirty();
	}

	TObjectPtr& operator [] (size_t nIndex)
	{
		assert (nIndex < m_vObj.size());
		if (nIndex >= m_vObj.size())
			throw std::runtime_error("");
		return m_vObj [nIndex];
	}

	const TObjectPtr& operator [] (size_t nIndex) const
	{
		assert (nIndex < m_vObj.size());
		if (nIndex >= m_vObj.size())
			throw std::runtime_error("");
		return m_vObj [nIndex];
	}

	size_t size() const
	{
		return m_vObj.size();
	}

	void Insert(const TObjectPtr& obj, size_t nIndex)
	{
		vmsCriticalSectionAutoLock csalStateGuardAutoLock(&m_csObj);
		m_vObj.insert (m_vObj.begin() + nIndex, obj);
		setDirty();
	}

	void DeleteAll()
	{
		if (m_vObj.empty ())
			return;
		vmsCriticalSectionAutoLock csalStateGuardAutoLock(&m_csObj);
		m_vObj.clear();
		setDirty();
	}

	bool IsEmpty () const 
	{
		return m_vObj.empty ();
	}

public:
	
	vmsPersistObjectsArray () 
	{
		m_pPersistChildObjects = this;
	}

	virtual ~vmsPersistObjectsArray () {}

protected:
	size_t getPersistObjectCount () {return m_vObj.size ();}
	vmsPersistObject* getPersistObject (size_t nIndex) { return m_vObj [nIndex]; };
	virtual size_t findPersistObjectIndex (vmsPersistObject *pObj) 
	{
		for (size_t i = 0; i < m_vObj.size (); i++)
		{
			if (m_vObj [i] == pObj)
				return i;
		}
		return size_t (-1);
	}

protected:
	std::vector <TObjectPtr> m_vObj;
};

#endif
