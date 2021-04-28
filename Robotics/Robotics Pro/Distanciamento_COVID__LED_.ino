int pinoTrig = 5;
int pinoEcho = 6;
int LEDV = 7;

void setup()
{
    pinMode (pinoTrig, OUTPUT);
    pinMode (pinoEcho, INPUT);
    pinMode (LEDV, OUTPUT);
    Serial.begin (9600);
}

void loop()
{  
  digitalWrite (pinoTrig, LOW);
  delayMicroseconds (2);
  digitalWrite (pinoTrig, HIGH);
  delayMicroseconds (10);
  digitalWrite (pinoTrig, LOW);

  float duracao = pulseIn (pinoEcho, HIGH);

  float distancia = 0.0343 * duracao / 2.0;

  if (distancia > 200.0) {
    digitalWrite (LEDV,LOW);
    Serial.println ("Distanciamento seguro!");
  } else {
    digitalWrite (LEDV,HIGH);
    Serial.println ("Alogmeração! Risco de contaminação!");
    delay (100);
  }
  
}
