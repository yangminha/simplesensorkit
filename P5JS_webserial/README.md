#  P5JS, Javascript example (P5JS, Javascript 예제)
=============

이 디렉토리에는 P5JS와 Javascript로 제공된 센서킷을 구동할 수 있는 간단한 예시가 들어가 있어요.
This directory contains simple examples demonstrating how to use the provided sensor kit with JavaScript and p5.js.

## - sensor_read.html
-------------
> Javascript로 만들어진 파일로, 제공된 센서킷의 기본 값이 어떻게 들어오는지 확인할 수 있어요.
> A JavaScript example that allows you to check the raw values received from the sensor kit.
![Alt text](/simplesensorkit/P5JS_webserial/sensor_read.png)

## - sensor_p5js_minimal.html
-------------
> P5JS로 센서에서 들어오는 값이 그래픽으로 어떻게 변환될 수 있는지 확인할 수 있어요.
> A p5.js example that demonstrates how incoming sensor values can be translated into graphics.
![Alt text](/simplesensorkit/P5JS_webserial/sensor_p5js_minimal.png)

## 센서 값 설명
-------------
> 아래는 센서데이터를 저장하는 자바스크립트의 객체입니다.
> The following JavaScript object stores the sensor data:
  let sensorData = {
    button1: false,
    button2: false,
    analog1: '512',
    analog2: '512',
    analog3: '512',
    vlActive: false,
    distanceMm: '400',
    tiltX: '0',
    tiltY: '0'
  };
  
### sensorData.button1
  - 왼쪽 버튼 : 값 true / false
  - Left button : Value true / false

### sensorData.button2
  - 오른쪽 버튼 : 값 true / false
  - Right button : Value true / false

### sensorData.analog1
  - 1번 가변저항 : 값 0 ~ 1023
  - Potentiometer 1 : value 0 ~ 10231

### sensorData.analog2
  - 2번 가변저항 : 값 0 ~ 1023
  - Potentiometer 2 : value 0 ~ 10231

### sensorData.analog3
  - 3번 가변저항 : 값 0 ~ 1023
  - Potentiometer 3 : value 0 ~ 10231

### sensorData.vlActive
  - 거리센서 활성화 여부 : 값 true / false
  - 거리센서는 대략 700cm(270in)를 벗어나면 false값을 줍니다. 그 안쪽에 있거나 거리 측정값이 들어오면 true를 주죠.
  - Distance sensor activity status  : Value true / false
  - The distance sensor returns false when the detected object is outside its approximate measurement range of 700 cm (270 in).
  - It returns true when an object is within range and a valid distance measurement is available.

### sensorData.distanceMm
  - 거리데이터 : 유효 값 50 ~ 600cm
  - 값은 미터법의 cm를 기준으로 처리되어 입력됩니다.
  - Distance data : Valid range 50~600cm
  - The value is provided in centimeters using the metric system.

### sensorData.tiltX
  - 기울기 X축 : 값 -18000~18000
  - 거리센서는 대략 -18000 ~ 18000의 값이 들어옵니다.
  - X축과 Y축은 화면을 기준으로 보면 뒤바뀐 것처럼 보일 수 있습니다.
  - sensor_p5js_minimal.html 예제에서는 값을 뒤바꿔 처리합니다.
  - X-axis tilt : value range -18000~18000
  - The tilt sensor returns a value between approximately -18000 and 18000.
  - The X and Y axes may appear to be reversed when viewed relative to the screen.
  - In the sensor_p5js_minimal.html example, the X- and Y-axis values are swapped when processed.

### sensorData.tiltY
  - 기울기 Y축 : 값 -18000~18000
  - 거리센서는 대략 -18000 ~ 18000의 값이 들어옵니다.
  - X축과 Y축은 화면을 기준으로 보면 뒤바뀐 것처럼 보일 수 있습니다.
  - sensor_p5js_minimal.html 예제에서는 값을 뒤바꿔 처리합니다.
  - Y-axis tilt : value range -18000~18000
  - The tilt sensor returns a value between approximately -18000 and 18000.
  - The X and Y axes may appear to be reversed when viewed relative to the screen.
  - In the sensor_p5js_minimal.html example, the X- and Y-axis values are swapped when processed.




