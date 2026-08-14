#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include "Adafruit_VL53L0X.h"

// You have to install libraries below
// >> MPU6050 by Electronic Cats -  Gyroscope Sensor
// >> Adafruit VL53L0X Library - Distance Sensor


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
  Serial.begin(38400);

  Serial.println("Initializing I2C devices...");
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

  if (!lox.begin()) {
    Serial.println(F("VL53L0X sensor not found!"));
    while(1);
  }
  Serial.println(F("VL53L0X initialized!"));

  pinMode(5, INPUT);
  pinMode(4, INPUT);
  bInput[0] = bInput[1] = false;
  aInput[0] = aInput[1] = aInput[2] = 0;
}

void loop() {
  
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    
  lox.rangingTest(&measure, false);

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

  sendData();
  delay(100);
}

void sendData() {
  // Send data via serial port
  vlActive = (measure.RangeStatus != 4);
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

