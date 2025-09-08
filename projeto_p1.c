#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // parei parei
    bool continuar_atribuicao = true;
    int polinomio[1][50];
    int grau_poli;
    int numero;

    for (int i = 0; i <= 1; i++)
    {
        for (int k = 0; k <= 50; k++)
        {
            polinomio[i][k] = k;
        }
    }

    printf("Digite qual o grau do polinomio a ser recebido pelo programa: \n");
    if (scanf("%d", &grau_poli) != 1)
    {
        printf("Entrada invalida! Encerrando programa.\n");
    }

    while (getchar() != '\n')
        ;

    for (int k = 0; k <= grau_poli; k++)
    {
        while (1)
        {
            printf("Digite o coeficiente %d do polinomio:\n", k);

            if (scanf("%d", &numero) == 1)
            {
                polinomio[0][k] = numero;
                while (getchar() != '\n')
                    ;
                break;
            }
            else
            {
                printf("Entrada invalida! Digite um numero inteiro.\n");
                while (getchar() != '\n')
                    ;
            }
        }
    }

    for (int k = grau_poli, i = 0; k >= 0; k--, i++)
    {
        polinomio[0][i] = k;
    }

    printf("\nPolinomio montado:\n");
    for (int k = 0; k <= grau_poli; k++)
    {
        printf("%dx^%d ", polinomio[0][k], polinomio[1][k]);
        if (k < grau_poli)
            printf("+ ");
    }
    printf("\n");

    return 0;
}
