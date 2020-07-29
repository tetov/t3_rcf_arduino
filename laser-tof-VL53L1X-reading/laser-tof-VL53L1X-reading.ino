#include <Wire.h>
#include <VL53L1X.h>

#define BAUD_RATE 115200
#define TIMING_BUDGET 100000 // in microseconds
#define DISTANCE_MODE VL53L1X::Short // Short, Medium, Long

VL53L1X sensor;

void setup()
{
  Serial.begin(BAUD_RATE);
  Wire.begin();
  Wire.setClock(400000); // use 400 kHz I2C

  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }
  sensor.setDistanceMode(DISTANCE_MODE);
  sensor.setMeasurementTimingBudget(TIMING_BUDGET);

  sensor.startContinuous(15);

  Serial.println("New program");
}

void loop()
{
  Serial.println(String(sensor.read() / 10.0));
}
