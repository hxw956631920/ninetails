#指定运行CMake最低版本
cmake_minimum_required(VERSION 2.8)
project(ninetails)

set(CMAKE_VERBOSE_MAKEFILE OFF)

# glfw和glew的头文件目录，这是我的路径，你可以换成你自己的
# include_directories(/usr/local/Cellar/glfw/3.3.2/include/GLFW)
# include_directories(/usr/local/Cellar/glew/2.1.0_1/include/GL)
include_directories(/usr/local/include)
include_directories(./shader)
include_directories(./object)
include_directories(./event)
# 查找当前目录下的所有源文件
aux_source_directory("./" SRCS)
# 查找object子目录
add_subdirectory(object)
# 查找event子目录
add_subdirectory(event)
# 查找shader子目录
add_subdirectory(shader)

set(CMAKE_CXX_FLAGS "-g -std=c++11 -Wformat")

# glew的库目录路径
link_directories(/usr/local/Cellar/glew/2.1.0_1/lib)
# glfw的库目录路径
link_directories(/usr/local/Cellar/glfw/3.3.2/lib)
link_libraries("-framework OpenGL")
add_executable(ninetails ${SRCS} )

# 添加链接库
# 指定glew库 glfw库
target_link_libraries(ninetails GLEW GLFW)
target_link_libraries(ninetails Object Event Shader)
