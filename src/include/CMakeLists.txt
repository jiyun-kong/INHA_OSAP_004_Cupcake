#INHA_OSAP_004_Cupcake/src/include/CMakeLists.txt

file(GLOB_RECURSE SRC "*.cpp" "*.c" "*.cc") #add all source files in this folder to keyword "${SRC}"

add_library(AvlTreeLibrary STATIC ${SRC}) #make a cmake Library named "AvlTreeLibrary"