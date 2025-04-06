#include <stdio.h>

int main() {

    // Declaração das variáveis para a Carta 1
    char estado1;          // Armazena a letra do estado (A-H)
    char codigo1[4];       // Armazena o código da carta (ex: A01)
    char nome_cidade1[50]; // Armazena o nome da cidade (até 49 caracteres + o terminador nulo)
    int populacao1;        // Armazena o número de habitantes
    float area1;           // Armazena a área da cidade (em km²)
    float pib1;            // Armazena o Produto Interno Bruto da cidade
    int pontos_turisticos1;// Armazena o número de pontos turísticos

    // Declaração das variáveis para a Carta 2
    char estado2;
    char codigo2[4];
    char nome_cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;

    // Leitura dos dados da Carta 1
    printf("Cadastro da Carta 1:\n");           // Imprime uma mensagem informativa
    printf("Estado (A-H): ");                   // Pede ao usuário para inserir o estado
    scanf(" %c", &estado1);                     // Lê um único caractere (o estado) e armazena em 'estado1'.
                                                // O espaço antes de '%c' é importante para consumir qualquer
                                                // caractere de espaço em branco (como a quebra de linha da entrada anterior).
    printf("Código da Carta (ex: A01): ");      // Pede o código da carta
    scanf("%s", codigo1);                       // Lê uma sequência de caracteres (string) sem espaços
                                                // e armazena em 'codigo1'. É importante que o usuário
                                                // não digite mais que 3 caracteres além do terminador nulo.
    printf("Nome da Cidade: ");                 // Pede o nome da cidade
    scanf(" %[^\n]", nome_cidade1);             // Lê uma linha inteira de texto (incluindo espaços) até encontrar
                                                // uma quebra de linha ('\n') e armazena em 'nome_cidade1'.
                                                // O " %[^\n]" é usado para ler strings com espaços.
    printf("População: ");                      // Pede a população
    scanf("%d", &populacao1);                   // Lê um número inteiro e armazena em 'populacao1'.
    printf("Área (em km²): ");                  // Pede a área
    scanf("%f", &area1);                        // Lê um número de ponto flutuante (decimal) e armazena em 'area1'.
    printf("PIB (em bilhões de reais): ");      // Pede o PIB
    scanf("%f", &pib1);                         // Lê outro número de ponto flutuante e armazena em 'pib1'.
    printf("Número de Pontos Turísticos: ");    // Pede o número de pontos turísticos
    scanf("%d", &pontos_turisticos1);           // Lê um número inteiro e armazena em 'pontos_turisticos1'.
    printf("\n");                               // Imprime uma linha em branco para separar as entradas das cartas.

    // Leitura dos dados da Carta 2 (o processo é idêntico ao da Carta 1,
    // mas os dados são armazenados em variáveis diferentes com o sufixo '2')
    printf("Cadastro da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Código da Carta (ex: B03): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade2);
    printf("População: ");
    scanf("%d", &populacao2);
    printf("Área (em km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);
    printf("\n");

    // Exibição dos dados da Carta 1
    printf("Carta 1:\n");                     // Imprime um cabeçalho para a Carta 1
    printf("Estado: %c\n", estado1);         // Imprime o estado da Carta 1
    printf("Código: %s\n", codigo1);         // Imprime o código da Carta 1
    printf("Nome da Cidade: %s\n", nome_cidade1); // Imprime o nome da cidade da Carta 1
    printf("População: %d\n", populacao1);     // Imprime a população da Carta 1
    printf("Área: %.2f km²\n", area1);       // Imprime a área da Carta 1, formatada para 2 casas decimais
    printf("PIB: %.2f bilhões de reais\n", pib1);// Imprime o PIB da Carta 1, formatado para 2 casas decimais
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1); // Imprime o número de pontos turísticos da Carta 1
    printf("\n");                             // Imprime uma linha em branco para separar as informações das cartas.

    // Exibição dos dados da Carta 2 (o processo é idêntico ao da Carta 1,
    // mas os dados exibidos são os armazenados nas variáveis da Carta 2)
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("\n");

    return 0; // Indica que o programa terminou com sucesso
}