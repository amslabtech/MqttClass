cmake_minimum_required(VERSION 2.0)
project(mqttclass)

set(CMAKE_CXX_FLAGS "-O2 -std=c++11 -Wall")

add_executable(mqttclass_talker src/talker.cpp)
add_executable(mqttclass_listener src/listener.cpp)
target_link_libraries(mqttclass_talker mosquitto)
target_link_libraries(mqttclass_listener mosquitto)

INSTALL(
	TARGETS mqttclass_talker mqttclass_listener
	EXPORT ${PROJECT_NAME}-export
	RUNTIME DESTINATION bin/${PROJECT_NAME}
)

INSTALL(
	EXPORT ${PROJECT_NAME}-export
	FILE ${PROJECT_NAME}-config.cmake
	DESTINATION share/cmake/${PROJECT_NAME}
)

