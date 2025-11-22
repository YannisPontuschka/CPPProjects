#include <iostream>
#include "classes.h"

int main()
{
    IConta *contaBase = new ContaInvestimento(100);
    IConta *contaInvestimento = new ContaAuditoriaDecorator(contaBase);
    contaInvestimento->sacar(5000);

    IConta *contaSalarioBase = new ContaSalario(5000);
    IConta *salarioAuditada = new ContaAuditoriaDecorator(contaSalarioBase);
    salarioAuditada->sacar(20000);

    IConta *contaPoupanca = new ContaPoupanca(1000);
    IConta *contaPoupancaAuditada = new ContaAuditoriaDecorator(contaPoupanca);
    contaPoupancaAuditada->sacar(10000);

    delete contaBase;
    delete contaInvestimento;
    delete contaSalarioBase;
    delete salarioAuditada;
    delete contaPoupanca;
    delete contaPoupancaAuditada;

    return 0;
}