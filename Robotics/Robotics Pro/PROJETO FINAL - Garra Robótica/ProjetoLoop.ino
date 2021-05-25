#include <Servo.h>
Servo garra;
Servo base;
Servo lado1;
Servo lado2;

void setup() 
{
  // Atenção para os pinos corretos de cada servo motor.
  garra.attach(6);
  base.attach(5);
  lado1.attach(3);
  lado2.attach(9);
}
void loop()
{ 
  garra.write(100); // fecha garra
  delay(1000);
  lado1.write(140); // recolhe
  lado2.write(50); // recolhe
  delay(1000);
  base.write(180); // base para direita
  delay(1000);
  garra.write(40); // abre garra
  delay(2000); // espera 2 segundos
  garra.write(100); // fecha garra
  delay(1000);
  base.write(0); // base para esquerda
  delay(1000);
  lado1.write(40); // avança
  lado2.write(120);  // avança
  delay(1000);
  garra.write(40); // abre garra
  delay(1000);
}
