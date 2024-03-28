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
* �� �� ����jstp_pack.h
* ģ�����ƣ����༫�ٽ���
* ����˵�������༫�ٽ���Э����
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
#ifndef __JSTP_PACK_H__
#define __JSTP_PACK_H__

#include <jstp_config.h>
#include <jstp_pack_type.h>

#if defined(_MSC_VER)
#if defined(JSTP_PACK_EXPORTS)
#define JSTP_PACK_API __declspec(dllexport)
#else
#define JSTP_PACK_API __declspec(dllimport)
#endif
#define JSTPCLISTDCALL __stdcall /* ensure stcall calling convention on NT */
#else
#if defined(JSTP_PACK_EXPORTS)
#define JSTP_PACK_API __attribute__((visibility("default")))
#else
#define JSTP_PACK_API
#endif
#define JSTPCLISTDCALL /* leave blank for other systems */
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ��ʼ�� */
// ��ʼ��api
JSTP_PACK_API jstp_handle_api_t JSTPCLISTDCALL JstpPackInit();

// api�˳�
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackExit(jstp_handle_api_t handle);

/* ѡ�� */
// ����APIѡ��
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetOption(jstp_handle_api_t handle, jstp_uint_t optionIndex, void const *optionValue);

// ��ȡAPIѡ��
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetOption(jstp_handle_api_t handle, jstp_uint_t optionIndex, void *optionValue);

/* �ⲿ�ڴ���� */
// �����ⲿ�ڴ���亯��
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetMallocFunc(jstp_handle_api_t handle, jstp_alloc_pt MallocFuncPtr);

// �����ⲿ�ڴ��ַ
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetWriteBufferPtr(jstp_handle_api_t handle, void *pWriteBuffer, size_t nBufferSize);

/* Э�����ݰ����� */
// ���ݴ��
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackBeginWrite(jstp_handle_api_t handle);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetValueChar(jstp_handle_api_t handle, const char *KeyName, char Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetValueInt(jstp_handle_api_t handle, const char *KeyName, int Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetValueInt64(jstp_handle_api_t handle, const char *KeyName, jstp_int64_t Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetValueDouble(jstp_handle_api_t handle, const char *KeyName, double Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetValueStr(jstp_handle_api_t handle, const char *KeyName, const char *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetValueByte(jstp_handle_api_t handle, const char *KeyName, const void *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetValuePack(jstp_handle_api_t handle, const char *KeyName, const void *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackSetValueHandle(jstp_handle_api_t handle, const char *KeyName, jstp_handle_api_t hPack);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetPacket(jstp_handle_api_t handle, void *Data, size_t DataSize, size_t *PackLen);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetPacketPointer(jstp_handle_api_t handle, void **Data, size_t *PackLen);

// ���ݽ��
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackPutPacket(jstp_handle_api_t handle, const void *Data, size_t DataSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetColNum(jstp_handle_api_t handle, size_t *ColNum);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetColInfo(jstp_handle_api_t handle, jstp_field_info_t *ColInfo, size_t ColInfoSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetValueChar(jstp_handle_api_t handle, const char *KeyName, char *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetValueInt(jstp_handle_api_t handle, const char *KeyName, int *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetValueInt64(jstp_handle_api_t handle, const char *KeyName, jstp_int64_t *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetValueDouble(jstp_handle_api_t handle, const char *KeyName, double *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetValueStr(jstp_handle_api_t handle, const char *KeyName, char *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetValueByte(jstp_handle_api_t handle, const char *KeyName, void *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetValueBytePointer(jstp_handle_api_t handle, const char *KeyName, void **Value, size_t *ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetValuePack(jstp_handle_api_t handle, const char *KeyName, void *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetValuePackPointer(jstp_handle_api_t handle, const char *KeyName, void **Value, size_t *ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackReaderGetPacket(jstp_handle_api_t handle, void *Data, size_t DataSize, size_t *PackLen);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackReaderGetPacketPointer(jstp_handle_api_t handle, void **Data, size_t *PackLen);

/* ��������� */
// ��������
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsCreate(jstp_handle_api_t handle, const char *RsName, const char *ColInfo);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsAddRow(jstp_handle_api_t handle);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByNameChar(jstp_handle_api_t handle, const char *ColName, char Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByNameInt(jstp_handle_api_t handle, const char *ColName, int Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByNameInt64(jstp_handle_api_t handle, const char *ColName, jstp_int64_t Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByNameDouble(jstp_handle_api_t handle, const char *ColName, double Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByNameStr(jstp_handle_api_t handle, const char *ColName, const char *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByNameByte(jstp_handle_api_t handle, const char *ColName, const void *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByNamePack(jstp_handle_api_t handle, const char *ColName, const void *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByIndexChar(jstp_handle_api_t handle, jstp_uint32_t ColIndex, char Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByIndexInt(jstp_handle_api_t handle, jstp_uint32_t ColIndex, int Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByIndexInt64(jstp_handle_api_t handle, jstp_uint32_t ColIndex, jstp_int64_t Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByIndexDouble(jstp_handle_api_t handle, jstp_uint32_t ColIndex, double Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByIndexStr(jstp_handle_api_t handle, jstp_uint32_t ColIndex, const char *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByIndexByte(jstp_handle_api_t handle, jstp_uint32_t ColIndex, const void *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSetColByIndexPack(jstp_handle_api_t handle, jstp_uint32_t ColIndex, const void *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSaveRow(jstp_handle_api_t handle);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsSave(jstp_handle_api_t handle);

// ��������
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsNext(jstp_handle_api_t handle);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetName(jstp_handle_api_t handle, char *RsName, size_t NameSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColNum(jstp_handle_api_t handle, size_t *ColNum);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColInfo(jstp_handle_api_t handle, jstp_field_info_t *ColInfo, size_t ColInfoSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsFetchRow(jstp_handle_api_t handle);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByNameChar(jstp_handle_api_t handle, const char *ColName, char *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByNameInt(jstp_handle_api_t handle, const char *ColName, int *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByNameInt64(jstp_handle_api_t handle, const char *ColName, jstp_int64_t *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByNameDouble(jstp_handle_api_t handle, const char *ColName, double *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByNameStr(jstp_handle_api_t handle, const char *ColName, char *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByNameByte(jstp_handle_api_t handle, const char *ColName, void **Value, size_t *ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByNamePack(jstp_handle_api_t handle, const char *ColName, void **Value, size_t *ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByIndexChar(jstp_handle_api_t handle, jstp_uint32_t ColIndex, char *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByIndexInt(jstp_handle_api_t handle, jstp_uint32_t ColIndex, int *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByIndexInt64(jstp_handle_api_t handle, jstp_uint32_t ColIndex, jstp_int64_t *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByIndexDouble(jstp_handle_api_t handle, jstp_uint32_t ColIndex, double *Value);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByIndexStr(jstp_handle_api_t handle, jstp_uint32_t ColIndex, char *Value, size_t ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByIndexByte(jstp_handle_api_t handle, jstp_uint32_t ColIndex, void **Value, size_t *ValueSize);
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackRsGetColByIndexPack(jstp_handle_api_t handle, jstp_uint32_t ColIndex, void **Value, size_t *ValueSize);

// �������Կɼ��ַ���ʽչʾ
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetPacketStrView(jstp_handle_api_t handle, void* Data, size_t PackLen, void** PackView, size_t* PackViewSize);

/* ������Ϣ */
// �������
JSTP_PACK_API jstp_int_t JSTPCLISTDCALL JstpPackGetErrorCode(jstp_handle_api_t handle);

// ������Ϣ
JSTP_PACK_API const char *JSTPCLISTDCALL JstpPackGetErrorMsg(jstp_handle_api_t handle);

#ifdef __cplusplus
}
#endif

#endif
