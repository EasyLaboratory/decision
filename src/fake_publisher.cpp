#include "ros/ros.h"
#include"std_msgs/Float32.h"
#include "perception_msgs/Matrix.h"
#include<iostream>
#include<memory>
#include<vector>

std::vector<std::vector<float>> test_data = {
    {6.8569e+02, 5.8536e+01, 9.3665e+02, 4.7713e+02, 1.0000e+00, 9.3087e-01, 1.5000e+01},
    {1.7559e+02, 1.9192e+01, 3.9366e+02, 4.8310e+02, 2.0000e+00, 9.1360e-01, 1.6000e+01},
};



class Fake_YOLO{
    public:
        Fake_YOLO(ros::NodeHandle & nh,std::vector<std::vector<float>>& test_data){
            nh.param<std::string>("fake_topic",fake_topic,"/perception_data");
            fake_topic_publisher = nh.advertise<perception_msgs::Matrix>(fake_topic,10);
            matrix = construct_perception_msg(test_data);
        }

        void run(){
           ros::Rate loop_rate(1);
           while (ros::ok())
           {
            fake_topic_publisher.publish(*matrix);
            ros::spinOnce();
            loop_rate.sleep();
           }
           
        }

        std::shared_ptr<perception_msgs::Matrix> construct_perception_msg(std::vector<std::vector<float>>& test_data)
        {
            auto matrix = std::make_shared<perception_msgs::Matrix>();
            matrix->matrix.resize(test_data.size());
            for(int i = 0; i<test_data.size();i++){
                matrix->matrix[i].data.assign(test_data[i].begin(),test_data[i].end());
            }
            return matrix;
        }
    private:
        std::string fake_topic;
        ros::Publisher fake_topic_publisher;
        std::shared_ptr<perception_msgs::Matrix> matrix;
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "yolo_data_publisher");
    ros::NodeHandle nh;

    Fake_YOLO fake_yolo(nh,test_data);
    fake_yolo.run();

    return 0;
}

