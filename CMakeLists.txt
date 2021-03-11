#指定运行CMake最低版本
cmake_minimum_required(VERSION 2.8.1)
project(ninetails)

set(CMAKE_VERBOSE_MAKEFILE OFF)

# glfw和glew的头文件目录，这是我的路径，你可以换成你自己的
# include_directories(/usr/local/Cellar/glfw/3.3.2/include/GLFW)
# include_directories(/usr/local/Cellar/glew/2.1.0_1/include/GL)
#include_directories(/usr/local/include)
include_directories(./)
# 查找当前目录下的所有源文件
aux_source_directory("./" SRCS)
# 查找window子目录
add_subdirectory(window)
# 查找object子目录
add_subdirectory(object)
# 查找event子目录
add_subdirectory(event)
# 查找shader子目录
add_subdirectory(shader)
# 查找image子目录
add_subdirectory(image)
# 查找data子目录
add_subdirectory(data)
# 查找example子目录
add_subdirectory(example)


set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wformat")

# glew的库目录路径
#LINK_DIRECTORIES(/usr/local/Cellar/glew/2.1.0_1/lib)
LINK_DIRECTORIES(./lib/glew/prebuild)
# glfw的库目录路径
#LINK_DIRECTORIES(/usr/local/Cellar/glfw/3.3.2/lib)
LINK_DIRECTORIES(./lib/glfw/prebuild)
# libpng的库目录路径
#LINK_DIRECTORIES(/usr/local/Cellar/libpng/1.6.37/lib)
LINK_DIRECTORIES(./lib/libpng/prebuild)
# libjpeg的库目录路径
LINK_DIRECTORIES(./lib/libjpeg/prebuild)


LINK_LIBRARIES("-framework OpenGL")
add_executable(ninetails ${SRCS} )

# 添加链接库
# 指定glew库 glfw库 libpng库 libjpeg库
TARGET_LINK_LIBRARIES(ninetails GLEW GLFW PNG JPEG)
TARGET_LINK_LIBRARIES(ninetails Window Object Event Shader Image Data Example)

