#include "ros/ros.h"
#include "perception_msgs/Matrix.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "yolo_data_publisher");
    ros::NodeHandle n;

    // 创建发布者
    ros::Publisher yolo_pub = n.advertise<perception_msgs::Matrix>("/perception_data", 10);

    ros::Rate loop_rate(1);  // 设置发布频率为1Hz
    
    float test_data[2][7] = {{6.8569e+02, 5.8536e+01, 9.3665e+02, 4.7713e+02, 1.0000e+00, 9.3087e-01, 1.5000e+01},
                             {1.7559e+02, 1.9192e+01, 3.9366e+02, 4.8310e+02, 2.0000e+00, 9.1360e-01, 1.6000e+01},
                            };

    while (ros::ok())
    {
        perception_msgs::Matrix yolo_data;

        // 假设我们将YOLO检测结果以一个简单的3x3矩阵形式存储
        yolo_data.matrix;  // 矩阵3x3，所以大小为9

        // 填充YOLO测试数据 (这里用简单的数字模拟检测数据)
        yolo_data.matrix={{1,2,3,4},{5,6,7,8}};

        // 发布消息
        yolo_pub.publish(yolo_data);

        ROS_INFO("YOLO data published!");

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

