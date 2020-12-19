
# -------- 3rd-party lib --------
# # -- Opencv4
# set(OpenCV_DIR "C:/Users/henryzhu/OneDrive/Programming/Cpp/CppLibrary/Opencv/mingw-build/install")
# find_package( OpenCV 4 REQUIRED )
# include_directories( ${OpenCV_INCLUDE_DIRS} )
# link_directories(${OpenCV_LIB_DIRS})
# message(STATUS "OpenCV status:")
# message(STATUS "    Opencv version: ${OpenCV_VERSION}")   
# message(STATUS "    Opencv include: ${OpenCV_INCLUDE_DIRS}")

message("----- CMAKE_BINARY_DIR:" ${PROJECT_SOURCE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) 

add_executable(${PROJECT_NAME} 
    main.cpp
    )

# 请仔细检查每一个调用的库，缺一不可！！！！！
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    src
    Solution
    )

