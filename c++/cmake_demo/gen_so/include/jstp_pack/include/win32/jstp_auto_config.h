#define JSTP_CONFIGURE " --with-cc=cl --builddir=objs --prefix= --conf-path=conf/jstpx.conf --pid-path=logs/jstpx.pid --http-log-path=logs/access.log --error-log-path=logs/error.log --sbin-path=jstpx.exe --http-client-body-temp-path=temp/client_body_temp --http-proxy-temp-path=temp/proxy_temp --http-fastcgi-temp-path=temp/fastcgi_temp --http-scgi-temp-path=temp/scgi_temp --http-uwsgi-temp-path=temp/uwsgi_temp --with-cc-opt='-D FD_SETSIZE=4096' --with-pcre=src/pcre --with-zlib=src/zlib --with-openssl=src/openssl --with-select_module --with-http_ssl_module"

#ifndef JSTP_HAVE_AIO
#define JSTP_HAVE_AIO  1
#endif


#ifndef JSTP_HAVE_IOCP
#define JSTP_HAVE_IOCP  1
#endif


#ifndef JSTP_HAVE_NONALIGNED
#define JSTP_HAVE_NONALIGNED  1
#endif


#ifndef JSTP_CPU_CACHE_LINE
#define JSTP_CPU_CACHE_LINE  32
#endif


#ifndef JSTP_HAVE_SELECT
#define JSTP_HAVE_SELECT  1
#endif


#ifndef JSTP_SWIFT_CACHE
#define JSTP_SWIFT_CACHE  0
#endif


#ifndef JSTP_SWIFT_GZIP
#define JSTP_SWIFT_GZIP  0
#endif


#ifndef JSTP_SWIFT_SSI
#define JSTP_SWIFT_SSI  0
#endif


#ifndef JSTP_CRYPT
#define JSTP_CRYPT  1
#endif


#ifndef JSTP_SWIFT_X_FORWARDED_FOR
#define JSTP_SWIFT_X_FORWARDED_FOR  1
#endif


#ifndef JSTP_SWIFT_SSL
#define JSTP_SWIFT_SSL  0
#endif


#ifndef JSTP_PCRE
#define JSTP_PCRE  0
#endif


#ifndef PCRE_STATIC
#define PCRE_STATIC  0
#endif


#ifndef JSTP_OPENSSL
#define JSTP_OPENSSL  0
#endif


#ifndef JSTP_SSL
#define JSTP_SSL  0
#endif


#ifndef JSTP_SWIFT_SPDY
#define JSTP_SWIFT_SPDY  0
#endif


#ifndef JSTP_HAVE_OPENSSL_MD5_H
#define JSTP_HAVE_OPENSSL_MD5_H  0
#endif


#ifndef JSTP_OPENSSL_MD5
#define JSTP_OPENSSL_MD5  0
#endif


#ifndef JSTP_HAVE_MD5
#define JSTP_HAVE_MD5  0
#endif


#ifndef JSTP_HAVE_OPENSSL_SHA1_H
#define JSTP_HAVE_OPENSSL_SHA1_H  0
#endif


#ifndef JSTP_HAVE_SHA1
#define JSTP_HAVE_SHA1  0
#endif


#ifndef JSTP_ZLIB
#define JSTP_ZLIB  0
#endif


#ifndef JSTP_CONF_PREFIX
#define JSTP_CONF_PREFIX  "conf/"
#endif


#ifndef JSTP_SBIN_PATH
#define JSTP_SBIN_PATH  "jstpx.exe"
#endif


#ifndef JSTP_CONF_PATH
#define JSTP_CONF_PATH  "conf/jstpx.conf"
#endif


#ifndef JSTP_PID_PATH
#define JSTP_PID_PATH  "logs/jstpx.pid"
#endif


#ifndef JSTP_LOCK_PATH
#define JSTP_LOCK_PATH  "logs/jstpx.lock"
#endif


#ifndef JSTP_ERROR_LOG_PATH
#define JSTP_ERROR_LOG_PATH  "logs/error.log"
#endif


#ifndef JSTP_SWIFT_LOG_PATH
#define JSTP_SWIFT_LOG_PATH  "logs/biz.log"
#endif


#ifndef JSTP_SUPPRESS_WARN
#define JSTP_SUPPRESS_WARN  1
#endif


#ifndef JSTP_SMP
#define JSTP_SMP  1
#endif


#ifndef JSTP_USER
#define JSTP_USER  ""
#endif


#ifndef JSTP_GROUP
#define JSTP_GROUP  ""
#endif

