# 智能车工具箱 Smartcar Toolbox

<img src="/docs/img/car_model_c.png" align="right" height="256" >


## 1. 开源协议

* 本工具箱相关代码（依赖库除外）遵循**GPLv3**开源协议。工具箱所依赖的开源库相关协议参照code/libraries目录下各库所附代的说明文件。

* C车模VREP仿真基于“天翊”在智能车制作论坛提供的[CAD模型](http://www.znczz.com/forum.php?mod=viewthread&tid=237102)制作


## 2. 开发环境

* Ubuntu 14.04 64-bit
* gcc >= 4.8.4
* cmake >= 2.8.11
* V-REP 3.3.2 PRO EDU

**依赖关系**：

* 工具箱核心功能（仿真/控制）所需要的文件全部包含于本目录，默认CMake配置只编译核心功能以维持最小依赖
* Eigen为header-only库，用于线性代数相关运算，一般不会涉及依赖问题
* Logging功能依赖于[g3log](https://github.com/KjellKod/g3log)，编译及使用参照其所提供的文档， 在code/CMakeLists.txt里将ENABLE_G3LOG变量设置为on以启用此功能
* Unit Test依赖于[googletest](https://github.com/google/googletest)，如需编译或添加测试代码，在code/CMakeLists.txt里将BUILD_TESTS变量设置为on以启用此功能

注： 本工具箱所有代码及所依赖的库均支持多平台，但默认在Ubuntu操作系统下开发和测试，相关文档也默认使用环境为Ubuntu。参照本文档应该可以在Windows及MacOS下编译和运行相关代码。

**安装编译工具(Ubuntu)**:
```
$ sudo apt-get install build-essential
$ sudo apt-get install cmake
$ sudo apt-get install git
```

## 3. 代码编译

为方便默认使用～/Workspace/smartcar_toolbox目录存放本项目repository文件。依个人偏好修改。默认编译输出目录：

* build/bin： 可执行文件
* build/lib: 工具箱库文件

**两种编译方法**

* 命令行+文本编辑器
```
$ cd ～/Workspace
$ git clone https://github.com/rxdu/smartcar_toolbox.git
$ cd smartcar_toolbox
$ mkdir build
$ cd build
$ cmake ../code
$ make
```

* Eclipse CDT
```
$ cd ～/Workspace
$ git clone https://github.com/rxdu/smartcar_toolbox.git
$ cd smartcar_toolbox
$ mkdir build
$ cd build
$ cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug ../code
```
Eclipse工程文件会生成在build目录下，在Eclipse里从该目录导入已有工程即可以查看编译代码。

## 4. 运行小车仿真

* 打开V-REP， 载入sim_scenes/rc_car_model_c_with_straight_track.ttt，启动仿真
* 运行build/bin/carsim_demo (通过Terminal或Eclipse)
