cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 17)

project (TestProject)

include_directories(C:/include/CImg-2.2.2)

ADD_LIBRARY(LibsModule Game.cpp Game.h GameObject.h BaseGameObject.cpp BaseGameObject.h)

target_link_libraries(LibsModule -lpthread)
target_link_libraries(LibsModule -lm)
target_link_libraries(LibsModule -lX11)

add_executable(TestProject TestGame.h TestGame.cpp)

target_link_libraries(TestProject LibsModule)