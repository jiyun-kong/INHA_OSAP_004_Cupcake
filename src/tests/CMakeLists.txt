# Copyright 2023 CUPCAKE Team, Inha Univ 
# released under GPL 3.0 License
# Contributor of this file : SungraeKim (23/11/11), JiyunKong (23/11/13)
# INHA_OSAP_004_Cupcake/src/tests/CMakeLists.txt

find_package(GTest REQUIRED)
add_executable(unitTest test.cpp)
target_include_directories(unitTest PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
target_link_libraries(unitTest PUBLIC AvlTreeLibrary GTest::GTest GTest::Main)
