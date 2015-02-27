/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSBROWSERFLVHISTORY_H__3804952E_83B3_40C0_B7DF_7BC4A97EB102__INCLUDED_)
#define AFX_VMSBROWSERFLVHISTORY_H__3804952E_83B3_40C0_B7DF_7BC4A97EB102__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsBrowserFlvHistory  
{
public:
	struct Item
	{
		string strUrl;
		string strHttpResponse;
		string strContentType;
	};
public:
	const Item* getItem (int nIndex) const;
	int getItemCount() const;
	virtual void Gather () = NULL;
	vmsBrowserFlvHistory();
	virtual ~vmsBrowserFlvHistory();

protected:
	vector <Item> m_vItems;
};

#endif 
