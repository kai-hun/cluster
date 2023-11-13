# 3장, Install jessiarm code

### 1. **jessiarm install on Jetson**

    $ cd ~/catkin_ws/src
    $ git clone https://github.com/zeta0707/jessiarm.git
    $ cd ~/catkin_ws

 opencv를 3.4.x로 downgrade한 이미지를 사용한다고 가정합니다.  앞 장에서 사용한 이미지는 opencv 3.4.6이 /usr/local에 설되었으므로 아래 patch를 실행해 cv_bridge가 빌드되게 만들어주세요.

    $ cd ~/Downloads/opencvDownTo34
    $ sudo patch -p1 /opt/ros/melodic/share/cv_bridge/cmake/cv_bridgeConfig.cmake -p1 < cv_brige.patch
    $ cd ~/catkin_ws
    
    #전체 빌드
    $ cma

### 2. **jessiarm install on PC**

 먼저 melodic-desktop-full을 설치합니다. 그 후 젯슨과 동일하게 jessiarm git을 clone 합니다. 그 후 빌드합니다.

    $ sudo apt update
    $ sudo apt install ros-melodic-desktop-full
    
    $ cd ~/catkin_ws/src
    $ git clone https://github.com/zeta0707/jessiarm.git
    $ cd ~/catkin_wss
    $ cma

# 4장, Test servo motor

### **1. adafruit_pca9685 서보모터 확인**

    $ sudo apt install python-pip -y
    $ pip2 install adafruit_pca9685

 처음 질문에 모터 번호, 두 번째 질문에 pulse값을 입력하면 됩니다. 모터 번호를 생략하면 앞 명령어에서 입력한 모터에 대해 동작을 합니다. 종료하고 싶을 때는 Ctrl-C를 입력하면 됩니다.

**사용방법:** 

    $ cd ~/catkin_ws
    $ python src/jessiarm/jessiarm_control/src/servokit_test.py

# 5장, Teleop by joystick

## **1. Check joystick(=gamepad)**

### 1.1 joystick 패키지 설치

    $ sudo apt-get install joystick
    $ cd /dev/input
    $ ls js*
    
    # check js0 is there
    jetson@jp4612GCv346Py37:/dev/input$ ls js*
    js0

### 1.2 joystick 동작 확인

    jetson@nano:~/ros2_ws$ sudo jstest /dev/input/js0

## **2. 로봇암 운전**

### 2.1 launch로 실행

    $ roslaunch jessiarm_joy joy_teleop_axes_jetson.launch

### 2.2 rosrun으로 실행

    #terminal #1
    $ roscore
    
    #terminal #2
    $ rosrun jessiarm_control joy_control.py

rosrun으로 joy_control.py 실행했으므로, joy_teleop_axes.launch를 따로 실행해서 게임패드의 움직임을 joy_control로 전달해주어야합니다.

    #terminal #3
    jetson@jp4612GCv346Py37:~$ roslaunch jessiarm_joy joy_teleop_axes.launch
