#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define colunas 50


void escreve_grau_polinomio(int grau_poli, int polinomio[][colunas])
{
    for (int k = grau_poli, i = 0; k >= 0; k--, i++)
    {
        polinomio[1][i] = k;
    }
}

int main()
{

    // bool continuar_atribuicao = true;
    int polinomio[2][colunas];
    int grau_poli;
    int entrada_numero;











    printf("Digite qual o grau do polinomio a ser recebido pelo programa: \n");
    if (scanf("%d", &grau_poli) != 1)
    {
        printf("Entrada invalida! Encerrando programa.\n");
    }
    escreve_grau_polinomio(grau_poli, polinomio);


        

    for (int k = 0, j = grau_poli; k <= grau_poli; k++, j--)
    {

        
            printf("Digite o coeficiente de x elevado a %d do polinomio:\n", j);
            // serve para apenas ses entrada do numero for inteiro adicionar na lista
            if (scanf("%d", &entrada_numero) == 1)
            {
                polinomio[0][k] = entrada_numero;

            }

        
    }




    printf("\nPolinomio montado:\n");
    for (int k = 0; k <= grau_poli; k++)
    {
        printf("%dx^%d ", polinomio[0][k], polinomio[1][k]);
    }
    printf("\n");

    return 0;
}
