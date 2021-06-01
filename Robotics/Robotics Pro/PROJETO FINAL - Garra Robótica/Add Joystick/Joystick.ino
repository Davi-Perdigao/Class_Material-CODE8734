#include <Servo.h>

Servo garra;
Servo base;
Servo lado1;
Servo lado2;

 
int Joy=0; // Declarando a variável do botão do Joystick ligada ao pino 0
int pino_x = A0; //Inicializa o pino analógico ao eixo X do joystick
int pino_y = A1; //Inicializa o pino analógico ao eixo Y do joystick
int val_x = 0; //Armazena o valor lido pelo eixo X do joystick
int val_y = 0; //Armazena o valor lido pelo eixo Y do joystick

 
int LED=13;


void setup()
{
  // Configurações do Joystick. 
  pinMode(Joy, INPUT); //Pino que vai ler quando o joystick for apertado

  // Atenção para os pinos corretos de cada servo motor.
  garra.attach(6);
  base.attach(5);
  lado1.attach(3);
  lado2.attach(9);

  // Declarando que o LED é saída.
  pinMode(LED,OUTPUT);
}

void loop()
{

 int aperto = digitalRead(Joy); // Lendo o pino Digital conectado ao botão do Joystick.

 if (aperto == HIGH) // Se a leitura for HIGH (1) com energia, abre a garra.
 {
   garra.write(40);
 }

 else if(aperto == LOW) // Se a leitura for LOW (0) sem energia, fecha a garra.
 {
   garra.write(100);
 }

}