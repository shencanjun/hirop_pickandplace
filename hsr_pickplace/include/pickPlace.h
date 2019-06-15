#ifndef PICK_EXCUTE_H
#define PICK_EXCUTE_H
#include <string>
#include <ros/ros.h>
#include <moveit_msgs/Grasp.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <geometry_msgs/PoseStamped.h>
#include <moveit_msgs/GripperTranslation.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/MoveItErrorCodes.h>
#include <sstream>

#include "pickPlace_execute.h"
#include "c_base_pickPlace.h"
#include "../3rd/include/hpluginloader.h"

#define REFERENCE_FRAME "base_link"
#define PLANNER_ID "RRTstarkConfigDefault"

using namespace hirop_pickPlace;
class hsr_pickplace:public CBasePickPlace{
public:
    /**
     * @brief 构造函数
     */
    hsr_pickplace();

    /**
     * @brief 设置抓取点位置
     * @param pickPos， 输入 抓取点位置
     * @return 0，成功
     */
    int set_pick_poses(pose_vec pickPos);

    /**
     * @brief 设置放置点位置
     * @param placePos，输入  放置点位置
     * @return  0，成功
     */
    int set_place_poses(pose_vec placePos);

    /**
     * @brief 设置物体位置
     * @param object_pose，输入 物体位置
     * @return 0，成功
     */
    int set_object(geometry_msgs::Pose object_pose);

    /**
     * @brief 执行抓取
     * @return  0，成功  -1 ，失败
     */
    int pick() ;

    /**
     * @brief 执行放置
     * @return 0，成功  -1，失败
     */
    int place() ;

    /**
     * @brief 返回执行状态
     * @param status，输出，状态
     * @return 0，成功
     */
    int pickplace_freeback(std::string &status);

    /**
     * @brief 停止执行
     * @return 0,成功
     */
    int stop_pickplace() ;

private:
    /**
     * @brief 初始化
     * @return 0，成功
     */
    int _init();

    /**
     * @brief 移动到home点
     * @return 0，成功 -1，失败
     */
    int move_to_home();

    /**
     * @brief 合成抓取点
     * @return 0，成功 -1，失败
     */
    int make_grasp();

    /**
     * @brief 初始化Moveit
     * @return 0，成功 -1，失败
     */
    int moveit_init();

    /**
     * @brief 添加物体定义
     * @param object_id，输入，物体ID
     * @return 0，成功
     */
    int add_collision_object(std::string object_id);

    /**
     * @brief 添加防撞地板
     * @return 0，成功  -1，失败
     */
    int add_base_table();

    /**
     * @brief 添加场景到moveit中
     * @return 0，成功  -1，失败
     */
    int add_collision();

    /**
     * @brief 移除场景
     * @return 0，成功  -1，失败
     */
    int remove_collision();

    /**
     * @brief 绑定物体到机器人
     * @param obj_id，物体ID
     * @return  0，成功
     */
    int attach_collision(std::string obj_id);

    /**
     * @brief 解除绑定到机器人
     * @param obj_id,物体ID
     * @return 0，成功
     */
    int dettach_collision(std::string obj);

    /**
     * @brief 初始化抓取点
     * @param jiont_position
     * @return 0，成功  -1，失败
     */
    trajectory_msgs::JointTrajectory make_gripper_posture(double jiont_position);

private:
    //节点句柄
    ros::NodeHandle npick;
    //抓取点位
    pickandplace_pose _pickpose;
    //放置点位
    pickandplace_pose _placepose;
    //抓取点位数组
    pose_vec _pickposes;
    //放置点位数组
    pose_vec _placeposes;
    //停止标志位
    bool _pick_stop_flag;
    //状态
    std::string _status;
    //抓取执行点位
    std::vector<moveit_msgs::Grasp> _grasp_poses;
    //场景物体
    std::vector<moveit_msgs::CollisionObject> _collision_objects;
    //moveit对象
    moveit::planning_interface::MoveGroup  *_move_group;
    //moveit添加场景对象
    moveit::planning_interface::PlanningSceneInterface _plan_Scene;
    //存储物体ID
    std::vector<std::string> _object_ids;
    //物体点位存储
    geometry_msgs::Pose _box_pose;
};
H_DECLARE_PLUGIN(hirop_pickPlace::IPickPlace)
#endif // PICK_EXCUTE_H
