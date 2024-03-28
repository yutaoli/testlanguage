/*
Copyright (c) 2023 Shenzhen Kingdom Co. Ltd.
All rights reserved
*/

#include <string>
#include <kgbp_lbmapi.h>
#include <stdio.h>
#include <jstp_pack.h>

extern "C" LBMEXPORTS void* LBMLog(void* pCA)
{
  void* dbmanager = nullptr;
  kgbp_handle_t handle = kgbp_lbm_init(pCA);
  if (!handle) {
    return nullptr;
  }
  int as_index = -1;
  int len;
  char lbmname[16];
  len = sizeof(lbmname);
  kgbp_get_options(handle, OPT_GET_LBM_NAME, lbmname, &len);
  kgbp_system(handle, OPT_GET_AS_INDEX, &as_index, &len);
  char msg[256];
  snprintf(msg, sizeof(msg), "as %d lbmname=%s writelog", as_index, lbmname);
  printf("%s\n", msg);
  kgbp_lbm_write_log(handle, 1, 0, msg);

  int level;
  kgbp_get_options(handle, OPT_LOG_LEVEL, &level, &len);
  printf("bizlog level = %d\n", level);

  jstp_handle_api_t pkt_hdl = kgbp_get_packet_handle(handle);
  JstpPackBeginWrite(pkt_hdl);
  JstpPackSetValueInt(pkt_hdl, "CODE", 0);
  JstpPackSetValueInt(pkt_hdl, "LEVEL", level);
  JstpPackSetValueStr(pkt_hdl, "MSG", "SUCCESS");

  kgbp_lbm_exit(handle);
  return nullptr;
}

extern "C" LBMEXPORTS void* LBMEmpty(void* pCA)
{
  kgbp_handle_t handle = kgbp_lbm_init(pCA);
  if (!handle) {
    return nullptr;
  }
  jstp_handle_api_t pkt_hdl = kgbp_get_packet_handle(handle);

  kgbp_set_lbm_err(handle, 0, 0, "OK");
  kgbp_lbm_exit(handle);  
  return nullptr;
}

extern "C" LBMEXPORTS void* ExitHold(void* pCA)
{
  kgbp_handle_t handle = kgbp_lbm_init(pCA);
  if (!handle) {
    return nullptr;
  }
  jstp_handle_api_t pkt_hdl = kgbp_get_packet_handle(handle);

  kgbp_set_lbm_err(handle, 111, 1, "err");
  int value = 1;
  kgbp_set_options(handle, OPT_EXIT_HOLD_HANLDE, &value, sizeof(value));
  kgbp_lbm_exit(handle);  

  int as_index = -1;
  int len;
  char lbmname[16];
  len = sizeof(lbmname);
  kgbp_get_options(handle, OPT_GET_LBM_NAME, lbmname, &len);
  kgbp_system(handle, OPT_GET_AS_INDEX, &as_index, &len);
  char msg[256];
  printf("ExitHold end--------");
  snprintf(msg, sizeof(msg), "as %d lbmname=%s writelog", as_index, lbmname);
  printf("%s\n", msg);
  kgbp_lbm_write_log(handle, 1, 0, msg);
  value = 0;
  kgbp_set_options(handle, OPT_EXIT_HOLD_HANLDE, &value, sizeof(value));
  kgbp_lbm_exit(handle);  
  
  return nullptr;
}


extern "C" LBMEXPORTS void* LBMRmSend(void* pCA)
{
  kgbp_handle_t handle = kgbp_lbm_init(pCA);
  if (!handle) {
    return nullptr;
  }
  jstp_handle_api_t pkt_hdl = kgbp_get_packet_handle(handle);

  JstpPackBeginWrite(pkt_hdl);
  JstpPackSetValueInt(pkt_hdl, "CODE", 0);
  JstpPackSetValueStr(pkt_hdl, "MSG", "OK");
  kgbp_rm_send(handle, 1, (void*)"123456789", 9);  // kgbp_conf.xml里配置的第二个access
  kgbp_rm_send(handle, -1, (void*)"123456789", 9); // -1是内部IPC应答队列
  kgbp_rm_send(handle, 111, (void*)"123456789", 9); // 无效access下标，报错

  kgbp_rm_send2(handle, "2_access", (void*)"123456789", 9);
  kgbp_rm_send2(handle, "onlypub", (void*)"123456789", 9);
  kgbp_rm_send2(handle, "notexist", (void*)"123456789", 9);

  int retflag = 0;
  kgbp_set_options(handle,OPT_RETURN_FLAG, &retflag, sizeof(retflag));
  kgbp_lbm_exit(handle);
  return nullptr;
}

extern "C" LBMEXPORTS void* LBMPrint(void* pCA)
{
  kgbp_handle_t handle = kgbp_lbm_init(pCA);
  if (!handle) {
    return nullptr;
  }
#if 1

  jstp_handle_api_t pkt_hdl = kgbp_get_packet_handle(handle);
  int val1;
  char val2[1024];

  JstpPackGetValueInt(pkt_hdl, "para1", &val1);
  JstpPackGetValueStr(pkt_hdl, "para2", val2, sizeof(val2));
  printf("val1:%d val2:%s\n", val1, val2);  

  JstpPackBeginWrite(pkt_hdl);
  JstpPackRsCreate(pkt_hdl, "MESSAGE", "LEVEL,CODE,MSG");
  JstpPackRsAddRow(pkt_hdl);
  JstpPackRsSetColByNameInt(pkt_hdl, "LEVEL", 1111);

  JstpPackRsSetColByNameInt(pkt_hdl, "CODE", 1111);
  JstpPackRsSetColByNameStr(pkt_hdl, "MSG", "msgreturned");
  JstpPackRsSaveRow(pkt_hdl);
  JstpPackRsSave(pkt_hdl);
#endif

  int retflag = 1;
  kgbp_set_options(handle,OPT_RETURN_FLAG, &retflag, sizeof(retflag));
printf("!!!!!!!lbmexit------\n");
  kgbp_lbm_exit(handle);  

  return nullptr;
}

extern "C" LBMEXPORTS void* LBMCore(void* pCA)
{
  kgbp_handle_t handle = kgbp_lbm_init(pCA);
  if (!handle) {
    return nullptr;
  }
  int* p = (int*)0x20;
  *p = 1;
  return nullptr;
}