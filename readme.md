# Prism Test Plugin

## License

This project is licensed under GPL-3.0-only; for more see the `LICENSE` file.

## Building

You also need to optain a copy of PrismLauncher's sourcecode from https://github.com/PrismLauncher/PrismLauncher.git .

This project expects to be placed alongside PrismLauncher's sourcecode like so:
```
+ root
  + PrismLauncher => downloaded PrismLauncher sourcecode
  + TestPlugin    => this folder
```

Now you can run:
```sh
$ mkdir build
$ cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./install
```

Ofc you also can set the install prefix to a folder inside prism's plugin directory.

Plugins are loaded from:
- on Windows: `%appdata%\PrismLauncher\plugins`
- on Linux: `~/.local/share/PrismLauncher/plugins`
- on Mac: `~/Library/Application Support/PrismLauncher/plugins`
- on Flatpak: `~/.var/app/org.prismlauncher.PrismLauncher/data/PrismLauncher/plugins`

For example:
```sh
$ cmake -S . -B build -DCMAKE_INSTALL_PREFIX=~/.local/share/PrismLauncher/plugins/testplugin
```
Note the additional `testplugin` at the end; development installations of plugins need to reside in their own folder!

### VS Code

If you're using VS Code then:

1. Add the path to your Qt `include` folder to `includePath`
2. Clone the PrismLauncher source and put the path to the `launcher/plugins/api` folder to `includePath`
3. Add `-L/{path to your Qt installation}/lib` to `compilerArgs`
4. Set `compileCommands` to `${workspaceFolder}/build/compile_commands.json`
5. Set `cppStandard` to `c++14` or higher

Here's an example on Arch Linux:

```json
{
    "configurations": [
        {
            "name": "Linux (PrismLauncher)",
            "includePath": [
                "${workspaceFolder}/**",
                "/usr/include/qt6/**",
                // In my setup, I have a root folder where all plugin project folders,
                // aswell as the PrismLauncher sourcecode is stored under.
                "${workspaceFolder}/../PrismLauncher/launcher/plugin/api"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/clang",
            "compilerArgs": [
                // Not really needed since qt is installed in a
                // systemwide default library folder.
                "-L/usr/lib"
            ],
            "compileCommands": "${workspaceFolder}/build/compile_commands.json",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-clang-x64"
        }
    ],
    "version": 4
}
```

Add `-DCMAKE_EXPORT_COMPILE_COMMANDS=ON` to your cmake command:
```sh
$ cmake -S . -B build -DCMAKE_INSTALL_PREFIX=./install -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
```
