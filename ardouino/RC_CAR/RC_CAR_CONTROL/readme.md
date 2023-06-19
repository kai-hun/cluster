# 순서도
   ![image](https://github.com/kai-hun/cluster/assets/68891654/91b46d5b-0ddb-4319-bfba-db25c4ff589d)
# H-bridge
 * circuit diagram
   ![image](https://github.com/kai-hun/cluster/assets/68891654/77391cc6-849d-4ac4-8d57-dad69417ed07)
   전류가 Q3,Q2를 통해 모터에 +전압
   
 * table
   
   DIRECTION | PinA | PinB | servo
   ---|---|---|---
   FORWARD | LOW | HIGH | 45
   BACKWARD | LOW | HIGH | 45
   RIGHT | X | X | 80
   LEFT | X | X | 0
   STOP | LOW | LOW | 45
