/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FS_TREE_H_
#define __FS_TREE_H_

#include "list.h"

namespace fs
{

template <class T> 
class ListTree
{
public:
	ListTree <T>* GetRoot () { return root; }
	void SetRoot (ListTree <T>* r) { root = r; };

	void SetData (const T& d) {	data = d; }
	T& GetData () { return data; }

	ListTree <T>* AddLeaf (const T& data)
	{
		ListTree <T> *item = new ListTree <T>;
		item->SetData (data);
		item->SetRoot (this);
		leafs.add (item);
		return item;
	}

	int GetLeafCount () { return leafs.size (); }
	ListTree <T>* GetLeaf (int iIndex) { return leafs [iIndex]; }
	void DeleteLeaf (int iIndex) { leafs.del (iIndex); }

	int GetDepth ()
	{
		return root ? root->GetDepth () + 1 : 0;
	}

        void Clear ()
	{
		for (int i = 0; i < leafs.size (); i++) 
			delete leafs [i]; 
		leafs.clear ();
	}

	ListTree () {root = NULL;}
	~ListTree () { for (int i = 0; i < leafs.size (); i++) delete leafs [i]; leafs.clear (); }
protected:
	ListTree <T> *root;
	list <ListTree*> leafs;
	T data;
};

};

#endif