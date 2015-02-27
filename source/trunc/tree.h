/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FS_TREE_H_
#define __FS_TREE_H_

#include <vmsObject.h>

namespace fs
{

template <class T> 
class ListTree : public vmsObject
{
public:
	typedef vmsObjectSmartPtr <ListTree> ListTreePtr;

public:
	ListTree* GetRoot () { return root; }
	void SetRoot (ListTree* r) { root = r; };

	void SetData (const T& d) {	data = d; }
	T& GetData () { return data; }

	ListTree* AddLeaf (const T& data)
	{
		ListTreePtr item;
		item.CreateInstance ();
		item->SetData (data);
		item->SetRoot (this);
		leafs.push_back (item);
		return item;
	}

	int GetLeafCount () const { return leafs.size (); }
	ListTree* GetLeaf (int iIndex) { return leafs [iIndex]; }
	void DeleteLeaf (int iIndex) { leafs.erase (leafs.begin () + iIndex); }

	int GetDepth () const { return root ? root->GetDepth () + 1 : 0; }

    void Clear () { leafs.clear (); }

protected:
	friend class vmsObject;
	friend class vmsObjectSmartPtr <ListTree>;
	ListTree () {}
	~ListTree () {}
protected:
	ListTreePtr root;
	std::vector <ListTreePtr> leafs;
	T data;
};

};

#endif