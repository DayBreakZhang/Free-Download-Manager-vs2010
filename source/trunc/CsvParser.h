/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef CSVPARSER_INCLUDED_FILE
#define CSVPARSER_INCLUDED_FILE

class CCsvParser
{
public:
	CCsvParser();
	virtual ~CCsvParser();
	void Init(const CString& sStr, const CString& sTextQulifier, const CString& sDelimiter);
	bool ParseNextRecord();
	bool GetNextField(CString& sValue);

private:
	void Sgets();
	int findDelimiter(bool& bIsQuote, int& nClosingQuotePos);
	int countQuote(int nStartChar, const CString& sValue);
	void procLastField(bool bIsQuote, int nClosingQuotePos, CString& sValue);
	void procLastButOneField(bool bIsQuote, int nClosingQuotePos, CString& sValue);
	void procField(int nDelimPos, bool bIsQuote, int nClosingQuotePos, CString& sValue);
	void decodeValue(bool bIsQuote, int nClosingQuotePos, CString& sValue);
	int findSingleQuote(int nStartChar, const CString& sValue);

	CString m_sCsvContent; 
	CString m_sRow; 
	CString m_sTextQulifier;
	CString m_sDelimiter;
	int m_nPos;
};

#endif
