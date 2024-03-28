#ifndef _KGBPCLI_H_
#define _KGBPCLI_H_

#if defined(_MSC_VER)
#ifdef KGBPCLI_EXPORTS
#define KGBPCLI_API         __declspec(dllexport)
#else
#define KGBPCLI_API         __declspec(dllimport)
#endif
#define KGBPCLI_STDCALL     __stdcall
#else
#ifdef KGBPCLI_EXPORTS
#define KGBPCLI_API         __attribute__((visibility("default")))
#else
#define KGBPCLI_API
#endif
#define KGBPCLI_STDCALL
#endif

#define KGBPCLI_API_DECLARE(rv) KGBPCLI_API rv KGBPCLI_STDCALL

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

//函数返回值
#define KGBPCLI_OK                       0
#define KGBPCLI_ERROR                   -1
#define KGBPCLI_AGAIN                   -2
#define KGBPCLI_BUSY                    -3
#define KGBPCLI_DONE                    -4
#define KGBPCLI_DECLINED                -5
#define KGBPCLI_ABORT                   -6
#define KGBPCLI_NONE                    -7


//日志级别
#define KGBPCLI_LOG_LEVEL_FATAL         1
#define KGBPCLI_LOG_LEVEL_ERR           2
#define KGBPCLI_LOG_LEVEL_WARN          3
#define KGBPCLI_LOG_LEVEL_INFO          4
#define KGBPCLI_LOG_LEVEL_DEBUG         5
#define KGBPCLI_LOG_LEVEL_TRACE         6


//KGBPCli_GetErrorCode得到的错误码说明。KGBPCli端错误码共5位，第一位固定为1
#define KGBPCLI_ERROR_NEW               12000   //调new失败
#define KGBPCLI_ERROR_PACKINIT          12001   //调JstpPackInit失败
#define KGBPCLI_ERROR_NETINIT           12002   //net的init失败，具体的还是要看KGBPCli_GetErrorMsg
#define KGBPCLI_ERROR_NO_SERVICE_NAME   12006   //同/异步调用中，发现没有送service name
#define KGBPCLI_ERROR_REQUSTID          12007   //异步调用中，送入的requestid指针为空
#define KGBPCLI_ERROR_TOO_BIG_PACKET    12009   //要发送的包太大了，超过了KGBPCLI_REQUEST_MAX_SIZE
#define KGBPCLI_ERROR_GETPACKET         12010   //同/异步调用中，JstpPackGetPacketPointer失败
#define KGBPCLI_ERROR_NO_REPLY          12011   //同步调用中，过了等待时间还没有等到应答
#define KGBPCLI_ERROR_CANNOT_SETOPTION  12012   //调了KGBPCli_SetCommArea后，不允许调用会改变包头长度的KGBPCli_SetOption
#define KGBPCLI_ERROR_SETOPTION_TYPE    12013   //KGBPCli_SetOption送的type参数不对
#define KGBPCLI_ERROR_SETOPTION_SIZE    12014   //KGBPCli_SetOption送的size参数不对
#define KGBPCLI_ERROR_GETOPTION_TYPE    12015   //KGBPCli_GetOption送的type参数不对
#define KGBPCLI_ERROR_GETOPTION_SIZE    12016   //KGBPCli_GetOption送的size参数不对
#define KGBPCLI_ERROR_ANS_SIZE          12021   //调GetCommArea时，发现收到的应答太小
#define KGBPCLI_ERROR_CONNECT           12044   //在连接的时候失败，具体的还是要看KGBPCli_GetErrorMsg
#define KGBPCLI_ERROR_SEND              12054   //通过socket发送包失败
#define KGBPCLI_ERROR_FORCE_DISCONN     12055   //同步调用中，因心跳超时断开连接，所以没有应答


/* 请求包超过该大小会报错，需要上层自己分包*/
#define KGBPCLI_REQUEST_MAX_SIZE        (64*1024*1024)


/***************以下为KGBPCli_SetOption/KGBPCli_GetOption第二个参数支持的值*************/

/* 设置/获取 收TCP包时的等待的超时时间 类型uint32_t 单位毫秒 默认 10毫秒 */
#define KGBPCLI_OPTION_POOL_TIMEOUT		1

/* 设置/获取 连接超时时间 暂未用 */
#define KGBPCLI_OPTION_CONNECT_TIMEOUT	2

/* 设置/获取 代理信息 类型为字符串 默认不启用 */
/* Address 小于256个字符 username、password 小于32个字符  */
// 	1>https://192.168.1.254:1080
//  2>socks4://192.168.1.254:1080
//  3>socks5://192.168.1.254:1080
#define KGBPCLI_OPTION_PROXY_ADDRESS	3
#define KGBPCLI_OPTION_PROXY_USERNAME	4
#define KGBPCLI_OPTION_PROXY_PASSWORD	5

/* 设置/获取 外网IP和端口 IP类型为字符串 端口类型uint16_t */
#define KGBPCLI_OPTION_INTERNET_ADDR	6
#define	KGBPCLI_OPTION_INTERNET_PORT	7

/* 设置/获取 请求、应答包中文字符集编码为 uint32_t  0:GBK 1:UTF8 */
#define KGBPCLI_OPTION_REQ_CHARSET      8
#define KGBPCLI_OPTION_ANS_CHARSET      9

/* 设置/获取Token 不超过24个字符 */
#define KGBPCLI_OPTION_USER_TOKEN       10

/* 设置/获取链路跟踪Traceid 类型uint64_t */
#define KGBPCLI_OPTION_USER_TRACEID     11

/* 设置/获取链路跟踪Traceid 类型uint64_t */
#define KGBPCLI_OPTION_USER_SPANID      12

/* 设置/获取SSL加密证书、私钥等文件路径带文件名 小于260个字符*/
#define KGBPCLI_OPTION_CA_CERT          13
#define KGBPCLI_OPTION_USER_CERT        14
#define KGBPCLI_OPTION_USER_KEY         15

/* 设置/获取当前调用业务是否是事务型业务 默认值:否 uint32_t 0:否 1:是 */
#define KGBPCLI_OPTION_IS_TRADE_BIZ     16

/* 设置/获取当前调用业务的client_session_id(对应客户号), 默认值：0 uint64_t */
#define KGBPCLI_OPTION_CLIENT_SESSION_ID    17

/* 设置/获取连接的心跳的发送间隔，默认值：0(表示不启用心跳)，类型：uint32_t 单位：毫秒 */
#define KGBPCLI_OPTION_HEARTBEAT_INTERVAL   18
/* 设置/获取连接的心跳的超时时间，默认值：2*发送间隔，类型：uint32_t 单位：毫秒 */
#define KGBPCLI_OPTION_HEARTBEAT_TIMEOUT    19

/* 设置/获取节点ID 类型uint32_t */
#define KGBPCLI_OPTION_NODE_ID          20

/* 设置/获取路由ID 类型uint32_t */
#define KGBPCLI_OPTION_ROUTE_ID         21

/* 设置/获取网关编号 类型uint32_t */
#define KGBPCLI_OPTION_GATEWAY_ID       22

/* 设置/获取网关序号 类型uint64_t */
#define KGBPCLI_OPTION_GATEWAY_SNO      23

/* 设置/获取网关转发请求时间戳 类型uint64_t */
#define KGBPCLI_OPTION_SEND_TIME        24

/* 设置/获取网关收到应答时间戳 类型uint64_t */
#define KGBPCLI_OPTION_RECV_TIME        25

/* 设置/获取服务名 设置时不超过11个字符 */
/* 同/异步调用时，功能号和服务名至少有一个有值，否则会报错KGBPCLI_ERROR_NO_SERVICE_NAME*/
#define KGBPCLI_OPTION_SERVICE_NAME     26

/* 获取kgbp包头的版本号 类型uint8_t。不支持设置 */
#define KGBPCLI_OPTION_HEAD_VERSION     27

/* 设置/获取网络类型 0:普通TCP连接类型 1:TCP Direct模式(slf网卡) 2:RDMA模式(mlx网卡) 3:exanic连接模式 4:efvi连接模式 5:驭数连接模式 */
/* 类型uint32_t 默认值为 0 */
#define KGBPCLI_OPTION_NETTYPE		    100
/* 设置/获取TCP Direct模式下的入参，小于32个字符 默认情况未设置此值 */
#define KGBPCLI_OPTION_LOCALIP		    101
/* 获取hare_socket的本地端口，不支持设置, uint16_t */
#define KGBPCLI_OPTION_LOCAL_PORT		102

/***************以上为KGBPCli_SetOption/KGBPCli_GetOption第二个参数支持的值*************/


typedef void (KGBPCLI_STDCALL *OnConnPtr)(void* apClient);
typedef void (KGBPCLI_STDCALL *OnDisConnPtr)(void* apClient);
typedef void (KGBPCLI_STDCALL *OnLoggerPtr)(void* apClient, int8_t nLogLevel, const char* szLogMsg);
typedef void (KGBPCLI_STDCALL *OnMsgPtr)(void* apClient, char* apMessage, uint32_t aLength, uint32_t aRequestId);

typedef struct {
	OnConnPtr		OnConn;     //连接回调函数。cli里面连接成功，会调该函数
    OnDisConnPtr    OnDisconn;  //断开连接回调函数；cli里面发生了连接断开，会调该函数
    OnLoggerPtr     OnLogger;   //日志回调函数。cli里面需要写日志的地方，会调该函数
    OnMsgPtr        OnMsg;      //消息处理回调函数。异步发送，cli里面收到应答会调用该函数
}KGBPCliHandler;

/* 调用接口导出 */

/**
* 获取版本信息
* @param	无
* @return	返回版本信息字符串
*/
KGBPCLI_API_DECLARE(const char*) KGBPCli_GetVersion();

/**
* 初始化客户端api
* @param	无
* @return	成功返回客户端api句柄，失败返回NULL
*/
KGBPCLI_API_DECLARE(void*) KGBPCli_Init();

/**
* 获取用户指针
* @param	apClient		客户端api句柄
* @return	返回用户指针，未设置则返回NULL
*/
KGBPCLI_API_DECLARE(void*) KGBPCli_GetUserData(void* apClient);

/**
* 设置用户指针
* @param	apClient		客户端api句柄
* @param	apUserData		用户指针
* @return	无
*/
KGBPCLI_API_DECLARE(void) KGBPCli_SetUserData(void* apClient, void* apUserData);

/**
* 设置回调函数
* @param	apClient		客户端api句柄
* @param	apEventHandler	回调函数结构体指针
* @return	无
*/
KGBPCLI_API_DECLARE(void) KGBPCli_RegisterHandler(void* apClient, KGBPCliHandler* apEventHandler);

/**
* 设置选项值
* @param	apClient		客户端api句柄
* @param	nOptionType		选项类型值，即KGBPCLI_OPTION_XXX宏
* @param	pVal			待设置的选项值指针
* @param	nValSize		待设置的选项值长度
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int)  KGBPCli_SetOption(void* apClient, int nOptionType, const void* pVal, size_t nValSize);

/**
* 获取选项值
* @param	apClient		客户端api句柄
* @param	nOptionType		选项类型值，即KGBPCLI_OPTION_XXX宏
* @param	pVal			选项值缓冲区指针，作为出参
* @param	nValSize		选项值缓冲区大小
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int)  KGBPCli_GetOption(void* apClient, int nOptionType, void* pVal, size_t nValSize);

/**
* 连接服务端（同时获取外网地址和端口）
* @param	apClient		客户端api句柄
* @param	szIp			服务端IP字符串
* @param	nPort			服务端端口
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR（连接成功但获取外网信息失败，只打印日志，仍返回KGBPCLI_OK）
*/
KGBPCLI_API_DECLARE(int)  KGBPCli_Start(void* apClient, const char* szIp, uint16_t nPort);

/**
* 判断连接状态
* @param	apClient		客户端api句柄
* @return	已建立连接返回1，未建立连接返回0
*/
KGBPCLI_API_DECLARE(int)  KGBPCli_IsConnected(void* apClient);

/**
* 同步连接服务端（同时获取外网地址和端口），相当于 KGBPCli_Start+不断的KGBPCli_IsConnected
* 用户
* @param	apClient		客户端api句柄
* @param	szIp			服务端IP字符串
* @param	nPort			服务端端口
* @param	aTimeoutMS		同步连接超时时间（毫秒）
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR（连接成功但获取外网信息失败，只打印日志，仍返回KGBPCLI_OK）
*/
KGBPCLI_API_DECLARE(int)  KGBPCli_StartX(void* apClient, const char* szIp, uint16_t nPort, int aTimeoutMS);

/**
* 设置内部jstppack数据，可以直接(A)CallProgram，设置的数据不支持后续的GetValue、GetNum等接口
* @param	apClient		客户端api句柄
* @param	apValue			jstppack数据指针（不包括包头）
* @param	aSize			jstppack数据长度
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int)  KGBPCli_SetCommArea(void* apClient, const void* apValue, size_t aSize);

/**
* 获取内部jstppack数据，与KGBPCli_SetCommArea成对使用，相当于KGBPCli_GetPacketPointer
* @param	apClient		客户端api句柄
* @param	appData			jstppack数据指针（不包括包头）
* @param	apPackLen		数据总长度指针，作为出参
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int)  KGBPCli_GetCommArea(void* apClient, void** appData, size_t* apPackLen);

/**
* 同步调用业务
* @param	apClient		客户端api句柄
* @param	aFuncId			业务功能号。不超过10个字节
* @param	aTimeoutMS		同步调用超时时间（毫秒）
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int)  KGBPCli_CallProgram(void* apClient, char* aFuncId, int aTimeoutMS);

/**
* 异步调用业务
* @param	apClient		客户端api句柄
* @param	aFuncId			业务功能号。不要超过10个字节
* @param	aRequestId		请求序号指针，由客户端api内部生成，作为出参
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int)  KGBPCli_ACallProgram(void* apClient, char* aFuncId, uint32_t* aRequestId);

/**
* 断开连接
* @param	apClient		客户端api句柄
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int)  KGBPCli_Stop(void* apClient);

/**
* 释放客户端api
* @param	apClient		客户端api句柄
* @return	无，调用后客户端api句柄失效
*/
KGBPCLI_API_DECLARE(void) KGBPCli_Exit(void* apClient);

/* 序列化接口 */

/**
* 准备写入数据
* @param	apClient		客户端api句柄
* @return	成功返回KGBPCLI_OK，会清空原有写入内容，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_BeginWrite(void* apClient);

/**
* 写入字段值
* @param	apClient		客户端api句柄
* @param	apKeyName		字段名称字符串
* @param	aValue			字段值
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_SetValueChar(void* apClient, const char* apKeyName, char aValue);
KGBPCLI_API_DECLARE(int) KGBPCli_SetValueInt(void* apClient, const char* apKeyName, int aValue);
KGBPCLI_API_DECLARE(int) KGBPCli_SetValueInt64(void* apClient, const char* apKeyName, int64_t aValue);
KGBPCLI_API_DECLARE(int) KGBPCli_SetValueDouble(void* apClient, const char* apKeyName, double aValue);
KGBPCLI_API_DECLARE(int) KGBPCli_SetValueStr(void* apClient, const char* apKeyName, const char* aValue);

/**
* 写入字段值（字节串）
* @param	apClient		客户端api句柄
* @param	apKeyName		字段名称字符串
* @param	aValue			字段值
* @param	aSize			字段值长度
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_SetValueByte(void* apClient, const char* apKeyName, const void* apValue, size_t aSize);

/**
* 写入字段值（jstppack字节串）
* @param	apClient		客户端api句柄
* @param	apKeyName		字段名称字符串
* @param	aValue			字段值
* @param	aSize			字段值长度
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_SetValuePack(void* apClient, const char* apKeyName, const void* apValue, size_t aSize);

/**
* 获取数据（有拷贝）
* @param	apClient		客户端api句柄
* @param	apData			数据缓冲区指针，作为出参
* @param	aSize			数据缓冲区大小
* @param	apPackLen		数据总长度指针，作为出参，传入NULL的apData和aSize也可获取此长度
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_GetPacket(void* apClient, void* apData, size_t aSize, size_t* apPackLen);

/**
* 获取数据指针（无拷贝）
* @param	apClient		客户端api句柄
* @param	appData			数据指针，作为出参
* @param	apPackLen		数据总长度指针，作为出参
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_GetPacketPointer(void* apClient, void** appData, size_t* apPackLen);

/**
* 创建新的结果集
* @param	apClient		客户端api句柄
* @param	apRsName		结果集名称字符串
* @param	apColInfo		结果集列名称字符串，如"name,age,id"，逗号隔开无空格
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsCreate(void* apClient, const char* apRsName, const char* apColInfo);

/**
* 创建新的一行结果
* @param	apClient		客户端api句柄
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsAddRow(void* apClient);

/**
* 按列名称写入结果集字段值
* @param	apClient		客户端api句柄
* @param	ColName			列名称字符串
* @param	aValue			字段值
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByNameChar(void* apClient, const char* ColName, char Value);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByNameInt(void* apClient, const char* ColName, int Value);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByNameInt64(void* apClient, const char* ColName, int64_t Value);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByNameDouble(void* apClient, const char* ColName, double Value);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByNameStr(void* apClient, const char* ColName, char* Value);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByNameByte(void* apClient, const char* ColName, const void* Value, size_t Size);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByNamePack(void* apClient, const char* ColName, const void* Value, size_t Size);

/**
* 按列索引写入结果集字段值
* @param	apClient		客户端api句柄
* @param	ColIndex		列索引值，对应ColInfo中各列名称索引，从1开始
* @param	aValue			字段值
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByIndexChar(void* apClient, int ColIndex, char Value);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByIndexInt(void* apClient, int ColIndex, int Value);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByIndexInt64(void* apClient, int ColIndex, int64_t Value);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByIndexDouble(void* apClient, int ColIndex, double Value);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByIndexStr(void* apClient, int ColIndex, char* Value);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByIndexByte(void* apClient, int ColIndex, const void* Value, size_t Size);
KGBPCLI_API_DECLARE(int) KGBPCli_RsSetColByIndexPack(void* apClient, int ColIndex, const void* Value, size_t Size);

/**
* 保存当前行的结果
* @param	apClient		客户端api句柄
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsSaveRow(void* apClient);

/**
* 保存当前结果集
* @param	apClient		客户端api句柄
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsSave(void* apClient);

/**
* 解析数据包
* @param	apClient		客户端api句柄
* @param	apData			数据指针
* @param	aSize			数据长度
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_PutPacket(void* apClient, const void* apData, size_t aSize);

/**
* 获取列数量
* @param	apClient		客户端api句柄
* @param	apColNum		列数量指针，作为出参
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_GetColNum(void* apClient, size_t* apColNum);

/**
* 获取字段名称
* @param	apClient		客户端api句柄
* @param	apColInfo		列名称字符串数组指针，作为出参
* @param	aColInfoSize	列名称字符串数组大小
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_GetColInfo(void* apClient, char* apColInfo, size_t aColInfoSize);

/**
* 获取字段值
* @param	apClient		客户端api句柄
* @param	apKeyName		字段名称字符串
* @param	aValue			字段值指针，作为出参
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_GetValueChar(void* apClient, const char* apKeyName, char* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_GetValueInt(void* apClient, const char* apKeyName, int* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_GetValueInt64(void* apClient, const char* apKeyName, int64_t* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_GetValueDouble(void* apClient, const char* apKeyName, double* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_GetValueStr(void* apClient, const char* apKeyName, char* apValue, size_t aSize);
KGBPCLI_API_DECLARE(int) KGBPCli_GetValueByte(void* apClient, const char* apKeyName, void* apValue, size_t aSize);
KGBPCLI_API_DECLARE(int) KGBPCli_GetValueBytePointer(void* apClient, const char* apKeyName, void** appValue, size_t* apSize);
KGBPCLI_API_DECLARE(int) KGBPCli_GetValuePack(void* apClient, const char* apKeyName, void* apValue, size_t aSize);
KGBPCLI_API_DECLARE(int) KGBPCli_GetValuePackPointer(void* apClient, const char* apKeyName, void** appValue, size_t* apSize);

/**
* 获取下一结果集
* @param	apClient		客户端api句柄
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsNext(void* apClient);

/**
* 获取当前结果集列数量
* @param	apClient		客户端api句柄
* @param	apColNum		列数量指针，作为出参
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColNum(void* apClient, size_t* apColNum);

/**
* 获取当前结果集列名称
* @param	apClient		客户端api句柄
* @param	apColInfo		列名称字符串数组指针，作为出参
* @param	aColInfoSize	列名称字符串数组大小
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColInfo(void* apClient, char* apColInfo, size_t aColInfoSize);

/**
* 获取当前结果名称
* @param	apClient		客户端api句柄
* @param	apRsName		结果集名称字符串数组指针，作为出参
* @param	aSize			结果集名称字符串数组大小
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetName(void* apClient, char* apRsName, size_t aSize);

/**
* 获取下一行结果
* @param	apClient		客户端api句柄
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsFetchRow(void* apClient);

/**
* 按列名称获取结果集字段值
* @param	apClient		客户端api句柄
* @param	apKeyName		字段名称字符串
* @param	aValue			字段值指针，作为出参
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByNameChar(void* apClient, const char* apColName, char* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByNameInt(void* apClient, const char* apColName, int* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByNameInt64(void* apClient, const char* apColName, int64_t* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByNameDouble(void* apClient, const char* apColName, double* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByNameStr(void* apClient, const char* apColName, char* apValue, size_t aSize);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByNameByte(void* apClient, const char* apColName, void** appValue, size_t* apSize);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByNamePack(void* apClient, const char* apColName, void** appValue, size_t* apSize);

/**
* 按列索引获取结果集字段值
* @param	apClient		客户端api句柄
* @param	ColIndex		列索引值，对应ColInfo中各列名称索引，从1开始
* @param	aValue			字段值
* @return	成功返回KGBPCLI_OK，失败返回KGBPCLI_ERROR
*/
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByIndexChar(void* apClient, int ColIndex, char* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByIndexInt(void* apClient, int ColIndex, int* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByIndexInt64(void* apClient, int ColIndex, int64_t* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByIndexDouble(void* apClient, int ColIndex, double* apValue);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByIndexStr(void* apClient, int ColIndex, char* apValue, size_t aSize);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByIndexByte(void* apClient, int ColIndex, void** appValue, size_t* apSize);
KGBPCLI_API_DECLARE(int) KGBPCli_RsGetColByIndexPack(void* apClient, int ColIndex, void** appValue, size_t* apSize);

/* 错误获取接口 */

/**
* 获取错误码
* @param	apClient		客户端api句柄
* @return	返回错误码
*/
KGBPCLI_API_DECLARE(int)         KGBPCli_GetErrorCode(void* apClient);

/**
* 获取错误信息字符串
* @param	apClient		客户端api句柄
* @return	返回错误信息字符串指针
*/
KGBPCLI_API_DECLARE(const char*) KGBPCli_GetErrorMsg(void* apClient);

#ifdef __cplusplus
}
#endif

#endif
