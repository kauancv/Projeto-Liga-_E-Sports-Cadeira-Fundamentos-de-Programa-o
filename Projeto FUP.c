#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {  // estrutura usada para salvar informacoes sobre os times
    int idTime, numeroJogadores, diaCriacao, mesCriacao, anoCriacao;
    char nomeTime[100], paisDeOrigemTime[100];
} Times;

typedef struct // estrutura usada para salvar informacoes sobre os jogadores
{
   int idJogador,idade;
   float salario;
   char nomeJogador[100],apelido[100],paisDeOrigemJogador[100],posicaoJogo[100];
}Jogadores;

typedef struct  // estrutura usada para salvar informacoes sobre as partidas
{
   int idPartida,idTimeCasa,idTimeVisitante,diaPartida,mesPartida,anoPartida,horaPartida,minPartida,segPartida;
   float pontuacaoTimeCasa,pontuacaoTimeVisitante;
   int DestaqueDaPartidaId;



}Partidas;

void cadastrarTime(int tam, Times *time) { // funcao para cadastrar o time
    FILE *arquivosTimes;
    arquivosTimes = fopen("times.txt", "a"); // abrir o arquivo, eh usado o "a" para adicionar as informacoes do time no fim do arquivo

    printf("\t\t\t\t\t------Preencha os Dados do Time------\n");
    printf("ID:");
    scanf("%d", &time[tam].idTime);
    getchar();

    printf("Nome:");
    fgets(time[tam].nomeTime, sizeof(time[tam].nomeTime), stdin);
    time[tam].nomeTime[strcspn(time[tam].nomeTime, "\n")] = '\0';

    printf("Pais de Origem:");
    fgets(time[tam].paisDeOrigemTime, sizeof(time[tam].paisDeOrigemTime), stdin);
    time[tam].paisDeOrigemTime[strcspn(time[tam].paisDeOrigemTime, "\n")] = '\0';

    printf("Data de Criacao\n");
    printf("Dia:");
    scanf("%d", &time[tam].diaCriacao);

    printf("Mes:");
    scanf("%d", &time[tam].mesCriacao);

    printf("Ano:");
    scanf("%d", &time[tam].anoCriacao);

    printf("Numero de Jogadores:");
    scanf("%d", &time[tam].numeroJogadores);
    getchar();

    printf ("\nTime cadastrado com sucesso!!!\n");

    fprintf(arquivosTimes, "%d|%d|%s|%s|%d/%d/%d\n", // salvar as informacoes preenchidas pelo o usuario dentro do arquivo
        time[tam].idTime,time[tam].numeroJogadores, time[tam].nomeTime,
        time[tam].paisDeOrigemTime, time[tam].diaCriacao,
        time[tam].mesCriacao, time[tam].anoCriacao);

    fclose(arquivosTimes);
}

void passarTimesArquivo(Times *time, int *quantidadeTimes) {  // funcao para passar as informacoes de dentro do arquivo para dentro da struct, para possibilitar o uso de dados pre-cadastrados
    FILE *arquivoTimes;
    arquivoTimes = fopen("times.txt", "r"); // abrir o arquivo no modo leitura

    if (arquivoTimes == NULL) { // verifica o arquivo
        printf("Erro ao abrir o arquivo.\n");
    }

    int i = 0;

    // usado while para passar as informacoes do arquivo para dentro da struct, enquanto for == 7

    while (fscanf(arquivoTimes, "%d|%d|%[^|]|%[^|]|%d/%d/%d\n",// udado o %[^|] para nao ler a "|" que eh usada para separar as informacoes dentro do arquivo
    &time[i].idTime, &time[i].numeroJogadores, time[i].nomeTime,
    time[i].paisDeOrigemTime, &time[i].diaCriacao,
    &time[i].mesCriacao, &time[i].anoCriacao) == 7) { // eh igualado a 7 por ser a quantidade de informacoes dentro da struct
    i++;
}

    fclose(arquivoTimes); // fechar arquivo
    *quantidadeTimes = i; // passado por ponteiro para alterar o valor fora da funcao
}

void listarTodosOsTimes (Times *time){ // funcao para mostrar todos os times cadastrados
   printf ("ID:%d\n",time->idTime);
   printf ("Nome:%s\n",time->nomeTime);
   printf ("Pais de Origem:%s\n",time->paisDeOrigemTime);
   printf ("Data de Criacao:%d/%d/%d\n",time->diaCriacao,time->mesCriacao,time->anoCriacao);
   printf ("Numero de Jogadores:%d\n",time->numeroJogadores);

 }
 
  
void alterarInformacoesTime (Times *time, int quantidadeTimes, int idTime){ // funcao para alterar as informacoes de um determinado time
   FILE *arquivosTimes;
   arquivosTimes = fopen("times.txt","w"); // abrir o arquivo, eh usado o "w" para substituir a informacao antiga pela a nova



   if (arquivosTimes == NULL){ // verifica o arquivo
      printf ("Erro ao abrir arquivo!!!");
   }

   int timeEscolhido = 0; // se o time for encontrado sera somado + 1, e vai ser verifado no fim da funcao

   for (int i = 0; i < quantidadeTimes; i++){ // usado para verificar se o time escolhido, existe dentro das informacoes ja cadastradas
      if (time[i].idTime == idTime){

         printf ("\nTime Encontrado!!!\n");
         printf ("\t\t\t\t\t------Preencha as novas Informacoes------\n");

      printf("Nome:");
      fgets(time[i].nomeTime, sizeof(time[i].nomeTime), stdin);
      time[i].nomeTime[strcspn(time[i].nomeTime, "\n")] = '\0';

      printf("Pais de Origem:");
      fgets(time[i].paisDeOrigemTime, sizeof(time[i].paisDeOrigemTime), stdin);
      time[i].paisDeOrigemTime[strcspn(time[i].paisDeOrigemTime, "\n")] = '\0';

      printf("Data de Criacao\n");
      printf("Dia:");
      scanf("%d", &time[i].diaCriacao);

      printf("Mes:");
      scanf("%d", &time[i].mesCriacao);

      printf("Ano:");
      scanf("%d", &time[i].anoCriacao);

      printf("Numero de Jogadores:");
      scanf("%d", &time[i].numeroJogadores);
      getchar();

      }
      fprintf(arquivosTimes, "%d|%d|%s|%s|%d/%d/%d\n",
        time[i].idTime,time[i].numeroJogadores, time[i].nomeTime,
        time[i].paisDeOrigemTime, time[i].diaCriacao,
        time[i].mesCriacao, time[i].anoCriacao);
   }
      if (timeEscolhido == 0){
        printf ("\nTime nao encontrado!!!\n");
      }
      fclose(arquivosTimes);
}

void cadastrarJogador (int tam,Jogadores *jogador){ // funcao para cadastrar jogador
  FILE *arquivosJogadores;
  arquivosJogadores = fopen("jogadores.txt", "a"); //abre e adiciona as informacoes no final arquivo

    printf("\t\t\t\t\t------Preencha os Dados do Jogador------\n");

    printf ("ID:");
    scanf ("%d",&jogador[tam].idJogador);
    getchar ();

    printf ("Nome:");
    fgets(jogador[tam].nomeJogador,sizeof(jogador[tam].nomeJogador),stdin);
    jogador[tam].nomeJogador[strcspn(jogador[tam].nomeJogador,"\n")] = '\0';

    printf ("Apelido:");
    fgets(jogador[tam].apelido,sizeof(jogador[tam].apelido),stdin);
    jogador[tam].apelido[strcspn(jogador[tam].apelido,"\n")] = '\0';

    printf ("Pais de Origem:");
    fgets(jogador[tam].paisDeOrigemJogador,sizeof(jogador[tam].paisDeOrigemJogador),stdin);
    jogador[tam].paisDeOrigemJogador[strcspn(jogador[tam].paisDeOrigemJogador,"\n")] = '\0';

    printf ("Idade:");
    scanf ("%d",&jogador[tam].idade);
    getchar ();

    printf ("Posicao Jogador:");
    fgets(jogador[tam].posicaoJogo,sizeof(jogador[tam].posicaoJogo),stdin);
    jogador[tam].posicaoJogo[strcspn(jogador[tam].posicaoJogo,"\n")] = '\0';

    printf ("Salario:");
    scanf ("%f",&jogador[tam].salario);
    getchar ();

    fprintf(arquivosJogadores, "%d|%s|%s|%s|%d|%s|%.2f\n", // passar as informacoes para dentro do arquivo
        jogador[tam].idJogador,jogador[tam].nomeJogador,jogador[tam].apelido,
        jogador[tam].paisDeOrigemJogador,jogador[tam].idade,jogador[tam].posicaoJogo,jogador[tam].salario);

    fclose (arquivosJogadores);
}

void passarJogadoresArquivo(Jogadores *jogador, int *quantidadeJogadores) { // funcao usada para retirar os dados do arquivo e repassar para dentro da struct para possibilitar trabalhar com dados pre-cadastrados
    FILE *arquivosJogadores;
    arquivosJogadores = fopen("jogadores.txt", "r"); // abri o arquivo no modo leitura para ler os dados

    if (arquivosJogadores == NULL) { // verifica a abertura do arquivo
        printf("Erro ao abrir arquivo!!!\n");
    }

    int i = 0;
    while (fscanf(arquivosJogadores, "%d|%[^|]|%[^|]|%[^|]|%d|%[^|]|%f\n", // usado o %[^|] para retirar o "|", que foi usado para separar as informacoes dentro do arquivo
        &jogador[i].idJogador,jogador[i].nomeJogador,jogador[i].apelido,
        jogador[i].paisDeOrigemJogador, &jogador[i].idade,jogador[i].posicaoJogo, &jogador[i].salario) == 7) {
        i++;
    }

    fclose(arquivosJogadores);
    *quantidadeJogadores = i; // passado por ponteiro para mudar o valor fora da funcao
}

void listarTodosJogadores (Jogadores *jogador){ // funcao usada para mostrar todos os jogadores cadastrados
   printf ("ID:%d\n",jogador->idJogador);
   printf ("Nome:%s\n",jogador->nomeJogador);
   printf ("Apelido:%s\n",jogador->apelido);
   printf ("Pais de Origem:%s\n",jogador->paisDeOrigemJogador);
   printf ("Idade:%d\n",jogador->idade);
   printf ("Posicao no Jogo:%s\n",jogador->posicaoJogo);
   printf ("Salario:%.2f\n",jogador->salario);
 }

void alterarInformacoesJogadores (Jogadores *jogador, int quantidadeJogadores, int idJogador){ // funcao para alterar as informacoes de um determinado jogador
   FILE *arquivosJogadores;
   arquivosJogadores = fopen("jogadores.txt","w");

   if (arquivosJogadores == NULL){ // verifica o arquivo
      printf ("Erro ao abrir arquivo!!!");
   }
     int jogadorEncontrado = 0; // usado para verificar se o jogador for encontrado, caso seja encotrado sera somado + 1, e vai ser usado para verificar no fim da funcao
   for (int i = 0; i < quantidadeJogadores; i++){ // for para buscar o jogador



      if (jogador[i].idJogador == idJogador){ // verifica se o id do jogador ja existe nos dados ja cadastrados

          printf ("Jogador encontrado!!!\n");
          printf ("Preencha as novas Informacoes\n");

      printf("Nome:");
      fgets(jogador[i].nomeJogador,sizeof(jogador[i].nomeJogador),stdin);
      jogador[i].nomeJogador[strcspn(jogador[i].nomeJogador, "\n")] = '\0';

      printf("Apelido:");
      fgets(jogador[i].apelido,sizeof(jogador[i].apelido),stdin);
      jogador[i].apelido[strcspn(jogador[i].apelido, "\n")] = '\0';

      printf("Pais de Origem:");
      fgets(jogador[i].paisDeOrigemJogador,sizeof(jogador[i].paisDeOrigemJogador),stdin);
      jogador[i].paisDeOrigemJogador[strcspn(jogador[i].paisDeOrigemJogador, "\n")] = '\0';

      printf ("Idade:");
      scanf ("%d",&jogador[i].idade);
      getchar();

      printf("Posicao Jogador:");
      fgets(jogador[i].posicaoJogo,sizeof(jogador[i].posicaoJogo),stdin);
      jogador[i].posicaoJogo[strcspn(jogador[i].posicaoJogo, "\n")] = '\0';

      printf ("Salario:");
      scanf ("%f",&jogador[i].salario);

      jogadorEncontrado++;
      getchar();

}

      fprintf(arquivosJogadores, "%d|%s|%s|%s|%d|%s|%.2f\n", // vai atualizar as informacoes do jogador dentro arquivo com os novos dados
        jogador[i].idJogador,jogador[i].nomeJogador,jogador[i].apelido,
        jogador[i].paisDeOrigemJogador,jogador[i].idade,jogador[i].posicaoJogo,jogador[i].salario);

 }
     if (jogadorEncontrado == 0){
        printf ("\nJogador nao Encontrado!!!\n");
     }
    fclose (arquivosJogadores);
  }

void cadastrarPartidas(int tam, Partidas *partida) { // funcao para cadastrar uma partida
    FILE *arquivosPartidas;
    arquivosPartidas = fopen("partidas.txt", "a"); // abrir e adicionar as informacoes no fim do arquivo

    printf("\t\t\t\t\t------Preencha os Dados sobre a Partida------\n");
    printf("ID da partida:");
    scanf("%d", &partida[tam].idPartida);
    getchar();

    printf("ID do time da casa:");
    scanf("%d", &partida[tam].idTimeCasa);
    getchar();

    printf("ID do time visitante:");
    scanf("%d", &partida[tam].idTimeVisitante);
    getchar();


    printf ("Horario da partida\n");
    printf ("Hora:");
    scanf ("%d",&partida[tam].horaPartida);

    printf ("Minutos:");
    scanf ("%d",&partida[tam].minPartida);

    printf ("Segundos:");
    scanf ("%d",&partida[tam].segPartida);

    printf ("Data da Partida\n");
    printf ("Dia:");
    scanf ("%d",&partida[tam].diaPartida);

    printf ("Mes:");
    scanf ("%d",&partida[tam].mesPartida);

    printf ("Ano:");
    scanf ("%d",&partida[tam].anoPartida);

    printf ("Placar Final\n");
    printf ("Pontuacao Time da casa:");
    scanf ("%f",&partida[tam].pontuacaoTimeCasa);

    printf ("Pontuacao Time visitante:");
    scanf ("%f",&partida[tam].pontuacaoTimeVisitante);

    printf ("Destaque individual da partida (ID do jogador que se destacou):");
    scanf ("%d",&partida[tam].DestaqueDaPartidaId);

    getchar();

    fprintf(arquivosPartidas, "%d|%d|%d|%d/%d/%d|%d/%d/%d|%f|%f|%d\n", // passar as informacoes para dentro do arquivo
        partida[tam].idPartida,partida[tam].idTimeCasa,partida[tam].idTimeVisitante,
        partida[tam].horaPartida,partida[tam].minPartida,partida[tam].segPartida,
        partida[tam].diaPartida,partida[tam].mesPartida,partida[tam].anoPartida,
        partida[tam].pontuacaoTimeCasa,partida[tam].pontuacaoTimeVisitante,partida[tam].DestaqueDaPartidaId);

    fclose(arquivosPartidas);
}

void passarPartidasArquivos(Partidas *partida, int *quantidadePartidas) { // funcao para pegar as informacoes de dentro do arquivo e passar para dentro da struct
    FILE *arquivosPartidas;
    arquivosPartidas = fopen("partidas.txt", "r");

    if (arquivosPartidas == NULL) {
        printf("Erro ao abrir arquivo!!!\n");
    }

    int i = 0;
    while (fscanf(arquivosPartidas, "%d|%d|%d|%d/%d/%d|%d/%d/%d|%f|%f|%d\n",
        &partida[i].idPartida,&partida[i].idTimeCasa,&partida[i].idTimeVisitante,
        &partida[i].horaPartida,&partida[i].minPartida,&partida[i].segPartida,
        &partida[i].diaPartida,&partida[i].mesPartida,&partida[i].anoPartida,
        &partida[i].pontuacaoTimeCasa,&partida[i].pontuacaoTimeVisitante,&partida[i].DestaqueDaPartidaId) == 12) {
        i++;
    }

    fclose(arquivosPartidas);
    *quantidadePartidas = i;
}


void buscarPartidasPorPeriodo(Partidas *partida, int quantidadePartidas) { // buscar partidas por data
    int diaInicio, mesInicio, anoInicio;
    int diaFim, mesFim, anoFim;

    printf("\nInforme a data de inicio\n");
    printf("Dia:");
    scanf("%d",&diaInicio);
    printf("Mes:");
    scanf("%d",&mesInicio);
    printf("Ano:");
    scanf("%d",&anoInicio);

    printf("Informe a data de fim\n");
    printf("Dia:");
    scanf("%d",&diaFim);
    printf("Mes:");
    scanf("%d",&mesFim);
    printf("Ano:");
    scanf("%d",&anoFim);

     printf ("\nPartidas Encontradas!!!\n");
    for (int i = 0; i < quantidadePartidas; i++) { // procurar a partida, e verificar se atende aos criterios de intervalo de datas
        if (partida[i].anoPartida >= anoInicio && partida[i].anoPartida <= anoFim &&
            partida[i].mesPartida >= mesInicio && partida[i].mesPartida <= mesFim &&
            partida[i].diaPartida >= diaInicio && partida[i].diaPartida <= diaFim) {
            printf("\nID da partida:%d\n", partida[i].idPartida);
            printf("ID do time da casa:%d\n", partida[i].idTimeCasa);
            printf("ID do time visitante:%d\n", partida[i].idTimeVisitante);
            printf("Data da partida:%d/%d/%d\n", partida[i].diaPartida, partida[i].mesPartida, partida[i].anoPartida);
            printf("Horario da partida:%d:%d:%d\n", partida[i].horaPartida, partida[i].minPartida, partida[i].segPartida);
            printf("Pontuacao do time da casa:%.2f\n", partida[i].pontuacaoTimeCasa);
            printf("Pontuacao do time visitante:%.2f\n", partida[i].pontuacaoTimeVisitante);
            printf("Destaque da partida (ID do jogador):%d\n", partida[i].DestaqueDaPartidaId);
            printf("\n");
        }
    }
}
int main() {
    Times time[1000];
    int quantidadeTimes = 0,idTime,idJogador;
    passarTimesArquivo(time, &quantidadeTimes);

    Jogadores jogador[1000];
    int quantidadeJogadores = 0;
    passarJogadoresArquivo(jogador,&quantidadeJogadores);

    int opcao;

    float mediaIdade = 0,totalSalario = 0;

    Partidas partida[1000];
    int quantidadePartidas = 0;
    passarPartidasArquivos(partida,&quantidadePartidas);

    do {
        printf("\t\t\t\t\t------Sistema de Liga E-Sports------\n");
        printf ("Escolha uma opcao abaixo\n");
        printf ("\n1 - Cadastrar um time\n");
        printf ("2 - Alterar informacoes de um time\n");
        printf ("3 - Cadastrar um jogador\n");
        printf ("4 - Alterar informacoes de um jogador\n");
        printf ("5 - Registrar uma partida\n");
        printf ("6 - Buscar partida por time\n");
        printf ("7 - Buscar partida por periodo\n");
        printf ("8 - Listar todos os times\n");
        printf ("9 - Listar todos os jogadores\n");
        printf ("10 - Calcular media de idade de todos os jogadores\n");
        printf ("11 - Preco total do time\n");
        printf ("12 - Sair do Programa\n");

        printf("\nOpcao:");
        scanf("%d", &opcao);
        getchar();

        while (opcao > 12) {
            printf("\nOpcao Invalida\nDigite Novamente:");
            scanf("%d", &opcao);
            getchar();
        }
        switch (opcao) {
        case 1: // cadastrar times
            cadastrarTime(quantidadeTimes, time);
            quantidadeTimes++;
            break;

            case 2: // alterar informacoes times
             printf ("\nInforme o ID do time que deseja alterar as informacoes:");
             scanf ("%d",&idTime);
             getchar();
             alterarInformacoesTime (time,quantidadeTimes,idTime);
            break;

            case 3: // cadastrar jogadores
            cadastrarJogador(quantidadeJogadores, jogador);
            quantidadeJogadores++;
            break;

            case 4: // alterar informacoes jogadores
             printf ("\nInforme o ID do jogador que deseja alterar as informacoes:");
             scanf ("%d",&idJogador);
             getchar();
             alterarInformacoesJogadores (jogador,quantidadeJogadores,idJogador);
            break;

            case 5: // cadastrar partidas
            cadastrarPartidas(quantidadePartidas, partida);
            quantidadePartidas++;
            break;

            case 7: // buscar partidas por periodos

            buscarPartidasPorPeriodo(partida, quantidadePartidas);
            break;


            case 8: // mostrar todos os times
             printf("\t\t\t\t\t------Todos os Times Cadastrados------\n");
             for (int i = 0; i < quantidadeTimes; i++){

            printf ("Time %d\n", i + 1);
            listarTodosOsTimes(&time[i]);
            printf ("\n");
          }
            break;

            case 9: //mostrar todos os jogadores
             printf("\t\t\t\t\t------Todos os Jogadores Cadastrados------\n");
          for (int i = 0; i < quantidadeJogadores; i++){

            printf ("Jogador %d\n", i + 1);
            listarTodosJogadores(&jogador[i]);
            printf ("\n");
          }
            break;

            case 10: // media de idade de todos os jogadores
            mediaIdade = 0;
          for (int i = 0; i < quantidadeJogadores; i++){
             mediaIdade += jogador[i].idade;
          }
          printf ("Media de idade de Todos os Jogadores:%.2f\n",mediaIdade/quantidadeJogadores);
          break;

            case 11: // total salario, soma do salario de todos os jogadores
              totalSalario = 0;
          for (int i = 0; i < quantidadeJogadores; i++){
             totalSalario += jogador[i].salario;
          }
          printf ("\nTotal Salario de todos os Jogadores:%.2f\n",totalSalario);
          break;

        case 12: // fim programa
            break;

        default:
            printf("\nOpcao Invalida\nDigite Novamente:");
            scanf("%d", &opcao);
            getchar();
            break;
        }

        if (opcao == 12) {
            printf("\nPrograma Encerrado!\n");
        }

    } while (opcao != 12);



}
