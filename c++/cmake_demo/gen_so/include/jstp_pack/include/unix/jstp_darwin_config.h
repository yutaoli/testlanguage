/*****************************************************************************
*
*                            ���༫�ٽ���ƽ̨(JSTP) V1.0                           
*
*           Copyright (C) 2009-2014, SHENZHEN KINGDOM Co., Ltd.
*
*                             All Rights Reserved.
*
* ===========================================================================
*
* �� �� ����jstpx.h
* ģ�����ƣ����༫�ٽ���
* ����˵����darwin����
* ��    �ߣ�cails
* �������ڣ�2014-10-24
* �� �� �ţ�1.0
* �޸���ʷ��
*
* �޸�����       ����            ����
* ---------------------------------------------------------------------------
* 2014-10-24     cails           ��ʼ�汾
*
******************************************************************************/
#ifndef __JSTP_DARWIN_CONFIG_H__
#define __JSTP_DARWIN_CONFIG_H__


#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <inttypes.h>
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
#include <sys/mount.h>          /* statfs() */

#include <sys/filio.h>          /* FIONBIO */
#include <sys/ioctl.h>
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

#include <sys/sysctl.h>
#include <xlocale.h>


#ifndef IOV_MAX
#define IOV_MAX   64
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


#define JSTP_LISTEN_BACKLOG  -1


#ifndef JSTP_HAVE_INHERITED_NONBLOCK
#define JSTP_HAVE_INHERITED_NONBLOCK  1
#endif


#ifndef JSTP_HAVE_CASELESS_FILESYSTEM
#define JSTP_HAVE_CASELESS_FILESYSTEM  1
#endif


#define JSTP_HAVE_OS_SPECIFIC_INIT    1
#define JSTP_HAVE_DEBUG_MALLOC        1


extern char **environ;


#endif /* __JSTP_DARWIN_CONFIG_H__ */
