cmake_minimum_required(VERSION 3.26)
project(Project_4_RD C)

set(CMAKE_C_STANDARD 99)

add_executable(Project_4_RD main.c HashTable.c HashTable.h Database.c Database.h
        PNBRelation.c PNBRelation.h TPNRelation.c TPNRelation.h TCRelation.c TCRelation.h GHVDRelation.c GHVDRelation.h
        GHVDLookUp.c GPGRelation.c GPGRelation.h Query.c Query.h main.h RelationalAlgebra.c RelationalAlgebra.h GHVDDelete.c)
