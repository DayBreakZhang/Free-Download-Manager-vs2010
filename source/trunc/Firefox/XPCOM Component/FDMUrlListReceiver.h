/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMURLLISTRECEIVER_H_
#define __FDMURLLISTRECEIVER_H_

#include "common.h"

#define FDMURLLISTRECEIVER_CONTRACTID "@freedownloadmanager.org/FDMUrlListReceiver;1"
#define FDMURLLISTRECEIVER_CLASSNAME "Free Download Manager Url List rcvr component for Firefox"

#define FDMURLLISTRECEIVER_CID { 0x2520b0c1, 0x4cd6, 0x4354, { 0xbf, 0xe7, 0xb6, 0xcd, 0xd3, 0xf1, 0x2f, 0xda } }

#include <comdef.h>
#include "../../Fdm.h"
_COM_SMARTPTR_TYPEDEF(IWGUrlListReceiver, __uuidof(IWGUrlListReceiver));

class CFDMUrlListReceiver : public IFDMUrlListReceiver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMURLLISTRECEIVER

  CFDMUrlListReceiver();

private:
  ~CFDMUrlListReceiver();

protected:
	IWGUrlListReceiverPtr m_spUrlListRcvr;
  
};

#endif 