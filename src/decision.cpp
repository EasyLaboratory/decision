#include"ros/ros.h"
#include"perception_msgs/Matrix.h"

void decisionCallback(const perception_msgs::Matrix::ConstPtr& msg){
  ROS_INFO("hello");
};


int main(int argc, char **argv)
{
    ros::init(argc, argv, "perception_subscriber");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("perception_detections", 1, decisionCallback);

    ros::spin();

    return 0;
}