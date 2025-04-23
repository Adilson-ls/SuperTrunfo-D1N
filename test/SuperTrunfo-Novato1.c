#include <stdio.h>
#include <string.h> // Necessário para usar strcpy

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

    // char nomes[NUM_CARTAS][TAM_NOME];
    // long long populacoes[NUM_CARTAS];
    // double areas[NUM_CARTAS];
    // double pibs[NUM_CARTAS];

int main() {

    // Definição das variáveis para armazenar as propriedades das cidades
    char codigo1[5];
    char nome1[50];
    int populacao1;
    float area1;
    float pib1;

    char codigo2[5];
    char nome2[50];
    int populacao2;
    float area2;
    float pib2;

    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    printf("--- Cadastro da Primeira Cidade ---\n");
    printf("Digite o código da cidade 1: ");
    scanf("%s", codigo1);
    printf("Digite o nome da cidade 1: ");
    scanf(" %s[^\n]", nome1);
    printf("Digite a população da cidade 1: ");
    scanf("%d", &populacao1);
    printf("Digite a área da cidade 1 (em km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB da cidade 1 (em bilhões de dólares): ");
    scanf("%f", &pib1);
    printf("\n");

    printf("--- Cadastro da Segunda Cidade ---\n");
    printf("Digite o código da cidade 2: ");
    scanf("%s", codigo2);
    printf("Digite o nome da cidade 2: ");
    scanf(" %s[^\n]", nome2);
    printf("Digite a população da cidade 2: ");
    scanf("%d", &populacao2);
    printf("Digite a área da cidade 2 (em km²): ");
    scanf("%f", &area2);
    printf("Digite o PIB da cidade 2 (em bilhões de dólares): ");
    scanf("%f", &pib2);
    printf("\n");

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    printf("--- Comparação das Cidades ---\n");


    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Comparação por População
    printf("Comparando por População:\n");
    if (populacao1 > populacao2) {
        printf("Cidade 1 (%s) tem maior população (%d).\n", nome1, populacao1);
    } else if (populacao2 > populacao1) {
        printf("Cidade 2 (%s) tem maior população (%d).\n", nome2, populacao2);
    } else {
        printf("As cidades têm a mesma população (%d).\n", populacao1);
    }

    // Comparação por Área
    printf("\nComparando por Área:\n");
    if (area1 > area2) {
        printf("Cidade 1 (%s) tem maior área (%.2f km²).\n", nome1, area1);
    } else if (area2 > area1) {
        printf("Cidade 2 (%s) tem maior área (%.2f km²).\n", nome2, area2);
    } else {
        printf("As cidades têm a mesma área (%.2f km²).\n", area1);
    }

    // Comparação por PIB
    printf("\nComparando por PIB:\n");
    if (pib1 > pib2) {
        printf("Cidade 1 (%s) tem maior PIB (%.2f bilhões).\n", nome1, pib1);
    } else if (pib2 > pib1) {
        printf("Cidade 2 (%s) tem maior PIB (%.2f bilhões).\n", nome2, pib2);
    } else {
        printf("As cidades têm o mesmo PIB (%.2f bilhões).\n", pib1);
    }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    char cidadeVencedoraPopulacao[50];
    char cidadeVencedoraArea[50];
    char cidadeVencedoraPIB[50];

    if (populacao1 > populacao2) {
        strcpy(cidadeVencedoraPopulacao, nome1);
    } else {
        strcpy(cidadeVencedoraPopulacao, nome2);
        if (populacao1 == populacao2) {
            strcpy(cidadeVencedoraPopulacao, "Nenhuma (Empate)");
        }
    }
    printf("\nA cidade com maior população é: %s\n", cidadeVencedoraPopulacao);

    if (area1 > area2) {
        strcpy(cidadeVencedoraArea, nome1);
    } else {
        strcpy(cidadeVencedoraArea, nome2);
        if (area1 == area2) {
            strcpy(cidadeVencedoraArea, "Nenhuma (Empate)");
        }
    }
    printf("A cidade com maior área é: %s\n", cidadeVencedoraArea);

    if (pib1 > pib2) {
        strcpy(cidadeVencedoraPIB, nome1);
    } else {
        strcpy(cidadeVencedoraPIB, nome2);
        if (pib1 == pib2) {
            strcpy(cidadeVencedoraPIB, "Nenhuma (Empate)");
        }
    }
    printf("A cidade com maior PIB é: %s\n", cidadeVencedoraPIB);

    return 0;
}
