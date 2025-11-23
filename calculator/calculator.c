#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef enum OPERATION
{
    SUM,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER,
} OPERATION;

typedef enum CONVERTIONS
{
    DEC2BIN,
    BIN2DEC,
} CONVERTIONS;

typedef enum CHOICE
{
    MATH_OPERATIONS,
    BASE_CONVERSIONS,
    EXIT
} CHOICE;

double get_operand()
{
    double input_number;
    scanf("%lf", &input_number);
    return input_number;
}

CHOICE get_choice()
{
    CHOICE choices[] = {MATH_OPERATIONS, BASE_CONVERSIONS, EXIT};
    char user_choice;
    scanf(" %c", &user_choice);
    int user_choice_int = user_choice - '0';
    int user_choice_index = user_choice_int - 1;
    return choices[user_choice_index];
}

OPERATION get_operation()
{
    OPERATION operations[] = {
        SUM,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISION,
        POWER,
    };
    char user_operation_chosen;
    scanf(" %c", &user_operation_chosen);
    int user_choice_int = user_operation_chosen - '0';
    int user_choice_index = user_choice_int - 1;
    return operations[user_choice_index];
}

double operate(int *valid_operation)
{
    printf("\n\n====OPERAÇÕES MATEMÁTICAS ====\n\n");
    printf("\n\n1 - Soma\n2 - Subtração\n3 - Multiplicação\n");
    printf("4 - Divisão\n5 - Potência\n\n");
    printf("Selecione uma operação: ");
    OPERATION selected_operation = get_operation();
    printf("Digite o primeiro número: ");
    double n1 = get_operand();
    printf("Digite o segundo número: ");
    double n2 = get_operand();

    switch (selected_operation)
    {
    case SUM:
        return n1 + n2;
    case SUBTRACTION:
        return n1 - n2;
    case MULTIPLICATION:
        return n1 * n2;
    case DIVISION:
        return n1 / n2;
    case POWER:
        return pow(n1, n2);
    default:
        *valid_operation = 0;
        printf("Operação inválida!!\n");
        return -1;
    }
}

CONVERTIONS get_base_convertion()
{
    CONVERTIONS bases[] = {DEC2BIN, BIN2DEC};
    char *user_choice;
    scanf("%s", user_choice);
    int user_choice_index = atoi(user_choice) - 1;
    return bases[user_choice_index];
}

int get_number_of_necessary_digits(int decimal_number)
{
    int number = 0;
    while (decimal_number > 0)
    {
        decimal_number /= 2;
        number++;
    }
    return number;
}

char *covert_dec2bin()
{

    printf("Digite o número em decimal: ");
    int number_in_decimal;
    scanf("%d", &number_in_decimal);
    int number_of_digits = get_number_of_necessary_digits(number_in_decimal);

    char *binary = (char *)malloc(sizeof(char) * number_of_digits);
    int i = number_of_digits - 1;
    while (number_in_decimal > 0)
    {
        int rest = number_in_decimal % 2;
        number_in_decimal /= 2;
        char digit = rest + '0';
        binary[i] = digit;
        i--;
    }
    return binary;
}

int convert_bin2dec()
{
    char *binary = (char *)malloc(sizeof(char) * 32);
    printf("Digite o número binário: ");
    scanf("%s", binary);
    int number_of_digits = strlen(binary);
    int number = 0;
    for (int i = 0; i < number_of_digits; i++)
    {
        int expoent = number_of_digits - i - 1;
        number += pow(2, expoent) * (binary[i] - '0');
    }
    return number;
}

void convert_base()
{
    printf("\n\n====CONVERSÕES DE BASE ====\n");
    printf("1 - Decimal para binário\n2 - Binário para decimal\n");
    CONVERTIONS selected_convertion = get_base_convertion();
    switch (selected_convertion)
    {
    case DEC2BIN:
        char *binary = covert_dec2bin();
        printf("Número binário: %s\n\n", binary);
        break;

    case BIN2DEC:
        int decimal_number = convert_bin2dec();
        printf("Número decimal: %d\n", decimal_number);

    default:
        break;
    }
}
int main(void)
{

    CHOICE selected_choice = MATH_OPERATIONS; // Inicializar para evitar valor lixo
    while (selected_choice != EXIT)
    {

        printf("====MENU PRINCIPAL====\n\n");
        printf("Selecione uma opção:\n");
        printf("1 - Operações Matemáticas\n2 - Conversão entre Bases\n3 - Sair do programa\n\n");

        selected_choice = get_choice();
        switch (selected_choice)
        {
        case MATH_OPERATIONS:
        {
            int is_valid_operation = 1;
            double result = operate(&is_valid_operation);
            if (is_valid_operation)
                printf("Resultado: %.2lf.\n\n", result);
            break;
        }
        break;
        case BASE_CONVERSIONS:
            convert_base();
            break;
        case EXIT:
            printf("Finalizando programa.\n");
            break;
        default:
            printf("Erro. Opção inexistente\n\n");
        }
    }
    return 0;
}