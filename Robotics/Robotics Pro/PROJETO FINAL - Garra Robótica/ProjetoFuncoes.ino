#include <Servo.h>

Servo garra;
Servo base;
Servo lado1;
Servo lado2;
int tempo=1000;

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
  fecha_garra();
  recolhe();
  base_direita();
  abre_garra();
  fecha_garra();
  base_esquerda();
  avanca();
  abre_garra();
}

void abre_garra()
{
  garra.write(40);
  delay(tempo);
}

void fecha_garra()
{
  garra.write(100);
  delay(tempo); 
}

void base_direita()
{
  base.write(180);
  delay(tempo); 
}

void base_esquerda()
{
  base.write(0);
  delay(tempo); 
}

void recolhe()
{  
  lado1.write(140); 
  lado2.write(50); 
  delay(tempo);
}

void avanca()
{
  lado1.write(40); 
  lado2.write(120); 
  delay(tempo);
}
