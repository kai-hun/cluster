![image](https://github.com/kai-hun/cluster/assets/68891654/4f516c06-9e7b-4112-912b-7dcbf267ba7a)

![image](https://github.com/kai-hun/cluster/assets/68891654/dd8412f4-1013-40cf-843a-61a64c2e581c)


`sudo sh install.sh`는 Linux 또는 Unix 기반 시스템에서 사용되는 명령어입니다. 이 명령어는 다음과 같은 역할을 합니다:

1. `sudo`: "superuser do"의 약자로, 슈퍼 유저 또는 관리자 권한으로 명령을 실행하도록 허용합니다. 일반 사용자가 시스템의 중요한 부분을 변경하거나 설치하기 위해 필요한 권한을 얻을 수 있습니다.

2. `sh`: Bourne 쉘 (Bourne Shell) 또는 호환 쉘 스크립트를 실행하는 명령어입니다. `install.sh` 파일은 일반적으로 쉘 스크립트 파일로, 시스템에 어떤 소프트웨어나 패키지를 설치하는 스크립트일 수 있습니다.

3. `install.sh`: 이는 실행하려는 쉘 스크립트 파일의 이름이며, 스크립트에는 설치 프로세스 및 다른 작업에 필요한 명령어가 포함될 것입니다.

따라서 `sudo sh install.sh` 명령어는 `install.sh`라는 스크립트를 슈퍼 유저 권한으로 실행하여 시스템에 어떤 소프트웨어나 패키지를 설치하려는 것으로 추정됩니다. 스크립트 내용과 설치할 내용에 따라 작동 방식이 다를 것이며, 실제 설치 프로세스 및 스크립트 내용은 `install.sh` 파일의 내용에 따라 다를 것입니다.

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
    $ cma

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
    
# 4장, Teleop by jostick

## 1 연결

 Jetson USB port에 USB dongle을 연결하고, gamepad 뒷면 ON/OFF 버튼을 ON으로 이동시켜주세요. 그 후 HOME 버튼을 한 번 눌러 붉은 LED 하나가 켜지는지 확인해주세요. Jetson 2G일 경우 단독 USB port에 연결해주세요.

### 1.1 joystick 패키지 설치

    $ sudo apt-get install joystick
    $ cd /dev/input
    $ ls js*
    
    # check js0 is there
    jetson@jp4612GCv346Py37:/dev/input$ ls js*
    js0

### 1.2 joystick 동작 확인

    jetson@nano:~/ros2_ws$ sudo jstest /dev/input/js0

## 2. Jessiar 운전

    #  terminal #1
    $ roslaunch jessicar_control joy_control.launch
    
    # terminal #2
    $ roslaunch jessicar_joy jessicar_teleop_joy.launch

# 5장, Teleop by keyboard

## 1. 실행

    # terminal #1
    $ roslaunch jessicar_control keyboard_control.launch
    
    # terminal #2
    $ roslaunch jessicar_teleop jessicar_teleop_key.launch

# 6장, Verify CSI camera

## 1. gst-launch로 확인(Option)

    gst-launch-1.0 nvarguscamerasrc sensor_id=0 ! 'video/x-raw(memory:NVMM),width=3280, height=2464, framerate=21/1, format=NV12' ! nvvidconv flip-method=0 ! 'video/x-raw,width=960, height=720' ! nvvidconv ! nvegltransform ! nveglglessink -e

## 2. csi_pub.py으로 확인

    $ sudo apt install ros-melodic-image-view

    # terminal #1
    $ roslaunch jessicar_camera csicam.launch
    # or
    $ roslaunch jessicar_camera usbcam.launch
    
    # terminal #2, PC or Jetson
    $ rqt_image_view

# 7장, Blob Tracking

## 1. 실행

    # terminal #1
    $ roslaunch jessicar_control blob_all.launch
    
    # image_view 실행, 이미지를 확인하기 위함, DISPLAY 필요
    $ rosrun image_view image_view image:=/blob/image_blob
    # 또는
    $ rqt_image_view

### 파라미터 조정

 find_ball.yaml파일에서 필터 색을 정할 수 있습니다.
 
 motor.yaml파일에서 모터 파라미터를 조정할 수 있습니다.

# 8장, Yolo4-tiny, darknet_ros

## 1. 패키지 설치

### 1.1 install darknet_ros

    $ sudo apt-get install -y ros-melodic-image-pipeline
    
    $ cd ~/catkin_ws/src
    $ git clone --recursive https://github.com/Tossy0423/yolov4-for-darknet_ros.git

### 1.2 darknet_ros modification

    $ cd ~/catkin_ws/src/yolov4-for-darknet_ros/darknet_ros
    $ git clone https://github.com/zeta0707/darknet_ros_custom.git
    $ cp -rf darknet_ros_custom/* darknet_ros/

## 2. Yolo4 Tracking

 두 개 launch로 구성되어있으며, 동작은 camera publish, yolo running, object x,y → car move입니다. yolo_chase.launch를 실행해야만 camera 입력이 yolo에 전달됩니다. yolo_v4에 의해 학습된 물체를 tracking 합니다.

 coco data중 tracking할 object는 **yolo_jessicar.yaml**에서 수정할 수 있습니다.

### 2.1 실행

    #terminal #1
    #object detect using Yolo_v4
    zeta@zeta-nano:~/catkin_ws$ roslaunch darknet_ros yolo_v4.launch
    
    #terminal #2, camera publish, object x/y -> car move
    zeta@zeta-nano:~/catkin_ws$ roslaunch jessicar_control yolo_chase.launch
