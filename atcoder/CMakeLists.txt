cmake_minimum_required(VERSION 4.0)
project(cp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(cp_atcoder INTERFACE main.hpp)
add_library(cp::atcoder ALIAS cp_atcoder)
target_include_directories(
    cp_atcoder INTERFACE ${CMAKE_SOURCE_DIR}
)

file(GLOB_RECURSE PROBLEM_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/abc/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/arc/*.cpp
)

foreach (src ${PROBLEM_SOURCES})
  file(RELATIVE_PATH rel ${CMAKE_CURRENT_SOURCE_DIR} ${src})
  string(REPLACE "/" "_" rel_with_ext ${rel})
  get_filename_component(name ${rel_with_ext} NAME_WE)

  add_executable(${name} ${src})
  target_include_directories(${name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
endforeach ()