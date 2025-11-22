# Projetos em C/C++

Este repositório contém uma coleção de projetos desenvolvidos em C e C++

### Jogo da Velha (`jogo_da_velha/`)

### Programação Orientada a Aspectos (`AOP/`/) 
Demonstração do **Paradigma de Programação Orientada a Aspectos (AOP)** em C++, utilizando uma hierarquia de classes que representam diferentes tipos de contas bancárias.


#### Estrutura do Projeto AOP

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

O padrão **Decorator** é utilizado para implementar o paradigma orientado a aspectos. O `ContaAuditoriaDecorator` envolve qualquer implementação de `IConta`, adicionando comportamento de auditoria sem modificar as classes originais.

## Como Compilar e Executar

```bash
g++ [nome_do_arquivo].cpp -o [nome_executavel]
./[nome_executavel]
```

