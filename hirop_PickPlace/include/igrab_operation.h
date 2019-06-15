#ifndef IGRAB_OPERATION_H
#define IGRAB_OPERATION_H
#include <iostream>
#include"../3rd/include/hplugin.h"
namespace hirop_pickPlace {
class IGrabOperation{
public:
    /**
     * @brief 串口打开
     * @param 传入，串口名
     * @param 传入，波特率
     * @return 0，成功  -1，失败
     */
    virtual int serial_open(std::string serialNo,int baudrate) = 0;

    /**
      * @brief 设置夹爪打开参数
      * @param 传入，最大打开距离
      * @param 传入，最小打开距离
      * @return 0，成功  -1，失败
      */
     virtual int gripper_open_size(int grab_max,int grab_min) = 0;

    /**
      * @brief 夹爪打开
      * @param 传入,速度
      * @return 0，成功  -1，失败
      */
     virtual int gripper_open(int speed) = 0;

    /**
      * @brief 夹爪关闭
      * @param 传入，速度
      * @param 传入，力度
      * @return 0，成功  -1，失败
      */
     virtual int gripper_close(int speed, int force) = 0;

    /**
      * @brief 夹爪急停
      * @return 0，成功  -1，失败
      */
     virtual int gripper_Stop() = 0;

     virtual ~IGrabOperation(){}
};
}
H_DECLARE_INTERFACE(hirop_pickPlace::IGrabOperation,"IGrabOperation/v1.0")
#endif // IGRAB_OPERATION_H
