// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

/*#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000*/

// Insert your headers here
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <tchar.h>
#include <time.h>
#include <windows.h>
#include <WinSock2.h>
#include <Ws2tcpip.h>

#include "display.h"
#include "rmff.h"
#include "asmrule.h"

#include "../Include.Add/vmsCriticalSection.h"
#include "../Include.Add/vmsObject.h"