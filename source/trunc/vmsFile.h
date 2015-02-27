/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFILE_H__88D636C1_5B75_4644_A165_E88280A83CBA__INCLUDED_)
#define AFX_VMSFILE_H__88D636C1_5B75_4644_A165_E88280A83CBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

namespace vmsFDM
{

class vmsFile  
{
public:
	
	void ReadDouble (double &f);
	void ReadInt64(__int64 &i);
	void ReadInt (int &i);
	void WriteInt (int i);
	void WriteInt64 (__int64 i);
	void WriteDouble (double f);
	void ReadString(fsString& str);
	void WriteString (LPCSTR psz);
	
	void Seek (DWORD dwDistance, DWORD dwMethod = FILE_BEGIN);
	
	DWORD GetSize();

	
	void Create (LPCTSTR pszFileName, DWORD dwAccess = GENERIC_READ, DWORD dwShareMode = FILE_SHARE_READ, DWORD dwCreationDisposition = OPEN_EXISTING, DWORD dwFlags = FILE_ATTRIBUTE_NORMAL);
	
	void Close();

	
	
	void Attach (HANDLE hFile, bool bAutoClose = true);
	
	HANDLE Detach();

	
	void Read (LPVOID pvBuffer, DWORD dwToRead, DWORD* pdwRead = NULL);
	void Write (LPCVOID pvBuffer, DWORD dwToWrite);

	
	operator HANDLE() const {return m_hFile;}
	
	vmsFile(HANDLE hFile = INVALID_HANDLE_VALUE, bool bAutoClose = true);
	virtual ~vmsFile();

protected:
	
	bool m_bThrowOnPartialRead;
	bool m_bAutoClose;
	HANDLE m_hFile;	
};

};

#endif 
