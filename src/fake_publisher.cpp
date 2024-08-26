#include "ros/ros.h"
#include "perception_msgs/Matrix.h"
#include<iostream>
#include<memory>
#include<vector>

std::vector<std::vector<float>> test_data = {
    {6.8569e+02, 5.8536e+01, 9.3665e+02, 4.7713e+02, 1.0000e+00, 9.3087e-01, 1.5000e+01},
    {1.7559e+02, 1.9192e+01, 3.9366e+02, 4.8310e+02, 2.0000e+00, 9.1360e-01, 1.6000e+01},
};

std::shared_ptr<perception_msgs::Matrix> construct_perception_msg(std::vector<std::vector<float>>& test_data)
{
    auto matrix = std::shared_ptr<perception_msgs::Matrix>();
    matrix->matrix.resize(test_data.size());
    for(int i = 0; i<test_data.size();i++){
        matrix->matrix.assign(test_data[i].begin(),test_data[i].end());
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "yolo_data_publisher");
    ros::NodeHandle n;

    // 创建发布者
    ros::Publisher yolo_pub = n.advertise<perception_msgs::Matrix>("/perception_data", 10);

    ros::Rate loop_rate(1); // 设置发布频率为1Hz

    while (ros::ok())
    {
        perception_msgs::Matrix yolo_data;
        
        yolo_pub.publish()

        ROS_INFO("YOLO data published!");

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

