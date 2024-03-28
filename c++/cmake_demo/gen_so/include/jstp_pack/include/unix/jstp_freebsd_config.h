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
* 功能说明：freebsd配置
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
#ifndef __JSTP_FREEBSD_CONFIG_H__
#define __JSTP_FREEBSD_CONFIG_H__


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
#include <sys/param.h>          /* ALIGN() */
#include <sys/mount.h>          /* statfs() */

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
#include <netinet/tcp.h>        /* TCP_NODELAY, TCP_NOPUSH */
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/un.h>

#include <libutil.h>            /* setproctitle() before 4.1 */
#include <osreldate.h>
#include <sys/sysctl.h>


#if __FreeBSD_version < 400017

/*
 * FreeBSD 3.x has no CMSG_SPACE() and CMSG_LEN() and has the broken CMSG_DATA()
 */

#undef  CMSG_SPACE
#define CMSG_SPACE(l)       (ALIGN(sizeof(struct cmsghdr)) + ALIGN(l))

#undef  CMSG_LEN
#define CMSG_LEN(l)         (ALIGN(sizeof(struct cmsghdr)) + (l))

#undef  CMSG_DATA
#define CMSG_DATA(cmsg)     ((u_char *)(cmsg) + ALIGN(sizeof(struct cmsghdr)))

#endif


#ifdef JSTP_HAVE_AUTO_CONFIG_H
#include <jstp_auto_config.h>
#endif


#if (JSTP_HAVE_POSIX_SEM)
#include <semaphore.h>
#endif


#if (JSTP_HAVE_POLL)
#include <poll.h>
#endif


#if (JSTP_HAVE_KQUEUE)
#include <sys/event.h>
#endif


#if (JSTP_HAVE_FILE_AIO || JSTP_HAVE_AIO)
#include <aio.h>
typedef struct aiocb  jstp_aiocb_t;
#endif


#define JSTP_LISTEN_BACKLOG        -1


#ifdef __DragonFly__
#define JSTP_KEEPALIVE_FACTOR      1000
#endif


#if (__FreeBSD_version < 430000 || __FreeBSD_version < 500012)

pid_t rfork_thread(int flags, void *stack, int (*func)(void *arg), void *arg);

#endif

#ifndef IOV_MAX
#define IOV_MAX   1024
#endif


#ifndef JSTP_HAVE_INHERITED_NONBLOCK
#define JSTP_HAVE_INHERITED_NONBLOCK  1
#endif


#define JSTP_HAVE_OS_SPECIFIC_INIT    1
#define JSTP_HAVE_DEBUG_MALLOC        1


extern char **environ;
extern char  *malloc_options;


#endif /* __JSTP_FREEBSD_CONFIG_H__ */
