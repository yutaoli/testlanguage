#!/bin/sh
#source ~/.bashrc

build_dir=build
rm ${build_dir} -rf 
mkdir -p ${build_dir}
cd ${build_dir}

#echo "\$-   : $-"
#shopt expand_aliases

cmake --version
cmake -DCMAKE_BUILD_TYPE=Debug ..  
#cmake -DCMAKE_BUILD_TYPE=Release .. 

cmake --build . --target clean
cmake --build . -j${nproc}
cmake --build . --target install
