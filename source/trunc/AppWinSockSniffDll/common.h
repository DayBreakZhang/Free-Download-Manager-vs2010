/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __COMMON__H_
#define __COMMON__H_

template <class T>
class myvector : public std::vector <T>
{
public:
	int findIndex (const T& elem) const {
		for (size_t i = 0; i < size (); i++)
		{
			if (at (i) == elem)
				return i;
		}
		return -1;
	}
};

#endif 