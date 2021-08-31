using System;

class MainClass {
  public static void Main (string[] args) {
    banco AdvBank = new banco();
    Console.WriteLine("Digite o nome do titular da conta: ");
    AdvBank.nome = Console.ReadLine();
    Console.WriteLine("Digite o saldo inicial da conta: ");
    AdvBank.saldo = float.Parse(Console.ReadLine());
    float dinheiro = AdvBank.saldo;
    AdvBank.saldo = funcoes.depositar(dinheiro);
    dinheiro = AdvBank.saldo;
    AdvBank.saldo = funcoes.sacar(dinheiro);
    Console.WriteLine("Olá " + AdvBank.nome + ", seu saldo atual é de: " + AdvBank.saldo);
  }
}