/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef UTILS_INCLUDED_FILE
#define UTILS_INCLUDED_FILE

bool ComErrToSysErrCode(HRESULT hr, DWORD& dwErr); 

void FormatMessageByErrCode(CString& sMsg, DWORD dwErr, bool& bFailedToRetreive);

void appendDiagnostics(CString&sMsg, const CString& sDiagnostics);

const int g_nGrowBy = 128;

template<class T>
void InitArray(CArray<T, T&>& arrDest)
{
	arrDest.SetSize(0, g_nGrowBy);
}

template<class T>
void InitArray(CArray<T*, T*>& arrDest)
{
	arrDest.SetSize(0, g_nGrowBy);
}

template<class T>
void CleanArray(CArray<T, T&>& arrDest)
{
	arrDest.RemoveAll();
	arrDest.FreeExtra();
}

template<class T>
void CleanArray(CArray<T*, T*>& arrDest)
{
	arrDest.RemoveAll();
	arrDest.FreeExtra();
}

template<class T>
void CopyArray(CArray<T, T&>& arrDest, CArray<T, T&>& arrSrc)
{
	CleanArray(arrDest);

	int i = 0;
	for (i = 0; i <= arrSrc.GetUpperBound(); i++) {
		T& tSrc = arrSrc.ElementAt(i);
		arrDest.Add(tSrc);
	}
}

template<class T>
void CopyArray(CArray<T, T&>& arrDest, const CArray<T, T&>& arrSrc)
{
	CleanArray(arrDest);

	int i = 0;
	for (i = 0; i <= arrSrc.GetUpperBound(); i++) {
		T tSrc = arrSrc.ElementAt(i);
		arrDest.Add(tSrc);
	}
}

#define CHECK_BUFFER_BOUNDS(buff_size, size) if (pbtBuffer != NULL && (buff_size - (pbtCurrentPos - pbtBuffer) < size)) return;
#define BOOLEAN_CHECK_BUFFER_BOUNDS(buff_size, size) if (pbtBuffer != NULL && (buff_size - (pbtCurrentPos - pbtBuffer) < size)) return false;

void putStrToBuffer(LPCTSTR tszStr, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSizeSize, DWORD* pdwSizeReuiqred);
bool getStrFromBuffer(LPTSTR* ptszStr, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSizeSize);

template <class T>
void putVarToBuffer(const T& t, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSizeSize, DWORD* pdwSizeReuiqred)
{
	if (pbtBuffer == 0) {
		if (pdwSizeReuiqred != 0) {
			*pdwSizeReuiqred += sizeof(t);
		}
		return;
	}

	CHECK_BUFFER_BOUNDS(dwBufferSizeSize, sizeof(t));
	CopyMemory(pbtCurrentPos, &t, sizeof(t));
	pbtCurrentPos += sizeof(t);
}

template<class T>
bool getVarFromBuffer(T& t, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSizeSize)
{
	if (pbtBuffer == 0 || pbtCurrentPos == 0)
		return false;

	BOOLEAN_CHECK_BUFFER_BOUNDS(dwBufferSizeSize, sizeof(t));
	CopyMemory(&t, pbtCurrentPos, sizeof(t));
	pbtCurrentPos += sizeof(t);
	return true;
}

template<class T>
void putListToBuffer(fs::list<T>* pvList, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSize, DWORD* pdwSizeRequired)
{
	if (pvList == 0)
		return;

	pvList->lock();
	int nCount = pvList->size();
	putVarToBuffer(nCount, pbtCurrentPos, 0, 0, pdwSizeRequired);
	TRACE("nCount: %d, size: %d\r\n", nCount, pdwSizeRequired ? *pdwSizeRequired : -1);

	int i = 0;
	for (i = 0; i < pvList->size(); i++) {
		putVarToBuffer(pvList->at(i), pbtCurrentPos, 0, 0, pdwSizeRequired);
		TRACE("element size: %d\r\n", pdwSizeRequired ? *pdwSizeRequired : -1);
	}

	if (pbtBuffer == NULL) {
		pvList->unlock();
		return;
	}

	putVarToBuffer(nCount, pbtCurrentPos, pbtBuffer, dwBufferSize, 0);

	for (i = 0; i < pvList->size(); i++) {
		putVarToBuffer(pvList->at(i), pbtCurrentPos, pbtBuffer, dwBufferSize, 0);
	}

	pvList->unlock();
}

template<class T>
bool getListFromBuffer(fs::list<T>* pvList, LPBYTE& pbtCurrentPos, LPBYTE pbtBuffer, DWORD dwBufferSize)
{
	if (pvList == 0)
		return false;

	pvList->lock();
	int nCount = 0;
	if (!getVarFromBuffer(nCount, pbtCurrentPos, pbtBuffer, dwBufferSize)) {
		pvList->unlock();
		return false;
	}

	if (nCount < 0) {
		pvList->unlock();
		return false;
	}

	int i = 0;
	for (i = 0; i < nCount; i++) {
		T t;
		if (!getVarFromBuffer(t, pbtCurrentPos, pbtBuffer, dwBufferSize)) {
			pvList->unlock();
			return false;
		}
		pvList->add(t);
	}

	pvList->unlock();
	return true;
}

#endif
