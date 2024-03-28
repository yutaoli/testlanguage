#!/bin/sh
build_dir=build
rm ${build_dir} -rf
mkdir -p ${build_dir}
cd ${build_dir}

cmake -DCMAKE_BUILD_TYPE=Debug .. 
#cmake -DCMAKE_BUILD_TYPE=Release .. 

cmake --build . --target clean
cmake --build . -j${nproc}
cmake --build . --target install
#make clean && make all -j${nproc} &&make install

cmake -DCMAKE_BUILD_TYPE=Release .. 
#cmake -DCMAKE_BUILD_TYPE=Release .. 

cmake --build . --target clean
cmake --build . -j${nproc}
cmake --build . --target install

