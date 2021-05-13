int pinoTrig = 5;
int pinoEcho = 6;
void setup()
{
    /*
       Define que estes pinos serão de
       saída (Trig) e entrada (Echo):
    */
    pinMode (pinoTrig, OUTPUT);
    pinMode (pinoEcho, INPUT);
    /*
       Inicia uma comunicação serial com
       velocidade de transmissão de 9600:
    */
    Serial.begin (9600);
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
       Mostra o valor da distância no serial
       e faz uma pausa de 100ms:
    */
   Serial.println (distancia);
   delay (100);
  }
}
