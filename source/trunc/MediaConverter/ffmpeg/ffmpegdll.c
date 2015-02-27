#include <windows.h>
#include <stdlib.h> 


BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	return TRUE;
}

static BOOL _bCancel = FALSE;

void exit (int code) 
{
	ExitThread (code);
}

int kbhit ()
{
	return _bCancel ? 1 : 0;
}

int getch ()
{
	return _bCancel ? 'q' : 0;
}

#include "ffmpeg.c"

DWORD WINAPI _threadConvert (LPVOID lp)
{
    char **ppszArgs = (char**)lp;
	int cArgs = 0;
	while (ppszArgs [cArgs])
		cArgs++;
    return main (cArgs, ppszArgs);
}

static LONG _lDllUsed = 0;

__declspec(dllexport) int Convert (LPCSTR pszSrcFile, LPCSTR pszDstFile, LPCSTR pszDstFormat, 
								   LPCSTR pszAudioCodec /*can be NULL*/, int nAudioChannels, int nAudioBitrate, 
								   int nAudioRate, LPCSTR pszVideoCodec /*can be NULL*/, int nVideoBitrate,
								   int nVideoFrameRate, int nVideoFrameWidth, int nVideoFrameHeight,
								   int nThreads, int *pnProgress, BOOL *pbCancel)
{
    if (InterlockedIncrement (&_lDllUsed) != 1)
    	return -1; // DLL was used already, and can't be used again
    	// it's required to reload it
    	// (this makes it easier to make changes in this DLL on further changes in FFMPEG)

	char szAudioChannels [20] = "", szAudioBitrate [20] = "", szAudioRate [20] = "",
		szVideoBitrate [20] = "", szVideoFrameRate [20] = "", szVideoFrameSize [40] = "",
		szThreads [20] = "";

	if (!pszDstFormat)
		pszDstFormat = "avi";
	if (nVideoBitrate != -1) /*e.g. 128000 -> 128kbps*/
		sprintf (szVideoBitrate, "%dk", nVideoBitrate);
	if (nVideoFrameRate != -1) /*e.g. 25Hz*/
		_itoa (nVideoFrameRate, szVideoFrameRate, 10);
	if (nVideoFrameWidth != -1 && nVideoFrameHeight != -1) /*e.g. 640x480*/
		sprintf (szVideoFrameSize, "%dx%d", nVideoFrameWidth, nVideoFrameHeight);
	if (nAudioChannels != -1) /*e.g. 2*/
		_itoa (nAudioChannels, szAudioChannels, 10);
	if (nAudioBitrate != -1) /*e.g. 128000 -> 128kbps*/
		sprintf (szAudioBitrate, "%dk", nAudioBitrate);
	if (nAudioRate != -1) /*e.g. 44100Hz*/
		_itoa (nAudioRate, szAudioRate, 10);
	if (pszAudioCodec != NULL && stricmp (pszAudioCodec, "mp3") == 0)
		pszAudioCodec = "libmp3lame";
	if (nThreads > 1)
		_itoa (nThreads, szThreads, 10);

	char* apszArgs [100];
	int i = 0;
    apszArgs [i++] = "ffmpeg.exe";
    apszArgs [i++] = "-v";  // verbose level
    apszArgs [i++] = "-1";
	apszArgs [i++] = "-y";  // overwrite destination file

	apszArgs [i++] = "-i";  // source file
    apszArgs [i++] = (char*)pszSrcFile;

	apszArgs [i++] = "-f";
	apszArgs [i++] = (char*)pszDstFormat;

	if (pszVideoCodec)
	{
		apszArgs [i++] = "-vcodec";
		apszArgs [i++] = (char*)pszVideoCodec;
	}
	if (*szVideoBitrate)
	{
		apszArgs [i++] = "-vb";
		apszArgs [i++] = szVideoBitrate;
	}
	if (*szVideoFrameRate)
	{
		apszArgs [i++] = "-r";
		apszArgs [i++] = szVideoFrameRate;
	}
	if (*szVideoFrameSize)
	{
		apszArgs [i++] = "-s";
		apszArgs [i++] = szVideoFrameSize;
	}
	if (pszAudioCodec)
	{
		apszArgs [i++] = "-acodec";
		apszArgs [i++] = (char*)pszAudioCodec;
	}
	if (*szAudioBitrate)
	{
		apszArgs [i++] = "-ab";
		apszArgs [i++] = szAudioBitrate;
	}
	if (*szAudioRate)
	{
		apszArgs [i++] = "-ar";
		apszArgs [i++] = szAudioRate;
	}
	if (*szAudioChannels)
	{
		apszArgs [i++] = "-ac";
		apszArgs [i++] = szAudioChannels;
	}

	if (*szThreads)
	{
		apszArgs [i++] = "-threads"; // thread count
		apszArgs [i++] = szThreads;
	}

    apszArgs [i++] = (char*)pszDstFile;

	apszArgs [i] = NULL; // end of arguments

	input_files [0] = NULL;

    DWORD dw;
    HANDLE hThread = CreateThread (NULL, 0, _threadConvert, apszArgs, 0, &dw);
    if (!hThread)
    	return 1; // error
	if (pnProgress)
		*pnProgress = 0;

    while (WAIT_TIMEOUT == WaitForSingleObject (hThread, 200))
	{
    	if (pnProgress && input_files[0] && input_files[0]->file_size && input_files[0]->pb)
			*pnProgress = (int) (input_files[0]->pb->pos * 100 / input_files[0]->file_size);
		if (pbCancel && *pbCancel)
			_bCancel = TRUE;//TerminateThread (hThread, (DWORD)-2);
			
	}
    
    dw = 0;
    GetExitCodeThread (hThread, &dw);
	CloseHandle (hThread);

    return dw;
}

