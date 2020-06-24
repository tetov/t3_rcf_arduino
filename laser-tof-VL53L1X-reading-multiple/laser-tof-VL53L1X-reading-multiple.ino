#include <Wire.h>
#include <VL53L1X.h>

#define TIMING_BUDGET 33000
#define DISTANCE_MODE VL53L1X::Long
#define SENSOR_TIMEOUT 500
#define ADDRESS_SENSOR2 0b0101010

VL53L1X sensor1;
VL53L1X sensor2;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C

  sensor2.setAddress(0b0101010); // sensor1 uses default 0b0101001 (or 0x29 with rw bit)

  sensor1.setTimeout(SENSOR_TIMEOUT);
  sensor2.setTimeout(SENSOR_TIMEOUT);
  if (!sensor1.init() || !sensor2.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }
  sensor1.setDistanceMode(DISTANCE_MODE);
  sensor2.setDistanceMode(DISTANCE_MODE);
  
  sensor1.setMeasurementTimingBudget(33000);
  sensor2.setMeasurementTimingBudget(33000);
  
  sensor1.startContinuous(1);
  sensor2.startContinuous(1);
  Serial.println("New program");
}

void loop()
{
  Serial.print(String(sensor1.read() / 10.0));
  Serial.print("&");
  Serial.println(String(sensor2.read() / 10.0));
}
