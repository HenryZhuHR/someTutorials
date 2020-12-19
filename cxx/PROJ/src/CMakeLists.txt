
add_subdirectory("./Solution")


aux_source_directory(./ DIR_SRCS)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

# ------ static
add_library(src STATIC ${DIR_SRCS})
# SET_TARGET_PROPERTIES (src_static PROPERTIES OUTPUT_NAME "src")


# ------ shared
# add_library(src SHARED ${DIR_SRCS})

message(STATUS "[INFO] SHARED linked library compiled by : " ${DIR_SRCS})

# add_subdirectory(mod2 mod2_lib)  # 新增 mod2 模块,　编译好的库置于 build/lib/mod2_lib　中
# link_directories(mod2_lib)      # 添加链接器的查找路径 build/lib/mod2_lib
# add_library(mod1 SHARED mod1.c mod1_func.c) # 生成动态库 libmod1.so
# target_link_libraries(mod1 mod2) # 将 libmod2.a 链接进入 libmod1.so 中

