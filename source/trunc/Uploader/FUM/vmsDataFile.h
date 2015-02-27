/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDATAFILE_H__2D3A0382_A38B_44AA_963E_6B7E3B3024DB__INCLUDED_)
#define AFX_VMSDATAFILE_H__2D3A0382_A38B_44AA_963E_6B7E3B3024DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "tree.h"
#include "vmsFile.h"

enum vmsVariantValueType
{
	VVT_EMPTY,			
	VVT_INT,			
	VVT_DOUBLE,			
	VVT_INT64,			
	VVT_ASTRING,		
	VVT_LPBYTE,			
};

struct vmsVariantValue
{
protected:
	vmsVariantValueType enType; 
	union {
		int iVal;			
		double fVal;		
		__int64 i64Val;		
		LPSTR pszVal;		
		struct {
			LPBYTE pbVal;	
			UINT nByteBufferSize;	
		};
	};

public:

	vmsVariantValue () {enType = VVT_EMPTY;}
	vmsVariantValue (const vmsVariantValue& vt) {vmsVariantValue (); *this = vt;}
	
	~vmsVariantValue () {clear ();}

	vmsVariantValueType type () {return enType;};
	bool empty () {return type () == VVT_EMPTY;};

	operator int () const {ASSERT (enType == VVT_INT); return iVal;}
	operator double () const {ASSERT (enType == VVT_DOUBLE); return fVal;}
	operator __int64 () const {ASSERT (enType == VVT_INT64); return i64Val;}
	operator LPCSTR () const {ASSERT (enType == VVT_ASTRING); return pszVal;}
	operator const LPBYTE () const {ASSERT (enType == VVT_LPBYTE); return pbVal;}
	operator LPBYTE () {ASSERT (enType == VVT_LPBYTE); return pbVal;}
	UINT bytebuffersize () {return nByteBufferSize;}

	void set (int i) {clear (); enType = VVT_INT; iVal = i;}
	void set (__int64 i) {clear (); enType = VVT_INT64; i64Val = i;}
	void set (double f) {clear (); enType = VVT_DOUBLE; fVal = f;}
	void set (LPCSTR psz) {
		clear (); enType = VVT_ASTRING; pszVal = new char [lstrlen (psz) + 1];
		lstrcpy (pszVal, psz);
	}
	void set (const LPBYTE pb, UINT nSize) {
		clear (); enType = VVT_LPBYTE; pbVal = new BYTE [nSize]; 
		CopyMemory (pbVal, pb, nSize);
		nByteBufferSize = nSize;
	}

	int operator = (int i) {set (i); return i;}
	__int64 operator = (__int64 i) {set (i); return i;}
	double operator = (double f) {set (f); return f;}
	LPCSTR operator = (LPCSTR psz) {set (psz); return psz;}

	void clear () {
		switch (enType) 
		{
		case VVT_EMPTY:
		case VVT_INT:
		case VVT_DOUBLE:
		case VVT_INT64: break;

		case VVT_LPBYTE: delete [] pbVal; break;
		case VVT_ASTRING: delete [] pszVal; break;

		default: ASSERT (false);	
		}
		enType = VVT_EMPTY;
	}

	vmsVariantValue& operator = (const vmsVariantValue& vt) {
		switch (vt.enType)
		{
		case VVT_EMPTY: clear (); break;
		case VVT_INT: set ((int)vt); break;
		case VVT_DOUBLE: set ((double)vt); break;
		case VVT_INT64: set ((__int64)vt); break;
		case VVT_ASTRING: set ((LPCSTR)vt); break;
		case VVT_LPBYTE: set ((const LPBYTE)vt, vt.nByteBufferSize); break;
		default: ASSERT (false); 
		}
		return *this;
	}
};

struct vmsDataFileItem
{
	fsString strName;	
	vmsVariantValue vt;	
};

typedef fs::ListTree <vmsDataFileItem> DATAFILETREE, *LPDATAFILETREE;

typedef vmsVariantValue DATAFILEITEM, *LPDATAFILEITEM;

class vmsDataFile
{
public:
	void get_Value (LPCSTR pszSection, LPCSTR pszValueName, LPBYTE& pbValue, UINT& nValueSize);
	void get_Value (LPCSTR pszSection, LPCSTR pszValueName, LPCSTR& strValue);
	void get_Value (LPCSTR pszSection, LPCSTR pszValueName, double& fValue);
	void get_Value (LPCSTR pszSection, LPCSTR pszValueName, __int64& i64Value);
	void get_Value (LPCSTR pszSection, LPCSTR pszValueName, int& iValue);
	void set_Value(LPCSTR pszSection, LPCSTR pszValueName, LPBYTE pbValue, UINT nValueSize);
	void set_Value(LPCSTR pszSection, LPCSTR pszValueName, LPCSTR pszValue);
	void set_Value(LPCSTR pszSection, LPCSTR pszValueName, double fValue);
	void set_Value(LPCSTR pszSection, LPCSTR pszValueName, __int64 i64Value);
	void set_Value (LPCSTR pszSection, LPCSTR pszValueName, int iValue);
	
	LPDATAFILEITEM CreateItem(LPCSTR pszSection, LPCSTR pszItemName);
	LPDATAFILEITEM CreateItem (LPDATAFILETREE pSection, LPCSTR pszItemName);
	LPDATAFILETREE CreateSection (LPCSTR pszSection, LPDATAFILETREE ptRoot = NULL);
	
	void LoadFromFile (HANDLE hFile);
	void SaveToFile (HANDLE hFile);

	vmsDataFile();
	virtual ~vmsDataFile();

protected:
	void LoadFromFile(vmsFDM::vmsFile& file, vmsDataFileItem &item);
	void LoadFromFile(vmsFDM::vmsFile& file, LPDATAFILETREE ptRoot);
	void SaveToFile(vmsFDM::vmsFile& file, vmsDataFileItem& item);
	void SaveToFile(vmsFDM::vmsFile& file, LPDATAFILETREE ptRoot);
	
	
	
	
	LPDATAFILETREE FindItem (LPCSTR pszSection, LPCSTR pszValueName, LPDATAFILETREE ptRoot = NULL);

	
	DATAFILETREE m_tData;
};

#endif 
