/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FDMUrlReceiver_H_
#define __FDMUrlReceiver_H_

#include "common.h"

#define FDMURLRECEIVER_CONTRACTID "@freedownloadmanager.org/FDMUrlReceiver;1"
#define FDMURLRECEIVER_CLASSNAME "Free Download Manager Url rcvr component for Firefox"

#define FDMURLRECEIVER_CID { 0x318a1448, 0xad5e, 0x4b75, { 0xb6, 0xd5, 0xfc, 0x1, 0xe5, 0xfb, 0x34, 0x3c } }

#include <comdef.h>
#include "../../Fdm.h"
_COM_SMARTPTR_TYPEDEF(IWGUrlReceiver, __uuidof(IWGUrlReceiver));

class CFDMUrlReceiver : public IFDMUrlReceiver
{
public:
  
  static nsresult ApplyUrlToReceiver (IWGUrlReceiver* pUrlRcvr, IFDMUrl* url);
  NS_DECL_ISUPPORTS
  NS_DECL_IFDMURLRECEIVER

  CFDMUrlReceiver();

private:
  ~CFDMUrlReceiver();

protected:
	IWGUrlReceiverPtr m_spUrlRcvr;
  
};

#endif 