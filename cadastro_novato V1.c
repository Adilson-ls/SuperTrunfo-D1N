#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Definição da estrutura para representar uma carta de cidade
typedef struct {
    char estado[3];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    if (area > 0) {
        return (float)populacao / area;
    } else {
        return 0; // Evitar divisão por zero
    }
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    if (populacao > 0) {
        return pib / populacao;
    } else {
        return 0; // Evitar divisão por zero
    }
}

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio
    Carta carta1, carta2;
    int atributoEscolhido;
    char atributoNome[30];

    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    printf("Digite os dados da primeira cidade:\n");
    printf("Estado (XX): ");
    scanf("%s", carta1.estado);
    printf("Código da carta: ");
    scanf("%s", carta1.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nome); // Lê a linha inteira, incluindo espaços
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    carta1.densidadePopulacional = calcularDensidadePopulacional(carta1.populacao, carta1.area);
    carta1.pibPerCapita = calcularPIBPerCapita(carta1.pib, carta1.populacao);

    printf("\nDigite os dados da segunda cidade:\n");
    printf("Estado (XX): ");
    scanf("%s", carta2.estado);
    printf("Código da carta: ");
    scanf("%s", carta2.codigo);
    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nome); // Lê a linha inteira, incluindo espaços
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    carta2.densidadePopulacional = calcularDensidadePopulacional(carta2.populacao, carta2.area);
    carta2.pibPerCapita = calcularPIBPerCapita(carta2.pib, carta2.populacao);

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Escolha do atributo para comparação (altere o número para comparar diferente atributo)
    // 1: População, 2: Área, 3: PIB, 4: Densidade Populacional, 5: PIB per capita
    atributoEscolhido = 1;

    printf("\nComparação de cartas (Atributo: ");

    // Lógica de comparação baseada no atributo escolhido
    if (atributoEscolhido == 1) {
        strcpy(atributoNome, "População");
        printf("%s):\n", atributoNome);
        printf("Carta 1 - %s (%s): %d\n", carta1.nome, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.nome, carta2.estado, carta2.populacao);
        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.populacao > carta1.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: As cartas empataram!\n");
        }
    } else if (atributoEscolhido == 2) {
        strcpy(atributoNome, "Área");
        printf("%s):\n", atributoNome);
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.area);
        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.area > carta1.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: As cartas empataram!\n");
        }
    } else if (atributoEscolhido == 3) {
        strcpy(atributoNome, "PIB");
        printf("%s):\n", atributoNome);
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.pib);
        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.pib > carta1.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: As cartas empataram!\n");
        }
    } else if (atributoEscolhido == 4) {
        strcpy(atributoNome, "Densidade Populacional");
        printf("%s):\n", atributoNome);
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.densidadePopulacional);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.densidadePopulacional);
        if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: As cartas empataram!\n");
        }
    } else if (atributoEscolhido == 5) {
        strcpy(atributoNome, "PIB per capita");
        printf("%s):\n", atributoNome);
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.pibPerCapita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.pibPerCapita);
        if (carta1.pibPerCapita > carta2.pibPerCapita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: As cartas empataram!\n");
        }
    } else {
        printf("Atributo inválido para comparação.\n");
    }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora); // Já implementado dentro dos blocos if-else

    return 0;
}