/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "vmsHash.h"
#include "md5.h"
#include "crc32.h"
#include "sha1.h"
#include "sha2.h"
#include "vmsFile.h"

vmsHash::vmsHash()
{
	m_pEvents = NULL;
	m_nSHA2Strength = 256;
}

vmsHash::~vmsHash()
{

}

std::string vmsHash::Hash(LPCSTR pszFile, vmsHashAlgorithm enHA)
{
	switch (enHA) {
	case HA_MD5:
		return Hash_MD5 (pszFile);

	case HA_CRC32:
		return Hash_CRC32 (pszFile);

	case HA_SHA1:
		return Hash_SHA1 (pszFile);

	case HA_SHA2:
		return Hash_SHA2 (pszFile);

	default:
		return "";
	}
}

std::string vmsHash::Hash_MD5(LPCSTR pszFile)
{
	MD5_CTX md5;
	if (0 == Hash_MD5_File (pszFile, 0, &md5))
		return "";
	return Hash_ResultToStr (md5.digest, 16);		
}

UINT64 vmsHash::Hash_MD5_File(const char *fn, unsigned long seed, void *pvContext)
{
	MD5_CTX *mdContext = (MD5_CTX*) pvContext;
	vmsFile file;
	__int64 trb = 0;

	try {
	
	file.Open (fn, TRUE);

	__int64 uSize;
	uSize = file.get_Size ();

	MD5Init (mdContext , seed);

	char buf [2048];
	for (;;) {
		int rb = (int) file.Read (buf, 2048);
		trb += rb;
		MD5Update (mdContext, (unsigned char *) buf, rb);

		if (m_pEvents) 
		{
			double f = (double)trb / uSize * 100;
			if (false == m_pEvents->OnProgressChanged (f)) {
				trb = 0;
				break;
			}
		}

		if (rb < 2048)
			break;
	}

	MD5Final (mdContext);

	}catch (...) {return 0;}

	return trb ;
}

std::string vmsHash::Hash_ResultToStr(unsigned char *pHR, int nSize)
{
	std::string str;

	for (int i = 0; i < nSize; i++)
	{
		char sz [3];
		_itoa_s (*pHR++, sz, 3, 16);
		if (sz [1] == 0) {
			sz [1] = sz [0];
			sz [2] = 0;
			sz [0] = '0';
		}

		str += sz; 
	}

	return str;
}

void vmsHash::set_EventsHandler(vmsHashEvents *pEvents)
{
	m_pEvents = pEvents;
}

std::string vmsHash::Hash_CRC32(LPCSTR pszFile)
{
	DWORD dwCrc32;
	CCrc32Static crc32;

	DWORD dwErrorCode = NO_ERROR;
	vmsFile file;

	dwCrc32 = 0xFFFFFFFF;

	try
	{

	file.Open (pszFile, TRUE);
	__int64 uSize = file.get_Size ();
	__int64 trb = 0;

	char buffer [MAX_BUFFER_SIZE];
	int nCount;
	while (nCount = file.Read (buffer, sizeof(buffer)))
	{
		for(int nLoop = 0; nLoop < nCount; nLoop++)
			crc32.CalcCrc32 (buffer [nLoop], dwCrc32);
		trb += nCount;

		if (m_pEvents) 
		{
			double f = (double)trb / uSize * 100;
			if (false == m_pEvents->OnProgressChanged (f)) {
				trb = 0;
				break;
			}
		}
	}

	}
	catch(...) {return "";}
	
	dwCrc32 = ~dwCrc32;

	char sz [100];
	sprintf_s (sz, 100, "%08x", dwCrc32);
	return sz;
}

std::string vmsHash::Hash_SHA1(LPCSTR pszFile)
{
	sha1_ctx sha1;
	vmsFile file;
	__int64 trb = 0;
	BYTE abBuf [16000];

	sha1_begin (&sha1);

	try {
		
	file.Open (pszFile, TRUE);
	__int64 uSize = file.get_Size ();
	DWORD dwRead;
	while (dwRead = file.Read (abBuf, sizeof (abBuf))) 
	{
		sha1_hash (abBuf, dwRead, &sha1);
		trb += dwRead;
		if (m_pEvents) 
		{
			double f = (double)trb / uSize * 100;
			if (false == m_pEvents->OnProgressChanged (f)) {
				trb = 0;
				break;
			}
		}
	}

	BYTE abRes [256];
	sha1_end (abRes, &sha1);

	if (trb == 0 && uSize != 0)
		return "";
	
	return Hash_ResultToStr (abRes, 20);

	}catch (...) {return "";}
}

std::string vmsHash::Hash_SHA2(LPCSTR pszFile)
{
	sha2_ctx sha2;
	vmsFile file;
	__int64 trb = 0;
	BYTE abBuf [16000];

	sha2_begin (m_nSHA2Strength, &sha2);

	try {
		
	file.Open (pszFile, TRUE);
	__int64 uSize = file.get_Size ();
	DWORD dwRead;
	while (dwRead = file.Read (abBuf, sizeof (abBuf))) 
	{
		sha2_hash (abBuf, dwRead, &sha2);
		trb += dwRead;
		if (m_pEvents) 
		{
			double f = (double)trb / uSize * 100;
			if (false == m_pEvents->OnProgressChanged (f)) {
				trb = 0;
				break;
			}
		}
	}

	BYTE abRes [256];
	sha2_end (abRes, &sha2);

	if (trb == 0 && uSize != 0)
		return "";
	
	return Hash_ResultToStr (abRes, m_nSHA2Strength / 8);

	}catch (...) {return "";}
}

void vmsHash::set_SHA2Strength(vmsHash_SHA2Strength en)
{
	switch (en) {
	case HSHA2S_256: m_nSHA2Strength = 256; break;
	case HSHA2S_384: m_nSHA2Strength = 384; break;
	case HSHA2S_512: m_nSHA2Strength = 512; break;
	}
}
