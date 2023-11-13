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

