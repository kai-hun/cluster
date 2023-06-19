# 순서도
   ![image](https://github.com/kai-hun/cluster/assets/68891654/8b6c7043-3593-4a9c-876c-d1be1ea17c03)


# H-bridge
 * circuit diagram
   ![image](https://github.com/kai-hun/cluster/assets/68891654/ff5dba77-ae5b-4501-b1b2-64f37e2f81cb)

   Q1,Q4를 통해 모터에 +전류가 흐르게 되면 모터가 정방향 회전
   
   Q3,Q2를 통해 모터에 -전류가 흐르게 되면 모터가 역방향 회전
   
   모터에 전류가 흐르지 않으면 정지

   ---
   
 * table
   
   DIRECTION | motor1PinA | motor1PinB | servo
   ---|---|---|---
   FORWARD | LOW | HIGH | 45
   BACKWARD | LOW | HIGH | 45
   RIGHT | X | X | 80
   LEFT | X | X | 0
   STOP | LOW | LOW | 45
