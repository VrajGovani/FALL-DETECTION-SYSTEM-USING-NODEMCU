#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_TEMPLATE_ID "TMPL3yGqmpxOw"
#define BLYNK_AUTH_TOKEN "ey3ztIzKi5uNGovLF-o1Ips2v2vrwonZ"

#include <Blynk.h>
#include <Wire.h>
#include <MPU6050_light.h>
#include <BlynkSimpleEsp8266.h>

MPU6050 mpu(Wire);



char ssid[] = "Prajveen's Galaxy S22";         
char pass[] = "dowc5687";         

const float FALL_THRESHOLD = 2.5;
const int FALL_DURATION = 750;

float prevTotalAcc = 1.0; 
unsigned long fallStartTime = 0;
bool fallingDetected = false;


#define SDA_PIN 4
#define SCL_PIN 5



void setup() {
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
 
  Wire.begin(SDA_PIN, SCL_PIN);
 
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while(status != 0) {
    Serial.println(F("Could not connect to MPU6050"));
    delay(1000);
  }

  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets();
  Serial.println("Done!\n");
}

void loop() {
   Blynk.run(); 
  mpu.update();
 
  float accX = mpu.getAccX();
  float accY = mpu.getAccY();
  float accZ = mpu.getAccZ();
 

  float totalAcc = sqrt(accX * accX + accY * accY + accZ * accZ);
 

  if (abs(totalAcc - prevTotalAcc)> FALL_THRESHOLD) {
    if (!fallingDetected) {
      fallingDetected = true;
      fallStartTime = millis();
    }
  } else if (fallingDetected && (millis() - fallStartTime > FALL_DURATION)) {
    Serial.println("Fall detected!");
    sendFallNotification();
    fallingDetected = false;
  }
 
  prevTotalAcc = totalAcc;
 
  delay(10);
}


void sendFallNotification() {
  Blynk.logEvent("fall_detect", "Fall detected! Check the person immediately.");

}
