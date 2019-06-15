#include "igrab_operation.h"
#include <ros/ros.h>
#include <serial/serial.h>

#include "hsr_gripper_driver/serial_open_srv.h"
#include "hsr_gripper_driver/close_srv.h"
#include "hsr_gripper_driver/open_srv.h"
#include "hsr_gripper_driver/stop_srv.h"
#include "hsr_gripper_driver/open_size_srv.h"
#include "hsr_gripper_driver/read_open_size_srv.h"

#include "../3rd/include/hpluginloader.h"

using namespace hirop_pickPlace;

class hsr_grab_operation:public IGrabOperation{
public:
    
    hsr_grab_operation();

    int serial_open(std::string serialNo,int baudrate);

    int gripper_open_size(int grab_max,int grab_min);

    int gripper_open(int speed);

    int gripper_close(int speed, int force);

    int gripper_Stop();

    void grab_init(ros::NodeHandle n);

private:
    ros::NodeHandle n_gripper;
    ros::ServiceClient client_serialOpen;
    ros::ServiceClient client_gripperOpenSize;
    ros::ServiceClient client_gripperOpen;
    ros::ServiceClient client_gripperClose;
    ros::ServiceClient client_gripperStop;
};

H_DECLARE_PLUGIN(hirop_pickPlace::IGrabOperation)
