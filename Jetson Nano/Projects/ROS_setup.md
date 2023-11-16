# **1장, 용어 정리**

## ROS란
ROS(Robot Operating System)는 로봇을 개발하고 제어하도록 설계된 오픈 소스 미들웨어 프레임워크입니다. 이름에도 불구하고 ROS는 실제 운영 체제가 아니라 로봇 시스템 개발을 촉진하는 소프트웨어 라이브러리 및 도구 모음입니다. 하드웨어 추상화, 장치 드라이버, 프로세스 간 통신, 패키지 관리 등과 같은 서비스를 제공합니다.

ROS의 주요 기능은 다음과 같습니다.

미들웨어: ROS는 로봇 시스템의 다양한 구성 요소 간의 통신을 가능하게 하는 미들웨어를 제공합니다. 이 통신은 노드(소프트웨어 프로세스)가 특정 주제에 메시지를 게시하고 다른 노드가 해당 주제를 구독하여 메시지를 받는 게시-구독 메커니즘을 통해 수행될 수 있습니다.

패키지 관리: ROS는 코드 구성 및 배포를 위해 패키지 기반 시스템을 사용합니다. 패키지에는 라이브러리, 실행 파일, 스크립트, 구성 파일 등이 포함될 수 있습니다. 이 모듈식 구조를 통해 코드를 재사용하고 로봇 소프트웨어를 쉽게 배포할 수 있습니다.

하드웨어 추상화: ROS는 하드웨어를 추상화하여 개발자가 사용 중인 특정 로봇 하드웨어와 독립적인 코드를 작성할 수 있도록 합니다. 이러한 추상화는 개발 프로세스를 단순화하고 다양한 로봇 플랫폼 간에 코드를 더 쉽게 포팅할 수 있게 해줍니다.

도구 및 시각화: ROS에는 시각화, 디버깅 및 분석을 위한 도구 세트가 함께 제공됩니다. 이러한 도구에는 3D 시각화를 위한 RViz, 그래픽 사용자 인터페이스를 위한 RQT, 다양한 로깅 및 디버깅 도구가 포함됩니다.

커뮤니티 및 생태계: ROS의 강점 중 하나는 활발하고 협력적인 커뮤니티입니다. 개발자는 다양한 기존 패키지를 활용하고 ROS 생태계에 자신의 패키지를 기여할 수 있습니다.
ROS는 연구 프로젝트부터 상용 제품에 이르기까지 로봇 응용 프로그램을 개발하기 위해 학술 및 산업 환경에서 널리 사용됩니다. C++, Python 등을 포함한 다양한 프로그래밍 언어를 지원하므로 광범위한 개발자가 액세스할 수 있습니다.

## 

# **2장. Jetpack & ROS install**

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
    
### 1.3  jtop 사용

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

