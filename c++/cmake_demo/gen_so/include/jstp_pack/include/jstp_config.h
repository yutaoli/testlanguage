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
* 功能说明：编译配置
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
#ifndef __JSTP_CONFIG_H__
#define __JSTP_CONFIG_H__

#define JSTP_LOG_OFF	0
#define JSTP_LOG_FATAL	1
#define JSTP_LOG_ERR	2
#define JSTP_LOG_WARN	3
#define JSTP_LOG_INFO	4
#define JSTP_LOG_DEBUG	5
#define JSTP_LOG_TRACE	6

#if defined(_WIN32)
#define JSTP_WIN32 1
#else
#define JSTP_LINUX 1
#endif

#if defined __DragonFly__ && !defined __FreeBSD__
#define __FreeBSD__ 4
#define __FreeBSD_version 480101
#endif

#if (JSTP_FREEBSD)
#include <jstp_freebsd_config.h>

#elif (JSTP_LINUX) //NOLINT
#include <jstp_linux_config.h>

#elif (JSTP_SOLARIS) //NOLINT
#include <jstp_solaris_config.h>

#elif (JSTP_DARWIN) //NOLINT
#include <jstp_darwin_config.h>

#elif (JSTP_WIN32) //NOLINT
#include <jstp_win32_config.h>

#else /* POSIX */
#include <jstp_posix_config.h>

#endif

#ifndef JSTP_HAVE_SO_SNDLOWAT
#define JSTP_HAVE_SO_SNDLOWAT 1
#endif

#if !(JSTP_WIN32)

#define jstp_signal_helper(n) SIG##n
#define jstp_signal_value(n) jstp_signal_helper(n)

#define jstp_random random

/* TODO: #ifndef */
#define JSTP_SHUTDOWN_SIGNAL QUIT
#define JSTP_TERMINATE_SIGNAL TERM
#define JSTP_NOACCEPT_SIGNAL WINCH
#define JSTP_RECONFIGURE_SIGNAL HUP

#if (JSTP_LINUXTHREADS)
#define JSTP_REOPEN_SIGNAL INFO
#define JSTP_CHANGEBIN_SIGNAL XCPU
#else
#define JSTP_REOPEN_SIGNAL USR1
#define JSTP_CHANGEBIN_SIGNAL USR2
#endif

#define jstp_cdecl
#define jstp_libc_cdecl

#endif

#if defined(_WIN32)
#define jstp_stdcall __stdcall
#else
#define jstp_stdcall
#endif

typedef int jstp_int_t;
typedef unsigned int jstp_uint_t;
typedef intptr_t jstp_flag_t;

typedef unsigned char jstp_byte_t;
typedef signed char jstp_int8_t;
typedef unsigned char jstp_uint8_t;
typedef signed short jstp_int16_t;
typedef unsigned short jstp_uint16_t;
typedef signed int jstp_int32_t;
typedef unsigned int jstp_uint32_t;
typedef int64_t jstp_int64_t;
typedef uint64_t jstp_uint64_t;
typedef float jstp_real32_t;
typedef double jstp_real64_t;

typedef size_t jstp_oid_t;
typedef void *jstp_handle_api_t;
typedef void *jstp_handle_resultset_t;

typedef const void *jstp_handle_database_t;
typedef const void *jstp_handle_table_t;

typedef jstp_handle_api_t *p_jstp_handle_api_t;


#define JSTP_CACHE_LINE_LENGTH (64)
typedef char jstp_cache_line_pad_t[JSTP_CACHE_LINE_LENGTH];

#define JSTP_MAX_OFFS (jstp_uint32_t) - 1
#define JSTP_MAX_OID (jstp_oid_t) - 1
#define JSTP_UINT32_MAX (jstp_uint32_t) - 1
#define JSTP_UINT16_MAX (jstp_uint16_t) - 1

#define JSTP_INT32_LEN (sizeof("-2147483648") - 1)
#define JSTP_INT64_LEN (sizeof("-9223372036854775808") - 1)

#if (JSTP_PTR_SIZE == 4)
#define JSTP_INT_T_LEN JSTP_INT32_LEN
#define JSTP_MAX_INT_T_VALUE 2147483647
#else
#define JSTP_INT_T_LEN JSTP_INT64_LEN
#define JSTP_MAX_INT_T_VALUE 9223372036854775807
#endif

#define JSTP_INT32_T_LEN JSTP_INT32_LEN
#define JSTP_MAX_INT32_T_VALUE 2147483647

#ifndef JSTP_ALIGNMENT
#define JSTP_ALIGNMENT sizeof(unsigned long) /* platform word */
#endif

#define jstp_align_down(d, a) ((d) & (~(a - 1)))
#define jstp_align(d, a) (((d) + (a - 1)) & ~(a - 1))
#define jstp_align_ptr(p, a) \
    (u_char *)(((uintptr_t)(p) + ((uintptr_t)a - 1)) & ~((uintptr_t)a - 1))

#define jstp_bit_set(a, b) ((a) |= (1 << (b)))
#define jstp_bit_clear(a, b) ((a) &= ~(1 << (b)))
#define jstp_bit_flip(a, b) ((a) ^= (1 << (b)))
#define jstp_bit_check(a, b) ((a) & (1 << (b)))

#define jstp_abort abort

/* TODO: platform specific: array[JSTP_INVALID_ARRAY_INDEX] must cause SIGSEGV */
#define JSTP_INVALID_ARRAY_INDEX 0x80000000

/* TODO: auto_conf: jstp_inline   inline __inline __inline__ */
#ifndef jstp_inline
#define jstp_inline inline
#endif

//#ifndef INADDR_NONE /* Solaris */
//#define INADDR_NONE ((unsigned int)-1)
//#endif

#ifdef MAXHOSTNAMELEN
#define JSTP_MAXHOSTNAMELEN MAXHOSTNAMELEN
#else
#define JSTP_MAXHOSTNAMELEN 256
#endif

#if ((__GNU__ == 2) && (__GNUC_MINOR__ < 8))
#define JSTP_MAX_UINT32_VALUE (uint32_t)0xffffffffLL
#else
#define JSTP_MAX_UINT32_VALUE (uint32_t)0xffffffff
#endif

#define JSTP_MAX_INT32_VALUE (uint32_t)0x7fffffff

#define JSTP_OK 0
#define JSTP_ERROR -1
#define JSTP_AGAIN -2
#define JSTP_BUSY -3
#define JSTP_DONE -4
#define JSTP_DECLINED -5
#define JSTP_ABORT -6
#define JSTP_NONE -7


#if (JSTP_WIN32)
typedef DWORD jstp_err_t;
#define jstp_errno GetLastError()
#define JSTP_BIGINT __int64
#define JSTP_INT8_FORMAT "%I64d"
#define JSTP_PRI64_FORMAT "I64d"
#define JSTP_UINT8_FORMAT "%I64u"
#else
typedef jstp_int_t jstp_err_t;
#define jstp_errno errno
#define JSTP_BIGINT long long
#define JSTP_INT8_FORMAT "%ld"
#define JSTP_PRI64_FORMAT "ld"
#define JSTP_UINT8_FORMAT "%lu"
#endif

#define JSTP_IID const char *

#ifndef BIG_ENDIAN
#define BIG_ENDIAN 4321 /* most-significant jstp_byte_t first (IBM, net) */
#endif
#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN 1234
#endif

#ifndef BYTE_ORDER
#if defined(__sparc__) || defined(__m68k__)
#define BYTE_ORDER BIG_ENDIAN
#else
#define BYTE_ORDER LITTLE_ENDIAN
#endif
#endif

#ifdef _MSC_VER
#if defined(_M_IX86) || defined(_M_X64)
#define JSTP_LITTLE_ENDIAN 1
#endif
#else
#include <sys/param.h> // __BYTE_ORDER
#include <sys/prctl.h> 
#if defined(__BYTE_ORDER) && __BYTE_ORDER == __LITTLE_ENDIAN
#define JSTP_LITTLE_ENDIAN 1
#endif
#endif

// detection for 64 bit
#if defined(__x86_64__) || defined(_M_X64) || defined(_WIN64)
#define JSTP_X64 1
#else
#define JSTP_X64 0
#endif

#if defined(__aarch64__)
#define JSTP_A64 1
#else
#define JSTP_A64 0
#endif

#if defined(__powerpc64__)
#define JSTP_PPC64 1
#else
#define JSTP_PPC64 0
#endif

#ifdef _WIN32
typedef HANDLE descriptor_t;
typedef HANDLE share_memory_handle_t;
#else
typedef jstp_int_t descriptor_t;
typedef jstp_int_t share_memory_handle_t;
#define ACCESS_PERMISSION_MASK 0666
#endif

#ifndef JSTP_ATTRIBUTE_ALWAYS_INLINE
#if defined(__GNUC__) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 1))
// For functions we want to force inline.
// Introduced in gcc 3.1.
#define JSTP_ATTRIBUTE_ALWAYS_INLINE __attribute__((always_inline))
#else
// Other compilers will have to figure it out for themselves.
#define JSTP_ATTRIBUTE_ALWAYS_INLINE
#endif
#endif

#ifndef JSTP_ATTRIBUTE_DEPRECATED
#ifdef __GNUC__
// If the method/variable/type is used anywhere, produce a warning.
#define JSTP_ATTRIBUTE_DEPRECATED __attribute__((deprecated))
#else
#define JSTP_ATTRIBUTE_DEPRECATED
#endif
#endif

#if !defined(_fastcall) && (!defined(_WIN32) || defined(__IBMCPP__) || defined(__MINGW32__))
#define _fastcall
#endif

#define itemsof(array) (sizeof(array) / sizeof *(array))

#if defined(__GNUC__)
#define jstp_likely(x) __builtin_expect((x), 1)
#define jstp_unlikely(x) __builtin_expect((x), 0)
#else
#define jstp_likely(x) (x)
#define jstp_unlikely(x) (x)
#endif

#if defined(_WIN32)

#define stricoll(x, y) _stricoll(x, y)
#define strnicoll(x, y, n) _strnicoll(x, y, n)
#define strncoll(x, y, n) _strncoll(x, y, n)

#else

#if defined(__GNUC__) && !defined(__APPLE__)

#define stricmp(x, y) strcasecmp(x, y)
#define strnicmp(x, y, n) strncasecmp(x, y, n)
#define wcsicmp(x, y) wcscasecmp(x, y)
#define wcsnicmp(x, y, n) wcsncasecmp(x, y, n)

#else

#ifdef __BORLANDC__
#define wcsicmp(x, y) _wcsicmp(x, y)
#define wcsnicmp(x, y, n) _wcsnicmp(x, y, n)
#endif

#ifndef NO_STRICMP
#define NO_STRICMP 1
#endif

#ifndef NO_STRNICMP
#define NO_STRNICMP 1
#endif

#ifndef NO_WCSICMP
#define NO_WCSICMP 1
#endif

#ifndef NO_WCSNICMP
#define NO_WCSNICMP 1
#endif

#endif

#ifndef NO_STRICOLL
#define NO_STRICOLL 1
#endif

#ifndef NO_STRNCOLL
#define NO_STRNCOLL 1
#endif

#ifndef NO_STRNICOLL
#define NO_STRNICOLL 1
#endif

#endif

#define JSTP_MEMCMP(dest, dest_sz, len) memcmp(dest, dest_sz, (len))
#define JSTP_ZEROMEM(dest, len) memset((dest), 0, (len))
#define JSTP_STRCMP(s1, s2) strcmp(s1, s2)
#define JSTP_STRSTR(dest, dest_sz) strstr(dest, dest_sz)
#define JSTP_STRCHR(dest, dest_sz) strchr(dest, dest_sz)

#if defined(_MSC_VER) && (_MSC_VER >= 1400)
#pragma warning(disable : 4351)
#pragma warning(disable : 4290)
#define JSTP_STRCAT_S(dest, dest_sz, src) strcat_s(dest, dest_sz, src)
#define JSTP_STRCPY_S(dest, dest_sz, src) strcpy_s(dest, dest_sz, src)
#define JSTP_STRNCPY_S(dest, dest_sz, src, count) strncpy_s(dest, dest_sz, src, count)

#define JSTP_SPRINTF_S(dest, dest_sz, format, ...) sprintf_s(dest, dest_sz, format, __VA_ARGS__)
#define JSTP_SNPRINTF_S(dest, dest_sz, count, format, ...) _snprintf_s(dest, dest_sz, count, format, __VA_ARGS__)
#define JSTP_VSNPRINTF_S(dest, dest_sz, count, format, argptr) vsnprintf_s(dest, dest_sz, count, format, argptr)

#define JSTP_STRNCMP(s1, s2, count) strncmp(s1, s2, count)
#define JSTP_STRICMP(s1, s2) _stricmp(s1, s2)
#define JSTP_STRNICMP(s1, s2, count) _strnicmp(s1, s2, count)

#else
#define JSTP_STRCAT_S(dest, dest_sz, src) strcat(dest, src) //NOLINT
#define JSTP_STRCPY_S(dest, dest_sz, src) strcpy(dest, src) //NOLINT
#define JSTP_STRNCPY_S(dest, dest_sz, src, count) strncpy(dest, src, count)

#if defined(_MSC_VER)
#define JSTP_SPRINTF_S vc6_sprintf::out
#define JSTP_SNPRINTF_S vc6_snprintf::out
#else
#define JSTP_SPRINTF_S(dest, dest_sz, format, ...) sprintf(dest, format, ##__VA_ARGS__) //NOLINT
#define JSTP_SNPRINTF_S(dest, dest_sz, count, format, ...) snprintf(dest, (count) + 1, format, ##__VA_ARGS__)
#endif

#define JSTP_VSNPRINTF_S(dest, dest_sz, count, format, argptr) vsnprintf(dest, count, format, argptr)

#if defined(_MSC_VER)
#define JSTP_STRNCMP(s1, s2, count) strncmp(s1, s2, count)
#define JSTP_STRICMP(s1, s2) stricmp(s1, s2)
#define JSTP_STRNICMP(s1, s2, count) strnicmp(s1, s2, count)
#else
#define JSTP_STRNCMP(s1, s2, count) strncmp(s1, s2, count)
#define JSTP_STRICMP(s1, s2) strcasecmp(s1, s2)
#define JSTP_STRNICMP(s1, s2, count) strncasecmp(s1, s2, count)
#endif

#endif

#if defined(_MSC_VER)
#define JSTP_STRTOLL(str) _atoi64(str)
#else
#define JSTP_STRTOLL(str) strtoll(str, NULL, 10)
#endif

typedef void (*jstp_thread_handler_pt)(void *param, void *pResverBuf, int nResverBufSize);

#define jstp_abs(value) (((value) >= 0) ? (value) : -(value))
#define jstp_max(val1, val2) ((val1 < val2) ? (val2) : (val1))
#define jstp_min(val1, val2) ((val1 > val2) ? (val2) : (val1))

#define STR_NULL " "
#define CHR_NULL ' '
#define DOUBLE_NULL 0.00
#define INT_NULL 0
#define ERR_LEVEL 1

#define FLOATCMP 0.00001
#define DOUBLECMP 0.000000001
/*
#define ABS(x) ((x) >= 0 ? (x) : -(x))
#define FEQ(X, Y) (fabs((X) - (Y)) < ((X) > 10 ? FLOATCMP : DOUBLECMP) ? 1 : 0) // 等于
#define FBG(X, Y) ((X) - (Y) > ((X) > 10 ? FLOATCMP : DOUBLECMP) ? 1 : 0)       // 大于
#define FLS(X, Y) FBG(Y, X)                                                     // 小于
*/
#endif /* __JSTP_CONFIG_H__ */
