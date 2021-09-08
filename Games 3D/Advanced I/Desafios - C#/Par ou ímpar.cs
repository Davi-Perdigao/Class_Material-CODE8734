/*Desenvolva um algoritmo que solicite a entrada de 
um número e calcule se o número é par ou impar
*/

using System;

class Program {
static void Main(string[] args)
{
  int NumeroDigitado;
  Console.Write("Insira um número: "); //Exibe a mensagem

  NumeroDigitado = Convert.ToInt32(Console.ReadLine()); //Lê e converte para int o número informado pelo usuário

  if (NumeroDigitado % 2 == 0)
  {
    //Número Par
    Console.WriteLine("Par");
  }else{
      //Número Impar
      Console.WriteLine("Impar");
    }
  }
}
