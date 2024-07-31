# Sistema de Liga E-Sports

## Introdução

Este projeto foi desenvolvido como trabalho final para a disciplina de Fundamentos de Programação. O objetivo é criar um programa em C que simule um sistema de registro de resultados de uma liga de e-sports. O sistema permite o cadastro e gerenciamento detalhado das partidas, incluindo informações sobre os times participantes, os jogadores, os placares e os destaques individuais.

## Descrição do Projeto

O programa oferece uma gestão completa para uma liga de e-sports, incluindo funcionalidades para:

- Cadastro e gerenciamento de times e jogadores
- Registro e acompanhamento de partidas
- Cálculo de estatísticas relevantes

## Principais Funcionalidades

- **Cadastrar um Time:** Inserção de dados de novos times, como nome, país de origem, data de criação e número de jogadores.
- **Alterar Informações de um Time:** Modificação dos dados de times existentes.
- **Cadastrar um Jogador:** Inserção de novos jogadores no sistema.
- **Alterar Informações de um Jogador:** Modificação dos dados dos jogadores existentes.
- **Registrar uma Partida:** Registro de partidas, incluindo seleções de times, data, placar e destaque individual.
- **Buscar Partidas por Time:** Exibição de partidas em que um time específico participou.
- **Buscar Partidas por Período:** Exibição de partidas realizadas dentro de um intervalo de datas.
- **Listar Todos os Times:** Exibição de todos os times cadastrados e o número de jogadores de cada um.
- **Listar Todos os Jogadores:** Exibição de todos os jogadores cadastrados.
- **Calcular a Média de Idade dos Jogadores:** Cálculo da média de idade dos jogadores cadastrados.
- **Preço Total do Time:** Cálculo do salário total dos jogadores de um time.
- **Sair do Programa:** Encerra a execução do programa.

## Estrutura de Dados

### Times

- **ID do Time:** Número de identificação único
- **Nome do Time:** Nome do time
- **País de Origem:** País de origem do time
- **Data de Criação:** Data em que o time foi criado
- **Número de Jogadores:** Quantidade de jogadores no time

### Jogadores

- **ID do Jogador:** Número de identificação único
- **Nome do Jogador:** Nome do jogador
- **Apelido:** Apelido do jogador
- **País de Origem:** País de origem do jogador
- **Idade:** Idade do jogador
- **Posição de Jogo:** Posição em que o jogador atua
- **Salário:** Salário do jogador

### Partidas

- **ID da Partida:** Número de identificação único
- **ID do Time da Casa:** ID do time que joga em casa
- **ID do Time Visitante:** ID do time visitante
- **Data e Hora da Partida:** Data e hora em que a partida ocorreu
- **Placar Final:** Pontuação final dos times
- **Destaque Individual da Partida:** ID do jogador que se destacou

## Como Usar

1. **Compile o código-fonte** usando um compilador C, como `gcc`:
   ```bash
   gcc -o sistema_liga_esports main.c
