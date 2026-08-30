#ifndef SHIM_H
#define SHIM_H

#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

typedef void *undefined;
typedef void (*code)(void);
typedef uint8_t undefined1;
typedef uint16_t undefined2;
typedef uint32_t undefined4;
typedef uint64_t undefined8;
typedef unsigned char byte;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned long ulong;
typedef long long longlong;
typedef unsigned long long ulonglong;

/* Ghidra emits undefinedN for odd/unknown sizes */
typedef unsigned char undefined3;
typedef unsigned char undefined5;
typedef unsigned char undefined6;
typedef unsigned char undefined7;
typedef unsigned char undefined9;
typedef unsigned char undefined10;
typedef unsigned char undefined12;
typedef unsigned char undefined16;
typedef unsigned char undefined20;
typedef unsigned char undefined24;
typedef unsigned char undefined32;

/* Opaque structs: Ghidra addresses these with byte arithmetic, so treat as 1-byte */
typedef unsigned char sdata;
typedef struct tm tm;
typedef struct itimerval itimerval;
typedef unsigned char cups_page_header2_s;
typedef unsigned char _cups_raster_s;
typedef unsigned char ppd_file_s;
typedef unsigned char faxcomp;
typedef unsigned char _BRCalibrationInfo;

/* CUPS + libc symbol aliasing: Mach-O imports use leading underscore */
#define _printf printf
#define _fprintf fprintf
#define _fwrite fwrite
#define _fflush fflush
#define _fopen fopen
#define _fclose fclose
#define _puts puts
#define _putchar putchar
#define _putc putc
#define _getc getc
#define _setbuf setbuf
#define _printf printf
#define _sprintf sprintf
#define _snprintf snprintf
#define _sscanf sscanf
#define _fscanf fscanf
#define _perror perror
#define _exit exit
#define _malloc malloc
#define _free free
#define _calloc calloc
#define _realloc realloc
#define _memcpy memcpy
#define _memset memset
#define _memmove memmove
#define _strcmp strcmp
#define _strncmp strncmp
#define _strcpy strcpy
#define _strncpy strncpy
#define _strcat strcat
#define _strncat strncat
#define _strlen strlen
#define _strstr strstr
#define _strchr strchr
#define _strtok strtok
#define _strcasecmp strcasecmp
#define _strncasecmp strncasecmp
#define _atoi atoi
#define _atol atol
#define _atof atof
#define _getenv getenv
#define _time time
#define _localtime localtime
#define _gmtime gmtime
#define _gettimeofday gettimeofday
#define _getuid getuid
#define _sleep sleep
#define _close close
#define _open open
#define _read read
#define _write write
#define _creat creat
#define _chmod chmod
#define _mkdir mkdir
#define _remove remove
#define _access access
#define _stat stat
#define _lstat lstat
#define _opendir opendir
#define _closedir closedir
#define _readdir readdir
#define _isatty isatty
#define _signal signal
#define _getpid getpid
#define _kill kill
#define _fstat fstat
#define _ftruncate ftruncate
#define _fdatasync fdatasync
#define _fsync fsync
#define _unlink unlink
#define _rename rename
#define _readlink readlink
#define ___bzero bzero
#define ___error __errno_location
#define ___sprintf_chk sprintf
static void __attribute__((noreturn)) _stack_chk_fail_wrap(void) { abort(); }
#define ___stack_chk_fail _stack_chk_fail_wrap
#define SBORROW1(a,b) ((unsigned char)(a) < (unsigned char)(b))
#define SBORROW2(a,b) ((unsigned short)(a) < (unsigned short)(b))
#define SBORROW4(a,b) ((unsigned int)(a) < (unsigned int)(b))
#define SBORROW8(a,b) ((unsigned long long)(a) < (unsigned long long)(b))
#define SCARRY1(a,b) ((unsigned char)(a) > (unsigned char)((a) - (b)))
#define SCARRY2(a,b) ((unsigned short)(a) > (unsigned short)((a) - (b)))
#define SCARRY4(a,b) ((unsigned int)(a) > (unsigned int)((a) - (b)))
#define SCARRY8(a,b) ((unsigned long long)(a) > (unsigned long long)((a) - (b)))
#undef NAN
#define NAN(x) isnan(x)
static void _memset_pattern16_impl(void *b, const void *pattern16, size_t len) {
  unsigned char *p = (unsigned char *)b;
  const unsigned char *pat = (const unsigned char *)pattern16;
  size_t i;
  for (i = 0; i < len; i++) p[i] = pat[i & 15];
}
#define _memset_pattern16 _memset_pattern16_impl
extern uintptr_t __stack_chk_guard;
extern void __stack_chk_fail(void) __attribute__((noreturn));
#define _setitimer setitimer
#define _setlocale setlocale
#define _gmtime_r gmtime_r
#define _localtime_r localtime_r
#define _strdup strdup
#define _rand rand
#define _srand srand
#define _abs abs
#define _labs labs
#define _floor floor
#define _ceil ceil
#define _memcmp memcmp
#define _strtol strtol
#define _strtoul strtoul
#define _getline getline

/* Ghidra CONCATxx macros: combine two integers into one (a=HIGH, b=LOW) */
#define CONCAT11(a,b) (((byte)(a) << 8) | ((byte)(b)))
#define CONCAT12(a,b) (((byte)(a) << 16) | ((ushort)(b)))
#define CONCAT14(a,b) (((byte)(a) << 32) | ((uint)(b)))
#define CONCAT18(a,b) (((byte)(a) << 56) | ((ulong)(b)))
#define CONCAT21(a,b) (((ushort)(a) << 8) | ((byte)(b)))
#define CONCAT22(a,b) (((ushort)(a) << 16) | ((ushort)(b)))
#define CONCAT24(a,b) (((ushort)(a) << 32) | ((uint)(b)))
#define CONCAT28(a,b) (((ushort)(a) << 48) | ((ulong)(b)))
#define CONCAT41(a,b) (((uint)(a) << 8) | ((byte)(b)))
#define CONCAT42(a,b) (((uint)(a) << 16) | ((ushort)(b)))
#define CONCAT44(a,b) (((uint)(a) << 32) | ((uint)(b)))
#define CONCAT48(a,b) (((ulong)(a) << 32) | ((ulong)(b)))
#define CONCAT81(a,b) (((ulong)(a) << 8) | ((ulong)(byte)(b)))
#define CONCAT82(a,b) (((ulong)(a) << 16) | ((ulong)(ushort)(b)))
#define CONCAT84(a,b) (((ulong)(a) << 32) | ((ulong)(uint)(b)))
#define CONCAT88(a,b) (((ulong)(a) << 32) | ((ulong)(b)))
#define CONCAT51(a,b) (((ulong)(a) << 40) | ((ulong)(byte)(b)))
#define CONCAT52(a,b) (((ulong)(a) << 40) | ((ulong)(ushort)(b)))
#define CONCAT54(a,b) (((ulong)(a) << 40) | ((ulong)(uint)(b)))
#define CONCAT58(a,b) (((ulong)(a) << 40) | ((ulong)(b)))
#define CONCAT61(a,b) (((ulong)(a) << 48) | ((ulong)(byte)(b)))
#define CONCAT62(a,b) (((ulong)(a) << 48) | ((ulong)(ushort)(b)))
#define CONCAT64(a,b) (((ulong)(a) << 48) | ((ulong)(uint)(b)))
#define CONCAT68(a,b) (((ulong)(a) << 48) | ((ulong)(b)))

#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <dirent.h>

/* CUPS symbols: Mach-O names vs Linux libcups */
#include <cups/cups.h>
#include <cups/ppd.h>
#include <cups/raster.h>
#include <cups/sidechannel.h>

#define _cupsBackChannelRead cupsBackChannelRead
#define _cupsFreeOptions cupsFreeOptions
#define _cupsGetOption cupsGetOption
#define _cupsParseOptions cupsParseOptions
#define _cupsRasterClose cupsRasterClose
#define _cupsRasterOpen cupsRasterOpen
#define _cupsRasterReadHeader2 cupsRasterReadHeader2
#define _cupsRasterReadPixels cupsRasterReadPixels
#define _cupsSideChannelDoRequest cupsSideChannelDoRequest
#define _cupsSideChannelSNMPGet cupsSideChannelSNMPGet
#define _cupsSideChannelSNMPWalk cupsSideChannelSNMPWalk
#define _cupsFileOpen cupsFileOpen
#define _cupsFileStdin cupsFileStdin
#define _cupsFileGetConf cupsFileGetConf
#define _ppdClose ppdClose
#define _ppdFindAttr ppdFindAttr
#define _ppdFindChoice ppdFindChoice
#define _ppdFindCustomOption ppdFindCustomOption
#define _ppdFindCustomParam ppdFindCustomParam
#define _ppdFindOption ppdFindOption
#define _ppdOpenFile ppdOpenFile

/* CF stubs (only used by non-print-core status/locale code) */
typedef void *CFTypeRef;
typedef const void *CFStringRef;
typedef const void *CFBundleRef;
typedef const void *CFArrayRef;
typedef const void *CFDictionaryRef;
typedef const void *CFURLRef;
typedef const void *CFDataRef;
typedef const void *CFPropertyListRef;
typedef const void *CFAllocatorRef;

#define _CFArrayCreate(...) (NULL)
#define _CFArrayGetCount(...) (0)
#define _CFArrayGetTypeID(...) (0)
#define _CFArrayGetValueAtIndex(...) (NULL)
#define _CFBundleCopyLocalizedString(...) (NULL)
#define _CFBundleCopyResourceURL(...) (NULL)
#define _CFBundleCreate(...) (NULL)
#define _CFBundleGetIdentifier(...) (NULL)
#define _CFBundleGetInfoDictionary(...) (NULL)
#define _CFBundleGetMainBundle(...) (NULL)
#define _CFDictionaryCreateCopy(...) (NULL)
#define _CFDictionaryGetValue(...) (NULL)
#define _CFEqual(...) (0)
#define _CFGetTypeID(...) (0)
#define _CFPreferencesSetAppValue(...)
#define _CFPropertyListCreateFromXMLData(...) (NULL)
#define _CFRelease(...)
#define _CFRetain(...)
#define _CFStringCreateMutableCopy(...) (NULL)
#define _CFStringCreateWithCString(...) (NULL)
#define _CFStringCreateWithFormat(...) (NULL)
#define _CFStringDelete(...)
#define _CFStringFind(...) (0)
#define _CFStringFindAndReplace(...) (0)
#define _CFStringGetCString(...) (0)
#define _CFStringGetLength(...) (0)
#define _CFStringGetTypeID(...) (0)
#define _CFStringHasSuffix(...) (0)
#define _CFURLCreateData(...) (NULL)
#define _CFURLCreateDataAndPropertiesFromResource(...) (NULL)
#define _CFURLCreateWithFileSystemPath(...) (NULL)
#define _CFAbsoluteTimeGetCurrent(...) (0.0)
#define _CFArrayCreateMutable(...) (NULL)
#define _CFArrayCreateCopy(...) (NULL)
#define _CFArrayAppendArray(...)
#define _CFArrayInsertValueAtIndex(...)
#define _CFArraySetValueAtIndex(...)
#define _CFDataAppendBytes(...)
#define _CFDataCreate(...) (NULL)
#define _CFDataCreateCopy(...) (NULL)
#define _CFDataCreateMutable(...) (NULL)
#define _CFDataCreateWithBytesNoCopy(...) (NULL)
#define _CFDataGetBytePtr(...) (NULL)
#define _CFDataGetLength(...) (0)
#define _CFDictionaryAddValue(...)
#define _CFDictionaryCreate(...) (NULL)
#define _CFDictionaryCreateMutable(...) (NULL)
#define _CFDictionaryCreateMutableCopy(...) (NULL)
#define _CFDictionaryGetCount(...) (0)
#define _CFDictionaryGetKeysAndValues(...)
#define _CFDictionaryGetValueIfPresent(...) (0)
#define _CFDictionarySetValue(...)
#define _CFPropertyListCreateData(...) (NULL)
#define _CFPropertyListCreateWithData(...) (NULL)
#define _CFStringCreateCopy(...) (NULL)
#define _CFStringGetIntValue(...) (0)
#define _CFURLCopyPath(...) (NULL)
#define _CFURLCreateCopyDeletingLastPathComponent(...) (NULL)
#define _CFURLCreateFromFileSystemRepresentation(...) (NULL)
#define _CFURLGetFileSystemRepresentation(...) (0)
#define _CFURLWriteDataAndPropertiesToResource(...) (0)
#define _FSOpenFork(...) (0)
#define _FSCloseFork(...) (0)
#define _FSReadFork(...) (0)
#define _FSWriteFork(...) (0)
#define _FSPathMakeRef(...) (0)
#define _kCFAllocatorDefault ((void *)0)
#define _kCFPreferencesCurrentApplication ((void *)0)
#define _kCFTypeArrayCallBacks ((void *)0)
#define _kCFTypeDictionaryKeyCallBacks ((void *)0)
#define _kCFTypeDictionaryValueCallBacks ((void *)0)
#define _kCFAllocatorNull ((void *)0)
#define _kCFAllocatorDefault ((void *)0)
#define ___CFConstantStringClassReference ((void *)0)

/* Mach-O stdout/stderr pointer indirection */
#define PTR____stdoutp_100012038 ((void *)&stdout)
#define PTR____stderrp_100012030 ((void *)&stderr)
#define PTR____stack_chk_guard_100012028 ((void *)&__stack_chk_guard)
#define PTR____stack_chk_guard_10000fa80 (&__stack_chk_guard)

#endif
