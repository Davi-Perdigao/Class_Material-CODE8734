#include <Servo.h>

/* Cria variável do tipo servo e
   cria valores para servo travado
   e destravado como 90º e 0º,
   respectivamente:         */
Servo servo;
int SERVO_TRAVADO = 90;
int SERVO_DESTRAVADO = 0;

/* Estabelece uma distância mínima para
   habilitar o servo. Essa distância é
   guardada pela variável distanciaMin:*/
float distanciaMin = 100.0;

/* Pinos usados pelo Arduino: */
int pinoServo = 9;
int pinoTrig = 10;
int pinoEcho = 11;

void setup ()
{
  /* Habilita pinos como entrada (Echo)
     e saída (Servo, Echo) para Arduino: */
  pinMode (pinoServo, OUTPUT);
  pinMode (pinoTrig, OUTPUT);
  pinMode (pinoEcho, INPUT);
  
  /* Inicia a variável servo, atribuindo
     a ela o pino 9:           */
  servo.attach (pinoServo);
  servo.write (SERVO_TRAVADO);
}

void loop ()
{
  /* Faz um pulso no pino Trig com duração
     de 10 microssegundos:             */
  digitalWrite (pinoTrig, LOW);
  delayMicroseconds (2);
  digitalWrite (pinoTrig, HIGH);
  delayMicroseconds (10);
  digitalWrite (pinoTrig, LOW);
  
  /* Recebe a duração do pulso com o comando
     'pulseIn' e armazena na variável criada
     com o nome de 'duracao':             */
  float duracao = pulseIn (pinoEcho, HIGH);
  
  /* Sabendo que a velocidade do som no ar
     é de aproximadamente 0.0343 cm/us, e
     que o pulso percorreu a distância duas
     vezes ('foi' e 'voltou'), a distância
     do objeto é dada pela fórmula:
     distancia = 0.0343 * duracao / 2    */
  float distancia = 0.0343 * duracao / 2.0;
  
  /* Verifica se a distância está na faixa
     mínima de 5cm e máxima de 3m lida pelo
     sensor ultrassônico:        */
  if (distancia < 300.0) {
     if (distancia < distanciaMin) {
       
       /* Se a distância for menor, ativa o
          servomotor, pelo comando 'write': */
       servo.write(SERVO_DESTRAVADO);
       delay (4000);
       servo.write(SERVO_TRAVADO);
     }
  }
  
  /* Delay para reduzir consumo computacional: */
  delay (100);
}
