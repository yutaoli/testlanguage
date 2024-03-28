cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(test LANGUAGES CXX)

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
	#set(platform "x86")
	set(platform "linux")
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
#set(test_lib "test_test")
#file(GLOB test_src_file 
#    ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp
#    )

set(test_include 
	${CMAKE_CURRENT_LIST_DIR}/../../include
        )

find_library(kgbpcli_lib NAMES kgbpcli PATHS ${CMAKE_CURRENT_LIST_DIR}/../../lib64/${platform})
find_library(jstp_pack_lib NAMES jstp_pack PATHS ${CMAKE_CURRENT_LIST_DIR}/../../lib64/${platform})
find_library(hare_socket_lib NAMES hare_socket PATHS ${CMAKE_CURRENT_LIST_DIR}/../../lib64/${platform})

if(MSVC)
	set(test_link_lib
    	${kgbpcli_lib}
    	${jstp_pack_lib}
    	${hare_socket_lib}
    	)
else()
	set(test_link_lib
    	${kgbpcli_lib}
    	${jstp_pack_lib}
    	${hare_socket_lib}
    	pthread
    	)
endif()

#third_party lib variables

#set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/dist/${CMAKE_BUILD_TYPE}/${platform})
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/)

#bin
file(GLOB src_file "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
message(STATUS " all cpp:${src_file}")

include_directories(${test_include})

foreach(cpp ${src_file})
	message(STATUS " create bin:${cpp}")
#string(REGEX MATCHALL "([0-9A-Za-z_]*).cpp" "\\1" executable_file ${cpp})
    string(REGEX REPLACE "([:0-9A-Za-z_\/]+)\/([0-9A-Za-z_]*).cpp" "\\2" executable_file ${cpp})
    message(STATUS " executable_file:${executable_file}")

#set(connection_test KGBPCli_connection_test)
	add_executable(${executable_file} ${cpp})

	target_link_libraries(${executable_file}
	${test_link_lib}
    ) 

#install
    install(TARGETS 
        ${executable_file} 
        RUNTIME
        DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
endforeach(cpp)


message(DEBUG " PROJECT_NAME= ${PROJECT_NAME}")
message(DEBUG " test_lib= ${test_lib}")
message(DEBUG " test_include= ${test_include}")
message(DEBUG " test_src_file= ${test_src_file}")
message(DEBUG " test_link_dir= ${test_link_dir}")

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
message(DEBUG "CMAKE_CURRENT_LIST_DIR= ${CMAKE_CURRENT_LIST_DIR}")

#add_subdirectory(src)

#add_subdirectory(ringbuffer)
#add_subdirectory(exporter)
#add_subdirectory(stat)

#install
#set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/dist/${CMAKE_BUILD_TYPE}/${platform})
#set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/)
#install(TARGETS 
#    ${connection_test} 
#    RUNTIME
#    DESTINATION ${CMAKE_INSTALL_BINDIR}
#	)
