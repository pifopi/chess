#set the minimum cmake version required
cmake_minimum_required(VERSION 3.9.1)

#set the name of the project
project(chess)

#enable c++ 17
set(CMAKE_CXX_STANDARD 17)

#set the root source directory as include directory
include_directories(${CMAKE_SOURCE_DIR})

#find Qt
find_package(Qt5 COMPONENTS Widgets Multimedia REQUIRED)
if (Qt5Widgets_VERSION VERSION_LESS 5.10.0)
	message(SEND_ERROR "Minimum supported Qt5 version is 5.10.0!")
endif()

set(MANAGER_MOC_FILE
	HelpWindow.h
	MainWindow.h
	MenuWindow.h
	OptionWindow.h
	PlayerSelectionWindow.h
)
QT5_WRAP_CPP(MANAGER_MOC ${MANAGER_MOC_FILE})

#enable warning and treat them as errors
if(CMAKE_COMPILER_IS_GNUCC)
	set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
elseif(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
endif()

file(GLOB MAIN_SOURCES
	*.cpp
	*.h
	*.hpp
)
add_executable(main WIN32 ${MAIN_SOURCES} ${MANAGER_MOC})
set_target_properties(main PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(main Qt5::Widgets Qt5::Multimedia)

#copy needed files
file(GLOB FILES
	"../resources/*"
)
file(COPY ${FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
