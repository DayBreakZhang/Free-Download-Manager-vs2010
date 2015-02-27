// ChineseConvert.cpp: implementation of the CChineseConvert class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ChineseConvert.h"

#include <windows.h>
#include <time.h>	// for time

//debug and log
FILE* g_fp = NULL;

void Log2File(const char* format_str, ...)
{
	if (g_fp)
	{
		time_t t = time(NULL);
		struct tm *ptime = localtime(&t);
		va_list p_list;
		va_start(p_list, format_str);
		fprintf(g_fp, "[%04d%02d%02d-%02d:%02d:%02d]", 
			(1900+ptime->tm_year), (1+ptime->tm_mon), ptime->tm_mday,
            ptime->tm_hour, ptime->tm_min, ptime->tm_sec);
		vfprintf(g_fp, format_str, p_list);
		va_end(p_list);
		
		fflush(g_fp);
	}
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChineseConvert::CChineseConvert()
{

}

CChineseConvert::~CChineseConvert()
{

}

char CChineseConvert::Char2Int(char ch)
{
	if(ch>='0' && ch<='9')return (char)(ch-'0');
	if(ch>='a' && ch<='f')return (char)(ch-'a'+10);
	if(ch>='A' && ch<='F')return (char)(ch-'A'+10);
	return -1;
}

char CChineseConvert::Str2Bin(char *str)
{
	char tempWord[2] = {0};
	char chn;

	tempWord[0] = Char2Int(str[0]);			//make the B to 11 -- 00001011
	tempWord[1] = Char2Int(str[1]);			//make the 0 to 0  -- 00000000

	chn = (tempWord[0] << 4) | tempWord[1];	//to change the BO to 10110000

	return chn;
}

string CChineseConvert::UrlDecode(const string& str)
{
	string output = "";
	char tmp[2] = {0};
	int i = 0;
	int len = str.length();
        
	while(i < len)
	{
		if(str[i]=='%')
		{
			tmp[0] = str[i+1];
			tmp[1] = str[i+2];
			output += Str2Bin(tmp);
			i += 3;
		}
		else if(str[i]=='+')
		{
			output += ' ';
			i++;
		}
		else
		{
			output += str[i];
			i++;
		}
	}
        
	return output;
}

char* CChineseConvert::UTF8ToGB2312(const char* pStrUTF8)
{
	// 先转成宽字符
	int nStrLen = MultiByteToWideChar(CP_UTF8, 0, pStrUTF8, -1, NULL, 0);
	wchar_t* pWStr = new wchar_t[nStrLen + 1];
	memset(pWStr, 0, nStrLen + 1);
	MultiByteToWideChar(CP_UTF8, 0, pStrUTF8, -1, pWStr, nStrLen);
	
	// 再转成GB2312
	nStrLen = WideCharToMultiByte(CP_ACP, 0, pWStr, -1, NULL, 0, NULL, NULL);
	char* pStr = new char[nStrLen + 1];
	memset(pStr, 0, nStrLen + 1);
	WideCharToMultiByte(CP_ACP, 0, pWStr, -1, pStr, nStrLen, NULL, NULL);
	Log2File("[UTF8ToGB2312]%s -> %s\n", pWStr, pStr);
	if(pWStr)
	{
		delete[] pWStr;
	}

	return pStr;
}

//输入url_Utf-8 ,输出 gb2312
string CChineseConvert::Url_Utf8ToGB2312(string& instr)
{
	string input = UrlDecode(instr);	
	string output = UTF8ToGB2312(input.c_str());

	Log2File("[Url_Utf8ToGB2312]%s -> %s -> %s\n", instr.c_str(), input.c_str(), output.c_str());

	return output;
}

bool CChineseConvert::IsUTF8String(const char* pStr)
{
    int i = 0;
    int nBytes = 0;//UTF8可用1-6个字节编码,ASCII用一个字节
    unsigned char chr = 0;
    bool bAllAscii = true;//如果全部都是ASCII,说明不是UTF-8

	int length = strlen(pStr);
	
    while (i < length)
    {
        chr = *(pStr + i);
        if ((chr & 0x80) != 0)
            bAllAscii = false;

        if (nBytes == 0)//计算字节数
        {
            if ((chr & 0x80) != 0)
            {
                while ((chr & 0x80) != 0)
                {
                    chr <<= 1;
                    nBytes++;
                }

                if (nBytes < 2 || nBytes > 6)
                    return false;//第一个字节最少为110x xxxx

                nBytes--;//减去自身占的一个字节
            }
        }
        else//多字节除了第一个字节外剩下的字节
        {
            if ((chr & 0xc0) != 0x80)
                return false;//剩下的字节都是10xx xxxx的形式

            nBytes--;
        }

        ++i;
    }

    if (bAllAscii)
        return false;

    return nBytes == 0;
}
