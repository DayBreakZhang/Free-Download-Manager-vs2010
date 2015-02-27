/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "FDMFirefoxExtension.h"
#include "vmsFlvSniffDllLoader.h"
#include "xrfix.h"

XRFIX_NS_IMPL_ISUPPORTS1(CFDMFirefoxExtension, IFDMFirefoxExtension, IFDMFIREFOXEXTENSION_IID)

nsISupports* CFDMFirefoxExtension::_pLastPost = NULL;

CFDMFirefoxExtension::CFDMFirefoxExtension()
{
}

CFDMFirefoxExtension::~CFDMFirefoxExtension()
{
}

NS_IMETHODIMP CFDMFirefoxExtension::GetLastPost(nsISupports * *aLastPost)
{
	if (_pLastPost)
		_pLastPost->AddRef ();
    *aLastPost = _pLastPost;
	return NS_OK;
}
NS_IMETHODIMP CFDMFirefoxExtension::SetLastPost(nsISupports * aLastPost)
{
	_pLastPost = aLastPost;
    return NS_OK;
}

NS_IMETHODIMP CFDMFirefoxExtension::MakeSureFlvSniffDllLoaded ()
{
	static vmsFlvSniffDllLoader ldr (2 );
	ldr.MakeSureDllLoaded ();
	return NS_OK;
}