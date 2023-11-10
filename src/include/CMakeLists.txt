#INHA_OSAP_004_Cupcake/src/include/CMakeLists.txt

file(GLOB_RECURSE SRC "*.cpp" "*.c" "*.cc")

add_library(AvlTreeLibrary STATIC ${SRC})