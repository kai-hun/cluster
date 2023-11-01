
![image](https://github.com/kai-hun/cluster/assets/68891654/4f516c06-9e7b-4112-912b-7dcbf267ba7a)

![image](https://github.com/kai-hun/cluster/assets/68891654/dd8412f4-1013-40cf-843a-61a64c2e581c)


`sudo sh install.sh`는 Linux 또는 Unix 기반 시스템에서 사용되는 명령어입니다. 이 명령어는 다음과 같은 역할을 합니다:

1. `sudo`: "superuser do"의 약자로, 슈퍼 유저 또는 관리자 권한으로 명령을 실행하도록 허용합니다. 일반 사용자가 시스템의 중요한 부분을 변경하거나 설치하기 위해 필요한 권한을 얻을 수 있습니다.

2. `sh`: Bourne 쉘 (Bourne Shell) 또는 호환 쉘 스크립트를 실행하는 명령어입니다. `install.sh` 파일은 일반적으로 쉘 스크립트 파일로, 시스템에 어떤 소프트웨어나 패키지를 설치하는 스크립트일 수 있습니다.

3. `install.sh`: 이는 실행하려는 쉘 스크립트 파일의 이름이며, 스크립트에는 설치 프로세스 및 다른 작업에 필요한 명령어가 포함될 것입니다.

따라서 `sudo sh install.sh` 명령어는 `install.sh`라는 스크립트를 슈퍼 유저 권한으로 실행하여 시스템에 어떤 소프트웨어나 패키지를 설치하려는 것으로 추정됩니다. 스크립트 내용과 설치할 내용에 따라 작동 방식이 다를 것이며, 실제 설치 프로세스 및 스크립트 내용은 `install.sh` 파일의 내용에 따라 다를 것입니다.

# 2장. Jetpack & ROS install

https://drive.google.com/file/d/1HU5F1cwiw2wzuNBdLL9R3Wvpg5AXLzw5/view?usp=sharing

id: jetson

passwd: jetson

## 1. Tool install on Jetson

### 1.1. Terminal(=SSH)에서 WiFi 연결하기

    # 실행해야할 명령
    $ sudo nmcli device wifi list
    $ sudo nmcli device wifi connect <ssid_name> password <password>
    $ ifconfig

    # 연결을 해제할 때
    $ sudo nmcli device disconnect wlan0
    
### 1.2 Cooling Fan

    $ cd Downloads
    $ git clone https://github.com/jetsonworld/jetson-fan-ctl.git
    $ cd jetson-fan-ctl
    
    $ sudo sh install.sh
    
### 1.4  jtop 사용

    $ jtop

## 2. ROS Melodic 설치

### 2.1 ROS Melodic 설치

    $ cd ~/Downloads/
    $ sudo apt update
    
    $ git clone https://github.com/zeta0707/installROS.git
    $ cd installROS
    $ ./install-ros.sh

### 2.2 .bashrc 수정

    $ gedit ~/.bashrc
    
    # 파일 제일 아래에 다음과 같은 내용 입력
    alias cma='catkin_make -DCATKIN_WHITELIST_PACKAGES=""'
    alias cop='catkin_make --only-pkg-with-deps'
    alias sds='source devel/setup.bash'
    alias coc='catkin clean'
    alias cca='catkin clean -y'

    source /opt/ros/melodic/setup.bash
    source ~/catkin_ws/devel/setup.bas

    # 에디터 종료 후 터미널 업데이트
    $ source ~/.bashrc

### 2.3 catkin workspace 설치

    jetson@jp4512G:~/catkin_ws$ cca
    
    jetson@jp4512G:~/catkin_ws$ cma

### 2.4 ROS 동작 확인(Option)

설치 후 제대로 되었는지 turtlesim으로 확인할 수 있습니다. 세 개의 창에 하나씩 아래 명령어를 실행해주세요.

    # 터미널 #1
    jetson@jp4512G:~/catkin_ws$ roscore
    # 터미널 #2
    jetson@jp4512G:~/catkin_ws$ rosrun turtlesim turtlesim_node
    # 터미널 #3
    jetson@jp4512G:~/catkin_ws$ rosrun turtlesim turtle_teleop_key

![Screenshot from 2023-11-01 18-40-55](https://github.com/kai-hun/cluster/assets/68891654/ae466a24-09a4-448e-9109-f0844c5deea3)

# 3장, install jessicar code

## 1. jessicar install on Jetson

    $ cd ~/catkin_ws/src
    $ git clone https://github.com/zeta0707/jessicar.git
    $ cd ~/catkin_ws

 앞 장에서 사용한 이미지는 opencv 3.4.6이 /usr/local에 설되었으므로 아래 patch를 실행해 cv_bridge가 빌드되게 만들어주세요.

    $ cd ~/Downloads/opencvDownTo34
    $ sudo patch -p1 /opt/ros/melodic/share/cv_bridge/cmake/cv_bridgeConfig.cmake -p1 < cv_brige.patch
    $ cd ~/catkin_ws
    
    #전체 빌드
    cma

 RCcar에 맞는 환경파일 만들기 위해 아래 절차를 수행해주세요.

    $ cd ~/catkin_ws/src/jessicar/script
    $ ./jetRccarParam.sh pca9685Steer

## 2. jessicar install on PC
 ...

## 3. other ROS package on Jetson
    $ sudo apt update
    $ sudo apt install ros-melodic-joy* \
    ros-melodic-teleop-twist-joy ros-melodic-teleop-twist-keyboard \
    python-smbus ros-melodic-ackermann-msgs ros-melodic-web-video-server \
    ros-melodic-image-pipeline python-pip
    
    $ pip2 install Adafruit_PCA9685
