#pragma once

#include <QObject>
#include <QtPlugin>
#include "PluginInterface.h"

class TestPlugin : public QObject, PluginInterface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.prismlauncher.PrismLauncher.PluginInterface")
    Q_INTERFACES(PluginInterface)

public:
    void onEnable(const PluginInstance& plugin) override;
    void onDisable(const PluginInstance& plugin) override;
    bool requiresRestart() override { return false; }
};
