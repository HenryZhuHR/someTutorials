

aux_source_directory(./ DIR_Solution)

include_directories(${PROJECT_SOURCE_DIR}/include)


# add_library(Solution STATIC ${DIR_Solution})


set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_library(Solution SHARED ${DIR_Solution})


message(STATUS "[INFO] SHARED linked library compiled by : " ${DIR_Solution})
