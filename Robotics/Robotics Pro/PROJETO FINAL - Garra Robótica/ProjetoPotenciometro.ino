#include <Servo.h>
 
Servo garra;
Servo base;
Servo lado1;
Servo lado2;
 
int pino_1 = A2; //Inicializa o pino analógico do potenciômetro 1
int pino_2 = A3; //Inicializa o pino analógico do potenciômetro 2
int pino_3 = A4; //Inicializa o pino analógico do potenciômetro 3
int pino_4 = A5; //Inicializa o pino analógico do potenciômetro 4
 
int val_base = 0; //Armazena o valor lido pelo potenciômetro 1
int val_garra = 0; //Armazena o valor lido pelo potenciômetro 2
int val_lado1 = 0; //Armazena o valor lido pelo potenciômetro 3
int val_lado2 = 0; //Armazena o valor lido pelo potenciômetro 4
 
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
 move_base(); // Função para mover base.
 move_garra(); // Função para mover a garra.
 move_lado1(); // Função para mover o servo lado1.
 move_lado2(); // Função para mover o servo lado2.
}
 
void move_base()
{
  val_base = analogRead(pino_1); //Recebe o valor lido pelo potenciômetro 1
  val_base = map(val_base, 0, 1023, 1, 180);
  base.write(val_base);
  delay(10); // Delay para suavizar movimentos.
}
void move_lado1()
{
  val_lado1 = analogRead(pino_2); //Recebe o valor lido pelo potenciômetro 2
  val_lado1 = map(val_lado1, 0, 1023, 40, 140);
  lado1.write(val_lado1);
  delay(10); // Delay para suavizar movimentos.
}
 
void move_lado2()
{
  val_lado2 = analogRead(pino_3); //Recebe o valor lido pelo potenciômetro 3
  val_lado2 = map(val_lado2, 0, 1023, 50, 120);
  lado2.write(val_lado2);
  delay(10); // Delay para suavizar movimentos.
}
 
void move_garra()
{
  val_garra = analogRead(pino_4); //Recebe o valor lido pelo potenciômetro 4
  val_garra = map(val_garra, 0, 1023, 40, 100);
  garra.write(val_garra);
  delay(10); // Delay para suavizar movimentos.
}
