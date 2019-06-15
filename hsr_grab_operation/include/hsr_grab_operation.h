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
    /**
     * @brief 构造函数
     */
    hsr_grab_operation();

    /**
     * @brief 夹爪初始化
     * @return
     */
    int gripper_init();

    /**
     * @brief 夹爪打开
     * @return 0，成功 -1，失败
     */
    int gripper_open();

    /**
     * @brief 夹爪关闭
     * @return
     */
    int gripper_close();

    /**
     * @brief 初始化
     * @param n 节点句柄
     */
    void grab_init(ros::NodeHandle n);

private:
    /**
     * @brief 串口打开
     * @param serialNo
     * @param baudrate
     * @return
     */
    int serial_open(std::string serialNo,int baudrate);

    /**
     * @brief 夹爪打开
     * @param speed
     * @return
     */
    int _gripper_open(int speed);

    /**
     * @brief 夹爪关闭
     * @param speed
     * @param force
     * @return
     */
    int _gripper_close(int speed, int force);

private:
    //节点句柄
    ros::NodeHandle n_gripper;
    //串口打开服务客户端
    ros::ServiceClient client_serialOpen;
    //夹爪打开打开服务客户端
    ros::ServiceClient client_gripperOpen;
    //夹爪关闭打开服务客户端
    ros::ServiceClient client_gripperClose;
};

H_DECLARE_PLUGIN(hirop_pickPlace::IGrabOperation)
