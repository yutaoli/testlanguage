#ifndef _JSTP_PACK_TYPE_H_
#define _JSTP_PACK_TYPE_H_
#include <jstp_config.h>

#ifdef __cplusplus
extern "C" {
#endif

// ����/��ȡJSTPЭ��ͷ��С (JstpPackSet/GetOption)
#define JSTP_PACK_OPTION_PACK_HEAD_SIZE 1

// ����/��ȡ�ַ��������ʽ[0:GBK 1:UTF-8] (JstpPackSet/GetOption)
#define JSTP_PACK_OPTION_CHARSET_TYPE   2

// jstp_pack���ڴ����������ⲿ�ṩ
typedef void *(*jstp_alloc_pt)(size_t size);

// �ֶ�����
typedef enum jstp_field_type {
	FILED_TYPE_CHAR = 0,	// �ַ�
	FILED_TYPE_INT32 = 1,	// 32λ����
	FILED_TYPE_INT64 = 2,	// 64λ����
	FILED_TYPE_DOUBLE = 3,	// ˫���ȸ�����
	FILED_TYPE_STRING = 4,	// �ַ���(�ַ�������ӦС��64k)
	FILED_TYPE_BINARY = 5,	// ������
	FILED_TYPE_DATASET = 6, // �����
	FILED_TYPE_PACK = 7		// Ƕ�׵�jstp_pack
} jstp_field_type;

typedef struct jstp_field_info_s
{
	jstp_uint16_t nFieldIdx;	 // ������,JstpPackRsGetColByIndexXXX
	jstp_field_type emFieldtype; // �ֶ�����
	char szFieldName[64];		 // �ֶ���
} jstp_field_info_t;

// �ַ�������
typedef enum jstp_charset_type_s {
    JSTP_CHARSET_TYPE_GBK = 0,
    JSTP_CHARSET_TYPE_UTF8 = 1
}jstp_charset_type_t;

#ifdef __cplusplus
}
#endif

#endif
