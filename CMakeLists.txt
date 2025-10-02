cmake_minimum_required(VERSION 3.10.0)
project(design_pattern_cpp VERSION 0.1.0 LANGUAGES C CXX)

add_executable(design_pattern_cpp main.cpp)

# Make sure the path is correct and the file exists
add_executable(Singleton SingletonPattern/Singleton.cpp)
add_executable(Observer ObserverPattern/Observer.cpp)
add_executable(ObserverExample ObserverPattern/Example/ObserverExample.cpp)
add_executable(AbstractFactory AbstractFactory/AbstractFactory.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
