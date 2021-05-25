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

int pos_x = 90; // Inicializa a base na posição central
int pos_y1 = 90; // Inicializa o corpo na posição central
int pos_y2 = 85; // Inicializa o corpo na posição central
 
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
 
  // Posição central dos motores.
  base.write(pos_x);
  lado1.write(pos_y1);
  lado2.write(pos_y2);
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
 
 move_base(); // Função para mover no eixo X.
 move_corpo(); // Função para mover no eixo Y.
 
}
 
void move_base()
{
 val_x = analogRead(pino_x); //Recebe o valor lido pelo eixo X do joystick
 if ((val_x<420)||(val_x>580)) // Verifica se o Joystick não está parado.
 {
 val_x = map(val_x, 0, 1023, -1, 1); //Converte o valor lido para um valor de incremento (-1 a 1)
 pos_x=pos_x+val_x; // Incrementa o ângulo.
 if(pos_x>180) // Limita o valor possível do ângulo em 180º
 {pos_x=180;}
 if(pos_x<1)// Limita o valor possível do ângulo em 1º
 {pos_x=1;}
 base.write(pos_x);
 delay(10); // Delay para suavizar movimentos.
 }
}
 
void move_corpo()
{
 val_y = analogRead(pino_y); //Recebe o valor lido pelo eixo Y do joystick
 val_y2 = analogRead(pino_y); //Recebe o valor lido pelo eixo Y do joystick
 if ((val_y<420)||(val_y>580)) // Verifica se o Joystick não está parado.
 {
 val_y = map(val_y, 0, 1023, -1, 1); //Converte o valor lido para um valor de incremento (-1 a 1)
 val_y2 = map(val_y2, 0, 1023, 1, -1);  //Converte o valor lido para um valor de incremento (-1 a 1)
 
 pos_y1=pos_y1+val_y; // Incrementa o ângulo.
 if(pos_y1>140)  // Limita o valor possível do ângulo em 140º
 {pos_y1=140;}
 if(pos_y1<40) // Limita o valor possível do ângulo em 40º
 {pos_y1=40;}
 
 pos_y2=pos_y2+val_y2; // Incrementa o ângulo.
 if(pos_y2>120)  // Limita o valor possível do ângulo em 120º
 {pos_y2=120;}
 if(pos_y2<50) // Limita o valor possível do ângulo em 50º
 {pos_y2=50;}
 
 lado1.write(pos_y1);
 lado2.write(pos_y2);
 delay(10);
 }
}
