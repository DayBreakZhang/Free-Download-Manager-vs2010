/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FSTREE_H_
#define __FSTREE_H_

namespace fs
{

template <class T>
class tree
{
public:
	tree () 
	{
		m_pRoot		= NULL;
		m_pLeft		= NULL;
		m_pRight	= NULL;
	}

	~tree ()
	{
		Clear ();
	}

	void Clear ()
	{
		if (m_pLeft)
			delete m_pLeft;

		if (m_pRight)
			delete m_pRight;

		m_pLeft = m_pRight = NULL;
	}

	void Data (const T& data)
	{
		m_data = data;
	}

	T Data ()
	{
		return m_data;
	}

	void Left (tree* pTree)
	{
		if (m_pLeft)
			delete m_pLeft;

		m_pLeft = pTree;
	}

	tree* Left () const
	{
		return m_pLeft;
	}

	void Right (tree* pTree)
	{
		if (m_pRight)
			delete m_pRight;

		m_pRight = pTree;
	}

	tree* Right () const
	{
		return m_pRight;
	}

	void Root (tree* pTree)
	{
		if (m_pRoot)
			delete m_pRoot;

		m_pRoot = pTree;
	}

	tree* Root () const
	{
		return m_pRoot;
	}

protected:
	tree *m_pRoot;
	tree *m_pLeft;
	tree *m_pRight;
	T m_data;

private:
	tree (tree&) {}
	tree operator = (tree&) {}
};

}; 

#endif