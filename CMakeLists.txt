project(http_requests)
cmake_minimum_required(VERSION 3.0)
set(restclient "/usr/include/restclient-cpp/")

include_directories( ${restclient} /usr/local/include ../restclient-cpp/include ../restclient-cpp/source ../restclient-cpp jsoncpp-0.10.5/dist)

find_library(rest restclient-cpp "/usr/local/lib/")

link_directories(${Boost_LIBRARY_DIRS} ${rest} )
FIND_PACKAGE( Boost 1.55.0 COMPONENTS log program_options system filesystem thread REQUIRED )

set(SOURCE_FILES main.cpp settings.cpp settings.h)
add_executable(http_requests ${SOURCE_FILES} jsoncpp-0.10.5/dist/jsoncpp.cpp)

TARGET_LINK_LIBRARIES( http_requests ${Boost_LIBRARIES} ${rest} curl pthread rt )


add_custom_command(TARGET http_requests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/config.ini ${CMAKE_CURRENT_BINARY_DIR}/config.ini)
