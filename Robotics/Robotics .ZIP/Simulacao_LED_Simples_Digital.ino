void setup()
{
  pinMode(10, OUTPUT);
}

void loop()
{
  analogWrite(10, 0);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(10, 255);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(10, 127);
  delay(1000); // Wait for 1000 millisecond(s)
  analogWrite(10, 64);
  delay(1000); // Wait for 1000 millisecond(s)
}
