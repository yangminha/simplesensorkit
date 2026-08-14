#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "Adafruit_VL53L0X.h"

Adafruit_VL53L0X lox = Adafruit_VL53L0X();
MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

VL53L0X_RangingMeasurementData_t measure;
bool vlActive = false;

int aInput[3];
bool bInput[2];

void setup() {
  Wire.begin();
  Serial.begin(38400); // 시리얼 모니터 속도
  Serial.println("Initializing I2C devices...");
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

  // 센서 초기화 확인
  if (!lox.begin()) {
    Serial.println(F("VL53L0X 센서를 찾을 수 없습니다. 배선을 확인하세요!"));
    while(1);
  }
  Serial.println(F("VL53L0X 센서 초기화 완료!"));

  pinMode(5, INPUT);
  pinMode(4, INPUT);
  bInput[0] = bInput[1] = false;
  aInput[0] = aInput[1] = aInput[2] = 0;
}

void loop() {
  // 가속도와 자이로 값 읽기
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);




    
  lox.rangingTest(&measure, false); // 측정 실행


  if (digitalRead(5)==HIGH) {
    bInput[0]=false;
  } else {
    bInput[0]=true;
  }
  
  if (digitalRead(4)==HIGH) {
    bInput[1]=false;
  } else {
    bInput[1]=true;
  }

  aInput[0] = analogRead(A1);
  aInput[1] = analogRead(A2);
  aInput[2] = analogRead(A3);

#if 1
  sendData();
#else
  debugPrint();
#endif

  delay(100);
}

void sendData() {
  // RangeStatus 4 means that the target is out of measurement range.
  vlActive = (measure.RangeStatus != 4);

  // Send one JSON object per line so Web Serial can safely separate samples.
  Serial.print(F("{\"button1\":"));
  Serial.print(bInput[0] ? F("true") : F("false"));
  Serial.print(F(",\"button2\":"));
  Serial.print(bInput[1] ? F("true") : F("false"));
  Serial.print(F(",\"analog1\":"));
  Serial.print(aInput[0]);
  Serial.print(F(",\"analog2\":"));
  Serial.print(aInput[1]);
  Serial.print(F(",\"analog3\":"));
  Serial.print(aInput[2]);
  Serial.print(F(",\"vlActive\":"));
  Serial.print(vlActive ? F("true") : F("false"));
  Serial.print(F(",\"distanceMm\":"));
  Serial.print(measure.RangeMilliMeter);
  Serial.print(F(",\"tiltX\":"));
  Serial.print(ax);
  Serial.print(F(",\"tiltY\":"));
  Serial.print(ay);
  Serial.println(F("}"));
}

void debugPrint() {

  if (measure.RangeStatus != 4) { // Status 4는 측정 범위를 벗어난 경우
    vlActive = true;
    Serial.print(measure.RangeMilliMeter);
    Serial.print("mm / ");
  } else {
    vlActive = false;
    Serial.print("N/A    / ");
  }
    
  // 시리얼 모니터에 값 출력
  Serial.print("\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.print(gz);

  Serial.print("\t");
  Serial.print(bInput[0]); Serial.print("\t");
  Serial.print(bInput[1]); Serial.print("\t");
  Serial.print(aInput[0]); Serial.print("\t");
  Serial.print(aInput[1]); Serial.print("\t");
  Serial.println(aInput[2]);

}
