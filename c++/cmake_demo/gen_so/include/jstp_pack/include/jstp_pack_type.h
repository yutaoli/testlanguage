#ifndef _JSTP_PACK_TYPE_H_
#define _JSTP_PACK_TYPE_H_
#include <jstp_config.h>

#ifdef __cplusplus
extern "C" {
#endif

// 设置/获取JSTP协议头大小 (JstpPackSet/GetOption)
#define JSTP_PACK_OPTION_PACK_HEAD_SIZE 1

// 设置/获取字符集编码格式[0:GBK 1:UTF-8] (JstpPackSet/GetOption)
#define JSTP_PACK_OPTION_CHARSET_TYPE   2

// jstp_pack的内存管理可以由外部提供
typedef void *(*jstp_alloc_pt)(size_t size);

// 字段类型
typedef enum jstp_field_type {
	FILED_TYPE_CHAR = 0,	// 字符
	FILED_TYPE_INT32 = 1,	// 32位整形
	FILED_TYPE_INT64 = 2,	// 64位整形
	FILED_TYPE_DOUBLE = 3,	// 双精度浮点数
	FILED_TYPE_STRING = 4,	// 字符串(字符串长度应小于64k)
	FILED_TYPE_BINARY = 5,	// 二进制
	FILED_TYPE_DATASET = 6, // 结果集
	FILED_TYPE_PACK = 7		// 嵌套的jstp_pack
} jstp_field_type;

typedef struct jstp_field_info_s
{
	jstp_uint16_t nFieldIdx;	 // 列索引,JstpPackRsGetColByIndexXXX
	jstp_field_type emFieldtype; // 字段类型
	char szFieldName[64];		 // 字段名
} jstp_field_info_t;

// 字符集编码
typedef enum jstp_charset_type_s {
    JSTP_CHARSET_TYPE_GBK = 0,
    JSTP_CHARSET_TYPE_UTF8 = 1
}jstp_charset_type_t;

#ifdef __cplusplus
}
#endif

#endif
