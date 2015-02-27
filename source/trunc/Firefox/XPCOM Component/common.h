/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __COMMON_H_
#define __COMMON_H_

#include "assert.h"

#define CC(cmd) {HRESULT hr = cmd; assert (SUCCEEDED (hr)); if (FAILED (hr)) return NS_ERROR_FAILURE;}

#if defined (XUL_SDK_VER) && XUL_SDK_VER >= 22

#if XUL_SDK_VER >= 30

#include "ivmsfdmff30.h"
#define XULSDK_PRBool	bool
#define PRUint32 uint32_t
#define PRUint8 uint8_t
#define PRUnicharIDL char16_t
#define wchar_t_IDL	char16_t

#else 

#include "ivmsfdmff22.h"
#define XULSDK_PRBool	bool
#define PRUnicharIDL PRUnichar
#define wchar_t_IDL	wchar_t

#endif

#else

#include "ivmsfdmff.h"
#define XULSDK_PRBool	PRBool
#define PRUnicharIDL PRUnichar
#define wchar_t_IDL	wchar_t

#endif 

inline wchar_t* pwchar_t_IDL_to_pwchar_t (wchar_t_IDL* p)
{
	return reinterpret_cast <wchar_t*> (p);
}

inline const wchar_t* pwchar_t_IDL_to_pwchar_t (const wchar_t_IDL* p)
{
	return reinterpret_cast <const wchar_t*> (p);
}

inline wchar_t_IDL* pwchar_t_to_pwchar_t_IDL (wchar_t* p)
{
	return reinterpret_cast <wchar_t_IDL*> (p);
}

inline const wchar_t_IDL* pwchar_t_to_pwchar_t_IDL (const wchar_t* p)
{
	return reinterpret_cast <const wchar_t_IDL*> (p);
}

#endif 