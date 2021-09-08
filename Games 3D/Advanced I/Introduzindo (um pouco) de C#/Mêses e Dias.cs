/*
Criar um código para verificação do mês salvo em uma 
variável e impressão do número de dias que ele tem. 
Por exemplo: se for Janeiro, imprimir “tem 31 dias”
*/

using System;

class MainClass {
  public static void Main (string[] args) {
    string mes = Console.ReadLine();
    if ( mes == "janeiro"){
      Console.WriteLine("Tem 31 dias");
    }
    else if ( mes == "fevereiro"){
      Console.WriteLine("Tem 28 dias");
    }
    else if ( mes == "março"){
      Console.WriteLine("Tem 31 dias");
    }
    else if ( mes == "abril"){
      Console.WriteLine("Tem 30 dias");
    }
    else if ( mes == "maio"){
      Console.WriteLine("Tem 31 dias");
    }
    else if ( mes == "junho"){
      Console.WriteLine("Tem 30 dias");
    }
    else if ( mes == "julho"){
      Console.WriteLine("Tem 31 dias");
    }
    else if ( mes == "agosto"){
      Console.WriteLine("Tem 31 dias");
    }
    else if ( mes == "setembro"){
      Console.WriteLine("Tem 31 dias");
    }
    else if ( mes == "outubro"){
      Console.WriteLine("Tem 31 dias");
    }
    else if ( mes == "novembro"){
      Console.WriteLine("Tem 31 dias");
    }
    else if ( mes == "dezembro"){
      Console.WriteLine("Tem 31 dias");
    }
  }
}
