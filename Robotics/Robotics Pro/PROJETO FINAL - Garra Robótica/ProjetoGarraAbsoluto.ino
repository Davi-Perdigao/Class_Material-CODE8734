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
int val_y2 = 0; //Armazena o valor lido pelo eixo Y do joystick
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
 
 digitalWrite(LED,HIGH);
 
 int aperto = digitalRead(Joy); // Lendo o pino Digital conectado ao botão do Joystick.
 
 if (aperto == HIGH) // Se a leitura for HIGH (1) com energia, abre a garra.
 {
   garra.write(40);
 }
 else if(aperto == LOW) // Se a leitura for LOW (0) sem energia, fecha a garra.
 {
   garra.write(100);
 }
 
// Lendo os valores dos eixos X e Y do Joystick e convertendo para valores em graus (1 a 180º).
 
 val_x = analogRead(pino_x); //Recebe o valor lido pelo eixo X do joystick
 val_x = map(val_x, 0, 1023, 1, 180); //Converte o valor lido para um valor em graus (1 a 180º)
 val_y = analogRead(pino_y); //Recebe o valor lido pelo eixo Y do joystick
 val_y2 = analogRead(pino_y); //Recebe o valor lido pelo eixo Y do joystick
 val_y = map(val_y, 0, 1023, 40, 140); //Converte o valor lido para um valor em graus (1 a 180º)
 val_y2 = map(val_y2, 0, 1023, 120, 50); //Converte o valor lido para um valor em graus (1 a 180º)
 
 base.write(val_x);
 lado1.write(val_y);
 lado2.write(val_y2);
}
