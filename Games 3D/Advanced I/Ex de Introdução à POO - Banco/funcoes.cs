using System.Collections;
using System.Collections.Generic;
using System;

public class funcoes
{
  public static float sacar (float s)
  {
    Console.WriteLine("Digite um valor a ser sacado: ");
    s = s - float.Parse(Console.ReadLine());
    return s;
  }
  public static float depositar (float s)
  {
    Console.WriteLine("Digite um valor a ser depositado: ");
    s = s + float.Parse(Console.ReadLine());
    return s;
  }
}