#include <Servo.h>
Servo servoteste;

void setup() 
{
  servoteste.attach(9);
}
void loop()
{
  servoteste.write(0);
  delay(1000);
  servoteste.write(90);
  delay(1000);
  servoteste.write(180);
  delay(1000);
}
