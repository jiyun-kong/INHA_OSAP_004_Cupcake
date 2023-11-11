#INHA_OSAP_004_Cupcake/src/tests/CMakeLists.txt

add_executable(unitTest test.cpp)
target_include_directories(unitTest PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
target_link_libraries(unitTest PUBLIC AvlTreeLibrary)