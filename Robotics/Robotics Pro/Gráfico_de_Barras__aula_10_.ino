// Variáveis: 
int leitura = 0;
int porta = 0;
int leds = 0;

// Inicia uma vez:
void setup()
{
  /* Define A0 como pino de entrada e
  os pinos de 2 a 10 como de saída: */
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  /* Lê o valor analógico (do pino A0) e
  mapeia para a faixa de 2 até 10: */
  leitura = analogRead(A0);
  leds = map(leitura, 0, 1023, 2, 10);
  
  // Percorre as portas usadas do Arduino:
  for (porta = 2; porta <= 10; porta += 1) {
    if (porta <= leds) {
      // Acende o LED:
      digitalWrite(porta, HIGH);
    } else {
      // Apaga o LED:
      digitalWrite(porta, LOW);
    }
  }
  // Pausa de 10 ms:
  delay(10); 
}
