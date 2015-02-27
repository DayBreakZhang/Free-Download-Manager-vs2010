/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __ARRAY_H_
#define __ARRAY_H_

namespace fs
{

template <class T, UINT MAXSIZE>
class array
{
public:
	array ()
	{
		m_uPos = 0;
	}

	void add (T data)
	{
		if (m_uPos < MAXSIZE)
			m_a [m_uPos++] = data;
	}

	T& operator [] (int i)
	{
		return m_a [i];
	}

	int size ()
	{
		return m_uPos;
	}

	void clear ()
	{
		m_uPos = 0;
	}

protected:
	UINT m_uPos;
	T m_a [MAXSIZE];
};

};

#endif