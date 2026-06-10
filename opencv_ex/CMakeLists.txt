cmake_minimum_required(VERSION 3.16)
project(opencv_cpp_basic)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    /usr/include/opencv4
    /usr/include/x86_64-linux-gnu/opencv4
)

file(GLOB PART1_SOURCES CONFIGURE_DEPENDS "part1/*.cpp")
file(GLOB PART2_SOURCES CONFIGURE_DEPENDS "part2/*.cpp")
file(GLOB PART1_SOURCES CONFIGURE_DEPENDS "part3/*.cpp")
foreach(SOURCE ${PART1_SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)
    add_executable(${TARGET_NAME} ${SOURCE})
    target_link_libraries(${TARGET_NAME} PRIVATE ${OpenCV_LIBS})
endforeach()

foreach(SOURCE ${PART2_SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)
    add_executable(${TARGET_NAME} ${SOURCE})
    target_link_libraries(${TARGET_NAME} PRIVATE ${OpenCV_LIBS})
endforeach()

foreach(SOURCE ${PART3_SOURCES})
    get_filename_component(TARGET_NAME ${SOURCE} NAME_WE)
    add_executable(${TARGET_NAME} ${SOURCE})
    target_link_libraries(${TARGET_NAME} PRIVATE ${OpenCV_LIBS})
endforeach()


