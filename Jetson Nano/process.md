# SETUP
* NVIDIA 회원가입
* SD카드 포맷

# INSTALL
1. Jetpack461 설치하기 (*https://developer.nvidia.com/jetson-nano-sd-card-image*)
2. 키트 조립하기

# CONNECT
* SD 카드
* HDMI
* 마우스
* 키보드
* 와이파이 동글
* 파워
* 마이크로 5핀

![img](https://github.com/kai-hun/cluster/assets/68891654/cfb7ebb1-1f32-49f8-9362-c8ddef5d6798)

# SYSTEM CONFIGURATION
1. 언어 - ENGLISH
2. 네트워크 연결
3. 지역 - SEOUL
4. 이름/패스워드 설정

# PIP3/JTOP
1. 터미널 실행
2. 패키지 업데이트 (`sudo apt-get upgrade/sudo apt-get update`)
3. PIP3 설치 (`sudo apt install python3-pip`)
4. JETSON 설치 (`sudo -H pip3 install -U jetson-stats`)
5. 리붓
6. jtop 실행 (`jtop`)

# Fan
* 팬 부착
* 터미널 실행
* 팬 실행 (`sudo sh -c 'echo 128 > /sys/devices/pwm-fan/target_pwm'`)

# Camera(CSI)
1. 카메라 설치
 
   *https://developer.nvidia.com/embedded/learn/jetson-nano-2gb-devkit-user-guide#id-.JetsonNano2GBDeveloperKitUserGuidevbatuu_v1.0-Camera*

2. 터미널 실행
3. 코드 입력

   ```shell
   git clone https://github.com/jetsonhacks/CSI-Camera.git
   
   ls
   
   CSI-Camera
   
   ls
   
   simple_camera.py
   ```

##### *캡쳐하기*

   *https://developer.nvidia.com/embedded/learn/tutorials/first-picture-csi-usb-camera#CameraGuide-USBCamera.1*

# JupyterLab
1. Windows PowerShell 관리자 권한으로 실행
2. docker 설치

   ```shell
   cd ..

   cd ..

   ssh <>@192.168.55.1

   mkdir -p ~/nvdli-data

   echo "sudo docker run --runtime nvidia -it --rm --network host \
   --volume ~/nvdli-data:/nvdli-nano/data \
   --device /dev/video0 \
   nvcr.io/nvidia/dli/dli-nano-ai:v2.0.2-r32.7.1" > docker_dli_run.sh

   chmod +x docker_dli_run.sh

   ./docker_dli_run.sh
   ```
  
3. *http://192.168.0.204:8888* 접속 (password : dlinano)
4. Hello camera 예제 실습
 
   1. ㄴㅇㄹ
   2. 

5. classification 예제 실습
     

