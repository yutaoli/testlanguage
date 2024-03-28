add_library(${lbm_lib} SHARED)

target_sources(${lbm_lib} 
PRIVATE ${lbm_src_file}
    )

target_include_directories(${lbm_lib} 
PUBLIC ${lbm_include}
    )

target_link_libraries(${lbm_lib}
    ${lbm_link_lib}
    )

#install
install(TARGETS 
    ${lbm_lib} 
    LIBRARY 
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )
