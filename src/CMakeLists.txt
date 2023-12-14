# Copyright 2023 CUPCAKE Team, Inha Univ 
# released under GPL 3.0 License
# Contributor of this file : SungraeKim (23/11/11)

#INHA_OSAP_004_Cupcake/src/CMakeLists.txt

add_subdirectory(tests)
add_subdirectory(include)
add_executable(mainApp main.cpp)
target_include_directories(mainApp PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
target_link_libraries(mainApp PUBLIC AvlTreeLibrary)

