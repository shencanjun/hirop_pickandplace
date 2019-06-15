#include "cpp_loader.h"

using namespace hirop_pickPlace;

CppLoader::CppLoader(){
    //this->loader = HPluginLoader::getLoader();
}

IGenerator* CppLoader::loadGenerator(std::string generatorName,std::string path){

    HPlugin *plugin;
    HPluginLoader *loaderg;
    loaderg = HPluginLoader::getLoader();
    //int ret = loaderg->setPath("/home/shen/hirop/install_libs/");
    loaderg->setPath(path);
    plugin = loaderg->load(generatorName);
    if(plugin == NULL)
        return NULL;
    return plugin->instance<IGenerator>();
}

IPickPlace* CppLoader::loadPickPlace(std::string PickPlaceName,std::string path){
    HPlugin *plugin;
    HPluginLoader *loaderp;
    loaderp = HPluginLoader::getLoader();
    //int ret = loaderp->setPath("/home/shen/catkin_ws/devel/lib/");
    loaderp->setPath(path);
    plugin = loaderp->load(PickPlaceName);
    if(plugin == NULL)
        return NULL;

    return plugin->instance<IPickPlace>();
}

IGrabOperation* CppLoader::loadGripper(std::string gripperName, std::string path)
{
    HPlugin *plugin;
    HPluginLoader *loaderp;
    loaderp = HPluginLoader::getLoader();
    loaderp->setPath(path);
    plugin = loaderp->load(gripperName);
    if(plugin == NULL)
        return NULL;
    return plugin->instance<IGrabOperation>();
}

