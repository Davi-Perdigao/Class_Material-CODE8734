#include <Servo.h>
Servo servoteste;
int limite_inferior=40; // Atenção para os limites.
int limite_superior=100; // Atenção para os limites.

// Caso o servo motor esteja forçando, desligue e modifique os limites.
void setup() 
{
  servoteste.attach(6); // Escolha o pino para trocar de servo.
  // Teste apenas 1 servo motor por vez!
}

void loop()
{ 
  delay(1000);
  servoteste.write(limite_inferior); // Levando o servo motor para o limite inferior.
  delay(1000);
  servoteste.write(limite_superior); // Levando o servo motor para o limite superior.
}
// Caso seja preciso testar só um dos limites, comente a linha de código
// do outro limite, utilizando //, todo código que vier depois das duas
// barras será comentado.
