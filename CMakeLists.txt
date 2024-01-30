cmake_minimum_required(VERSION 3.0.0)
project(CSproject VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


add_executable(CSproject main.cpp)
add_subdirectory(src)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

target_link_libraries(${PROJECT_NAME} PUBLIC additional_functions)
target_link_libraries(${PROJECT_NAME} PUBLIC WeaponAndListOfWeapon)
target_link_libraries(${PROJECT_NAME} PUBLIC ListOfWeapon) 
target_link_libraries(${PROJECT_NAME} PUBLIC PlayerAndList)
target_include_directories(${PROJECT_NAME} PUBLIC additional_functions)
