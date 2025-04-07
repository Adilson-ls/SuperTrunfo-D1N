programa {
  funcao inicio() {
    // Desafio Super Trunfo - Países
    // Tema 1 - Cadastro das Cartas
    // Este pseudocódigo representa a lógica do código C para o desenvolvimento do sistema de cadastro de cartas de cidades.
    // Siga as instruções para implementar cada parte do desafio.
    // Teste Adilson

    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.

    // Declaração das variáveis para a Carta 1
    caracter estado1          // Armazena a letra do estado (A-H)
    cadeia codigo1[4]        // Armazena o código da carta (ex: A01)
    cadeia nome_cidade1[50]  // Armazena o nome da cidade (até 49 caracteres)
    inteiro populacao1       // Armazena o número de habitantes
    real area1             // Armazena a área da cidade (em km²)
    real pib1              // Armazena o Produto Interno Bruto da cidade
    inteiro pontos_turisticos1 // Armazena o número de pontos turísticos

    // Declaração das variáveis para a Carta 2
    caracter estado2
    cadeia codigo2[4]
    cadeia nome_cidade2[50]
    inteiro populacao2
    real area2
    real pib2
    inteiro pontos_turisticos2

    // Cadastro das Cartas:
    // Sugestão: Utilize a instrução leia para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.

    // Leitura dos dados da Carta 1
    escreva("Cadastro da Carta 1:\n")
    escreva("Estado (A-H): ")
    leia(estado1)
    escreva("Código da Carta (ex: A01): ")
    leia(codigo1)
    escreva("Nome da Cidade: ")
    leia(nome_cidade1)
    escreva("População: ")
    leia(populacao1)
    escreva("Área (em km²): ")
    leia(area1)
    escreva("PIB (em bilhões de reais): ")
    leia(pib1)
    escreva("Número de Pontos Turísticos: ")
    leia(pontos_turisticos1)
    escreva("\n")

    // Leitura dos dados da Carta 2 (o processo é idêntico ao da Carta 1,
    // mas os dados são armazenados em variáveis diferentes com o sufixo '2')
    escreva("Cadastro da Carta 2:\n")
    escreva("Estado (A-H): ")
    leia(estado2)
    escreva("Código da Carta (ex: B03): ")
    leia(codigo2)
    escreva("Nome da Cidade: ")
    leia(nome_cidade2)
    escreva("População: ")
    leia(populacao2)
    escreva("Área (em km²): ")
    leia(area2)
    escreva("PIB (em bilhões de reais): ")
    leia(pib2)
    escreva("Número de Pontos Turísticos: ")
    leia(pontos_turisticos2)
    escreva("\n")

    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a instrução escreva para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    // Exibição dos dados da Carta 1
    escreva("Carta 1:\n")
    escreva("Estado: ", estado1, "\n")
    escreva("Código: ", codigo1, "\n")
    escreva("Nome da Cidade: ", nome_cidade1, "\n")
    escreva("População: ", populacao1, "\n")
    escreva("Área: ", area1:2, " km²\n")
    escreva("PIB: ", pib1:2, " bilhões de reais\n")
    escreva("Número de Pontos Turísticos: ", pontos_turisticos1, "\n")
    escreva("\n")

    // Exibição dos dados da Carta 2 (o processo é idêntico ao da Carta 1,
    // mas os dados exibidos são os armazenados nas variáveis da Carta 2)
    escreva("Carta 2:\n")
    escreva("Estado: ", estado2, "\n")
    escreva("Código: ", codigo2, "\n")
    escreva("Nome da Cidade: ", nome_cidade2, "\n")
    escreva("População: ", populacao2, "\n")
    escreva("Área: ", area2:2, " km²\n")
    escreva("PIB: ", pib2:2, " bilhões de reais\n")
    escreva("Número de Pontos Turísticos: ", pontos_turisticos2, "\n")
    escreva("\n")
  }
}