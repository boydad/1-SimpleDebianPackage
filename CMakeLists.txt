cmake_minimum_required(VERSION 3.2)

project(helloworld)


#find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 1)
set(PROJECT_VERSIOM_BUILD $ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in version.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(helloworld main.cpp)
add_library(myDynLib SHARED myDynLib.cpp)


target_link_libraries(helloworld myDynLib)

set_target_properties(helloworld myDynLib PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

#set_target_properties(helloworld_cli PROPERTIES
#  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#)

#target_link_libraries(helloworld_cli 
#  helloworld
#)

#target_link_libraries(test_main_cli
#  ${Boost_LIBRARIES}
#  cpp01_2
#)

install(TARGETS helloworld DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION_BUILD ${PROJECT_VERSIOM_BUILD})

set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.${PROJECT_VERSIOM_BUILD}")

set(CPACK_PACKAGE_CONTACT boyda_d@mail.ru)

include(CPack)

#enable_testing()

#add_test(test_version_valid test_main_cli)
