cmake_minimum_required(VERSION 3.5)

project(helloworld)

#==============================
# work with version determination...
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules ${CMAKE_MODULE_PATH})
#
# Make a version file containing the current version from git.
#
include(GetGitRevisionDescription)
git_describe(VERSION --tags --dirty=-dirty)

#parse the version information into pieces.
string(REGEX REPLACE "^v([0-9]+)\\..*" "\\1" VERSION_MAJOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.([0-9]+).*" "\\1" VERSION_MINOR "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" VERSION_PATCH "${VERSION}")
string(REGEX REPLACE "^v[0-9]+\\.[0-9]+\\.[0-9]+(.*)" "\\1" VERSION_SHA1 "${VERSION}")
set(VERSION_SHORT "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}.$ENV{TRAVIS_BUILD_NUMBER}")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/version.cpp.in
                ${CMAKE_CURRENT_BINARY_DIR}/version.cpp)
set(version_file "${CMAKE_CURRENT_BINARY_DIR}/version.cpp")
#================================
# end version part

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(helloworld ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp )
add_library(myDynLib SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/myDynLib.cpp ${version_file})
add_executable(testTestableFunc ${CMAKE_CURRENT_SOURCE_DIR}/src/testTestableFunc.cpp)


target_link_libraries(helloworld myDynLib)

target_link_libraries(testTestableFunc
  ${Boost_LIBRARIES}
  myDynLib
)

set_target_properties(helloworld myDynLib testTestableFunc PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)



install(TARGETS helloworld DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION ${VERSION_SHORT})
set(CPACK_PACKAGE_CONTACT xxx@xxx.xx)

include(CPack)

enable_testing()

add_test(testTestableFunc testTestableFunc)
