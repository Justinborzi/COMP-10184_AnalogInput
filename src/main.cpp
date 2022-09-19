#include <Arduino.h>

void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop()
{
  // read digitized value from the D1 Mini's A/D convertor
  int iVal = analogRead(A0);
  float voltage = iVal * (3.3 / 1023.0);
  long temp = map(voltage, 0, 3.3, 0, 50.0);

  // print value to the USB port
  Serial.println("Digitized Value of " + String(iVal) + " is equivalent to a tempature input of " + String(temp) + " deg. which is");

  if (temp < 10)
  {
    Serial.print("Cold!");
  }
  else if (temp < 15)
  {
    Serial.print("Cool");
  }
  else if (temp < 25)
  {
    Serial.print("Perfect");
  }
  else if (temp < 30)
  {
    Serial.print("Warm");
  }
  else if (temp < 35)
  {
    Serial.print("Hot");
  }
  else if (temp > 35)
  {
    Serial.print("Too Hot!");
  }

  // wait 0.5 seconds (500 ms)
  delay(500);
}