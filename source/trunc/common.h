/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __COMMON_H_
#define __COMMON_H_

#define SAFE_DELETE(p) do {if (p) {delete p; p = NULL;}} while (0)
#define SAFE_DELETE_ARRAY(a) do {if (a) {delete [] a; a = NULL;}} while (0)
#define SAFE_DELETE_BYTE_ARRAY(a) do {if (a) {delete [] (LPBYTE)a; a = NULL;}} while (0)
#define SAFE_RELEASE(p) do {if (p) {p->Release (); p = NULL;}} while (0)

#define RIF(e) do {if (FAILED (hr=(e))) return hr;} while (0)
                 
#define Is9xME ((GetVersion () & 0x80000000) != 0)

#endif