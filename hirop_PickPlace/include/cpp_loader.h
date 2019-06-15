#ifndef LOADER_H
#define LOADER_H
#include "igenerator.h"
#include "ipickPlace.h"
#include "igrab_operation.h"
#include "../3rd/include/hpluginloader.h"

namespace hirop_pickPlace{

class CppLoader{

public:
    CppLoader();

    /**
     * @brief       加载相关的生成器
     * @param    [trainerName] 输入，生成器的名称
     * @return      返回相关生成器的指针
     */
    IGenerator *loadGenerator(std::string generatorName,std::string path);

    /**
     * @brief       加载相关的执行器
     * @param    [trainerName] 输入，执行器的名称
     * @return      返回相关执行器的指针
     */
    IPickPlace *loadPickPlace(std::string PickPlaceName,std::string path);

    /**
      * @brief 加载相关夹爪
      * @param gripperName，输入，夹爪名
      * @param path 输入，路径
      * @return 返回相关夹爪的指针
      */
     IGrabOperation *loadGripper(std::string gripperName,std::string path);

private:
     /**
     * @brief 具体加载器
     */
    HPluginLoader *loader;
};

}
#endif // LOADER_H
