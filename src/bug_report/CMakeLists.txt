cmake_minimum_required(VERSION 2.8.3)

project(bug_report)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        message_generation
)

add_message_files(
        FILES
        SimpleMessage.msg
	# The Big Message breaks things. Comment out and remove devel
	# directory to fix
	BigMessage.msg
)

generate_messages(
        DEPENDENCIES
        std_msgs
)

catkin_package(
        CATKIN_DEPENDS message_runtime
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(
        super_simple
        SuperSimple.cpp )

add_dependencies(super_simple ${bug_report_EXPORTED_TARGETS})

target_link_libraries(
        super_simple
        ${catkin_LIBRARIES}
)

#############
## Install ##
#############

#############
## Testing ##
#############
