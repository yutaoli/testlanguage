#include <string.h>

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include "KGBPCli.h"
using namespace std;
using namespace std::chrono;

// 连接成功的回调函数
void KGBPCLI_STDCALL OnConn(void* apClient) {
  void* pUserData = KGBPCli_GetUserData(apClient);
  cout << "连接建立成功" << endl;
}

// 连接断开的回调函数
void KGBPCLI_STDCALL OnDisConn(void* apClient) {
  void* pUserData = KGBPCli_GetUserData(apClient);
  cout << "连接断开" << endl;
}

// 日志回调函数。KGBPCli里面要写的日志会调用该函数
void KGBPCLI_STDCALL OnLoggerLbmTest(void* apClient, int8_t nLogLevel,
                                     const char* szLogMsg) {
  char szLogLevel[][32] = {"NULL",  "FATAL", "ERROR", " WARN",
                           " INFO", "DEBUG", "TRACE"};

  void* pUserData = KGBPCli_GetUserData(apClient);
  cout << "Client:" << apClient
       << " 收到日志 日志级别为:" << szLogLevel[nLogLevel]
       << " 日志内容:" << szLogMsg << endl;
}

int LbmTest(char* gw_ip, int gw_port) {
  /* step 1 初始化句柄 */
  void* hClient = KGBPCli_Init();
  if (NULL == hClient) {
    cout << "初始化客户端调用句柄失败" << endl;
    return 1;
  }

  /* step 2 注册回调接口(可选) */
  KGBPCliHandler objHandler;
  objHandler.OnConn = OnConn;
  objHandler.OnDisconn = OnDisConn;
  objHandler.OnLogger = OnLoggerLbmTest;
  objHandler.OnMsg = NULL;

  KGBPCli_RegisterHandler(hClient, &objHandler);

  /* step 3 设置心跳超时（可选） */
  uint32_t nHBInterval = 5000;
  uint32_t nHBTimeout = 10000;
  if (0 != KGBPCli_SetOption(hClient, KGBPCLI_OPTION_HEARTBEAT_INTERVAL,
                             &nHBInterval, sizeof(nHBInterval)) ||
      0 != KGBPCli_SetOption(hClient, KGBPCLI_OPTION_HEARTBEAT_TIMEOUT,
                             &nHBTimeout, sizeof(nHBTimeout))) {
    cout << "设置心跳发送间隔与超时时间失败 错误码:"
         << KGBPCli_GetErrorCode(hClient)
         << "错误信息:" << KGBPCli_GetErrorMsg(hClient) << endl;
    return 3;
  }

  /*  step 4 连接服务器 */
  // 同步连接
  if (0 != KGBPCli_StartX(hClient, gw_ip, gw_port, 10000)) {
    cout << "业务同步调用连接服务器失败 错误码:"
         << KGBPCli_GetErrorCode(hClient)
         << "错误信息:" << KGBPCli_GetErrorMsg(hClient) << endl;
    return 4;
  }

  /*  step 6 BeginWrite */
  if (0 != KGBPCli_BeginWrite(hClient)) {
    cout << "业务同步调用开始设置入参失败 错误码:"
         << KGBPCli_GetErrorCode(hClient)
         << "错误信息:" << KGBPCli_GetErrorMsg(hClient) << endl;
    return 6;
  }

  /*  step 7 SetOption。服务名必须设置 */
  if (0 != KGBPCli_SetOption(hClient, KGBPCLI_OPTION_SERVICE_NAME, "fs-oms",
                             strlen("fs-oms"))) {
    cout << "业务同步调用设置KGBPCLI_OPTION_SERVICE_NAME失败 错误码:"
         << KGBPCli_GetErrorCode(hClient)
         << "错误信息:" << KGBPCli_GetErrorMsg(hClient) << endl;
    return 7;
  }

  uint32_t nodeid = 1;
  if (0 != KGBPCli_SetOption(hClient, KGBPCLI_OPTION_NODE_ID, &nodeid,
                             sizeof(nodeid))) {
    cout << "业务同步调用设置KGBPCLI_OPTION_SERVICE_NAME失败 错误码:"
         << KGBPCli_GetErrorCode(hClient)
         << "错误信息:" << KGBPCli_GetErrorMsg(hClient) << endl;
    return 8;
  }

  /*  step 8 设置业务入参 */
  if (0 != KGBPCli_SetValueStr(hClient, "param", "this is test")) {
    cout << "业务同步调用设置入参失败 错误码:" << KGBPCli_GetErrorCode(hClient)
         << "错误信息:" << KGBPCli_GetErrorMsg(hClient) << endl;
    return 9;
  }

  /*  step 9 发起业务调用*/
  if (0 != KGBPCli_CallProgram(hClient, "testreturn", 30 * 1000)) {
    cout << "业务同步调用失败 错误码:" << KGBPCli_GetErrorCode(hClient)
         << "错误信息:" << KGBPCli_GetErrorMsg(hClient) << endl;
    return 10;
  }

  /*  step 10 取业务应答第一结果集 */
  int nCode, nLevel;
  char szMsg[1024];
  if (0 != KGBPCli_GetValueInt(hClient, "CODE", &nCode) ||
      0 != KGBPCli_GetValueInt(hClient, "LEVEL", &nLevel) ||
      0 != KGBPCli_GetValueStr(hClient, "MSG", szMsg, sizeof(szMsg))) {
    cout << "业务同步调用取第一结果集失败 错误码:"
         << KGBPCli_GetErrorCode(hClient)
         << "错误信息:" << KGBPCli_GetErrorMsg(hClient) << endl;
    return 11;
  }

  if (0 != nCode) {
    cout << "业务同步调用业务返回错误 错误码:" << nCode << "错误信息:" << szMsg
         << endl;
    return 12;
  }

  /*  step 11 取业务应答后续所有结果集 */
  char result[128] = {0};
  while (0 == KGBPCli_RsNext(hClient)) {
    while (0 == KGBPCli_RsFetchRow(hClient)) {
      if (0 != KGBPCli_RsGetColByIndexStr(hClient, 1, result, sizeof(result))) {
        cout << "结果集获取错误 错误码："
             << KGBPCli_GetErrorCode(hClient)
             << "错误信息：" << KGBPCli_GetErrorMsg(hClient) << endl;
        return 14;
      } else {
        cout << "获取结果信息：" << result << endl;
      }
    }
  }

  cout << "业务同步调用完成" << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(10));

  KGBPCli_Stop(hClient);
  KGBPCli_Exit(hClient);

  return 0;
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf("%s cmd gw_ip gw_port\n", argv[0]);
    printf("usage:%s 1 gw_ip gw_port---lbmtest\n", argv[0]);
    return 0;
  }
  cout << "KGBPCli_GetVersion: " << KGBPCli_GetVersion() << endl;

  int cmd = atoi(argv[1]);
  char* gw_ip = argv[2];
  int gw_port = atoi(argv[3]);

  if (cmd == 1) {
    LbmTest(gw_ip, gw_port);
  }

  return 0;
}
