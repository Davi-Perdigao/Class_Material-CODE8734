#include <Servo.h>

Servo garra;
Servo base;
Servo lado1;
Servo lado2;

int i=0; // Variável para incrementar a posição de 1 em 1.
int tempo=1000; // Controle do tempo de parada entre cada função.
int Vspeed=10; // Velocidade de movimento 0 - rápido / 10 - lento.

int LED=13;

void setup() 
{
  // Atenção para os pinos corretos de cada servo motor.
  garra.attach(6);
  base.attach(5);
  lado1.attach(3);
  lado2.attach(9);

  // Declarando que o LED é saída.
  pinMode(LED,OUTPUT);
  
  // Definindo a posição inicial do robô, esse código é executado somente 1 vez.
  digitalWrite(LED,HIGH); // Indicando que o robô irá se mover de forma brusca.
  delay(tempo);

  // Definindo a posição inicial do robô, esse código é executado somente 1 vez.
  garra.write(100); // Garra fechada
  base.write(180); // Posição direita
  lado1.write(40); // Cima
  lado2.write(50); // Recolhido
}

void loop()
{ 

  if (Vspeed<=5)
  {digitalWrite(LED,HIGH);} // Indicando que o robô irá se mover de forma brusca.
  else
  {digitalWrite(LED,LOW);} // Indicando que o robô irá se mover suavemente.
 

  recolhe();
  delay(tempo);
  sobe();
  base_direita();
  delay(tempo);
  avanca();
  delay(tempo);
  abre_garra();
  fecha_garra();
  base_esquerda();
  delay(tempo);
  desce();
  delay(tempo);
  abre_garra();
  fecha_garra();
}

void abre_garra() // A garra precisa de pressão para pegar objetos, movimento rápido
{
  garra.write(40);
  delay(tempo);
}

void fecha_garra()  // A garra precisa de pressão para pegar objetos, movimento rápido
{
  garra.write(100);
  delay(tempo); 
}

void base_direita() // A base precisa se mover lentamente
{
  for(i = 180; i >= 0; i -= 1) // Indo de 180 a 0 graus de 1 em 1
  {       
    if(i<0)
    {
      i=0;
      break;
    } 
    base.write(i); // Pedindo para que o servo vá para a posição "i"
    delay(Vspeed);
  } 
}

void base_esquerda() // A base precisa se mover lentamente
{
  for(i = 0; i <= 180; i += 1) // Indo de 0 até 180 graus de 1 em 1
  { 
    if(i>180)
    {
      i=180;
      break;
    }
    base.write(i); // Pedindo para que o servo vá para a posição "i"
    delay(Vspeed); 
  } 
}

void recolhe() // O braço precisa se mover lentamente
{  
    for(i = 120; i >= 50; i -= 1) // Indo de 120 a 50 graus de 1 em 1
  {       
    if(i<50)
    {
      i=50;
      break;
    } 
    lado2.write(i); // Pedindo para que o servo vá para a posição "i"
    delay(Vspeed);
  } 
}

void avanca() // O braço precisa se mover lentamente
{
  for(i = 50; i <= 120; i += 1) // Indo de 50 até 120 graus de 1 em 1
  { 
    if(i>120)
    {
      i=120;
      break;
    }
    lado2.write(i); // Pedindo para que o servo vá para a posição "i"
    delay(Vspeed); 
  } 
}

void desce() // O braço precisa se mover lentamente
{
      for(i = 140; i >= 40; i -= 1) // Indo de 140 a 40 graus de 1 em 1
  {       
    if(i<40)
    {
      i=40;
      break;
    } 
    lado1.write(i); // Pedindo para que o servo vá para a posição "i"
    delay(Vspeed);
  } 
}

void sobe() // O braço precisa se mover lentamente
{
    for(i = 40; i <= 140; i += 1) // Indo de 40 até 140 graus de 1 em 1
  { 
    if(i>140)
    {
      i=140;
      break;
    }
    lado1.write(i); // Pedindo para que o servo vá para a posição "i"
    delay(Vspeed); 
  } 
}
