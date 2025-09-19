// Grupo
// Carlos Alexandre maciel Gonçalves RA: 10320951
// Daniel Henrique Carvalho RA: 10736657
// Felipe Sousa Vasques Honorato RA: 10735577


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
        
        printf("\nVoce deseja adicionar outro polinomio? (s=1,n=0) ");
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

void soma_polinomios(int polinomios[][colunas], int *contador)
{
    int total_polinomios_existentes = *contador / 2;

    // Verifica se ha pelo menos dois polinômios para somar
    if (total_polinomios_existentes < 2) {
        printf("Necessario pelo menos dois polinomios para realizar a soma.\n");
        return;
    }

    // Selecao dos polinomios a serem somados
    int numero_poli1;
	int numero_poli2;
    printf("Digite o numero do primeiro polinomio para somar (1 a %d): ", total_polinomios_existentes);
    scanf("%d", &numero_poli1);
    printf("Digite o numero do segundo polinomio para somar (1 a %d): ", total_polinomios_existentes);
    scanf("%d", &numero_poli2);

    // Verifica se os indices fornecidos sao validos
    if (numero_poli1 < 1 || numero_poli1 > total_polinomios_existentes || numero_poli2 < 1 || numero_poli2 > total_polinomios_existentes) {
        printf("Polinomios invalidos!\n");
        return;
    }

    // Calcula os indices nas linhas da matriz
    int linha_coef_poli1 = 2 * (numero_poli1 - 1);
    int linha_coef_poli2 = 2 * (numero_poli2 - 1);
    int linha_resultado = *contador;           // onde armazenar coeficientes do resultado
    int linha_graus_resultado = linha_resultado + 1; // onde armazenar os graus do resultado

    // Inicializa a linha do polinomio resultado com 0 e -1
    for (int i = 0; i < colunas; i++) {
        polinomios[linha_resultado][i] = 0;       // zera coeficientes
        polinomios[linha_graus_resultado][i] = -1; // marca fim dos graus com -1
    }

    // Copia o polinomio 1 para o resultado
    int pos_resultado = 0;
    while (polinomios[linha_coef_poli1 + 1][pos_resultado] >= 0) {
        polinomios[linha_graus_resultado][pos_resultado] = polinomios[linha_coef_poli1 + 1][pos_resultado]; // grau
        polinomios[linha_resultado][pos_resultado] = polinomios[linha_coef_poli1][pos_resultado];           // coeficiente
        pos_resultado++;
    }

    // Soma os coeficientes do polinômio 2 no resultado
    for (int j = 0; polinomios[linha_coef_poli2 + 1][j] >= 0; j++) {
        int grau_atual = polinomios[linha_coef_poli2 + 1][j];
        int coef_atual = polinomios[linha_coef_poli2][j];
        int grau_encontrado = 0;

        // Verifica se o grau ja existe no resultado
        for (int k = 0; polinomios[linha_graus_resultado][k] >= 0; k++) {
            if (polinomios[linha_graus_resultado][k] == grau_atual) {
                polinomios[linha_resultado][k] += coef_atual;
                grau_encontrado = 1;
                break;
            }
        }

        // Se nao encontrou o grau, adiciona novo termo no resultado
        if (!grau_encontrado) {
            polinomios[linha_graus_resultado][pos_resultado] = grau_atual;
            polinomios[linha_resultado][pos_resultado] = coef_atual;
            pos_resultado++;
        }
    }

    // Ordena os termos do resultado em ordem decrescente de grau
    for (int i = 0; i < pos_resultado - 1; i++) {
        for (int j = i + 1; j < pos_resultado; j++) {
            if (polinomios[linha_graus_resultado][i] < polinomios[linha_graus_resultado][j]) {
             // troca graus
                int tmp_grau = polinomios[linha_graus_resultado][i];
                polinomios[linha_graus_resultado][i] = polinomios[linha_graus_resultado][j];
                polinomios[linha_graus_resultado][j] = tmp_grau;

                // troca coeficientes correspondentes
                int tmp_coef = polinomios[linha_resultado][i];
                polinomios[linha_resultado][i] = polinomios[linha_resultado][j];
                polinomios[linha_resultado][j] = tmp_coef;
        }
    }
}


    // Marca o fim da linha de graus
    polinomios[linha_graus_resultado][pos_resultado] = -1;

    // Atualiza o contador (adicionamos mais um polinomio na matriz)
    *contador += 2;

    printf("Polinomio resultante da soma foi adicionado como polinomio %d.\n", (*contador / 2));
}



void calcular_valor_polinomio(int polinomio1[][colunas], int count)
{
    int polinomio_desejado = 0;
    int procura_o_polinomio;
    int valor_raiz;
    int somador = 0;
    int total_polinomios = count / 2;

    if (total_polinomios == 0)
    {
        printf("Nenhum polinomio disponivel para calcular!\n");
        return;
    }

    printf("Polinomios disponiveis: %d\n", total_polinomios);
    printf("Qual polinomio deseja calcular? ");
    scanf("%d", &polinomio_desejado);

    if (polinomio_desejado < 1 || polinomio_desejado > total_polinomios)
    {
        printf("Polinomio invalido!\n");
        return;
    }

    printf("Qual valor para x voce deseja usar: ");
    scanf("%d", &valor_raiz);

    procura_o_polinomio = 2 * (polinomio_desejado - 1);

    for (int i = 0; polinomio1[procura_o_polinomio + 1][i] >= 0; i++)
    {
        int coef = polinomio1[procura_o_polinomio][i];
        int expo = polinomio1[procura_o_polinomio + 1][i];

        somador += coef * (int)pow(valor_raiz, expo);
    }

    printf("Para x = %d, o valor do polinomio escolhido eh: %d\n", valor_raiz, somador);
}

void menu(int polinomio1[][colunas], int *count)
{
    int opcao = 0;
    
    while(opcao != 5)
    {
        printf("\n=== MENU ===");
        printf("\n1 - Adicionar polinomio");
        printf("\n2 - Visualizar polinomio");
        printf("\n3 - Calcular valor do polinomio");
        printf("\n4 - Soma de polinomio");
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
            calcular_valor_polinomio(polinomio1, *count);
        }
        else if(opcao == 4)
        {
            soma_polinomios(polinomio1, count);
        }
        else if (opcao == 5)
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
