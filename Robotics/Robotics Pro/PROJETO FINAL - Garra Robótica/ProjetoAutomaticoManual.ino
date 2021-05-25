#include <Servo.h>

Servo garra;
Servo base;
Servo lado1;
Servo lado2;

int pinoTrig = 10;
int pinoEcho = 11;

int i=0; // Variável para incrementar a posição de 1 em 1.
int tempo=1000; // Controle do tempo de parada entre cada função.
int Vspeed=5; // Velocidade de movimento 0 - rápido / 10 - lento.

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
int flag = 1; // Tipo de Movimento (Automático=1 Manual=2)

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

  // Declarando os pinos do Ultrassom
  pinMode (pinoTrig, OUTPUT);
  pinMode (pinoEcho, INPUT);

}

void loop()
{

// Verificando Distância
  digitalWrite (pinoTrig, LOW);
  delayMicroseconds (2);
  digitalWrite (pinoTrig, HIGH);
  delayMicroseconds (10);
  digitalWrite (pinoTrig, LOW);
  float duracao = pulseIn (pinoEcho, HIGH);
  float distancia = 0.0343 * duracao / 2.0;
  
if (distancia < 10.0) 
{
  if (flag==2)
  {
  // Posição central dos motores.
  pos_x = 90; // Inicializa a base na posição central
  pos_y1 = 90; // Inicializa o corpo na posição central
  pos_y2 = 85; // Inicializa o corpo na posição central
  base.write(pos_x); 
  lado1.write(pos_y1);
  lado2.write(pos_y2);
  flag=1;
  }
  movimento_auto();
}

if (distancia >= 10.0) 
{
  if (flag==1)
  {
  // Posição central dos motores.
  pos_x = 90; // Inicializa a base na posição central
  pos_y1 = 90; // Inicializa o corpo na posição central
  pos_y2 = 85; // Inicializa o corpo na posição central
  base.write(pos_x); 
  lado1.write(pos_y1);
  lado2.write(pos_y2);
  flag=2;
  }
  
 digitalWrite(LED,LOW);
 
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



// Funções automáticas

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

void movimento_auto()
{
  digitalWrite(LED,HIGH); // Indicando que o robô irá se mover de forma automática
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
