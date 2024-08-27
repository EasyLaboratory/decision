#include"ros/ros.h"
#include"perception_msgs/Matrix.h"
#include"RosNodeBase.h"

std::ostream& operator<<(std::ostream& os, const perception_msgs::Matrix& matrix) {
    os << "Matrix(";
    for (size_t i = 0; i < matrix.matrix.size(); ++i) {
        os << "[";
        for (size_t j = 0; j < matrix.matrix[i].size(); ++j) {
            os << matrix.matrix[i][j];
            if (j < matrix.data[i].size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        if (i < matrix.data.size() - 1) {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

class Decision:public RosNodeBase{
  public:
    Decision(const ros::M_string &remappings, const std::string &nodeName):RosNodeBase(remappings,nodeName){
        nh->param<std::string>("perception_data",perception_topic,"/perception_data");
        perception_sub = nh->subscribe(perception_topic,10,&Decision::decision_callback,this);
    }

    void run(){
      ros::spin();
    }
  private:
    std::string perception_topic;
    ros::Subscriber perception_sub;
    ros::Publisher downstream;
    void decision_callback(const perception_msgs::Matrix& matrix){
         ROS_INFO("decision call back");
    }
};


int main(int argc, char **argv)
{   
    Decision decision(ros::M_string(),"decision_node");
    decision.run();
    return 0;
}