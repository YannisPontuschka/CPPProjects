# Programação Orientada a Aspectos (AOP) em C++

Este projeto demonstra uma implementação do **Paradigma de Programação Orientada a Aspectos (AOP)** em C++, utilizando uma hierarquia de classes que representam diferentes tipos de contas bancárias.


## Estrutura do Projeto

### Hierarquia de Classes

```
IConta (Interface)
    │
    ├── Conta (Classe Base)
    │       │
    │       ├── ContaInvestimento
    │       ├── ContaSalario
    │       └── ContaPoupanca
    │
    └── ContaAuditoriaDecorator (Aspecto)
```

### Componentes Principais

- **`IConta`**: Interface que define o contrato para todas as contas (sacar, depositar, resgatar saldo, e resgatar data de abertura)

- **`Conta`**: Classe base concreta que implementa a lógica fundamental de uma conta bancária

- **`ContaInvestimento`**, **`ContaSalario`**, **`ContaPoupanca`**: Classes derivadas que representam tipos específicos de contas

- **`ContaAuditoriaDecorator`**: Decorator que implementa o aspecto de auditoria, adicionando validação de valores e logging de operações

O padrão **Decorator** é utilizado para implementar o paradigma orientado a aspectos. O `ContaAuditoriaDecorator` envolve qualquer implementação de `IConta`, adicionando comportamento de auditoria sem modificar as classes originais.

## Como Compilar e Executar

```bash
g++ program.cpp -o program
./program
```

