#ifndef IGRAB_OPERATION_H
#define IGRAB_OPERATION_H
#include <iostream>
#include"../3rd/include/hplugin.h"
namespace hirop_pickPlace {
class IGrabOperation{
public:
    /**
     * @brief 夹爪初始化
     * @return 0，成功   -1，失败
     */
    virtual int gripper_init() = 0;

    /**
      * @brief 夹爪打开
      * @return 0，成功  -1，失败
      */
     virtual int gripper_open() = 0;

    /**
      * @brief 夹爪关闭
      * @return 0，成功  -1，失败
      */
     virtual int gripper_close() = 0;

     virtual ~IGrabOperation(){}
};
}
H_DECLARE_INTERFACE(hirop_pickPlace::IGrabOperation,"IGrabOperation/v1.0")
#endif // IGRAB_OPERATION_H
