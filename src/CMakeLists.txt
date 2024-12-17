project(Prac_prog)

set(source-files "${PROJECT_SOURCE_DIR}/prac_prog.cpp" CACHE INTERNAL "")

add_library(
        prac_prog SHARED ${source-files} ${Prac1_SOURCE_DIR}/include/prac_prog.h
)
