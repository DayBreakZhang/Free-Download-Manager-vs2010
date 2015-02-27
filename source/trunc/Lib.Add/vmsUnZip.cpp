/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "vmsUnZip.h"
#include "unzip.h"
#include <fileutil.h>

vmsUnZip::vmsUnZip()
{

}

vmsUnZip::~vmsUnZip()
{

}

BOOL vmsUnZip::Unpack(LPCTSTR ptszFileName, LPCTSTR ptszDstFolder)
{
	USES_CONVERSION;
	BOOL result = FALSE;
    unzFile zipFile = unzOpen (CT2AEX<> ((LPTSTR)ptszFileName));
    if (NULL != zipFile) 
    {
        if (UNZ_OK == unzGoToFirstFile(zipFile))
        {
            BOOL bContinue = TRUE;
            while (bContinue) 
            {
                result = FALSE;
                unz_file_info fi;
                char filename[MAX_PATH] = {0};
                if (UNZ_OK == unzGetCurrentFileInfo(zipFile, &fi, 
                    filename, sizeof (filename), 0, 0, 0, 0))
                {
					if (*filename && (filename [strlen (filename)-1] == '/' || filename [strlen (filename)-1] == '\\'))
					{
						assert (fi.uncompressed_size == 0);
						tstring tstr = ptszDstFolder;
						tstr += '\\';
						tstr += CA2TEX<> (filename);
						tstr += '1';
						vmsBuildPathToFile (tstr.c_str ());
						result = TRUE;
					}
					else if (UNZ_OK == unzOpenCurrentFile(zipFile))
                    {
                        UINT dataLen = fi.uncompressed_size;
                        BYTE* fileData = new BYTE[dataLen];
                        if (!fileData) 
                            break;
                        if(dataLen == unzReadCurrentFile(zipFile, fileData, dataLen))
                        {
                            char filePathName[MAX_PATH] = {0};
                            strcat (filePathName, T2A ((LPTSTR)ptszDstFolder));
                            strcat (filePathName, "\\");
                            strcat (filePathName, filename);
							while (strchr (filePathName, '/'))
								*strchr (filePathName, '/') = '\\';
							FILE* pFile = fopen (filePathName, "wb");
							if (!pFile)
							{
								vmsBuildPathToFile (CA2TEX<> (filePathName));
								pFile = fopen (filePathName, "wb");
							}
							if (pFile)
							{
								result = (dataLen == fwrite(fileData, 1, dataLen, pFile));
								result = result && (0 == fclose(pFile));
							}
                        }
                        delete [] fileData;
						result = result && (UNZ_OK == unzCloseCurrentFile(zipFile));
                    }
                }
                if (!result) 
                    break;
                if (UNZ_END_OF_LIST_OF_FILE == unzGoToNextFile(zipFile))
                    bContinue = FALSE;
            }
        }
        result = result && (UNZ_OK == unzClose(zipFile));
    }
    return result;
}
