// #include "ros/ros.h"
// #include "perception_msgs/Matrix.h"
// #include "RosNodeBase.h"
// #include <vector>
// #include "Eigen/Dense"
// #include <message_filters/subscriber.h>
// #include <message_filters/time_synchronizer.h>
// #include <message_filters/sync_policies/approximate_time.h>
// #include"perception_msgs/SyncedImg.h"

// class Decision : public RosNodeBase
// {
// public:
//   Decision(const ros::M_string &remappings, const std::string &nodeName) : RosNodeBase(remappings, nodeName)
//   {
//     nh->param<std::string>("perception_data", perception_topic, "/perception_data");
//     perception_sub = nh->subscribe(perception_topic, 10, &Decision::decision_callback, this);

//     // nh->param<std::string>("synced_imgae",synced_image_topic,"/airsim/synced_image");
//     // perception_sub = nh->subscribe(synced_image_topic,10)
//   }

//   void run()
//   {
//     ros::spin();
//   }

// private:
//   std::string synced_image_topic;
//   message_filters::Subscriber<perception_msgs::Matrix> synced_image_sub;
//   // std::string perception_topic;
//   // message_filters::Subscriber<perception_msgs::SyncedImg> perception_sub;
//   ros::Publisher downstream;
//   int target_id = 1;
//   int target_type = 15;

//   void decision_callback(const perception_msgs::Matrix &matrix)
//   {
//     ROS_INFO("decision call back");
//     std::vector<perception_msgs::Row> filtered_target = find_target(matrix);
//     get_3D_point(filtered_target);
//   }

//   std::vector<perception_msgs::Row> find_target(const perception_msgs::Matrix &matrix)
//   {
//     std::vector<perception_msgs::Row> results;
//     for (const auto &row : matrix.matrix)
//     {
//       if (int(row.data[4]) == target_id)
//       {
//         results.push_back(row);
//       }
//     }
//     return results;
//   }

//   std::vector<Eigen::Vector3d> get_3D_point(std::vector<perception_msgs::Row> &filtered_target)
//   {
//     std::vector<Eigen::Vector3d> results; 
//     if (filtered_target.empty())return results;   
//     for (auto data : filtered_target)
//     {
//       ROS_INFO("VALUE [%f]",data.data[0]);
//     }
//     return results;
//   }
// };

int main(int argc, char **argv)
{
  // Decision decision(ros::M_string(), "decision_node");
  // decision.run();
  return 0;
}