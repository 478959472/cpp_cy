# CMakeList.txt: base_learn 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)


include_directories(../sylar)

set(LIB_SRC 
    ../sylar/log.cpp
    ../sylar/util.cpp
)

add_library(sylar SHARED ${LIB_SRC} "template_demo.cpp")
# 将源代码添加到此项目的可执行文件。
add_executable (base_learn "main.cpp")
add_executable (template_demo "template_demo.cpp")

target_link_libraries(base_learn sylar)

# TODO: 如有需要，请添加测试并安装目标。
