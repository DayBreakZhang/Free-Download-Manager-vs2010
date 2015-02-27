#pragma once

#include "TransferProtocolObject.h"
#include <WTypes.h>
#include "network.h"

class TransferProtocolDownloader : public TransferProtocolObject
{
public:	

	virtual BOOL InitTpStream(LPCSTR pszUrl, LPCSTR pszOutputPath, int nStreamingSpeed) = NULL;
	virtual BOOL Start() = NULL;
	virtual BOOL Stop() = NULL;
	virtual UINT get_DownloadSpeed() = NULL;
	virtual BOOL IsDone() = NULL;
	virtual TransportProtocolStateEx get_State() = NULL;
	virtual float get_PercentDone () = NULL;
	virtual int get_ConnectionCount () = NULL;
	virtual UINT64 get_TotalFilesSize () = NULL;
	virtual UINT64 get_TotalDownloadedBytesCount () = NULL;
	virtual int get_StreamingSpeed () = NULL;
	virtual int get_NumberOfSections () = NULL;
	virtual int get_DownloadingSectionCount () = NULL;
	virtual LPCSTR get_LastError() = NULL;
	virtual BOOL IsLiveStreaming () = NULL;
	virtual BOOL ReStart() = NULL;
};