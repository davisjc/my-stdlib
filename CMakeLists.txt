
cmake_minimum_required(VERSION 3.0)

project("my-stdlib")

file(GLOB sources "src/*.c" "src/*.h" "src/include/my-stdlib/*.h")
file(GLOB headers_include "src/include/my-stdlib/*.h")
include_directories("src/include/")
add_library("my-stdlib" SHARED ${sources})
install(TARGETS "my-stdlib" DESTINATION "/usr/lib")
install(FILES ${headers_include}
        DESTINATION "/usr/include/my-stdlib")

