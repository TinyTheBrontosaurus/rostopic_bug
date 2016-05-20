#include <ros/ros.h>
#include <bug_report/SimpleMessage.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "super_simple_name");
    ros::NodeHandle nh;

    ros::Publisher mPublisher = nh.advertise<bug_report::SimpleMessage>("simple_topic", 1000);

    ros::Rate rate(1);

    for(int i = 0; i < 1000; i++) {
        rate.sleep();
        ROS_INFO("%d", i);
    }

    ROS_INFO("Done");
}
