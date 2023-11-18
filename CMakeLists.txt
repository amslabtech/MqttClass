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

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/mosquitto.hpp)

install(TARGETS mqttclass
	EXPORT mqttclass-export
	LIBRARY DESTINATION lib
	PUBLIC_HEADER DESTINATION include
)

install(EXPORT mqttclass-export
	FILE mqttclass-config.cmake
	DESTINATION share/cmake/${PROJECT_NAME}
)
