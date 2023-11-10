#INHA_OSAP_004_Cupcake/src/CMakeLists.txt

add_subdirectory(tests)
add_subdirectory(include)
add_executable(mainApp main.cpp)
target_include_directories(mainApp PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
target_link_libraries(mainApp PUBLIC AvlTreeLibrary)

