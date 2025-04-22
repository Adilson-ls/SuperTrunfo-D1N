#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura para representar uma carta de cidade
typedef struct {
    char ID[2]; // ID da carta
    char nome[50];
    int Populacao; // População
    int area; // Área
    int PIB; // PIB
    int Pontos_Turisticos; // Pontos Turísticos
    int superTrunfoNivel; // 0 para normal, >0 para Super Trunfo
} CartaCidade;

// Função para criar uma nova carta de cidade
CartaCidade criarCartaCidade(const char *nome, int Populacao, int area, int PIB, int Pontos_Turisticos, int superTrunfoNivel) {
    CartaCidade novaCarta;
    strcpy(novaCarta.nome, nome);
    novaCarta.Populacao = Populacao;
    novaCarta.area = area;
    novaCarta.PIB = PIB;
    novaCarta.Pontos_Turisticos = Pontos_Turisticos;
    novaCarta.superTrunfoNivel = superTrunfoNivel;
    return novaCarta;
}

// Função para exibir uma carta de cidade
void exibirCartaCidade(CartaCidade carta) {
    printf("----------------------------------------\n");
    printf("Cidade: %s\n", carta.nome);
    printf("Populacao: %d\n", carta.Populacao);
    printf("area: %.2f km²\n", (float)carta.area);
    printf("PIB: %.2f Bilhões USD\n", (float)carta.PIB);
    printf("Pontos_Turisticos: %d\n", carta.Pontos_Turisticos);
    if (carta.superTrunfoNivel > 0) {
        printf("SUPER TRUNFO Nível: %d\n", carta.superTrunfoNivel);
    }
    printf("----------------------------------------\n");
}

// Função para comparar cartas (Nível Novato - Um atributo com if/else)
int compararRodadaNovato(CartaCidade cartaJogador1, CartaCidade cartaJogador2, int atributoEscolhido) {
    printf("\n*** Nível Novato - Comparando Rodada ***\n");
    printf("Carta Jogador 1: %s\n", cartaJogador1.nome);
    printf("Carta Jogador 2: %s\n", cartaJogador2.nome);

    if (cartaJogador1.superTrunfoNivel > 0 && cartaJogador2.superTrunfoNivel == 0) {
        printf("Super Trunfo de %s vence!\n", cartaJogador1.nome);
        return 1; // Jogador 1 vence
    } else if (cartaJogador2.superTrunfoNivel > 0 && cartaJogador1.superTrunfoNivel == 0) {
        printf("Super Trunfo de %s vence!\n", cartaJogador2.nome);
        return 2; // Jogador 2 vence
    } else if (cartaJogador1.superTrunfoNivel > 0 && cartaJogador2.superTrunfoNivel > 0) {
        printf("Comparando níveis de Super Trunfo...\n");
        if (cartaJogador1.superTrunfoNivel > cartaJogador2.superTrunfoNivel) {
            printf("Super Trunfo de %s vence!\n", cartaJogador1.nome);
            return 1;
        } else if (cartaJogador2.superTrunfoNivel > cartaJogador1.superTrunfoNivel) {
            printf("Super Trunfo de %s vence!\n", cartaJogador2.nome);
            return 2;
        } else {
            printf("Empate entre Super Trunfos!\n");
            return 0; // Empate
        }
    }

    if (atributoEscolhido == 1) {
        printf("Atributo Escolhido: Populacao\n");
        if (cartaJogador1.Populacao > cartaJogador2.Populacao) return 1;
        else if (cartaJogador2.Populacao > cartaJogador1.Populacao) return 2;
        else return 0;
    } else if (atributoEscolhido == 2) {
        printf("Atributo Escolhido: area\n");
        if (cartaJogador1.area > cartaJogador2.area) return 1;
        else if (cartaJogador2.area > cartaJogador1.area) return 2;
        else return 0;
    } else if (atributoEscolhido == 3) {
        printf("Atributo Escolhido: PIB\n");
        if (cartaJogador1.PIB > cartaJogador2.PIB) return 1;
        else if (cartaJogador2.PIB > cartaJogador1.PIB) return 2;
        else return 0;
    } else if (atributoEscolhido == 4) {
        printf("Atributo Escolhido: Pontos_Turisticos\n");
        if (cartaJogador1.Pontos_Turisticos > cartaJogador2.Pontos_Turisticos) return 1;
        else if (cartaJogador2.Pontos_Turisticos > cartaJogador1.Pontos_Turisticos) return 2;
        else return 0;
    } else {
        printf("Atributo inválido!\n");
        return 0;
    }
}

int main() {
    // Criação de algumas cartas para teste
    CartaCidade cartaA = criarCartaCidade("São Paulo", 12396372, 1521, 1225, 10, 0);
    CartaCidade cartaB = criarCartaCidade("Rio de Janeiro", 6747815, 1200, 343, 20, 1); // Super Trunfo

    // Simulação de uma rodada (Nível Novato)
    printf("--- Simulação Nível Novato ---\n");
    exibirCartaCidade(cartaA);
    exibirCartaCidade(cartaB);
    printf("Jogador 1 escolhe o atributo para comparar (1-Populacao, 2-area, 3-PIB, 4-Pontos_Turisticos): ");
    int atributoNovato;
    scanf("%d", &atributoNovato);
    int vencedorNovato = compararRodadaNovato(cartaA, cartaB, atributoNovato);
    if (vencedorNovato == 1) printf("Jogador 1 venceu a rodada!\n");
    else if (vencedorNovato == 2) printf("Jogador 2 venceu a rodada!\n");
    else printf("Empate na rodada!\n");

    return 0;
}