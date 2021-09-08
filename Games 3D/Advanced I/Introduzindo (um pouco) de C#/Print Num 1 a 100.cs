/*
Criar um código que imprima apenas os números pares de 1 a 100
*/

using System;
using System.Collections.Generic;

class Program
{
    static void Main (string[] args)
    {
        for (int i=2; i<=100; i=i +2)
        {
            Console.WriteLine(i);
        }
    }
}