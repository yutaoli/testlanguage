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
* 功能说明：linux配置
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
#ifndef __JSTP_LINUX_CONFIG_H__
#define __JSTP_LINUX_CONFIG_H__

#ifndef _GNU_SOURCE
#define _GNU_SOURCE             /* pread(), pwrite(), gethostname() */
#endif

#define _FILE_OFFSET_BITS  64

#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>             /* offsetof() */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <glob.h>
#include <sys/vfs.h>            /* statfs() */

#include <sys/uio.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sched.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>        /* TCP_NODELAY, TCP_CORK */
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/un.h>

#include <time.h>               /* tzset() */
#include <malloc.h>             /* memalign() */
#include <limits.h>             /* IOV_MAX */
#include <sys/ioctl.h>
#include <crypt.h>
#include <sys/utsname.h>        /* uname() */
#include <dlfcn.h>

#ifdef JSTP_HAVE_AUTO_CONFIG_H
#include <jstp_auto_config.h>
#endif


#if (JSTP_HAVE_POSIX_SEM)
#include <semaphore.h>
#endif


#if (JSTP_HAVE_SYS_PRCTL_H)
#include <sys/prctl.h>
#endif


#if (JSTP_HAVE_SENDFILE64)
#include <sys/sendfile.h>
#else
extern ssize_t sendfile(int s, int fd, int32_t *offset, size_t size);
#define JSTP_SENDFILE_LIMIT  0x80000000
#endif


#if (JSTP_HAVE_POLL)
#include <poll.h>
#endif


#if (JSTP_HAVE_EPOLL)
#include <sys/epoll.h>
#endif


#if (JSTP_HAVE_SYS_EVENTFD_H)
#include <sys/eventfd.h>
#endif
#include <sys/syscall.h>
#if (JSTP_HAVE_FILE_AIO)
#include <linux/aio_abi.h>
typedef struct iocb  jstp_aiocb_t;
#endif


#define JSTP_LISTEN_BACKLOG        511


#ifndef JSTP_HAVE_SO_SNDLOWAT
/* setsockopt(SO_SNDLOWAT) returns ENOPROTOOPT */
#define JSTP_HAVE_SO_SNDLOWAT         0
#endif


#ifndef JSTP_HAVE_INHERITED_NONBLOCK
#define JSTP_HAVE_INHERITED_NONBLOCK  0
#endif


#define JSTP_HAVE_OS_SPECIFIC_INIT    1
#define jstp_debug_init()


extern char **environ;


#endif /* _JSTP_LINUX_CONFIG_H_INCLUDED_ */
