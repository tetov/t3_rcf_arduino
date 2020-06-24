#include <Wire.h>
#include <VL53L1X.h>

VL53L1X sensor;

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C

  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }
  //sensor.setDistanceMode(VL53L1X::Long);
  sensor.setDistanceMode(VL53L1X::Short);
  sensor.setMeasurementTimingBudget(33000);
  sensor.startContinuous(15);
  Serial.println("New program");
}

void loop()
{
  Serial.println(String(sensor.read() / 10.0));
}
