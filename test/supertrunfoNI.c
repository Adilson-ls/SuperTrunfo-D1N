#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura para representar uma carta de cidade
typedef struct {
    char nome[50];
    int populacao;     // Atributo 1
    float area;        // Atributo 2
    float pib;         // Atributo 3 (em bilhões de dólares)
    int pontosTuristicos; // Atributo 4
    int id;            // Identificador único da carta
    int superTrunfoNivel; // 0 para normal, >0 para Super Trunfo (nível de poder)
} CartaCidade;

// Função para criar uma nova carta de cidade
CartaCidade criarCartaCidade(const char *nome, int populacao, float area, float pib, int pontosTuristicos, int id, int superTrunfoNivel) {
    CartaCidade novaCarta;
    strcpy(novaCarta.nome, nome);
    novaCarta.populacao = populacao;
    novaCarta.area = area;
    novaCarta.pib = pib;
    novaCarta.pontosTuristicos = pontosTuristicos;
    novaCarta.id = id;
    novaCarta.superTrunfoNivel = superTrunfoNivel;
    return novaCarta;
}

// Função para exibir uma carta de cidade
void exibirCartaCidade(CartaCidade carta) {
    printf("----------------------------------------\n");
    printf("Cidade: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f Bilhões USD\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    if (carta.superTrunfoNivel > 0) {
        printf("SUPER TRUNFO Nível: %d\n", carta.superTrunfoNivel);
    }
    printf("----------------------------------------\n");
}

// Função para embaralhar um baralho de cartas
void embaralhar(CartaCidade baralho[], int numCartas) {
    srand(time(NULL));
    for (int i = numCartas - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        CartaCidade temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

// Função para distribuir as cartas entre dois jogadores
void distribuirCartas(CartaCidade baralho[], int numCartas, CartaCidade jogador1[], int *numCartasJogador1, CartaCidade jogador2[], int *numCartasJogador2) {
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

    switch (atributoEscolhido) {
        case 1: // População (maior vence)
            printf("Atributo Escolhido: População\n");
            if (cartaJogador1.populacao > cartaJogador2.populacao) return 1;
            else if (cartaJogador2.populacao > cartaJogador1.populacao) return 2;
            else return 0;
        case 2: // Área (maior vence)
            printf("Atributo Escolhido: Área\n");
            if (cartaJogador1.area > cartaJogador2.area) return 1;
            else if (cartaJogador2.area > cartaJogador1.area) return 2;
            else return 0;
        case 3: // PIB (maior vence)
            printf("Atributo Escolhido: PIB\n");
            if (cartaJogador1.pib > cartaJogador2.pib) return 1;
            else if (cartaJogador2.pib > cartaJogador1.pib) return 2;
            else return 0;
        case 4: // Pontos Turísticos (maior vence)
            printf("Atributo Escolhido: Pontos Turísticos\n");
            if (cartaJogador1.pontosTuristicos > cartaJogador2.pontosTuristicos) return 1;
            else if (cartaJogador2.pontosTuristicos > cartaJogador1.pontosTuristicos) return 2;
            else return 0;
        default:
            printf("Atributo inválido!\n");
            return 0;
    }
}

// Função para comparar cartas (Nível Intermediário - Múltiplos atributos com switch e if-else if)
int compararRodadaIntermediario(CartaCidade cartaJogador1, CartaCidade cartaJogador2, int atributoEscolhido) {
    printf("\n*** Nível Intermediário - Comparando Rodada ***\n");
    printf("Carta Jogador 1: %s\n", cartaJogador1.nome);
    printf("Carta Jogador 2: %s\n", cartaJogador2.nome);

    if (cartaJogador1.superTrunfoNivel > 0 && cartaJogador2.superTrunfoNivel == 0) return 1;
    else if (cartaJogador2.superTrunfoNivel > 0 && cartaJogador1.superTrunfoNivel == 0) return 2;
    else if (cartaJogador1.superTrunfoNivel > 0 && cartaJogador2.superTrunfoNivel > 0) {
        if (cartaJogador1.superTrunfoNivel > cartaJogador2.superTrunfoNivel) return 1;
        else if (cartaJogador2.superTrunfoNivel > cartaJogador1.superTrunfoNivel) return 2;
        else return 0;
    }

    switch (atributoEscolhido) {
        case 1: // População
            printf("Atributo Escolhido: População\n");
            if (cartaJogador1.populacao > cartaJogador2.populacao) return 1;
            else if (cartaJogador2.populacao > cartaJogador1.populacao) return 2;
            else return 0;
        case 2: // Área
            printf("Atributo Escolhido: Área\n");
            if (cartaJogador1.area > cartaJogador2.area) return 1;
            else if (cartaJogador2.area > cartaJogador1.area) return 2;
            else return 0;
        case 3: // PIB
            printf("Atributo Escolhido: PIB\n");
            if (cartaJogador1.pib > cartaJogador2.pib) return 1;
            else if (cartaJogador2.pib > cartaJogador1.pib) return 2;
            else return 0;
        case 4: // Pontos Turísticos
            printf("Atributo Escolhido: Pontos Turísticos\n");
            if (cartaJogador1.pontosTuristicos > cartaJogador2.pontosTuristicos) return 1;
            else if (cartaJogador2.pontosTuristicos > cartaJogador1.pontosTuristicos) return 2;
            else return 0;
        default:
            printf("Atributo inválido!\n");
            return 0;
    }
}

// Função para comparar cartas (Nível Aventureiro - Dois atributos com operador ternário e integração)
int compararRodadaAventureiro(CartaCidade cartaJogador1, CartaCidade cartaJogador2, int atributoEscolhido1, int atributoEscolhido2) {
    printf("\n*** Nível Aventureiro - Comparando Rodada ***\n");
    printf("Carta Jogador 1: %s\n", cartaJogador1.nome);
    printf("Carta Jogador 2: %s\n", cartaJogador2.nome);
    printf("Atributo Escolhido 1: %d, Atributo Escolhido 2: %d (empate)\n", atributoEscolhido1, atributoEscolhido2);

    if (cartaJogador1.superTrunfoNivel > 0 && cartaJogador2.superTrunfoNivel == 0) return 1;
    else if (cartaJogador2.superTrunfoNivel > 0 && cartaJogador1.superTrunfoNivel == 0) return 2;
    else if (cartaJogador1.superTrunfoNivel > 0 && cartaJogador2.superTrunfoNivel > 0) {
        return (cartaJogador1.superTrunfoNivel > cartaJogador2.superTrunfoNivel) ? 1 :
               (cartaJogador2.superTrunfoNivel > cartaJogador1.superTrunfoNivel) ? 2 : 0;
    }

    int resultado = 0;

    switch (atributoEscolhido1) {
        case 1: resultado = (cartaJogador1.populacao > cartaJogador2.populacao) ? 1 : (cartaJogador1.populacao < cartaJogador2.populacao) ? 2 : 0; break;
        case 2: resultado = (cartaJogador1.area > cartaJogador2.area) ? 1 : (cartaJogador1.area < cartaJogador2.area) ? 2 : 0; break;
        case 3: resultado = (cartaJogador1.pib > cartaJogador2.pib) ? 1 : (cartaJogador1.pib < cartaJogador2.pib) ? 2 : 0; break;
        case 4: resultado = (cartaJogador1.pontosTuristicos > cartaJogador2.pontosTuristicos) ? 1 : (cartaJogador1.pontosTuristicos < cartaJogador2.pontosTuristicos) ? 2 : 0; break;
        default: printf("Primeiro atributo inválido!\n"); return 0;
    }

    if (resultado == 0) {
        printf("Empate no Atributo %d. Comparando pelo Atributo %d...\n", atributoEscolhido1, atributoEscolhido2);
        switch (atributoEscolhido2) {
            case 1: resultado = (cartaJogador1.populacao > cartaJogador2.populacao) ? 1 : (cartaJogador1.populacao < cartaJogador2.populacao) ? 2 : 0; break;
            case 2: resultado = (cartaJogador1.area > cartaJogador2.area) ? 1 : (cartaJogador1.area < cartaJogador2.area) ? 2 : 0; break;
            case 3: resultado = (cartaJogador1.pib > cartaJogador2.pib) ? 1 : (cartaJogador1.pib < cartaJogador2.pib) ? 2 : 0; break;
            case 4: resultado = (cartaJogador1.pontosTuristicos > cartaJogador2.pontosTuristicos) ? 1 : (cartaJogador1.pontosTuristicos < cartaJogador2.pontosTuristicos) ? 2 : 0; break;
            default: printf("Segundo atributo inválido!\n"); return 0;
        }
    }

    return resultado;
}

int main() {
    // Criação do baralho de cartas Cidades do Mundo
    CartaCidade baralho[10] = {
        criarCartaCidade("São Paulo", 12396372, 1521.11, 1225.8, 10, 1, 0),
        criarCartaCidade("Rio de Janeiro", 6747815, 1200.33, 343.6, 20, 2, 1), // Super Trunfo Nível 1
        criarCartaCidade("Buenos Aires", 3075646, 203.00, 340.0, 15, 3, 0),
        criarCartaCidade("Nova York", 8398748, 783.84, 2000.0, 50, 4, 2),   // Super Trunfo Nível 2
        criarCartaCidade("Tóquio", 13929286, 2193.27, 1950.0, 30, 5, 0),
        criarCartaCidade("Cidade do México", 9209944, 1485.30, 450.0, 25, 6, 0),
        criarCartaCidade("Paris", 2141000, 105.40, 700.0, 40, 7, 0),
        criarCartaCidade("Londres", 8982000, 1572.15, 2800.0, 60, 8, 3),   // Super Trunfo Nível 3
        criarCartaCidade("Roma", 2860009, 1285.30, 250.0, 35, 9, 0),
        criarCartaCidade("Berlim", 3645000, 891.85, 370.0, 45, 10, 0)
    };
    int numCartas = 10;

    // Embaralhar as cartas
    embaralhar(baralho, numCartas);

    // Distribuir as cartas para dois jogadores
    CartaCidade jogador1[numCartas];
    CartaCidade jogador2[numCartas];
    int numCartasJogador1 = 0;
    int numCartasJogador2 = 0;
    distribuirCartas(baralho, numCartas, jogador1, &numCartasJogador1, jogador2, &numCartasJogador2);

    printf("--- Preparação ---\n");
    printf("Cartas do Jogador 1 (%d cartas):\n", numCartasJogador1);
    for (int i = 0; i < numCartasJogador1; i++) {
        printf("%s ", jogador1[i].nome);
    }
    printf("\nCartas do Jogador 2 (%d cartas):\n", numCartasJogador2);
    for (int i = 0; i < numCartasJogador2; i++) {
        printf("%s ", jogador2[i].nome);
    }
    printf("\n");

    // Simulação de algumas rodadas (Nível Novato)
    if (numCartasJogador1 > 0 && numCartasJogador2 > 0) {
        printf("--- Nível Novato - Primeira Rodada ---\n");
        exibirCartaCidade(jogador1[0]);
        printf("Jogador 1 escolhe o atributo para comparar (1-População, 2-Área, 3-PIB, 4-Pontos Turísticos): ");
        int atributoNovato;
        scanf("%d", &atributoNovato);
        exibirCartaCidade(jogador2[0]);
        int vencedorNovato = compararRodadaNovato(jogador1[0], jogador2[0], atributoNovato);
        if (vencedorNovato == 1) printf("Jogador 1 venceu a rodada!\n");
        else if (vencedorNovato == 2) printf("Jogador 2 venceu a rodada!\n");
        else printf("Empate na rodada!\n");
    }

    // Simulação de algumas rodadas (Nível Intermediário)
    if (numCartasJogador1 > 1 && numCartasJogador2 > 1) {
        printf("\n--- Nível Intermediário - Primeira Rodada ---\n");
        exibirCartaCidade(jogador1[1]);
        printf("Jogador 1 escolhe o atributo para comparar (1-População, 2-Área, 3-PIB, 4-Pontos Turísticos): ");
        int atributoIntermediario;
        scanf("%d", &atributoIntermediario);
        exibirCartaCidade(jogador2[1]);
        int vencedorIntermediario = compararRodadaIntermediario(jogador1[1], jogador2[1], atributoIntermediario);
        if (vencedorIntermediario == 1) printf("Jogador 1 venceu a rodada!\n");
        else if (vencedorIntermediario == 2) printf("Jogador 2 venceu a rodada!\n");
        else printf("Empate na rodada!\n");
    }

    // Simulação de algumas rodadas (Nível Aventureiro)
    if (numCartasJogador1 > 2 && numCartasJogador2 > 2) {
        printf("\n--- Nível Aventureiro - Primeira Rodada ---\n");
        exibirCartaCidade(jogador1[2]);
        int atributoAventureiro1, atributoAventureiro2;
        printf("Jogador 1 escolha o primeiro atributo para comparar (1-População, 2-Área, 3-PIB, 4-Pontos Turísticos): ");
        scanf("%d", &atributoAventureiro1);
        printf("Jogador 1 escolha o segundo atributo para empate (1-População, 2-Área, 3-PIB, 4-Pontos Turísticos): ");
        scanf("%d", &atributoAventureiro2);
        exibirCartaCidade(jogador2[2]);
        int vencedorAventureiro = compararRodadaAventureiro(jogador1[2], jogador2[2], atributoAventureiro1, atributoAventureiro2);
        if (vencedorAventureiro == 1) printf("Jogador 1 venceu a rodada!\n");
        else if (vencedorAventureiro == 2) printf("Jogador 2 venceu a rodada!\n");
        else printf("Empate na rodada!\n");
    }

    printf("\n--- Fim da Simulação (Demonstração dos Níveis) ---\n");
    printf("O jogo completo continuaria até que um jogador tenha todas as cartas.\n");

    return 0;
}