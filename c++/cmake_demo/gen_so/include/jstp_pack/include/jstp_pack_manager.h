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
* 文 件 名：jstp_pack_manager.h
* 模块名称：雨燕极速交易
* 功能说明：雨燕极速交易协议打包
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
#ifndef __JSTP_PACK_MANAGER_H__
#define __JSTP_PACK_MANAGER_H__

#include "jstp_pack.h"
#include <stdexcept>

#if defined(_MSC_VER)
#pragma comment(lib, "jstp_pack.lib")
#endif

#include <vector>

using namespace std; // NOLINT

// CJstpPackManager
class CJstpPackManager
{
  public:
	explicit CJstpPackManager(jstp_handle_api_t hPack = NULL)
	{
		m_bUseExtFlag = hPack != NULL;
		m_hPack = m_bUseExtFlag ? hPack : JstpPackInit();
	}

	~CJstpPackManager()
	{
		if (!m_bUseExtFlag)
			JstpPackExit(m_hPack);
	}

  public:
	// 获取打包的Handle
	jstp_handle_api_t GetPackHandle() const
	{
		return m_hPack;
	}

  public:
	/* 打包选项 */
	// 设置数据库选项
	bool SetPackOption(jstp_int_t optionIndex, void const *optionValue)
	{
		if (JstpPackSetOption(m_hPack, optionIndex, optionValue) != JSTP_OK)
			raise_pack_error("JstpPackSetOption call error");
		return true;
	}

	// 获取数据库选项
	bool GetPackOption(jstp_int_t optionIndex, void *optionValue)
	{
		if (JstpPackGetOption(m_hPack, optionIndex, optionValue) != JSTP_OK)
			raise_pack_error("JstpPackGetOption call error");
		return true;
	}

	/* 外部内存管理 */
	// 设置外部内存分配函数
	bool SetMallocFunc(jstp_alloc_pt MallocFuncPtr)
	{
		if (JstpPackSetMallocFunc(m_hPack, MallocFuncPtr) != JSTP_OK)
			raise_pack_error("JstpPackSetMallocFunc call error");
		return true;
	}

	// 设置外部内存地址
	bool SetWriteBuffer(void *pWriteBuffer, size_t nBufferSize)
	{
		if (JstpPackSetWriteBufferPtr(m_hPack, pWriteBuffer, nBufferSize) != JSTP_OK)
			raise_pack_error("JstpPackSetWriteBufferPtr call error");
		return true;
	}

  public:
	/* 协议数据包处理 */
	// 数据打包
	bool BeginWrite()
	{
		if (JstpPackBeginWrite(m_hPack) != JSTP_OK)
			raise_pack_error("JstpPackBeginWrite call error");
		return true;
	}

	bool SetValue(const char *KeyName, char Value)
	{
		if (JstpPackSetValueChar(m_hPack, KeyName, Value) != JSTP_OK)
			raise_pack_error("JstpPackSetValueChar call error");
		return true;
	}

	bool SetValue(const char *KeyName, int Value)
	{
		if (JstpPackSetValueInt(m_hPack, KeyName, Value) != JSTP_OK)
			raise_pack_error("JstpPackSetValueInt call error");
		return true;
	}

	bool SetValue(const char *KeyName, jstp_uint32_t Value)
	{
		if (JstpPackSetValueInt(m_hPack, KeyName, (int)Value) != JSTP_OK)
			raise_pack_error("JstpPackSetValueInt call error");
		return true;
	}

	bool SetValue(const char *KeyName, jstp_uint64_t Value)
	{
		if (JstpPackSetValueInt64(m_hPack, KeyName, (jstp_int64_t)Value) != JSTP_OK)
			raise_pack_error("JstpPackSetValueInt64 call error");
		return true;
	}

	bool SetValue(const char *KeyName, jstp_int64_t Value)
	{
		if (JstpPackSetValueInt64(m_hPack, KeyName, Value) != JSTP_OK)
			raise_pack_error("JstpPackSetValueInt64 call error");
		return true;
	}

	bool SetValue(const char *KeyName, double Value)
	{
		if (JstpPackSetValueDouble(m_hPack, KeyName, Value) != JSTP_OK)
			raise_pack_error("JstpPackSetValueDouble call error");
		return true;
	}

	bool SetValue(const char *KeyName, const char *Value)
	{
		if (JstpPackSetValueStr(m_hPack, KeyName, Value) != JSTP_OK)
			raise_pack_error("JstpPackSetValueStr call error");
		return true;
	}

	bool SetValue(const char *KeyName, const void *Value, size_t ValueSize)
	{
		if (JstpPackSetValueByte(m_hPack, KeyName, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackSetValueByte call error");
		return true;
	}

	bool SetValuePack(const char *KeyName, const void *Value, size_t ValueSize)
	{
		if (JstpPackSetValuePack(m_hPack, KeyName, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackSetValuePack call error");
		return true;
	}

	bool SetValue(const char *KeyName, CJstpPackManager& PackManager)
	{
		if (JstpPackSetValueHandle(m_hPack, KeyName, PackManager.GetPackHandle()) != JSTP_OK)
			raise_pack_error("JstpPackSetValueHandle call error");
		return true;
	}

	bool GetPacket(void *Data, size_t DataSize, size_t &PackLen, bool isWriterGetPacket = true)
	{
		if (isWriterGetPacket)
		{
			if (JstpPackGetPacket(m_hPack, Data, DataSize, &PackLen) != JSTP_OK)
				raise_pack_error("JstpPackGetPacket call error");
		}
		else
		{
			if (JstpPackReaderGetPacket(m_hPack, Data, DataSize, &PackLen) != JSTP_OK)
				raise_pack_error("JstpPackReaderGetPacket call error");
		}
		return true;
	}

	bool GetPacketPointer(void *&Data, size_t &PackLen, bool isWriterGetPacket = true)
	{
		if (isWriterGetPacket)
		{
			if (JstpPackGetPacketPointer(m_hPack, &Data, &PackLen) != JSTP_OK)
				raise_pack_error("JstpPackGetPacketPointer call error");
		}
		else
		{
			if (JstpPackReaderGetPacketPointer(m_hPack, &Data, &PackLen) != JSTP_OK)
				raise_pack_error("JstpPackReaderGetPacketPointer call error");
		}
		return true;
	}

	// 数据解包
	bool PutPacket(const void *Data, size_t DataSize)
	{
		if (JstpPackPutPacket(m_hPack, Data, DataSize) != JSTP_OK)
			raise_pack_error("JstpPackPutPacket call error");
		return true;
	}

	bool GetColNum(size_t *ColNum)
	{
		if (JstpPackGetColNum(m_hPack, ColNum) != JSTP_OK)
			raise_pack_error("JstpPackGetColNum call error");
		return true;
	}

	bool GetColInfo(jstp_field_info_t *ColInfo, size_t ColInfoSize)
	{
		if (JstpPackGetColInfo(m_hPack, ColInfo, ColInfoSize) != JSTP_OK)
			raise_pack_error("JstpPackGetColInfo call error");
		return true;
	}

	bool GetValue(const char *KeyName, char &Value)
	{
		if (JstpPackGetValueChar(m_hPack, KeyName, &Value) != JSTP_OK)
			raise_pack_error("JstpPackGetValueChar call error");
		return true;
	}

	bool GetValue(const char *KeyName, int &Value)
	{
		if (JstpPackGetValueInt(m_hPack, KeyName, &Value) != JSTP_OK)
			raise_pack_error("JstpPackGetValueInt call error");
		return true;
	}

	bool GetValue(const char *KeyName, jstp_uint32_t &Value)
	{
		if (JstpPackGetValueInt(m_hPack, KeyName, (jstp_int32_t *)&Value) != JSTP_OK)
			raise_pack_error("JstpPackGetValueInt call error");
		return true;
	}

	bool GetValue(const char *KeyName, jstp_int64_t &Value)
	{
		if (JstpPackGetValueInt64(m_hPack, KeyName, &Value) != JSTP_OK)
			raise_pack_error("JstpPackGetValueInt64 call error");
		return true;
	}

	bool GetValue(const char *KeyName, jstp_uint64_t &Value)
	{
		if (JstpPackGetValueInt64(m_hPack, KeyName, (jstp_int64_t *)&Value) != JSTP_OK)
			raise_pack_error("JstpPackGetValueInt64 call error");
		return true;
	}

	bool GetValue(const char *KeyName, double &Value)
	{
		if (JstpPackGetValueDouble(m_hPack, KeyName, &Value) != JSTP_OK)
			raise_pack_error("JstpPackGetValueDouble call error");
		return true;
	}

	bool GetValue(const char *KeyName, char *Value, size_t ValueSize)
	{
		if (JstpPackGetValueStr(m_hPack, KeyName, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackGetValueStr call error");
		return true;
	}

	bool GetValue(const char *KeyName, void *Value, size_t ValueSize)
	{
		if (JstpPackGetValueByte(m_hPack, KeyName, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackGetValueByte call error");
		return true;
	}

	bool GetValue(const char *KeyName, void **Value, size_t *ValueSize)
	{
		if (JstpPackGetValueBytePointer(m_hPack, KeyName, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackGetValueBytePointer call error");
		return true;
	}

	bool GetValuePack(const char *KeyName, void *Value, size_t ValueSize)
	{
		if (JstpPackGetValuePack(m_hPack, KeyName, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackGetValuePack call error");
		return true;
	}

	bool GetValuePack(const char *KeyName, void **Value, size_t *ValueSize)
	{
		if (JstpPackGetValuePackPointer(m_hPack, KeyName, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackGetValuePackPointer call error");
		return true;
	}

	/* 结果集处理 */
	// 结果集打包
	bool RsCreate(const char *RsName, const char *ColInfo)
	{
		if (JstpPackRsCreate(m_hPack, RsName, ColInfo) != JSTP_OK)
			raise_pack_error("JstpPackRsCreate call error");
		return true;
	}

	bool RsSave()
	{
		if (JstpPackRsSave(m_hPack) != JSTP_OK)
			raise_pack_error("JstpPackRsSave call error");
		return true;
	}

	bool RsAddRow()
	{
		if (JstpPackRsAddRow(m_hPack) != JSTP_OK)
			raise_pack_error("JstpPackRsAddRow call error");
		return true;
	}

	bool RsSetColByName(const char *ColName, char Value)
	{
		if (JstpPackRsSetColByNameChar(m_hPack, ColName, Value) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByNameChar call error");
		return true;
	}

	bool RsSetColByName(const char *ColName, int Value)
	{
		if (JstpPackRsSetColByNameInt(m_hPack, ColName, Value) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByNameInt call error");
		return true;
	}

	bool RsSetColByName(const char *ColName, jstp_int64_t Value)
	{
		if (JstpPackRsSetColByNameInt64(m_hPack, ColName, Value) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByNameInt64 call error");
		return true;
	}

	bool RsSetColByName(const char *ColName, double Value)
	{
		if (JstpPackRsSetColByNameDouble(m_hPack, ColName, Value) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByNameDouble call error");
		return true;
	}

	bool RsSetColByName(const char *ColName, const char *Value)
	{
		if (JstpPackRsSetColByNameStr(m_hPack, ColName, Value) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByNameStr call error");
		return true;
	}

	bool RsSetColByName(const char *ColName, const void *Value, size_t ValueSize)
	{
		if (JstpPackRsSetColByNameByte(m_hPack, ColName, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByNameByte call error");
		return true;
	}

	bool RsSetColByNamePack(const char *ColName, const void *Value, size_t ValueSize)
	{
		if (JstpPackRsSetColByNamePack(m_hPack, ColName, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByNamePack call error");
		return true;
	}

	bool RsSetColByIndex(jstp_uint32_t ColIndex, char Value)
	{
		if (JstpPackRsSetColByIndexChar(m_hPack, ColIndex, Value) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByIndexChar call error");
		return true;
	}

	bool RsSetColByIndex(jstp_uint32_t ColIndex, int Value)
	{
		if (JstpPackRsSetColByIndexInt(m_hPack, ColIndex, Value) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByIndexInt call error");
		return true;
	}

	bool RsSetColByIndex(jstp_uint32_t ColIndex, jstp_int64_t Value)
	{
		if (JstpPackRsSetColByIndexInt64(m_hPack, ColIndex, Value) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByIndexInt64 call error");
		return true;
	}

	bool RsSetColByIndex(jstp_uint32_t ColIndex, double Value)
	{
		if (JstpPackRsSetColByIndexDouble(m_hPack, ColIndex, Value) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByIndexDouble call error");
		return true;
	}

	bool RsSetColByIndex(jstp_uint32_t ColIndex, char *Value)
	{
		if (JstpPackRsSetColByIndexStr(m_hPack, ColIndex, Value) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByIndexStr call error");
		return true;
	}

	bool RsSetColByIndex(jstp_uint32_t ColIndex, void *Value, size_t ValueSize)
	{
		if (JstpPackRsSetColByIndexByte(m_hPack, ColIndex, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByIndexByte call error");
		return true;
	}

	bool RsSetColByIndexPack(jstp_uint32_t ColIndex, void *Value, size_t ValueSize)
	{
		if (JstpPackRsSetColByIndexPack(m_hPack, ColIndex, Value, ValueSize) != JSTP_OK)
			raise_pack_error("JstpPackRsSetColByIndexPack call error");
		return true;
	}

	bool RsSaveRow()
	{
		if (JstpPackRsSaveRow(m_hPack) != JSTP_OK)
			raise_pack_error("JstpPackRsSaveRow call error");
		return true;
	}

	// 结果集解包
	bool RsNext()
	{
		return (JstpPackRsNext(m_hPack) == JSTP_OK);
	}

	bool RsGetName(char *RsName, size_t NameSize)
	{
		if (JstpPackRsGetName(m_hPack, RsName, NameSize) != JSTP_OK)
			raise_pack_error("JstpPackRsGetName call error");
		return true;
	}

	bool RsGetColNum(size_t *ColNum)
	{
		if (JstpPackRsGetColNum(m_hPack, ColNum) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColNum call error");
		return true;
	}

	bool RsGetColInfo(jstp_field_info_t *ColInfo, size_t ColInfoSize)
	{
		if (JstpPackRsGetColInfo(m_hPack, ColInfo, ColInfoSize) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColInfo call error");
		return true;
	}

	bool RsFetchRow()
	{
		return (JstpPackRsFetchRow(m_hPack) == JSTP_OK);
	}

	bool RsGetColByName(const char *ColName, char &Value)
	{
		if (JstpPackRsGetColByNameChar(m_hPack, ColName, &Value) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByNameChar call error");
		return true;
	}

	bool RsGetColByName(const char *ColName, int &Value)
	{
		if (JstpPackRsGetColByNameInt(m_hPack, ColName, &Value) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByNameInt call error");
		return true;
	}

	bool RsGetColByName(const char *ColName, jstp_int64_t &Value)
	{
		if (JstpPackRsGetColByNameInt64(m_hPack, ColName, &Value) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByNameInt64 call error");
		return true;
	}

	bool RsGetColByName(const char *ColName, double &Value)
	{
		if (JstpPackRsGetColByNameDouble(m_hPack, ColName, &Value) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByNameDouble call error");
		return true;
	}

	bool RsGetColByName(const char *ColName, char *Value, size_t Size)
	{
		if (JstpPackRsGetColByNameStr(m_hPack, ColName, Value, Size) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByNameStr call error");
		return true;
	}

	bool RsGetColByName(const char *ColName, void **Value, size_t &Size)
	{
		if (JstpPackRsGetColByNameByte(m_hPack, ColName, Value, &Size) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByNameByte call error");
		return true;
	}

	bool RsGetColByNamePack(const char *ColName, void **Value, size_t &Size)
	{
		if (JstpPackRsGetColByNamePack(m_hPack, ColName, Value, &Size) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByNamePack call error");
		return true;
	}

	bool RsGetColByIndex(jstp_uint32_t ColIndex, char &Value)
	{
		if (JstpPackRsGetColByIndexChar(m_hPack, ColIndex, &Value) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByIndexChar call error");
		return true;
	}

	bool RsGetColByIndex(jstp_uint32_t ColIndex, int &Value)
	{
		if (JstpPackRsGetColByIndexInt(m_hPack, ColIndex, &Value) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByIndexInt call error");
		return true;
	}

	bool RsGetColByIndex(jstp_uint32_t ColIndex, jstp_int64_t &Value)
	{
		if (JstpPackRsGetColByIndexInt64(m_hPack, ColIndex, &Value) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByIndexInt64 call error");
		return true;
	}

	bool RsGetColByIndex(jstp_uint32_t ColIndex, double &Value)
	{
		if (JstpPackRsGetColByIndexDouble(m_hPack, ColIndex, &Value) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByIndexDouble call error");
		return true;
	}

	bool RsGetColByIndex(jstp_uint32_t ColIndex, char *Value, size_t Size)
	{
		if (JstpPackRsGetColByIndexStr(m_hPack, ColIndex, Value, Size) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByIndexStr call error");
		return true;
	}

	bool RsGetColByIndex(jstp_uint32_t ColIndex, void **Value, size_t &Size)
	{
		if (JstpPackRsGetColByIndexByte(m_hPack, ColIndex, Value, &Size) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByIndexByte call error");
		return true;
	}

	bool RsGetColByIndexPack(jstp_uint32_t ColIndex, void **Value, size_t &Size)
	{
		if (JstpPackRsGetColByIndexPack(m_hPack, ColIndex, Value, &Size) != JSTP_OK)
			raise_pack_error("JstpPackRsGetColByIndexPack call error");
		return true;
	}

public:
	void raise_pack_error(const char* szPrefix)
	{
		std::string strError(szPrefix);
		strError += ": ";
		strError += GetErrorMsg();
		throw std::runtime_error(strError);
	}

public:
	bool GetPacketStrView(void* Data, size_t PackLen, void** PackView, size_t* PackViewSize)
	{
		if (JstpPackGetPacketStrView(m_hPack, Data, PackLen, PackView, PackViewSize) != JSTP_OK)
			raise_pack_error("JstpPackGetPacketStrView call error");
		return true;
	}

	/* 错误信息 */
	// 错误代码
	jstp_int_t GetErrorCode()
	{
		return JstpPackGetErrorCode(m_hPack);
	}

	// 错误信息
	const char *GetErrorMsg()
	{
		return JstpPackGetErrorMsg(m_hPack);
	}

private:
	bool m_bUseExtFlag;
	jstp_handle_api_t m_hPack;
};

#endif
