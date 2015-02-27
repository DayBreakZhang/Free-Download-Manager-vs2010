/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __VMS_ARRAY_H_
#define __VMS_ARRAY_H_

namespace vms
{

template <class T> 
struct array
{
	array (int nInitialSize = 0) {
		construct_init_object ();
		if (nInitialSize)
			realloc (nInitialSize);
	}
	~array () {if (m_p) delete [] m_p;}

	array (const array& a) {
		construct_init_object ();
		operator=(a);
	}

	operator T* () {return m_p;}

	void put_Data (const T* const p, int len) {
		if (m_size < len)
			realloc (len);
		CopyMemory (m_p, p, len * sizeof (T));
		m_len = len;
	}

	array& operator= (const array& a) {
		put_Data (a, a.m_len);
		return *this;
	}

	array& operator += (const array& a) {add (a, a.m_len); return *this;}

	void add (const T* const p, int len) {
		realloc (m_len + len);
		CopyMemory (m_p + m_len, p, len * sizeof (T));
		m_len += len;
	}

	T& operator [] (int nIndex)
	{
		if (nIndex+1 > m_size)
			realloc (nIndex+1);

		if (m_len <= nIndex) {
			m_len = nIndex + 1;
			m_p [nIndex] = T(0);
		}
		return m_p [nIndex];
	}

	void realloc (int nNewLen)
	{
		if (nNewLen < m_size)
			return;
		T* p = new T [nNewLen];
		if (m_p) {
			CopyMemory (p, m_p, sizeof (T)*m_len);
			delete [] m_p;
		}
		m_p = p;
		m_size = nNewLen;
	}

	void clear () {m_len = 0;};

	int length () {return m_len;}
	int capacity () {return m_size;}

protected:
	void construct_init_object () {
		m_p = 0; 
		m_size = m_len = 0;
		m_grow = 1000;
	};
	T* m_p;
	int m_size;	
	int m_len;	
	int m_grow;	
};

};

#endif	