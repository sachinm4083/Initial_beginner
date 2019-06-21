#include "ros/ros.h"
#include<rosbag/bag.h>
#include <rosbag/view.h>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <boost/foreach.hpp>




int main()
{
  
    rosbag::Bag bag;
    bag.open("/lulllaby/rosbag/2019-06-09-01-38-30.bag", rosbag::bagmode::Read);

    std::vector<std::string> topics;
    topics.push_back(std::string("scan"));
    topics.push_back(std::string("rosout"));

    rosbag::View view(bag, rosbag::TopicQuery(topics));

    BOOST_FOREACH(rosbag::MessageInstance const m, view)
    {
        std_msgs::String::ConstPtr s = m.instantiate<std_msgs::String>();
        if (s != NULL)
            std::cout << s->data << std::endl;

        std_msgs::Int32::ConstPtr i = m.instantiate<std_msgs::Int32>();
        if (i != NULL)
            std::cout << i->data << std::endl;
    }

    bag.close();
return 0; 
}
