#include <iostream>
#include <string>
#include <ctime>

class IConta
{

public:
    virtual void sacar(double dinheiro) = 0;
    virtual void depositar(double dinheiro) = 0;
    virtual double resgatarSaldo() = 0;
    virtual time_t resgatarDataAbertura() = 0;
    virtual ~IConta() = default;
};

class ContaAuditoriaDecorator : public IConta
{
private:
    IConta *conta;

public:
    ContaAuditoriaDecorator(IConta *conta) : conta(conta) {}
    void sacar(double dinheiro) override
    {
        if (dinheiro <= 0)
        {
            std::cout << "ERRO: Dinheiro negativo ou nulo" << std::endl;
            return;
        }

        double saldoAtual = resgatarSaldo();

        if (saldoAtual - dinheiro < 0)
        {
            std::cout << "ERRO: saldo atual (" << saldoAtual << ") não possibilita o saque de " << dinheiro << std ::endl;
            return;
        }

        std::cout << "LOG: Auditoria: Iniciando saque de " << dinheiro << std::endl;
        conta->sacar(dinheiro);
        std::cout << "LOG: Auditoria: Saque concluído." << std::endl;
    }
    void depositar(double dinheiro) override
    {
        conta->depositar(dinheiro);
    }

    double resgatarSaldo() override
    {
        return conta->resgatarSaldo();
    }

    time_t resgatarDataAbertura() override
    {
        return conta->resgatarDataAbertura();
    }
};

class Conta : public IConta
{
private:
    time_t dataAbertura;
    double saldo;

public:
    Conta(double saldoInicial) : saldo(saldoInicial)
    {
        dataAbertura = time(NULL);
    }
    void sacar(double dinheiro)
    {
        saldo = saldo - dinheiro;
    }
    void depositar(double dinheiro)
    {
        saldo = saldo + dinheiro;
    }

    double resgatarSaldo()
    {
        return saldo;
    }

    time_t resgatarDataAbertura()
    {
        return dataAbertura;
    }
};

class ContaInvestimento : public Conta
{
public:
    ContaInvestimento(double saldoInicial) : Conta(saldoInicial)
    {
        std::cout << "Conta de Investimento Inicializada" << std::endl;
    }
};

class ContaSalario : public Conta
{
public:
    ContaSalario(double saldoInicial) : Conta(saldoInicial)
    {
        std::cout << "Conta Salário Inicializada" << std::endl;
    }
};

class ContaPoupanca : public Conta
{
public:
    ContaPoupanca(double saldoInicial) : Conta(saldoInicial)
    {
        std::cout << "Conta Poupança Inicializada" << std::endl;
    }
};