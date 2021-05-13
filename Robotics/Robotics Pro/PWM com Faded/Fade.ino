// Variáveis
int luz = 0; // Intesidade da luz.
int counter; // Contador 1.
int counter2; // Contador 2.

void setup()
{
  pinMode(9, OUTPUT); // Declarando o pino 9 como saída.
}

void loop()
{
  luz = 0; // Inicia a intensidade de luz igual à 0.
  
  // Aumentando a intensidade.
  
  for (counter = 0; counter < 25; ++counter) 
  {
    analogWrite(9, luz); // PWM.
    luz += 10;
    delay(100);
  }
  
  // Reduzindo a intensidade.
  
  for (counter2 = 0; counter2 < 25; ++counter2)
  {
    analogWrite(9, luz); // PWM.
    luz += -10;
    delay(100);
  }
}
