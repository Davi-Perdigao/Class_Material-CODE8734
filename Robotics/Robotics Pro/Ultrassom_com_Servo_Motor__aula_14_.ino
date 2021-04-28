int pinoTrig = 5;
int pinoEcho = 6;
int pinoBuzzer = 8;

void setup()
{
    /*
       Define que estes pinos serão de
       saída (Trig, Buzzer) e entrada
       (Echo): 
    */
    pinMode (pinoTrig, OUTPUT);
    pinMode (pinoEcho, INPUT);
    pinMode (pinoBuzzer, OUTPUT);
}

void loop()
{  
  /* 
     Faz um pulso no pino Trig com 
     duração de 10 microssegundos:
  */
  digitalWrite (pinoTrig, LOW);
  delayMicroseconds (2);
  digitalWrite (pinoTrig, HIGH);
  delayMicroseconds (10);
  digitalWrite (pinoTrig, LOW);
  /* 
     Recebe a duração do pulso com o comando
     'pulseIn' e armazena na variável criada
     com o nome de 'duracao':
  */
  float duracao = pulseIn (pinoEcho, HIGH);
  /* 
     Sabendo que a velocidade do som no ar
     é de aproximadamente 0.0343 cm/us, e
     que o pulso percorreu a distância duas
     vezes ('foi' e 'voltou'), a distância
     do objeto é dada pela fórmula:
     
     distancia = 0.0343 * duracao / 2
   */
  float distancia = 0.0343 * duracao / 2.0;
  /* 
     Verifica se a distância está na faixa
     mínima de 5cm e máxima de 3m lida 
     pelo sensor ultrassônico:
  */
  if (distancia > 300.0) {
     Serial.println ("fora da faixa!");
  } else {
     /*
       Verifica se a distância é menor do que
       uma distância mínima de segurança de
       10 cm, guardada por uma variável:
     */
     float distanciaMinima = 100.0;
    if (distancia < distanciaMinima) {
       /*
         Se este for o caso, aciona o buzzer.
         Senão, desliga o alarma:
       */
       digitalWrite (pinoBuzzer, HIGH);
    } else {
       digitalWrite (pinoBuzzer, LOW);
    }
  }
}
void loop ()
{
  digitalWrite (pinoTrig, LOW);
  delayMicroseconds (2);
  digitalWrite (pinoTrig, HIGH);
  delayMicroseconds (10);
  digitalWrite (pinoTrig, LOW);
  
  float duracao = pulseIn (pinoEcho, HIGH);
  float distancia = 0.0343 * duracao / 2.0;
 
  if (distancia < 300.0) {
     if (distancia < distanciaMin) {
       servo.write(SERVO_DESTRAVADO);
       delay (4000);
       servo.write(SERVO_TRAVADO);
     }
  }
  delay (100);
}
