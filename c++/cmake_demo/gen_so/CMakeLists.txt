cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(lbm LANGUAGES CXX)

#define variables
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

#set(conf_dir ${PROJECT_SOURCE_DIR}/../conf)
#set(doc_dir ${PROJECT_SOURCE_DIR}/../doc)

if(MSVC)
   # 添加编译选项, 设置 输入代码的编码格式为 utf-8
   add_compile_options("/source-charset:utf-8")
endif()

set(platform "arm")
if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "aarch64")
	set(platform "arm")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
	set(platform "x86")
elseif(MSVC)
	set(platform "win")
endif()

#define compiler variables
#if(MSVC AND "${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
if(MSVC)
   SET(CMAKE_CXX_FLAGS_DEBUG "/MDd /Od /Zi /MP")
   SET(CMAKE_CXX_FLAGS_RELEASE "/MD /O2 /Zi /MP")
   add_compile_options(/W3)
   add_definitions(-DWIN32_LEAN_AND_MEAN -DHARE_CPU_X64 -D_CRT_SECURE_NO_WARNINGS -DNOMINMAX)

else()
   add_compile_options(-fpermissive -w -O2)

   #SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -Wall -g ")
   #SET(CMAKE_CXX_FLAGS_RELEASE "-O2 -Wall -g ")
   #add_definitions(-DFMT_HEADER_ONLY=1)
endif()

#define lib variables
set(lbm_lib "lbm_test")
file(GLOB lbm_src_file 
    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
    )

if(MSVC)
    set(lbm_include 
        ${CMAKE_CURRENT_LIST_DIR}/include
        ${CMAKE_CURRENT_LIST_DIR}/include/jstp_pack/include
        ${CMAKE_CURRENT_LIST_DIR}/include/jstp_pack/include/win32
        )
else()
    set(lbm_include 
        ${CMAKE_CURRENT_LIST_DIR}/include
        ${CMAKE_CURRENT_LIST_DIR}/include/jstp_pack/include
        ${CMAKE_CURRENT_LIST_DIR}/include/jstp_pack/include/unix
        )
endif()

find_library(jstp_pack_lib NAMES jstp_pack PATHS ${CMAKE_CURRENT_LIST_DIR}/lib64/${platform})
find_library(kgbp_lbmapi_lib NAMES kgbp_lbmapi PATHS ${CMAKE_CURRENT_LIST_DIR}/lib64/${platform})
set(lbm_link_lib
    ${jstp_pack_lib}
    ${kgbp_lbmapi_lib}
    )

#third_party lib variables

#bin
#add_executable(${client_test_bin} client_test.cpp)

#include_directories(${yyjson_include})
message(DEBUG " PROJECT_NAME= ${PROJECT_NAME}")
message(DEBUG " lbm_lib= ${lbm_lib}")
message(DEBUG " lbm_include= ${lbm_include}")
message(DEBUG " lbm_src_file= ${lbm_src_file}")
message(DEBUG " lbm_link_dir= ${lbm_link_dir}")

message(DEBUG "CMAKE_BINARY_DIR= ${CMAKE_BINARY_DIR}")
message(DEBUG "CMAKE_INSTALL_LIBDIR= ${CMAKE_INSTALL_LIBDIR}")
message(DEBUG "CMAKE_ARCHIVE_OUTPUT_DIRECTORY= ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}")
message(DEBUG "CMAKE_LIBRARY_OUTPUT_DIRECTORY= ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")
message(DEBUG "CMAKE_RUNTIME_OUTPUT_DIRECTORY= ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(DEBUG "CMAKE_CURRENT_BINARY_DIR= ${CMAKE_CURRENT_BINARY_DIR}")
message(DEBUG "PROJECT_SOURCE_DIR= ${PROJECT_SOURCE_DIR}")
message(DEBUG "CMAKE_INSTALL_PREFIX= ${CMAKE_INSTALL_PREFIX}")
message(DEBUG "CMAKE_INSTALL_BINDIR= ${CMAKE_INSTALL_BINDIR}")
message(DEBUG "exporter_include= ${exporter_include}")
message(DEBUG "CMAKE_HOST_SYSTEM_PROCESSOR= ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(DEBUG "conf_dir= ${conf_dir}")

add_subdirectory(src)

#add_subdirectory(ringbuffer)
#add_subdirectory(exporter)
#add_subdirectory(stat)

#install
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/dist/${CMAKE_BUILD_TYPE}/${platform})
