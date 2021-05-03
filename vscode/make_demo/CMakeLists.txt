cmake_minimum_required(VERSION 3.5)

project(Tutorial)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

configure_file(TutorialConfig.h.in TutorialConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("${PROJECT_BINARY_DIR}")
include_directories(MathFunctions)
set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)

add_subdirectory(MathFunctions)

add_executable(Tutorial main.cpp)

#target_include_directories(Tutorial PUBLIC
#        "${PROJECT_BINARY_DIR}"
#        "${PROJECT_SOURCE_DIR}/MathFunctions"
#        )
target_link_libraries(Tutorial ${EXTRA_LIBS})