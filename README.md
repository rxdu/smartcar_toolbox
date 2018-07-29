# Smartcar Toolbox

<img src="/docs/img/car_model_c.png" align="right" height="168" >


## 1. License

* This toolbox is licensed under **GPLv3**. Dependent libraries found in the "code/libraries" directory may be distributed with different licenses. Refer to the documents in each library folder for details.

* The simulation was created using the [CAD model](http://www.znczz.com/forum.php?mod=viewthread&tid=237102) provided by "天翊".


## 2. Development Environment

* Ubuntu 16.04 64-bit
* gcc >= 4.8.4
* cmake >= 2.8.11
* V-REP 3.3.2 PRO EDU

**Dependencies**：

Note: The source code and dependent libraries are all cross-platform. Since the main development and tests are done under Ubuntu, the documentation assumes this platform is used and only limited instructions will be provided for other platforms. But it shouldn't be much different to compile and run code on Windows/MacOS. 

**Install Tools**:
```
$ sudo apt-get install build-essential
$ sudo apt-get install cmake
$ sudo apt-get install git
$ sudo apt-get install libeigen3-dev
```

## 3. Compile Code

Here "～/Workspace/smartcar_toolbox" is used as an example directory to put the repository. You can change it to whatever you prefer.

The default output directories：

* smartcar_toolbox/build/bin： executables
* smartcar_toolbox/build/lib: libraries

**Two Compile Methods**

* Terminal + Text Editor
```
$ cd ～/Workspace
$ git clone https://github.com/rxdu/smartcar_toolbox.git
$ cd smartcar_toolbox
$ mkdir build
$ cd build
$ cmake ../src
$ make
```

* Eclipse CDT
```
$ cd ～/Workspace
$ git clone https://github.com/rxdu/smartcar_toolbox.git
$ cd smartcar_toolbox
$ mkdir build
$ cd build
$ cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug ../src
```
An eclipse project will be generated under "build" directory. Import this project into your Eclipse workspace and compile code.

## 4. Run the Simulation

* Start V-REP， open sim_scenes/rc_car_model_c_with_straight_track.ttt，then start the simulation
* Run build/bin/carsim_demo (from Terminal or Eclipse)
