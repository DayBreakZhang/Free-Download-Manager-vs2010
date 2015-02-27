/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __FSLIST_H_
#define __FSLIST_H_

namespace fs
{

template <class T>
class list
{

public:
	template <class T>
	struct ListItem 
	{
		T data;
		ListItem *next, *prev;
	};

	BOOL save (HANDLE hFile)
	{
		int sz = size ();
		DWORD dw;

		if (!WriteFile (hFile, &sz, sizeof (sz), &dw, NULL))
			return FALSE;

		for (int i = 0; i < sz; i++)
		{
			if (!WriteFile (hFile, &at (i), sizeof (T), &dw, NULL))
				return FALSE;
		}

		return TRUE;
	}

	BOOL load (HANDLE hFile)
	{
		int sz;
		DWORD dw;

		if (!ReadFile (hFile, &sz, sizeof (sz), &dw, NULL) || dw != sizeof (sz))
			return FALSE;

		if (sz < 0)
			return FALSE;

		while (sz--)
		{
			T data;
			if (!ReadFile (hFile, &data, sizeof (T), &dw, NULL) || dw != sizeof (T))
				return FALSE;

			add (data);
		}

		return TRUE;
	}

	void add (T data)
	{
		ListItem <T> *item = new ListItem <T>;

		item->data = data;
		item->next = item->prev = NULL;

		if (end)
		{
			end->next = item;
			item->prev = end;
			end = item;
		}
		else
		{
			start = end = item;
		}

		_size++;
	}

	void insert (int iInsert, T data)
	{
		ListItem <T> *itemAfter = start;
		ListItem <T> *itemBefore = start;
		ListItem <T> *item;

		last = NULL;

		while (iInsert && itemAfter)
		{
			itemBefore = itemAfter;
			itemAfter = itemAfter->next;
			iInsert--;
		}

		if (itemAfter == NULL)
		{
			add (data);
			return;
		}

		item = new ListItem <T>;

		item->data = data;
		item->next = itemAfter;
		item->prev = itemBefore;

		itemAfter->prev = item;

		if (itemAfter == itemBefore)
		{
			start = item;
			item->prev = NULL;
		}
		else
		{
			itemBefore->next = item;
		}

		_size++;
	}

	void del (int i)
	{
		ListItem <T> *item = start;

		while (item && i--)
		{
			item = item->next;
		}

		if (item == NULL)
			return;

		if (item->prev)
			item->prev->next = item->next;
		else
			start = item->next;

		if (item->next)
			item->next->prev = item->prev;
		else
			end = item->prev;

		delete item;

		last = NULL;

		_size--;
	}

	void clear ()
	{
		if (!start)
			return;

		ListItem <T> *item;

		while (start)
		{
			item = start->next;
			delete start;
			start = item;
		}

		start = end = NULL;
		last = NULL;
		_size = 0;
	}

	int size () const
	{
		return _size;
	}

	T& at (int i)
	{
		ListItem <T> *item = NULL;

		if (last)
		{
			if (lastIndex == i)
				item = last;
			else if (i == lastIndex - 1)
			{
				item = last->prev;
			}
			else if (i == lastIndex+1)
			{
				item = last->next;
			}
		}

		lastIndex = i;
		
		if (item == NULL)
		{
			item = start;
			while (i--) 
				item = item->next;
		}

		last = item;
		
		return item->data;
	}

	int find (T& item)
	{
		for (int i = 0; i < size (); i++)
			if (at (i) == item)
				break;

		return i != size () ? i : -1;
	}

	T& operator [] (int i)
	{
		return at (i);		
	}

	list& operator = (list& l)
	{
		clear ();
		for (int i = 0; i < l.size (); i++)
			add (l [i]);

		return *this;
	}

	list (list& l)
	{
		start = end = NULL;
		last = NULL;
		_size = 0;

		*this = l;
	}

	list () 
	{ 
		start = end = NULL;
		last = NULL;
		_size = 0;
	}

	~list () 
	{
		clear ();
	};

private:
	ListItem <T> *start, *end;
	ListItem <T> *last; int lastIndex;
	int _size;
};

};

#endif