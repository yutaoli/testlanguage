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
* 功能说明：solaris配置
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
#ifndef __JSTP_SOLARIS_CONFIG_H__
#define __JSTP_SOLARIS_CONFIG_H__


#ifndef _REENTRANT
#define _REENTRANT
#endif

#define _FILE_OFFSET_BITS  64   /* must be before <sys/types.h> */

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
#include <time.h>
#include <sys/statvfs.h>        /* statvfs() */

#include <sys/filio.h>          /* FIONBIO */
#include <sys/uio.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sched.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>        /* TCP_NODELAY */
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/un.h>

#include <sys/systeminfo.h>
#include <limits.h>             /* IOV_MAX */
#include <inttypes.h>
#include <crypt.h>

#define JSTP_ALIGNMENT  _MAX_ALIGNMENT

#ifdef JSTP_HAVE_AUTO_CONFIG_H
#include <jstp_auto_config.h>
#endif


#if (JSTP_HAVE_POSIX_SEM)
#include <semaphore.h>
#endif


#if (JSTP_HAVE_POLL)
#include <poll.h>
#endif


#if (JSTP_HAVE_DEVPOLL)
#include <sys/ioctl.h>
#include <sys/devpoll.h>
#endif


#if (JSTP_HAVE_EVENTPORT)
#include <port.h>
#endif


#if (JSTP_HAVE_SENDFILE)
#include <sys/sendfile.h>
#endif


#define JSTP_LISTEN_BACKLOG           511


#ifndef JSTP_HAVE_INHERITED_NONBLOCK
#define JSTP_HAVE_INHERITED_NONBLOCK  1
#endif


#ifndef JSTP_HAVE_SO_SNDLOWAT
/* setsockopt(SO_SNDLOWAT) returns ENOPROTOOPT */
#define JSTP_HAVE_SO_SNDLOWAT         0
#endif


#define JSTP_HAVE_OS_SPECIFIC_INIT    1
#define jstp_debug_init()


extern char **environ;


#endif /* __JSTP_SOLARIS_CONFIG_H__ */
