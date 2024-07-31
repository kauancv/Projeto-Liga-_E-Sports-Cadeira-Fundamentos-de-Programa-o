Sistema de Liga E-Sports

Introdução

Este projeto foi desenvolvido como trabalho final para a disciplina de Fundamentos de Programação. O objetivo é criar um programa que simule um sistema de registro de resultados de uma liga de e-sports, permitindo o cadastro e gerenciamento detalhado das partidas, incluindo informações sobre os times participantes, os jogadores, os placares e os destaques individuais.

Descrição do Projeto
O programa permite a gestão completa de uma liga de e-sports, incluindo o cadastro de times, jogadores e partidas. Ele também oferece funcionalidades para modificar dados, buscar informações específicas e calcular estatísticas relevantes.

Principais Funcionalidades

Cadastrar um Time: Permite ao usuário inserir os dados de um novo time no sistema, incluindo nome, país de origem, data de criação e número de jogadores.
Alterar Informações de um Time: Permite ao usuário escolher um time existente e modificar seus dados, como nome, país de origem, data de criação ou número de jogadores.
Cadastrar um Jogador: Permite ao usuário inserir os dados de um novo jogador no sistema.
Alterar Informações de um Jogador: Permite ao usuário escolher um jogador existente e modificar seus dados, como nome, apelido, país de origem, idade ou posição de jogo.
Registrar uma Partida: Permite ao usuário selecionar dois times, informar a data e hora da partida, o placar final e o destaque individual da partida.
Buscar Partidas por Time: Permite ao usuário inserir o ID de um time e exibir todas as partidas em que o time participou.
Buscar Partidas por Período: Permite ao usuário inserir uma data de início e uma data de fim e exibir todas as partidas realizadas dentro desse período.
Listar Todos os Times: Exibe informações sobre todos os times no sistema, incluindo o número de jogadores.
Listar Todos os Jogadores: Exibe informações sobre todos os jogadores no sistema.
Calcular a Média de Idade dos Jogadores: Exibe a média de idade de todos os jogadores cadastrados.
Preço Total do Time: Calcula o salário total de todos os jogadores de um time.
Sair do Programa: Encerra a execução do programa.
Estrutura de Dados
O programa utiliza tipos estruturados para representar times, jogadores e partidas:

Times:

ID do time (número de identificação único)
Nome do time
País de origem
Data de criação
Número de jogadores
Jogadores:

ID do jogador (número de identificação único)
Nome do jogador
Apelido
País de origem
Idade
Posição de jogo
Salário
Partidas:

ID da partida (número de identificação único)
ID do time da casa
ID do time visitante
Data e hora da partida
Placar final (pontuação dos times)
Destaque individual da partida (ID do jogador que se destacou)

Como Usar

Para usar o programa, compile o código-fonte e execute o executável. O menu do programa guiará você através das operações disponíveis, permitindo que você cadastre e gerencie times, jogadores e partidas, além de buscar informações específicas e calcular estatísticas.
