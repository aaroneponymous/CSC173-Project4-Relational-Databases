cmake_minimum_required(VERSION 3.26)
project(Project_4_RD C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES main.c Database.c GHVDDelete.c GHVDLookUp.c GHVDRelation.c GPGRelation.c HashTable.c PNBRelation.c Query.c RelationalAlgebra.c TCRelation.c TPNRelation.c)

add_executable(my_project ${SOURCE_FILES})

target_compile_options(my_project PRIVATE -std=c99 -pedantic -Wall -Werror)
set_target_properties(my_project PROPERTIES OUTPUT_NAME "my_database_EXE")