/*
Copyright (c) 2023 Shenzhen Kingdom Co. Ltd.
All rights reserved
*/
#ifndef __KGBP_LBMAPI_H_
#define __KGBP_LBMAPI_H_
#include <stdlib.h>
#if defined(_WIN32)
#if defined(LBMAPI_EXPORTS)
#define KGBP_LBMAPI_API	__declspec(dllexport)
#else
#define KGBP_LBMAPI_API	__declspec(dllimport)
#endif
#define LBMEXPORTS	__declspec(dllexport)
#else
#define KGBP_LBMAPI_API
#define LBMEXPORTS
#endif


#define OPT_GET_AS_INDEX     1   // 取LBM执行所在as
#define OPT_GET_AS_NUM       19  // 取AS数

// 取LBM名
#define OPT_GET_LBM_NAME     2
#define OPT_CUR_XA_NAME      3
#define SET_ANS_ACCESS_IDX   9
#define SET_ANS_ACCESS_NAME  11
#define GET_HARE_QUEUE_TIME  21 // 取hare排队时间戳
#define GET_HARE_QUEUE_SNO   23
#define CUR_ACCESS_IS_HA     25 // 查询当前接入是否高可用
#define REQ_MSG_TYPE         27 // 请求消息类型 1：备集群或节点消息 2: 重演消息

// 设、取业务日志级别
#define OPT_LOG_LEVEL        1003

#define OPT_GET_GATEWAY_ID   1004
#define OPT_GET_GATEWAY_SNO  1006
#define OPT_RETURN_FLAG      1007
#define OPT_EXIT_HOLD_HANLDE 1008 // 为1,只返回应答，不退出
#define OPT_GET_TRACE_ID     1010
#define OPT_GET_SPAN_ID      1011

typedef void* kgbp_handle_t;

#ifdef __cplusplus
extern "C"
{
#endif
// 初始化
KGBP_LBMAPI_API kgbp_handle_t  kgbp_lbm_init(void* comm_area);

// 取业务打包句柄
KGBP_LBMAPI_API kgbp_handle_t kgbp_get_packet_handle(kgbp_handle_t handle);

// 退出,返回应答也在此接口
KGBP_LBMAPI_API int  kgbp_lbm_exit(kgbp_handle_t handle);

// 切换XA为当前XA，并返回句柄
KGBP_LBMAPI_API int  kgbp_xa_select(kgbp_handle_t handle, char* xa_name,
                       void** xa_handle);

// 得到XA句柄,不切换
KGBP_LBMAPI_API int  kgbp_xa_get_handle(kgbp_handle_t handle, 
                       char* xa_name, void** xa_handle);

// 得到XA对外导出结构句柄
KGBP_LBMAPI_API int  kgbp_xa_get_export(kgbp_handle_t handle, 
                       char* xa_name, void** xa_export);

// 得到当前xa名
KGBP_LBMAPI_API int  kgbp_get_cur_xaname(kgbp_handle_t handle, char* buf,
                       int* len);


// 通过index指定的接入模块发送数据
KGBP_LBMAPI_API int  kgbp_rm_send(kgbp_handle_t handle, int index, void* buf,  size_t len);

// 通过名字指定的接入模块发送数据
KGBP_LBMAPI_API int  kgbp_rm_send2(kgbp_handle_t handle, const char* name, void* buf,  size_t len);


// 事务控制，先保留,可由JstpBase封装
KGBP_LBMAPI_API int  kgbp_begin_trans(kgbp_handle_t handle);
KGBP_LBMAPI_API int  kgbp_commit(kgbp_handle_t handle);
KGBP_LBMAPI_API int  kgbp_rollback(kgbp_handle_t handle);

// 设置属性
KGBP_LBMAPI_API int  kgbp_set_options(kgbp_handle_t handle, int index, 
                       const void* value, int len);

// 查询属性
KGBP_LBMAPI_API int  kgbp_get_options(kgbp_handle_t handle, int index, 
                       void* value, int* len);

// 系统控制类接口
KGBP_LBMAPI_API int  kgbp_system(kgbp_handle_t handle, int index,
                       void* value, int* len);

// 写业务日志(注:binlog日志由jstp_base封装)
KGBP_LBMAPI_API int  kgbp_lbm_write_log(kgbp_handle_t handle,
                       int level, int err_code, const char* msg);

KGBP_LBMAPI_API int  kgbp_set_lbm_err(kgbp_handle_t handle, int err_code, 
                       int level,  const char* msg);


// 排队控制
KGBP_LBMAPI_API void	kgbp_entry_readqueue(kgbp_handle_t handle);
KGBP_LBMAPI_API void	kgbp_exit_readqueue(kgbp_handle_t handle);
KGBP_LBMAPI_API void	kgbp_entry_writequeue(kgbp_handle_t handle);
KGBP_LBMAPI_API void	kgbp_exit_writequeue(kgbp_handle_t handle);

#if 0
// CWA功能目前不提供
KGBP_LBMAPI_API int	kgbp_saveto_cwa(kgbp_handle_t handle, int pos, void* mem, int len);
KGBP_LBMAPI_API int	kgbp_loadfrom_cwa(kgbp_handle_t handle, int pos, void* mem, int len);
KGBP_LBMAPI_API int	kgbp_lock_cwa(kgbp_handle_t handle, int pos, int len);
KGBP_LBMAPI_API int	kgbp_unlock_cwa(kgbp_handle_t handle, int pos, int len);
#endif

#ifdef __cplusplus
}
#endif
#endif
