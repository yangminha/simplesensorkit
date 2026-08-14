#  Arduino 소스를 수정하거나 확인하고 싶은 분들만 보세요. 
# For Users Who Want to Review or Modify the Arduino Source Code
=============
  - 수정한 파일로 새로 업로드 할 경우 본래 기능하던 코드는 무용지물이 됩니다. 가급적 수정하지 마세요.
  - Warning: Uploading a modified version of the source code will overwrite the original firmware, and the sensor kit may no longer work as intended. Avoid modifying or uploading the code unless absolutely necessary.

## 반드시 필요한 라이브러리들 (Required Libraries)
-------------
 - 센서키트에는 거리센서인 VL53L0X와 MPU6050이 들어가있어요. 이 센서들은 따로 라이브러리가 두 개 필요합니다.
 - 먼저 Sketch / Include Library / Manage Libraries 메뉴를 따라가주세요. Manage Libraries 메뉴를 클릭하면 "Filter your search..."라고 쓰여있는 인풋박스가 보여요.
 - 그곳에서 아래 키워드를 검색해 설치해줍니다.
 - The sensor kit includes a VL53L0X distance sensor and an MPU6050 gyroscope/accelerometer sensor. Each sensor requires a separate Arduino library.
 - In the Arduino IDE, go to Sketch → Include Library → Manage Libraries.
 - When the Library Manager opens, find the input box labeled "Filter your search...".
 - Search for and install the following libraries.
   
### MPU6050
  - MPU6050로 검색하면 Electronic Cats이 만든 Gyroscope Sensor가 보여요.
  - 이 센서킷에 설치된 버전은 1.4.5입니다. 가능하면 해당 버전으로 설치해주세요.
  - Search for MPU6050.
  - Install the MPU6050 Gyroscope Sensor library developed by Electronic Cats.
  - The version used by this sensor kit is 1.4.5. If possible, install the same version.
    
### VL53L0X
  - VL53L0X로 검색하면 Adafruit이 만든 Adafruit VL53L0X (Distance Sensor)가 보여요.
  - 이 센서킷에 설치된 버전은 1.3.1입니다. 가능하면 해당 버전으로 설치해주세요.
  - Search for VL53L0X.
  - Install the Adafruit VL53L0X distance sensor library developed by Adafruit.
  - The version used by this sensor kit is 1.3.1. If possible, install the same version.


## 핀 설명 (Pin Configuration)

### A4 아날로그 4번, 5번 핀 (Analog Pins A4 and A5)
  - 거리센서와 자이로 센서의 I2C 통신을 위해 사용됩니다.
  - 두 센서 모두 이 핀을 통해 값을 전달받습니다. 건드리면 안돼요.
  - A4번 핀 (SDA): 데이터(Serial Data) 송수신
  - A5번 핀 (SCL): 클록(Serial Clock) 신호 전달
  - These pins are reserved for I²C communication with the distance sensor and the gyroscope/accelerometer sensor.
  - Both sensors transmit data through these pins. Do not modify or reassign them.
  - A4 (SDA): Transmits and receives serial data.
  - A5 (SCL): Carries the serial clock signal.

### A1 아날로그 1번 (Analog Pin A1)
  - 회전형 가변저항 1번
  - Rotary potentiometer 1

### A2 아날로그 2번 (Analog Pin A2)
  - 회전형 가변저항 2번
  - Rotary potentiometer 2

### A3 아날로그 3번 (Analog Pin A3)
  - 회전형 가변저항 3번
  - Rotary potentiometer 3

### 5 디지털 5번
  - 버튼 1번
  - Button 1

### 4 디지털 4번
  - 버튼 2번
  - Button 2

### 데이터는 1초에 10번만 보내도록 delay를 100ms으로 정해두었습니다. 50정도로 낮추면 더 쾌적한 센서 입력을 받을 수 있어요.
### The delay is set to 100 ms, so sensor data is transmitted 10 times per second. Reducing the delay to approximately 50 ms will increase the transmission rate to about 20 times per second, providing smoother and more responsive sensor input.
  - delay(50);

