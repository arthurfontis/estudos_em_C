#include <stdio.h>

int soma(int a, int b)
{
    int soma = a + b;
    return soma;
}
int multiplicacao(int a, int b)
{
    int multiplica = a * b;
    return multiplica;
}
int divisao(int a, int b)
{
    int divide = a / b;
    return divide;
}
int subtracao(int a, int b)
{
    int subtrai = a - b;
    return subtrai;
}

int main()
{
    int n1, n2;
    int operacao = 0;
    while (operacao != 5)
    {
        printf("\nSelecione uma operação: \n");
        printf("1 - Soma \n");
        printf("2 - Subtracao \n");
        printf("3 - Multiplicacao \n");
        printf("4 - Divisao \n");
        printf("5 - Sair \n");

        scanf("%d", &operacao);
        if (operacao == 5)
        {
            printf("Saindo...\n");
            continue;
        }
        
        printf("Insira os numeros para a operacao %d: ", operacao);
        scanf("%d %d", &n1, &n2);

        switch (operacao)
        {
        case 1:
            printf("Resultado: %d\n", soma(n1, n2));
            break;
        case 2:
            printf("Resultado: %d\n", subtracao(n1, n2));
            break;
        case 3:
            printf("Resultado: %d\n", multiplicacao(n1, n2));
            break;
        case 4:
            printf("Resultado: %d\n", divisao(n1, n2));
            break;
        default:
        printf("Op Inválida! \n");
            break;
        }
    }

    return 0;
}