/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSDLDFILTER_H__5E70A16A_D18D_46ED_BEA7_B92C070E9601__INCLUDED_)
#define AFX_FSDLDFILTER_H__5E70A16A_D18D_46ED_BEA7_B92C070E9601__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

enum fsDldFilterType
{
	DFT_NONE,	
	DFT_GROUP	
};

class fsDldFilter
{
public:
	
	virtual fsDldFilterType GetType();
	
	virtual BOOL IsSatisfies (vmsDownloadSmartPtr dld);

	fsDldFilter();
	virtual ~fsDldFilter();

};

class fsDldGroupFilter : public fsDldFilter  
{
public:
	virtual fsDldFilterType GetType();

	
	vmsDownloadsGroupSmartPtr GetGroup();
	
	void SetGroup (vmsDownloadsGroupSmartPtr pGroup);

	virtual BOOL IsSatisfies (vmsDownloadSmartPtr dld);
	fsDldGroupFilter();
	virtual ~fsDldGroupFilter();

protected:
	vmsDownloadsGroupSmartPtr m_pGrp;
};

class fsDldRunningFilter : public fsDldFilter  
{
public:
	BOOL IsSatisfies(vmsDownloadSmartPtr dld);
	fsDldRunningFilter();
	virtual ~fsDldRunningFilter();

};

class fsDldDoneFilter : public fsDldFilter 
{
public:
	BOOL IsSatisfies(vmsDownloadSmartPtr dld);
	fsDldDoneFilter();
	virtual ~fsDldDoneFilter();

};

class fsDldTasksFilter : public fsDldFilter 
{
public:
	BOOL IsSatisfies(vmsDownloadSmartPtr dld);
	fsDldTasksFilter();
	virtual ~fsDldTasksFilter();

};

class fsDldStoppedFilter : public fsDldFilter  
{
public:
	BOOL IsSatisfies(vmsDownloadSmartPtr dld);
	fsDldStoppedFilter();
	virtual ~fsDldStoppedFilter();

};

class fsDldScheduledFilter : public fsDldFilter  
{
public:
	BOOL IsSatisfies(vmsDownloadSmartPtr dld);
	fsDldScheduledFilter();
	virtual ~fsDldScheduledFilter();

};

class fsDldHistRecFilter  
{
public:
	virtual BOOL IsSatisfies (fsDLHistoryRecord* rec);
	fsDldHistRecFilter();
	virtual ~fsDldHistRecFilter();

};

class fsDldHistRecFilter_DuringPeriod : public fsDldHistRecFilter  
{
public:
	void SetPeriod (int cDays);
	virtual BOOL IsSatisfies(fsDLHistoryRecord* rec);

	fsDldHistRecFilter_DuringPeriod();
	virtual ~fsDldHistRecFilter_DuringPeriod();

protected:
	int m_lastDays;	

};

class fsDldHistRecFilter_Today : public fsDldHistRecFilter  
{
public:
	virtual BOOL IsSatisfies(fsDLHistoryRecord* rec);
	fsDldHistRecFilter_Today();
	virtual ~fsDldHistRecFilter_Today();

};

class fsDldHistRecFilter_Yesterday : public fsDldHistRecFilter  
{
public:
	virtual BOOL IsSatisfies(fsDLHistoryRecord* rec);
	fsDldHistRecFilter_Yesterday();
	virtual ~fsDldHistRecFilter_Yesterday();

};

class fsDldHistRecFilter_Custom : public fsDldHistRecFilter  
{
public:
	void SetTimeRange (FILETIME tFrom, FILETIME tTo);
	const FILETIME* Get_TFrom () const {return &m_tFrom;}
	const FILETIME* Get_TTo () const {return &m_tTo;}

	virtual BOOL IsSatisfies(fsDLHistoryRecord* rec);
	fsDldHistRecFilter_Custom();
	virtual ~fsDldHistRecFilter_Custom();

protected:
	FILETIME m_tFrom, m_tTo;	

};

#endif 
