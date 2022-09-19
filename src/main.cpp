#include <Arduino.h>

/*
 * I, Justin Borzi, 000798465 certify that this material is my original
 * work. No other person's work has been used without due
 * acknowledgement. (Replace with your own name and student number)
 */

void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);
}

void loop()
{
  String tempatureString;
  // read digitized value from the D1 Mini's A/D convertor
  int iVal = analogRead(A0);
  float voltage = iVal * (3.3 / 1023.0);
  float temp = voltage * (50.0 / 3.3);

  if (temp <= 10)
  {
    tempatureString = "Cold!";
  }
  else if (temp < 15)
  {
    tempatureString = "Cool";
  }
  else if (temp < 25)
  {
    tempatureString = "Perfect";
  }
  else if (temp < 30)
  {
    tempatureString = "Warm";
  }
  else if (temp < 35)
  {
    tempatureString = "Hot";
  }
  else if (temp >= 35)
  {
    tempatureString = "Too Hot!";
  }

  // print value to the USB port
  Serial.println("Digitized Value of " + String(iVal) + " is equivalent to a tempature input of " + String(temp) + " deg. which is " + tempatureString);

  // wait 0.5 seconds (500 ms)
  delay(500);
}