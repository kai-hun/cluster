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
    ```shell
    # 실행해야할 명령
    $ sudo nmcli device wifi list
    $ sudo nmcli device wifi connect <ssid_name> password <password>
    $ ifconfig

    # 연결을 해제할 때
    $ sudo nmcli device disconnect wlan0
    ```
### 1.2 Cooling Fan
    ```shell
    cd Downloads
    git clone https://github.com/jetsonworld/jetson-fan-ctl.git
    cd jetson-fan-ctl
    
    sudo sh install.sh
    ```
### 1.4  jtop 사용
    `jtop`

## 2. ROS Melodic 설치
### 2.1 ROS Melodic 설치
    ```shell
    cd ~/Downloads/
    sudo apt update
    
    git clone https://github.com/zeta0707/installROS.git
    cd installROS
    ./install-ros.sh
    ```
### 2.2 .bashrc 수정
    ```shell
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
    ```
### 2.3 catkin workspace 설치
    `jetson@jp4512G:~/catkin_ws$ cca`
    
    `jetson@jp4512G:~/catkin_ws$ cma`


    