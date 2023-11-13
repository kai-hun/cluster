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

```bash
jetson@nano:~/ros2_ws$ sudo jstest /dev/input/js0
```

## **2. 로봇암 운전**

### 2.1 launch로 실행

```bash
$ roslaunch jessiarm_joy joy_teleop_axes_jetson.launch
```

### 2.2 rosrun으로 실행

```bash
#terminal #1
$ roscore
    
#terminal #2
$ rosrun jessiarm_control joy_control.py

rosrun으로 joy_control.py 실행했으므로, joy_teleop_axes.launch를 따로 실행해서 게임패드의 움직임을 joy_control로 전달해주어야합니다.

#terminal #3
jetson@jp4612GCv346Py37:~$ roslaunch jessiarm_joy joy_teleop_axes.launch
```

# 6장, Teleop by keyboard

### **1. teleop_twist_keyboard 설치**

```bash
jetson@jp4612GCv346Py37:~/catkin_ws$ git clone https://github.com/ros-teleop/teleop_twist_keyboard.git
jetson@jp4612GCv346Py37:~/catkin_ws$ cd ..
jetson@jp4612GCv346Py37:~/catkin_ws$ cma
```

### **2. launch파일로 실행**

```bash
$ roslaunch jessiarm_control teleop_keyboard.launch
```

### **3. rosrun으로 각각 파이썬 코드 실행**

 먼저 roscore를 실행합니다. 그 후 젯슨 다른 터미널에서 아래 명령어를 실행합니다.

```bash
#terminal #1
jetson@jp4612GCv346Py37:~$  roscore
        
#terminal #2
jetson@jp4612GCv346Py37:~$  rosrun teleop_twist_keyboard teleop_twist_keyboard.py
        
#terminal #3
jetson@jp4612GCv346Py37:~$  rosrun jessiarm_control keyboard_control.py
```

# 7장, Verify USB camera

### **1. Jetson에서 카메라 동작 확인**

```bash
jetson@jp4612GCv346Py37:~$ ls /dev/video*
/dev/video0
jetson@jp4612GCv346Py37:~$ nvgstcapture-1.0 --camsrc=0 --cap-dev-node=/dev/video0
```

## **2. PC/jetson에서 ROS webcam으로 이미지 확인**

```bash
jetson@jp4612GCv346Py37:~$ sudo apt install ros-melodic-image-view
```

### 2.1 Jetson만 사용할 경우

```bash
$ roscore 
$ rosrun jessiarm_csicamera webcam_pub.py
$ rosrun image_view image_view image:=/webcam_image
```

### 2.2 PC에서 영상을 확인할 경우

**Jetson:**

~/.bashrc에 아래 환경변수 추가

export ROS_MASTER_URI=http://192.168.55.1:11311

export ROS_IP=192.168.55.1
​
그 후 아래 명령을 실행해 webcam image를 publish합니다.

```bash
# 터미널 #1
$ roscore 
        
# 터미널 #2
$ rosrun jessiarm_csicamera webcam_pub.py
```

**PC:**

~/.bashrc에 아래 환경변수 추가

export ROS_MASTER_URI=http://192.168.55.1:11311

export ROS_IP=192.168.55.100

        $ rqt_image_view

# 8장, blob PicknPlace

### **1. launch로 실행**

        $ roslaunch jessiarm_control blob_control.launch


```yaml
#find_ball.yaml의 내용
define: &blue_min [55,40,0]
define: &blue_max [150, 255, 255]
define: &white_min [16, 0, 66]
define: &white_max [133, 251, 255]
define: &pink_min [135, 41, 95]
define: &pink_max [255, 196, 255]
define: &green_min [39, 81, 71]
define: &green_max [75, 255, 255]
define: &orange_min [7, 109, 50]
define: &orange_max [76, 218, 234]
define: &red_min [0, 94, 92]
define: &red_max [255, 255, 255]

#아래 두 라인으로 필터를 선택합니다.
blob_detector:
blob_min: *green_min
blob_max: *green_max
```
  
find_ball.yaml파일에서 필터 색을 정할 수 있습니다. blob_min, blob_max에 있는 string을 변경하시면 됩니다.

Jessiarm이 scan하는 speed를 설정할 수 있습니다. 0.00으로 정하면 Jessiarm이 제자리에서 움직이지 않습니다.

PC에서 rqt_image_view를 실행해서 image를 확인합니다.

### **2. rosrun으로 실행**

```bash
# 터미널 #1
$ roscore

# 터미널 #2, camera image publisher
$ rosrun jessiarm_csicamera webcam_pub.py

# 터미널 #3, CV Magic, Bind Ball with Pixel Value
# requires load parameter at first
jetson@jp4612GCv346Py37:~/catkin_ws$ rosparam load src/jessiarm/jessiarm_control/config/find_ball.yaml
jetson@jp4612GCv346Py37:~/catkin_ws$ rosrun jessiarm_cv find_ball.py 

# 터미널 #4, Blob Point to Twist
$ rosrun jessiarm_control chase_the_ball.py

# 터미널 #5, PWM Control node
$ rosrun jessiarm_control blob_chase.py
```

***PC or Jetson***

```bash
# image_view 실행
$ rqt_image_view
```

# 9장, Yolo4 PicknPlace

## **1. 패키지 설치**

### 1.1 install darknet_ros

```bash
sudo apt-get install -y ros-melodic-image-pipeline

cd ~/catkin_ws/src
git clone --recursive https://github.com/Tossy0423/yolov4-for-darknet_ros.git
```

### 1.2 darknet_ros modification

yolov4 → yolov4-tiny로 수정, 그리고 custom dataset에 해당하는 config, weights 적용

```bash
cd ~/catkin_ws/src/yolov4-for-darknet_ros/darknet_ros
git clone https://github.com/zeta0707/darknet_ros_custom.git
cp -rf darknet_ros_custom/* darknet_ros/
```

package가 준비 되었으므로 빌드합니다.

```bash
zeta@zeta-nano:~/catkin_ws/src$ cd ..
zeta@zeta-nano:~/catkin_ws$ cma
```

## **2. darknet_ros 실행**

### 2.1 coco object PicknPlace

```bash
#terminal #1, object detect using Yolo_v4
jetson@jp4612GCv346Py37:~$ roslaunch darknet_ros yolo_v4.launch

#terminal #2, camera publish, object x/y -> robot move
jetson@jp4612GCv346Py37:~$ roslaunch jessiarm_control yolo_chase.launch
```
