#include "testplugin.h"
#include <iostream>

void TestPlugin::onEnable(const PluginInstance& plugin)
{
    qInfo() << "======= HELLO FROM TEST PLUGIN =======";
    qInfo() << plugin.id();
}

void TestPlugin::onDisable(const PluginInstance& plugin)
{
    qInfo() << "======= BYE FROM TEST PLUGIN =======";
}
