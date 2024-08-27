#include <string>
#include "ros/ros.h"
#ifndef ROS_NODE_H
#define ROS_NODE_H

class RosNodeBase
{
public:
    RosNodeBase(const ros::M_string &remappings, const std::string &nodeName)
    {
        ros::init(remappings, nodeName);
        this->nh = std::make_shared<ros::NodeHandle>();
        ROS_INFO("Node[%s] initialized",nodeName.c_str());
    }

    virtual void run()=0;
    virtual ~RosNodeBase(){
        ROS_INFO("Node[%s] shut down",ros::this_node::getName().c_str());
    }

protected:
    std::shared_ptr<ros::NodeHandle> nh;
};

#endif