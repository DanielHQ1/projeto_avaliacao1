#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define colunas 50

void escreve_grau_polinomio(int grau_poli, int polinomio[][colunas], int count)
{
    for (int k = grau_poli, i = 0; k >= 0; k--, i++)
    {
        polinomio[count + 1][i] = k;
    }
    polinomio[count + 1][grau_poli + 1] = -1;
}

void criacao_polinomio(int polinomio1[][colunas], int *count)
{
    int continuar_entrada = 1;
    int grau_poli;
    int entrada_numero = 0;
    int count2 = *count;
    
    while(continuar_entrada == 1)
    {
        printf("Digite qual o grau do polinomio a ser recebido pelo programa: \n");
        if (scanf("%d", &grau_poli) != 1)
        {
            printf("Entrada invalida! Encerrando programa.\n");
            continuar_entrada = 0;
            break;
        }
        
        escreve_grau_polinomio(grau_poli, polinomio1, count2);

        for (int k = 0, j = grau_poli; k <= grau_poli; k++, j--)
        {
            printf("Digite o coeficiente de x elevado a %d do polinomio(caso o polinomio nao possua o termo, digite o valor 0):\n", j);
            if (scanf("%d", &entrada_numero) == 1)
            {
                polinomio1[count2][k] = entrada_numero;
            }
        }
        
        printf("\nVoce deseja adicionar outro polinomio? (s=1,n=0)");
        scanf("%d",&continuar_entrada);
        count2 += 2;
        *count = count2;
    }
}

void visualizar_polinomio(int polinomio1[][colunas], int count)
{
    int polinomio_desejado;
    int procura_o_polinomio;
    int total_polinomios = count / 2;
    
    if (total_polinomios == 0)
    {
        printf("Nenhum polinomio disponivel!\n");
        return;
    }
    
    printf("Polinomios disponiveis: %d\n", total_polinomios);
    printf("Qual polinomio voce quer visualizar? (1 a %d): ", total_polinomios);
    scanf("%d", &polinomio_desejado);
    
    if (polinomio_desejado < 1 || polinomio_desejado > total_polinomios)
    {
        printf("Polinomio invalido!\n");
        return;
    }
    
    procura_o_polinomio = 2 * (polinomio_desejado - 1);
    
    printf("\nPolinomio montado:\n");
    for(int k = 0; polinomio1[procura_o_polinomio + 1][k] >= 0; k++)
    {
        printf("%dx^%d", polinomio1[procura_o_polinomio][k], polinomio1[procura_o_polinomio + 1][k]);
        if(polinomio1[procura_o_polinomio + 1][k + 1] >= 0) printf(" + ");
    }
    printf("\n");
}

void menu(int polinomio1[][colunas], int *count)
{
    int opcao = 0;
    
    while(opcao != 3)
    {
        printf("\n=== MENU ===");
        printf("\n1 - Adicionar polinomio");
        printf("\n2 - Visualizar polinomio");
        printf("\n3 - Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        
        if(opcao == 1)
        {
            criacao_polinomio(polinomio1, count);
        }
        else if(opcao == 2)
        {
            visualizar_polinomio(polinomio1, *count);
        }
        else if(opcao == 3)
        {
            printf("Saindo...\n");
        }
        else
        {
            printf("Opcao invalida!\n");
        }
    }
}

int main()
{
    int polinomio1[10][colunas];
    int count = 0;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            polinomio1[i][j] = -1;
        }
    }
    
    menu(polinomio1, &count);
    
    printf("\n");
    return 0;
}