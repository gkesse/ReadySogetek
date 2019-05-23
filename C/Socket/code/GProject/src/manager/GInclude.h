//===============================================
#ifndef _GInclude_
#define _GInclude_
//===============================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//===============================================
#ifdef __WIN32
#include <winsock2.h>
#define G_PLATEFORM_OS "WINDOWS"
#else
#define G_PLATEFORM_OS "UNIX"
#endif
//===============================================
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
//===============================================
#endif
//===============================================
