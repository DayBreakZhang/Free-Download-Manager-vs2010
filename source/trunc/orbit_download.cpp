/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "system.h"
#include "orbit_download.h"
#include "CsvParser.h"

TOrbitDownload::TOrbitDownload()
	: bIsComplete(false),
	  uCompletedSize(0),
	  uFileSize(0)
{
}

void parseOrbitDownloadsList(const CString& sDldList, OrbitDownloadsArray& arrDownloads)
{
	CString sMsg;
	if (sDldList.IsEmpty())
		return;

	CCsvParser cpParser;
	cpParser.Init(sDldList, "\"", ",");

	CString sContent;
	while (cpParser.ParseNextRecord()) {

		int nFieldNumber = -1;
		CString sValue;
		TOrbitDownload tOrbitDownload;
		while (cpParser.GetNextField(sValue)) {
			++nFieldNumber;
			if (nFieldNumber == 0) {
				tOrbitDownload.sPath = sValue;
			}
			if (nFieldNumber == 1) {
				tOrbitDownload.sFile = sValue;
			}
			if (nFieldNumber == 2) {
				sValue.Trim();
				UINT64 uFileSize;
				if (sscanf_s((const char*)sValue, "%I64u", &uFileSize) != 1) {
					sMsg = LS (L_CANT_PARSE_ORBIT_DOWNLOAD_LIST);
					throw std::runtime_error((LPCTSTR)sMsg);
				}

				char szCompletedSize[16] = {0,};
				sprintf_s(szCompletedSize, 16, "%I64u", uFileSize);
				if (sValue.CompareNoCase(szCompletedSize) != 0) {
					sMsg = LS (L_CANT_PARSE_ORBIT_DOWNLOAD_LIST);
					throw std::runtime_error((LPCTSTR)sMsg);
				}

				tOrbitDownload.uFileSize = uFileSize;

			}
			if (nFieldNumber == 4) {
				tOrbitDownload.sUrl = sValue;
			}
			if (nFieldNumber == 10) {
				sValue.Trim();
				if (!sValue.IsEmpty())
					tOrbitDownload.bIsComplete = true;
			}

			
		}

		if (nFieldNumber < 10) {
			sMsg = LS (L_CANT_PARSE_ORBIT_DOWNLOAD_LIST);
			throw std::runtime_error((LPCTSTR)sMsg);
		}

		if (tOrbitDownload.bIsComplete)
			arrDownloads.Add(tOrbitDownload);

	}

	
	int nFieldNumber = -1;
	CString sValue;
	TOrbitDownload tOrbitDownload;
	while (cpParser.GetNextField(sValue)) {
		++nFieldNumber;
		if (nFieldNumber == 0) {
			tOrbitDownload.sPath = sValue;
		}
		if (nFieldNumber == 1) {
			tOrbitDownload.sFile = sValue;
		}
		if (nFieldNumber == 2) {
			sValue.Trim();
			UINT64 uFileSize;
			if (sscanf_s((const char*)sValue, "%I64u", &uFileSize) != 1) {
				sMsg = LS (L_CANT_PARSE_ORBIT_DOWNLOAD_LIST);
				throw std::runtime_error((LPCTSTR)sMsg);
			}

			char szCompletedSize[16] = {0,};
			sprintf_s(szCompletedSize, 16, "%I64u", uFileSize);
			if (sValue.CompareNoCase(szCompletedSize) != 0) {
				sMsg = LS (L_CANT_PARSE_ORBIT_DOWNLOAD_LIST);
				throw std::runtime_error((LPCTSTR)sMsg);
			}

			tOrbitDownload.uFileSize = uFileSize;

		}
		if (nFieldNumber == 4) {
			tOrbitDownload.sUrl = sValue;
		}

		if (nFieldNumber == 10) {
			sValue.Trim();
			if (!sValue.IsEmpty())
				tOrbitDownload.bIsComplete = true;
		}

		
	}

	if (nFieldNumber < 10) {
		sMsg = LS (L_CANT_PARSE_ORBIT_DOWNLOAD_LIST);
		throw std::runtime_error((LPCTSTR)sMsg);
	}

	if (tOrbitDownload.bIsComplete)
		arrDownloads.Add(tOrbitDownload);
}
