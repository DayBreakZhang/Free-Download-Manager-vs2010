// ChineseConvert.h: interface for the CChineseConvert class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHINESECONVERT_H__1515F40D_636D_44CC_8A84_5F979CCE9634__INCLUDED_)
#define AFX_CHINESECONVERT_H__1515F40D_636D_44CC_8A84_5F979CCE9634__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
using namespace std;

//debug and log
extern FILE* g_fp;
void Log2File(const char* format_str, ...);

class CChineseConvert  
{
public:
	CChineseConvert();
	virtual ~CChineseConvert();

	//从UTF-8编码的URL专用格式字符串还原成普通字符串
	static string Url_Utf8ToGB2312(string& instr);
	//UTF-8转GB2312
	static char* UTF8ToGB2312(const char* pStrUTF8);
	//检测是否UTF-8字符串
	static bool IsUTF8String(const char* pStr);

private:

	static char Char2Int(char ch);	
	static char Str2Bin(char *str);	
	static string UrlDecode(const string& str);

};

#endif // !defined(AFX_CHINESECONVERT_H__1515F40D_636D_44CC_8A84_5F979CCE9634__INCLUDED_)
