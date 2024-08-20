#include "ros/ros.h"
#include "perception_msgs/Matrix.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "yolo_data_publisher");
    ros::NodeHandle n;

    // 创建发布者
    ros::Publisher yolo_pub = n.advertise<perception_msgs::Matrix>("/perception_data", 10);

    ros::Rate loop_rate(1);  // 设置发布频率为1Hz

    float yolo_test_data = 

    while (ros::ok())
    {
        perception_msgs::Matrix yolo_data;

        // 假设我们将YOLO检测结果以一个简单的3x3矩阵形式存储
        yolo_data.matrix;  // 矩阵3x3，所以大小为9

        // 填充YOLO测试数据 (这里用简单的数字模拟检测数据)
        yolo_data.data[0] = 1.0;  // 假设第一个检测框的x坐标
        yolo_data.data[1] = 1.0;  // 假设第一个检测框的y坐标
        yolo_data.data[2] = 100.0;  // 假设第一个检测框的宽度
        yolo_data.data[3] = 100.0;  // 假设第一个检测框的高度
        yolo_data.data[4] = 0.9;  // 假设第一个检测框的置信度
        yolo_data.data[5] = 0.0;  // 假设第一个检测框的类别（例如：0表示"person"）
        
        yolo_data.data[6] = 2.0;  // 第二个检测框的数据...
        yolo_data.data[7] = 2.0;
        yolo_data.data[8] = 0.8;

        // 发布消息
        yolo_pub.publish(yolo_data);

        ROS_INFO("YOLO data published!");

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

