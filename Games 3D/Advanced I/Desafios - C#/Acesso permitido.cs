/*Desenvolva um algoritmo que solicite a entrada da idade
de um determinado usuário, se for menor que 18 anos exiba 
na cor vermelha “Sem permissão”, caso seja maior ou igual 
a 18 anos exiba na cor verde “Permissão concedida”
*/

using System;
using System.Collections.Generic; //Contém interfaces e classes que definem coleções genéricas, que permitem aos usuários criar coleções fortemente tipadas que fornecem melhor segurança de tipo e desempenho do que coleções não genéricas 
using System.Linq; //Oferece classes e interfaces compatíveis com consultas que usam LINQ (Consulta Integrada à Linguagem).
using System.Text; // Contém classes que representam as codificações de caracteres ASCII e Unicode, classes base abstratas para conversão de blocos de caracteres entre blocos de bytes
using System.Threading.Tasks; //Uma tarefa (ou task) representa uma unidade de trabalho que deverá ser realizada

class Program
{
  static void Main(string[] args)
  {
    Processar();
  }

  private static void Processar()
  {
    int Idade;
    Console.Write("Informe a sua idade: ");
    int.TryParse(Console.ReadLine(), out Idade); //Se a conversão falhar retorna zero

    if (Idade >= 18)
    {
      Console.ForegroundColor = ConsoleColor.Green;
      Console.WriteLine("Acesso permitido");
    }
    else
    {
      Console.ForegroundColor = ConsoleColor.Red;
      Console.WriteLine("Acesso Negado");
    }
  }
}
