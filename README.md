# Jogo da Cobrinha

Este é um projeto simples de implementação do clássico **Jogo da Cobrinha** (Snake Game) utilizando a biblioteca **ncurses**, desenvolvido em C.

## Descrição

O objetivo do jogo é controlar uma cobrinha que cresce à medida que come a comida (representada por um 'O'), evitando colidir com as paredes. O jogo termina quando a cobrinha bate em uma parede.

## Funcionalidades

- Movimentação da cobrinha em 4 direções: cima, baixo, esquerda e direita.
- Crescimento da cobrinha ao comer a comida.
- Pontuação baseada no número de itens consumidos.
- Fim de jogo quando a cobrinha colide com a parede.

## Tecnologias Utilizadas

- **Linguagem:** C
- **Biblioteca:** [ncurses](https://invisible-island.net/ncurses/)
- **Compilador:** GCC
- **Sistema Operacional:** Unix/Linux (por conta da dependência da biblioteca ncurses)

## Requisitos

Para rodar o jogo, é necessário ter a biblioteca **ncurses** instalada no seu sistema. Se estiver utilizando um sistema baseado em Debian/Ubuntu, pode instalar a biblioteca executando o seguinte comando:

```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```

## Como Rodar o Jogo

1. Clone o repositório:

   ```bash
   git clone https://github.com/GabrielSantana013/Cobrinha.git
   ```

2. Navegue até o diretório do projeto:

   ```bash
   cd Cobrinha
   ```

3. Compile o projeto utilizando o Makefile:

   ```bash
   make
   ```

4. Execute o jogo:

   ```bash
   ./cobrinha
   ```

## Estrutura do Projeto

O projeto está organizado da seguinte maneira:

```
Cobrinha/
├── src/
│   ├── nibbles.c        # Arquivo principal que inicia o jogo (nibbles.c)
├── functions/           # Funções responsáveis pela lógica do jogo
│   ├── snakeMove.c
│   ├── spawnFood.c
│   ├── updateSnake.c
│   └── functions.h
├── view/                # Parte visual (telas, desenhos e menu)
│   ├── drawScreen.c
│   ├── gameStart.c
│   ├── instructionsScreen.c
│   ├── menu.c
│   ├── logo.c
│   ├── logo.h
│   └── view.h
├── Makefile
├── nibbles.exe
└── README.md
```

- O diretório `src/` contém o arquivo-fonte em C.
- O diretório `functions/` contém o Header com as structs e funções em C, além dos arquivos .c das funções.
- O diretório `view/` contém as telas e as partes visuals do sistema
- O `Makefile` é responsável por compilar o projeto e criar o executável `cobrinha`.

## Contato

Se você tiver alguma dúvida ou sugestão, sinta-se à vontade para abrir uma **issue** ou entrar em contato.

---
