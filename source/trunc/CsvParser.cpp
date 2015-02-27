/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "CsvParser.h"

CCsvParser::CCsvParser()
	: m_nPos(0)
{
}

CCsvParser::~CCsvParser()
{
}

void CCsvParser::Init(const CString& sStr, const CString& sTextQulifier, const CString& sDelimiter)
{
	m_sCsvContent = sStr;

	if (sTextQulifier.GetLength() == 1)
		m_sTextQulifier = sTextQulifier;
	else
		m_sTextQulifier = "\"";

	if (sDelimiter.GetLength() == 1)
		m_sDelimiter = sDelimiter;
	else
		m_sDelimiter = ",";

	m_nPos = 0;
}

bool CCsvParser::ParseNextRecord()
{
	Sgets();
	if (m_nPos < m_sCsvContent.GetLength() - 1) {
		++m_nPos;
		return true;
	}

	return false;
}

int CCsvParser::countQuote(int nStartChar, const CString& sValue)
{
	if (nStartChar < 0 || nStartChar > sValue.GetLength() - 1)
		return -1;

	int nUpperBound = sValue.GetLength() - 1;
	int nCount = 0;
	for (int i = nStartChar; i <= nUpperBound && sValue.GetAt(i) == m_sTextQulifier.GetAt(0); i++, ++nCount)
		;

	return nCount;
}

int CCsvParser::findSingleQuote(int nStartChar, const CString& sValue)
{
	if (nStartChar < 0 || nStartChar > sValue.GetLength() - 1)
		return -1;

	int nUpperBound = sValue.GetLength() - 1;
	int i = nStartChar;
	while (i <= nUpperBound) {
		if (sValue.GetAt(i) == m_sTextQulifier.GetAt(0)) {
			int nQuoteCount = countQuote(i, sValue);
			if ((int)(nQuoteCount * 0.5) * 2 != nQuoteCount)
				return i + nQuoteCount - 1;
			else
				i += nQuoteCount;
		} else {
			i++;
		}
	}

	return -1;
}

int CCsvParser::findDelimiter(bool& bIsQuote, int& nClosingQuotePos)
{
	nClosingQuotePos = -1;
	int nPos = -1;
	int nDelimPos = -1;
	int nQuoteCount = countQuote(0, m_sRow);

	if ((int)(nQuoteCount * 0.5) * 2 != nQuoteCount) {

		bIsQuote = true;

		nPos = findSingleQuote(nQuoteCount, m_sRow);
		nClosingQuotePos = nPos;

		if (nPos == -1) {
			nDelimPos = -1;
		} else if (nPos == m_sRow.GetLength() - 1) {
			nDelimPos = -1;
		} else {
			nDelimPos = m_sRow.Find(m_sDelimiter.GetAt(0), nPos + 1);
		}

	} else {
		nDelimPos = m_sRow.Find(m_sDelimiter.GetAt(0));
	}

	return nDelimPos;
}

void CCsvParser::decodeValue(bool bIsQuote, int nClosingQuotePos, CString& sValue)
{
	if (bIsQuote) {
		ASSERT((nClosingQuotePos == -1 || nClosingQuotePos >= 2) && 
				(nClosingQuotePos <= sValue.GetLength() - 1));

		CString sFirstPart;
		CString sSecondPart;
		
		if (nClosingQuotePos != -1) {

			sFirstPart = sValue.Mid(1, nClosingQuotePos - 1);
			if (nClosingQuotePos <= sValue.GetLength() - 1)
				sSecondPart = sValue.Mid(nClosingQuotePos + 1);

		} else {
			sFirstPart = sValue.Mid(1);
		}

		CString sDoubleTextQulifier = m_sTextQulifier + m_sTextQulifier;

		sFirstPart.Replace(sDoubleTextQulifier, m_sTextQulifier);
		sValue = sFirstPart + sSecondPart;

	}
}

void CCsvParser::procLastField(bool bIsQuote, int nClosingQuotePos, CString& sValue)
{
	sValue = m_sRow;
	m_sRow = "";
	decodeValue(bIsQuote, nClosingQuotePos, sValue);
}

void CCsvParser::procLastButOneField(bool bIsQuote, int nClosingQuotePos, CString& sValue)
{
	sValue = m_sRow.Mid(0, m_sRow.GetLength() - 1);
	m_sRow = "";
	decodeValue(bIsQuote, nClosingQuotePos, sValue);
}

void CCsvParser::procField(int nDelimPos, bool bIsQuote, int nClosingQuotePos, CString& sValue)
{
	sValue = m_sRow.Mid(0, nDelimPos);
	m_sRow = m_sRow.Mid(nDelimPos + 1);
	decodeValue(bIsQuote, nClosingQuotePos, sValue);
}

bool CCsvParser::GetNextField(CString& sValue)
{
	bool bIsQuote = false;
	int nClosingQuotePos = -1;

	
	int nDelimPos = findDelimiter(bIsQuote, nClosingQuotePos);

	
	if (nDelimPos == -1) {
		procLastField(bIsQuote, nClosingQuotePos, sValue);
		
		return false;
	}

	
	
	if (nDelimPos == m_sRow.GetLength() - 1) {
		procLastButOneField(bIsQuote, nClosingQuotePos, sValue);
		
		return true;
	}
	
	
	procField(nDelimPos, bIsQuote, nClosingQuotePos, sValue);
	
	
	return true;
}

void CCsvParser::Sgets()
{
	ASSERT((m_nPos >= 0) && (m_sCsvContent.IsEmpty() || m_nPos <= m_sCsvContent.GetLength() - 1));

	m_sRow.Empty();
	wchar_t c = 0;

	bool bIsTextQulifierScope = true;
	bool bIsField = false;
	bool bIsLineFeed = false;
	while ((c != '\n' || bIsField) && m_nPos <= m_sCsvContent.GetLength() - 1) {

		if (bIsTextQulifierScope) {
			if (c == m_sTextQulifier.GetAt(0)) {
				bIsField = !bIsField;
			} else {
				if (!bIsField)
					bIsTextQulifierScope = false;
			}
		}

		if (!bIsTextQulifierScope && (c == m_sDelimiter.GetAt(0))) {
			bIsTextQulifierScope = true;
		}

		if (c != L'\r')
			bIsLineFeed = false;
		else
			bIsLineFeed = true;

		m_sRow += m_sCsvContent.Mid(m_nPos, 1);

		++m_nPos;
		if (m_nPos <= m_sCsvContent.GetLength() - 1)
			c = m_sCsvContent[m_nPos];
	}

	
	if (c == L'\n' && bIsLineFeed) {
		ASSERT(m_sRow.GetLength() >= 1);

		m_sRow = m_sRow.Mid(0, m_sRow.GetLength() - 1);
	}
}
