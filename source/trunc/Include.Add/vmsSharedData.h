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
	bool Aquire (LPCTSTR ptszName, bool bOpenExisting = true, DWORD dwSize = 0, DWORD dwDesiredAccess = FILE_MAP_ALL_ACCESS, LPSECURITY_ATTRIBUTES pSecurityAttributes = NULL)
	{
		Release ();

		if (ptszName == NULL)
			return false;

		if (!bOpenExisting)
		{
			m_hFileMapping = CreateFileMapping (INVALID_HANDLE_VALUE,
				pSecurityAttributes, PAGE_READWRITE, 0, dwSize, ptszName);
		}
		else
		{
			m_hFileMapping = OpenFileMapping (dwDesiredAccess, FALSE, ptszName);
		}

		if (!m_hFileMapping)
			return false;

		m_pViewOfFile = MapViewOfFile (m_hFileMapping, dwDesiredAccess,
			0, 0, 0);

		if (!m_pViewOfFile)
			return false;

		return true;
	}

	void Release()
	{
		if (m_hFileMapping)
		{
			if (m_pViewOfFile)
				UnmapViewOfFile (m_pViewOfFile);
			CloseHandle (m_hFileMapping);

			m_hFileMapping = NULL;
			m_pViewOfFile  = NULL;
		}
	}

	LPVOID getData()
	{
		return m_pViewOfFile;
	}

	HANDLE getHandle () const
	{
		return m_hFileMapping;
	}	
	
	vmsSharedData (LPCTSTR ptszName = NULL, bool bOpenExisting = true, DWORD dwSize = 0, DWORD dwDesiredAccess = FILE_MAP_ALL_ACCESS, LPSECURITY_ATTRIBUTES pSecurityAttributes = NULL)
	{
		m_hFileMapping = NULL;
		m_pViewOfFile  = NULL;

		if (ptszName)
			Aquire (ptszName, bOpenExisting, dwSize, dwDesiredAccess, pSecurityAttributes);
	}

	virtual ~vmsSharedData()
	{
		Release ();
	}

protected:
	HANDLE m_hFileMapping;
	LPVOID m_pViewOfFile;
};

template <class T>
class vmsSharedDataT : public vmsSharedData
{
public:
	vmsSharedDataT (LPCTSTR ptszName = NULL, bool bOpenExisting = true, DWORD dwSize = 0, DWORD dwDesiredAccess = FILE_MAP_ALL_ACCESS, LPSECURITY_ATTRIBUTES pSecurityAttributes = NULL) : 
	  vmsSharedData (ptszName, bOpenExisting, dwSize * sizeof (T), dwDesiredAccess, pSecurityAttributes) {}
	virtual ~vmsSharedDataT() {};

	operator T* () {return (T*) getData ();}
	T& operator [] (int n) {return *(((T*)getData())+n);}
};

#endif 
