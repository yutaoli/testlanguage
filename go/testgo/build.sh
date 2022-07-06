#!/bin/bash
bin="testgo.exe"

argv0=$0 # 文件名
argv1=$1 # 第一个参数
argc=$# # 参数个数

ROOT="/root/project_code/go"
#export GOROOT="/usr/lib/golang/"
export GOPATH="$ROOT/testgo"

#set CGO_ENABLED=0  // 禁用CGO
#set GOOS=linux  // 目标平台是linux
#set GOARCH=x86_64  // 目标处理器架构是amd64

#默认，不带参数
if [ $argc -eq 0 ]; then
	go build
	exit 0
fi

# push到外网
if [ ${argv1} = "push" ]; then
 scp -r $bin yutaoli_23_133_1_120:/data/project/testgo
else 
 echo "Usage:$argv0"
 echo "      $argv0 push"
fi
