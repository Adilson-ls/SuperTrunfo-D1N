/*
No nível Aventureiro, você expandirá o sistema para incluir o cálculo de dois novos atributos: Densidade Populacional e PIB per capita.

🆕 Diferença em relação ao Nível Novato:

Novos Atributos:
Densidade Populacional: População / Área ( float)
PIB per capita: PIB / População ( float)
⚙️ Funcionalidades do Sistema:

O sistema irá gerar automaticamente a Densidade Populacional e o PIB per capita.
Os novos atributos serão exibidos junto com os demais.
📥 Entrada e 📤 Saída de Dados:

Mesma entrada do nível Novato.
A saída exibirá também os atributos calculados.
Simplificações para o Nível Intermediário:

Continue cadastrando apenas duas cartas.
Continue sem usar laços ( for, while) ou condicionais ( if, else).
*/

#include <stdio.h>

// Função para ler os dados de uma carta
void lerDadosCarta(int numero_carta, char *estado, char *codigo, char *nome_cidade,
                   int *populacao, float *area, float *pib, int *pontos_turisticos) {
    printf("Cadastro da Carta %d:\n", numero_carta);
    printf("Estado (A-H): ");
    scanf(" %c", estado);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo);
    printf("Nome da Cidade: ");
    scanf(" %s[^\n]", nome_cidade);
    printf("População: ");
    scanf("%d", populacao);
    printf("Área (em km²): ");
    scanf("%f", area);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", pontos_turisticos);
    printf("\n");
}

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(int populacao, float area) {
    return (float)populacao / area;
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(float pib, int populacao) {
    return (pib * 1000000000.0) / populacao;
}

// Função para exibir os dados de uma carta
void exibirDadosCarta(int numero_carta, char estado, char *codigo, char *nome_cidade,
                      int populacao, float area, float pib, int pontos_turisticos,
                      float densidade_populacional, float pib_per_capita) {
    printf("Carta %d:\n", numero_carta);
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", nome_cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional);
    printf("PIB per capita: %.2f reais\n", pib_per_capita);
    printf("\n");
}

int main() {
    // Variáveis para a Carta 1
    char estado1;
    char codigo1[4];
    char nome_cidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade_populacional1;
    float pib_per_capita1;

    // Variáveis para a Carta 2
    char estado2;
    char codigo2[4];
    char nome_cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade_populacional2;
    float pib_per_capita2;

    // Leitura dos dados da Carta 1
    lerDadosCarta(1, &estado1, codigo1, nome_cidade1, &populacao1, &area1, &pib1, &pontos_turisticos1);

    // Cálculo dos novos atributos da Carta 1
    densidade_populacional1 = calcularDensidadePopulacional(populacao1, area1);
    pib_per_capita1 = calcularPibPerCapita(pib1, populacao1);

    // Leitura dos dados da Carta 2
    lerDadosCarta(2, &estado2, codigo2, nome_cidade2, &populacao2, &area2, &pib2, &pontos_turisticos2);

    // Cálculo dos novos atributos da Carta 2
    densidade_populacional2 = calcularDensidadePopulacional(populacao2, area2);
    pib_per_capita2 = calcularPibPerCapita(pib2, populacao2);

    // Exibição dos dados da Carta 1
    exibirDadosCarta(
        1, 
        estado1, 
        codigo1, 
        nome_cidade1, 
        populacao1, 
        area1, 
        pib1, 
        pontos_turisticos1, 
        densidade_populacional1, 
        pib_per_capita1
    );

    // Exibição dos dados da Carta 2
    exibirDadosCarta(
        2, 
        estado2, 
        codigo2, 
        nome_cidade2, 
        populacao2, 
        area2, 
        pib2, 
        pontos_turisticos2, 
        densidade_populacional2, 
        pib_per_capita2
    );

    return 0;
}