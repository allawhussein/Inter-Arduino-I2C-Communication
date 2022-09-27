#include <Wire.h>

String answer = "hello";

void setup() 
{
  // put your setup code here, to run once:
  Wire.begin(8);

  Wire.onRequest(sending);

  Wire.onReceive(receving);

  Serial.begin(9600);
  Serial.println("Slave arduino is online");
  
}

void sending()
{
  byte response[5];
  for (byte i = 0; i < 5; i++)
  {
    response[i] = (byte)answer.charAt(i);
  }

  Wire.write(response ,5);

  Serial.println("sended package to master");
}

void receving()
{
  while (Wire.available() > 0)
  {
    byte x = Wire.read();
  }
  Serial.println("package is receieved");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
}
