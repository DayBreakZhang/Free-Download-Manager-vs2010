/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __COMMON_H_
#define __COMMON_H_

#define SAFE_DELETE(p) {if (p) {delete p; p = NULL;}}
#define SAFE_DELETE_ARRAY(a) {if (a) {delete [] a; a = NULL;}}
#define SAFE_RELEASE(p) {if (p) {p->Release (); p = NULL;}}

#define RIF(e) {if (FAILED (hr=(e))) return hr;}

#endif