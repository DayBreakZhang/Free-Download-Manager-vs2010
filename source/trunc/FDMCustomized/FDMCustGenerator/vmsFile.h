/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFILE_H__CC4F8BEC_228B_4CED_9F88_1B186737F773__INCLUDED_)
#define AFX_VMSFILE_H__CC4F8BEC_228B_4CED_9F88_1B186737F773__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsFile  
{
public:
	void set_Pos (DWORD dwPos, DWORD dwMethod);
	DWORD get_Pos();
	void Read (LPVOID lp, DWORD dwSize);
	void Write (LPCVOID pb, DWORD dwSize);
	DWORD get_Size();
	void Create (LPCSTR pszFile);
	void Open (LPCSTR pszFile, BOOL bRead);
	void Close();
	operator HANDLE() const;
	vmsFile();
	virtual ~vmsFile();

protected:
	HANDLE m_hFile;
};

#endif 
