cmake_minimum_required(VERSION 3.15)

project(testplugin LANGUAGES CXX)

# Find Qt6 & setup it correctly
find_package(Qt6 REQUIRED COMPONENTS Core CoreTools Widgets Core5Compat)
qt_standard_project_setup()

# Declare the plugin's sources
set(PLUGIN_SOURCES
    src/testplugin.cpp
    src/testplugin.h
)

# Tell qt that we want to produce a plugin
qt_add_plugin(testplugin
    CLASS_NAME TestPlugin
    ${PLUGIN_SOURCES}
)

# Set the include library for the plugin API
target_include_directories(testplugin PRIVATE
    ../PrismLauncher/launcher/plugin/api
)

# Link some Qt libraries that might be helpfull
target_link_libraries(testplugin PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Core5Compat
)

# Install asset files
install(FILES plugin.json icon.png DESTINATION ".")
install(DIRECTORY cats DESTINATION ".")

# Install the plugin itself
install(TARGETS testplugin RUNTIME DESTINATION "." LIBRARY DESTINATION ".")
