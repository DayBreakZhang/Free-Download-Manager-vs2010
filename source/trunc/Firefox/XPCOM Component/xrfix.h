/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef _XRFIX_H_
#define _XRFIX_H_

#define XRFIX_NS_IMPL_ISUPPORTS1(_class, _interface, _iid)					\
NS_IMPL_ADDREF(_class)														\
NS_IMPL_RELEASE(_class)														\
NS_IMETHODIMP _class::QueryInterface (const nsID &iid, void** ppv)			\
{																			\
	if (!memcmp (&iid, &NS_GET_IID (nsISupports), sizeof (iid)))			\
	{																		\
		*ppv = (nsISupports*)this;											\
		AddRef ();															\
		return NS_OK;														\
	}																		\
																			\
	const nsIID myiid = _iid;												\
	if (!memcmp (&iid, &myiid, sizeof (iid)))								\
	{																		\
		*ppv = (_interface*)this;											\
		AddRef ();															\
		return NS_OK;														\
	}																		\
																			\
	*ppv = NULL;															\
	return NS_NOINTERFACE;													\
}

#endif 