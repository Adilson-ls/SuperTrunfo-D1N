```mermaid
graph TD
    A[Início] --> B[Declaração das variáveis]
    B --> C[Cadastro da Carta 1]
    C --> D[Leitura dos dados da Carta 1]
    D --> E[Cadastro da Carta 2]
    E --> F[Leitura dos dados da Carta 2]
    F --> G[Exibição dos dados da Carta 1]
    G --> H[Exibição dos dados da Carta 2]
    H --> I[Fim]


```mermaid
graph TD
    A[Início] --> B{Declaração Variáveis Carta 1};
    B --> C{Declaração Variáveis Carta 2};
    C --> D{Imprime "Cadastro da Carta 1:"};
    D --> E{Imprime "Estado (A-H): "};
    E --> F{Lê estado1};
    F --> G{Imprime "Código da Carta (ex: A01): "};
    G --> H{Lê codigo1};
    H --> I{Imprime "Nome da Cidade: "};
    I --> J{Lê nome_cidade1};
    J --> K{Imprime "População: "};
    K --> L{Lê populacao1};
    L --> M{Imprime "Área (em km²): "};
    M --> N{Lê area1};
    N --> O{Imprime "PIB (em bilhões de reais): "};
    O --> P{Lê pib1};
    P --> Q{Imprime "Número de Pontos Turísticos: "};
    Q --> R{Lê pontos_turisticos1};
    R --> S{Imprime "\n"};
    S --> T{Imprime "Cadastro da Carta 2:"};
    T --> U{Imprime "Estado (A-H): "};
    U --> V{Lê estado2};
    V --> W{Imprime "Código da Carta (ex: B03): "};
    W --> X{Lê codigo2};
    X --> Y{Imprime "Nome da Cidade: "};
    Y --> Z{Lê nome_cidade2};
    Z --> AA{Imprime "População: "};
    AA --> BB{Lê populacao2};
    BB --> CC{Imprime "Área (em km²): "};
    CC --> DD{Lê area2};
    DD --> EE{Imprime "PIB (em bilhões de reais): "};
    EE --> FF{Lê pib2};
    FF --> GG{Imprime "Número de Pontos Turísticos: "};
    GG --> HH{Lê pontos_turisticos2};
    HH --> II{Imprime "\n"};
    II --> JJ{Imprime "Carta 1:"};
    JJ --> KK{Imprime "Estado: ", estado1};
    KK --> LL{Imprime "Código: ", codigo1};
    LL --> MM{Imprime "Nome da Cidade: ", nome_cidade1};
    MM --> NN{Imprime "População: ", populacao1};
    NN --> OO{Imprime "Área: ", area1, " km²"};
    OO --> PP{Imprime "PIB: ", pib1, " bilhões de reais"};
    PP --> QQ{Imprime "Número de Pontos Turísticos: ", pontos_turisticos1};
    QQ --> RR{Imprime "\n"};
    RR --> SS{Imprime "Carta 2:"};
    SS --> TT{Imprime "Estado: ", estado2};
    TT --> UU{Imprime "Código: ", codigo2};
    UU --> VV{Imprime "Nome da Cidade: ", nome_cidade2};
    VV --> WW{Imprime "População: ", populacao2};
    WW --> XX{Imprime "Área: ", area2, " km²"};
    XX --> YY{Imprime "PIB: ", pib2, " bilhões de reais"};
    YY --> ZZ{Imprime "Número de Pontos Turísticos: ", pontos_turisticos2};
    ZZ --> AAA{Imprime "\n"};
    AAA --> FIM[Fim];