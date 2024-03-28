/*****************************************************************************
*
*                            雨燕极速交易平台(JSTP) V1.0                           
*
*           Copyright (C) 2009-2014, SHENZHEN KINGDOM Co., Ltd.
*
*                             All Rights Reserved.
*
* ===========================================================================
*
* 文 件 名：jstpx.h
* 模块名称：雨燕极速交易
* 功能说明：WIN32配置
* 作    者：cails
* 创建日期：2014-10-24
* 版 本 号：1.0
* 修改历史：
*
* 修改日期       姓名            内容
* ---------------------------------------------------------------------------
* 2014-10-24     cails           初始版本
*
******************************************************************************/
#ifndef __JSTP_WIN32_CONFIG_H__
#define __JSTP_WIN32_CONFIG_H__

#ifndef STRICT
#define STRICT
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

/* enable getenv() and gmtime() in msvc8 */
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif

/*
 * we need to include <windows.h> explicitly before <winsock2.h> because
 * the warning 4201 is enabled in <windows.h>
 */
#include <windows.h>

#ifdef _MSC_VER
#pragma warning(disable:4201)
#endif

#ifndef FD_SETSIZE
#define FD_SETSIZE      1024
#endif /* FD_SETSIZE */

#ifndef JSTP_NOT_INCLUDE_WIN32_NETWORK
#include <winsock2.h>
#include <ws2tcpip.h>  /* ipv6 */
#include <mswsock.h>
#include <shellapi.h>
#include <stddef.h>    /* offsetof() */
#endif

#ifdef __MINGW64_VERSION_MAJOR

/* GCC MinGW-w64 supports _FILE_OFFSET_BITS */
#define _FILE_OFFSET_BITS 64

#elif defined __GNUC__

/* GCC MinGW's stdio.h includes sys/types.h */
#define _OFF_T_

#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#ifdef __MINGW64_VERSION_MAJOR
#include <stdint.h>
#endif
#include <ctype.h>
#include <locale.h>
#include <direct.h>

#ifdef __WATCOMC__
#define _TIME_T_DEFINED
typedef long  time_t;
/* OpenWatcom defines time_t as "unsigned long" */
#endif

#include <time.h>      /* localtime(), strftime() */


#ifdef _MSC_VER

/* the end of the precompiled headers */
#pragma hdrstop

#pragma warning(default:4201)

/* disable some "-W4" level warnings */

/* 'type cast': from function pointer to data pointer */
#pragma warning(disable:4054)

/* 'type cast': from data pointer to function pointer */
#pragma warning(disable:4055)

/* unreferenced formal parameter */
#pragma warning(disable:4100)

/* FD_SET() and FD_CLR(): conditional expression is constant */
#pragma warning(disable:4127)

/* array is too small to include a terminating null character */
#pragma warning(disable:4295)

#endif


#ifdef __WATCOMC__

/* symbol 'jstp_rbtree_min' has been defined, but not referenced */
#pragma disable_message(202)

#endif


#ifdef __BORLANDC__

/* the end of the precompiled headers */
#pragma hdrstop

/* functions containing (for|while|some if) are not expanded inline */
#pragma warn -8027

/* unreferenced formal parameter */
#pragma warn -8057

#endif

#ifdef JSTP_HAVE_AUTO_CONFIG_H
#include <jstp_auto_config.h>
#endif

#define jstp_inline          __inline
#define jstp_cdecl           __cdecl


#ifdef _MSC_VER
typedef unsigned __int32    uint32_t;
typedef __int32             int32_t;
typedef unsigned __int16    uint16_t;
#define jstp_libc_cdecl      __cdecl

#elif defined __BORLANDC__
typedef unsigned __int32    uint32_t;
typedef __int32             int32_t;
typedef unsigned __int16    uint16_t;
#define jstp_libc_cdecl      __cdecl

#else /* __WATCOMC__ */
typedef unsigned int        uint32_t;
typedef int                 int32_t;
typedef unsigned short int  uint16_t;
#define jstp_libc_cdecl

#endif

typedef __int64             int64_t;
typedef unsigned __int64    uint64_t;

//#if !defined(__WATCOMC__) && !defined(__MINGW64_VERSION_MAJOR)
//typedef int                 intptr_t;
//typedef u_int               uintptr_t;
//#endif


//#ifndef __MINGW64_VERSION_MAJOR
//#ifndef _OFF_T_DEFINED
///* Windows defines off_t as long, which is 32-bit */
//typedef long				_off_t;                    /* file offset value */
//typedef __int64     off_t;
//#define _OFF_T_DEFINED
//#endif
//#endif


#ifdef __WATCOMC__

/* off_t is redefined by sys/types.h used by zlib.h */
#define __TYPES_H_INCLUDED
typedef int                 dev_t;
typedef unsigned int        ino_t;

#elif __BORLANDC__

/* off_t is redefined by sys/types.h used by zlib.h */
#define __TYPES_H

typedef int                 dev_t;
typedef unsigned int        ino_t;

#endif


#ifndef __MINGW64_VERSION_MAJOR
	#ifdef _MSC_VER
		#if defined (_WIN64) || defined (WIN64)
			typedef SSIZE_T ssize_t;
		#else
			typedef int ssize_t;
		#endif
	#endif
#endif


typedef uint32_t            in_addr_t;
typedef uint16_t			in_port_t;
typedef int                 sig_atomic_t;


#ifdef _WIN64

#define JSTP_PTR_SIZE            8
#define JSTP_SIZE_T_LEN          (sizeof("-9223372036854775808") - 1)
#define JSTP_MAX_SIZE_T_VALUE    9223372036854775807
#define JSTP_TIME_T_LEN          (sizeof("-9223372036854775808") - 1)
#define JSTP_TIME_T_SIZE         8
#define JSTP_MAX_TIME_T_VALUE    9223372036854775807

#else

#define JSTP_PTR_SIZE            4
#define JSTP_SIZE_T_LEN          (sizeof("-2147483648") - 1)
#define JSTP_MAX_SIZE_T_VALUE    2147483647
#define JSTP_TIME_T_LEN          (sizeof("-2147483648") - 1)
#define JSTP_TIME_T_SIZE         4
#define JSTP_MAX_TIME_T_VALUE    2147483647

#endif


#define JSTP_OFF_T_LEN           (sizeof("-9223372036854775807") - 1)
#define JSTP_MAX_OFF_T_VALUE     9223372036854775807
#define JSTP_SIG_ATOMIC_T_SIZE   4


#define JSTP_HAVE_LITTLE_ENDIAN  1
#define JSTP_HAVE_NONALIGNED     1


#define JSTP_WIN_NT        200000


#define JSTP_LISTEN_BACKLOG           511


#ifndef JSTP_HAVE_INHERITED_NONBLOCK
#define JSTP_HAVE_INHERITED_NONBLOCK  1
#endif

#ifndef JSTP_HAVE_CASELESS_FILESYSTEM
#define JSTP_HAVE_CASELESS_FILESYSTEM  1
#endif

#ifndef JSTP_HAVE_WIN32_TRANSMITPACKETS
#define JSTP_HAVE_WIN32_TRANSMITPACKETS  1
#define JSTP_HAVE_WIN32_TRANSMITFILE     0
#endif

#ifndef JSTP_HAVE_WIN32_TRANSMITFILE
#define JSTP_HAVE_WIN32_TRANSMITFILE  1
#endif

#if (JSTP_HAVE_WIN32_TRANSMITPACKETS) || (JSTP_HAVE_WIN32_TRANSMITFILE)
#define JSTP_HAVE_SENDFILE  1
#endif

#ifndef JSTP_HAVE_SO_SNDLOWAT
/* setsockopt(SO_SNDLOWAT) returns error WSAENOPROTOOPT */
#define JSTP_HAVE_SO_SNDLOWAT         0
#endif

#define JSTP_HAVE_GETADDRINFO         1

#define jstp_random					rand
#define jstp_debug_init()

#define JSTP_SECURITY_SET												\
	SECURITY_DESCRIPTOR sd;												\
	SECURITY_ATTRIBUTES sa;												\
	InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);	\
	SetSecurityDescriptorDacl(&sd, TRUE, NULL, FALSE);					\
	sa.nLength = sizeof(sa);											\
	sa.bInheritHandle = TRUE;											\
	sa.lpSecurityDescriptor = &sd;

#define JSTP_SECURITY_ATTRIBUTES &sa

#endif /* __JSTP_WIN32_CONFIG_H__ */
