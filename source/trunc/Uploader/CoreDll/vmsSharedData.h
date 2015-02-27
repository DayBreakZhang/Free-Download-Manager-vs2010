/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSHAREDDATA_H__B3734779_FAC2_41DD_895D_BDC9659EB411__INCLUDED_)
#define AFX_VMSSHAREDDATA_H__B3734779_FAC2_41DD_895D_BDC9659EB411__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsSharedData  
{
public:
	LPVOID get_Data();
	void Release();
	BOOL Aquire (LPCSTR pszName, BOOL bOpenExisting = TRUE, DWORD dwSize = 0);
	vmsSharedData (LPCSTR pszName = NULL, BOOL bOpenExisting = TRUE, DWORD dwSize = 0);
	virtual ~vmsSharedData();

protected:
	HANDLE m_hFileMapping;
	LPVOID m_pViewOfFile;
};

template <class T>
class vmsSharedDataT : public vmsSharedData
{
public:
	vmsSharedDataT (LPCSTR pszName = NULL, BOOL bOpenExisting = TRUE, DWORD dwSize = 0) : vmsSharedData (pszName, bOpenExisting, dwSize * sizeof (T)) {}
	virtual ~vmsSharedDataT() {};

	operator T* () {return (T*) get_Data ();}
	T& operator [] (int n) {return *(((T*)get_Data())+n);}
};

#endif 
