#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura para representar uma carta
typedef struct {
    char codigo[3]; // Ex: A1, D6
    int valorNumerico; // Valor de 1 a 6
    char letra;       // Letra de A a D
} Carta;

// Função para criar uma nova carta
Carta criarCarta(char letra, int valor) {
    Carta novaCarta;
    novaCarta.letra = letra;
    novaCarta.valorNumerico = valor;
    sprintf(novaCarta.codigo, "%c%d", letra, valor);
    return novaCarta;
}

// Função para exibir uma carta
void exibirCarta(Carta carta) {
    printf("Carta: %s (Letra: %c, Valor: %d)\n", carta.codigo, carta.letra, carta.valorNumerico);
}

// Função para criar um baralho completo de cartas
void criarBaralho(Carta baralho[], int *numCartas) {
    *numCartas = 0;
    char letras[] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 6; j++) {
            baralho[*numCartas] = criarCarta(letras[i], j);
            (*numCartas)++;
        }
    }
}

// Função para embaralhar um baralho de cartas
void embaralhar(Carta baralho[], int numCartas) {
    srand(time(NULL));
    for (int i = numCartas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

// Função para distribuir as cartas entre dois jogadores
void distribuirCartas(Carta baralho[], int numCartas, Carta jogador1[], int *numCartasJogador1, Carta jogador2[], int *numCartasJogador2) {
    *numCartasJogador1 = 0;
    *numCartasJogador2 = 0;
    for (int i = 0; i < numCartas; i++) {
        if (i % 2 == 0) {
            jogador1[(*numCartasJogador1)++] = baralho[i];
        } else {
            jogador2[(*numCartasJogador2)++] = baralho[i];
        }
    }
}

int main() {
    Carta baralho[24]; // 4 letras * 6 valores
    int numCartas = 0;

    // Criar o baralho
    criarBaralho(baralho, &numCartas);
    printf("Baralho criado com %d cartas:\n", numCartas);
    for (int i = 0; i < numCartas; i++) {
        exibirCarta(baralho[i]);
    }
    printf("\n");

    // Embaralhar o baralho
    embaralhar(baralho, numCartas);
    printf("Baralho embaralhado:\n");
    for (int i = 0; i < numCartas; i++) {
        exibirCarta(baralho[i]);
    }
    printf("\n");

    // Distribuir as cartas para dois jogadores
    Carta jogador1[12];
    Carta jogador2[12];
    int numCartasJogador1 = 0;
    int numCartasJogador2 = 0;
    distribuirCartas(baralho, numCartas, jogador1, &numCartasJogador1, jogador2, &numCartasJogador2);

    printf("Cartas do Jogador 1 (%d cartas):\n", numCartasJogador1);
    for (int i = 0; i < numCartasJogador1; i++) {
        exibirCarta(jogador1[i]);
    }
    printf("\n");

    printf("Cartas do Jogador 2 (%d cartas):\n", numCartasJogador2);
    for (int i = 0; i < numCartasJogador2; i++) {
        exibirCarta(jogador2[i]);
    }
    printf("\n");

    return 0;
}