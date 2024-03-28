#!/bin/sh

BOOL_OS_IS_LINUX=`uname -a |grep x86_64|wc -l`

PWD=`pwd`
if [ $BOOL_OS_IS_LINUX -eq 1 ]; then
    export HOME_LIB=$PWD/../../lib64/linux
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME_LIB
else
    export HOME_LIB=$PWD/../../lib64/arm
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME_LIB
fi
