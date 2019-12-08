cmake_minimum_required(VERSION 2.8)
project(mqttclass)

set(CMAKE_CXX_FLAGS "-O2 -std=c++11 -Wall")

add_executable(mqttclass_talker example/talker.cpp)
add_executable(mqttclass_listener example/listener.cpp)

target_include_directories(mqttclass_talker   
	PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_include_directories(mqttclass_listener 
	PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

target_link_libraries(mqttclass_talker mosquitto)
target_link_libraries(mqttclass_listener mosquitto)

INSTALL(
	FILES ${PROJECT_SOURCE_DIR}/include/mosquitto.hpp
	DESTINATION /usr/local/include
)

