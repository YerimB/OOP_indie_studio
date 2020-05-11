cmake_minimum_required(VERSION 3.11)
project(bomberman)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


# Add .lib files
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Add source files
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/Sources/*.cpp)
	
# Add header files
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/Headers/*.h
    ${CMAKE_SOURCE_DIR}/Headers/*.hpp)

include_directories(
    ${CMAKE_BINARY_DIR}/Headers
    ${CMAKE_BINARY_DIR}/includes)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})


if (WIN32)

# Find Irrlicht on Windows
find_package(IRRLICHT REQUIRED)
message(STATUS "Irrlicht included at ${IRRLICHT_INCLUDE_DIR}")
set(LIBS opengl32 IRRLICHT)

ELSE()

# Find Irrlicht on Linux
find_library(IRRLICHT_LIBRARY irrlicht)
set(LIBS GL GLEW X11 Xxf86vm Xext IRRLICHT_LIBRARY)

ENDIF()

target_link_libraries(${PROJECT_NAME} ${LIBS})
