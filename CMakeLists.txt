
cmake_minimum_required(VERSION 3.0)

project("my-stdlib")

file(GLOB sources "src/*.c" "src/*.h" "src/include/*.h")
file(GLOB headers_include "src/include/*.h")
include_directories("src/include/")
add_library("my-stdlib" SHARED ${sources})
install(TARGETS "my-stdlib" DESTINATION "~/code/my-stdlib/installed/lib")
install(FILES ${headers_include}
        DESTINATION "~/code/my-stdlib/installed/include/my-stdlib")

