#set the minimum cmake version required
cmake_minimum_required(VERSION 3.16.0)

#set the name of the project
project(chess)

#enable c++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set the root source directory as include directory
include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#find Qt
find_package(Qt6 COMPONENTS Widgets REQUIRED)

#enable warning and treat them as errors
if (MSVC)
	add_compile_options(/W4 /WX /wd5054)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

#produce clang tidy file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB MAIN_SOURCES
	*.cpp
	*.h
	*.hpp
)
add_executable(chess WIN32 MACOSX_BUNDLE ${MAIN_SOURCES})
set_target_properties(chess PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(chess Qt6::Widgets Qt6::Multimedia)

#copy needed files
file(GLOB FILES
	"../resources/*"
)
file(COPY ${FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
