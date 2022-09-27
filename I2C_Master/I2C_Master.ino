#include <Wire.h>

String response = "";
char letter;

void setup()
{
  Wire.begin();

  Serial.begin(9600);
  Serial.println("I2C master online");
  
}

void loop()
{
  Wire.beginTransmission(8);
  Wire.write(1185);
  Wire.endTransmission();

  Serial.println("sended package");

  Wire.requestFrom(8, 5);

  while (Wire.available())
  {
    letter = Wire.read();
    response += letter;
  }

  Serial.print("recieved from slave:");
  Serial.println(response);
  
}
