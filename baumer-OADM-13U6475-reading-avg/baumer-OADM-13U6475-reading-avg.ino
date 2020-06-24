/*--------------------------------------------------------------
  Program:      volt_measure

  Description:  Reads value on analog input A2 and calculates
                the voltage assuming that a voltage divider
                network on the pin divides by 11.
  
  Hardware:     Arduino Uno with voltage divider on A2.
                
  Software:     Developed using Arduino 1.0.5 software
                Should be compatible with Arduino 1.0 +

  Date:         22 May 2013
 
  Author:       W.A. Smith, http://startingelectronics.org
  https://startingelectronics.org/articles/arduino/measuring-voltage-with-arduino/
--------------------------------------------------------------
*/

// number of analog samples to take per reading
#define NUM_SAMPLES 10

int sum = 0;                    // sum of samples taken
unsigned char sample_count = 0; // current sample number
float average = 0.0;
float distance = 0.0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    // take a number of analog samples and add them up
    while (sample_count < NUM_SAMPLES) {
        sum += analogRead(A0);
        sample_count++;
        delay(10);
    }
    // calculate the voltage
    // use 5.0 for a 5.0V ADC reference voltage
    // 5.015V is the calibrated reference voltage
    average = (float)sum / (float)NUM_SAMPLES;
    distance = map(average, 0, 1023, 50, 350);
   
    Serial.print("Current ");
    Serial.print(average);
    Serial.print(", Distance ");
    Serial.println(distance);
    sample_count = 0;
    sum = 0;
}
