//Matheus Rauan Silva Do Nascimento 23484
//CAMILA MAYARA LENKE VIEIRA 21872
#include <stdio.h>
#include "EstruturaUser.h"
#include "Data.h"
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]) {
    FILE* fagenda;
    FILE* feventos;
    char buffer[2048];
    if (argc != 3) {// ele ja limita a leitura a tres posicoes para leitura
        printf("Numero de argumentos errados,indique o Agenda.exe, o agenda.txt e o eventos.txt no terminal do debug\n");
        exit(0);
    }
    fagenda = fopen(argv[1], "r");
    if (fagenda == NULL) {
        printf("ficheiro da agenda nao encontrado\n");
        exit(0);
    }
    feventos = fopen(argv[2], "r");
    if (fagenda == NULL) {
        printf("ficheiro da eventos nao encontrado\n");
        exit(0);
    }
    int ano, mes, dia,i;
    fscanf(fagenda, "%i%i%i", &ano, &mes, &dia);
    int dataAtual[] = { ano, mes, dia };//pegou a data atual do ficheiro
    int numeroUsuarios;
    fscanf(fagenda, "%i", &numeroUsuarios);
    fscanf(fagenda, " ");
    //printf("%i\n", numeroUsuarios);
    ptrUser* usuario = (ptrUser*)malloc(numeroUsuarios * sizeof(ptrUser));//cria um array de usuarios
    for (i = 0; i < numeroUsuarios; i++) {
        fgets(buffer, 2048, fagenda);
        buffer[strlen(buffer) - 1] = '\0';//indicar fim do array
        //puts(buffer);
        usuario[i] = criarAlocarUser(buffer, NULL);
    }
    //fscanf(fagenda, " ");
    int numEventosAgenda;
    fscanf(fagenda, "%i", &numEventosAgenda);
    //printf("%i\n", numEventosAgenda);
    fscanf(fagenda, " ");
    for (i = 0; i < numEventosAgenda; i++) {
        fgets(buffer, 2048, fagenda);
        buffer[strlen(buffer) - 1] = '\0';//indicar fim do array
        //puts(buffer);
        separarStringEvento(buffer, usuario, numeroUsuarios, dataAtual);
    }
   
    int numeroNovosEventos;
    fscanf(feventos, "%i", &numeroNovosEventos);
    printf("%i\n", numeroNovosEventos);
    fscanf(feventos, " ");
    for (i = 0; i < numeroNovosEventos; i++) {
        fgets(buffer, 2048, feventos);
        buffer[strlen(buffer) - 1] = '\0';
        separarStringEvento(buffer, usuario, numeroUsuarios, dataAtual);

    }

    /*
    printf("Imprimindo eventos de hoje:\n");
    //listarEventosPorData(usuario, numeroUsuarios, dataAtual);
    for (i = 0; i < numeroUsuarios; i++)
        imprimirUsuario(usuario[i]);
    //ImprimirNeventos(usuario,numeroUsuarios,3);

    for (i = 0; i < numeroUsuarios; i++)
        imprimirUsuario(usuario[i]);*/

    for (i = 0; i < numeroUsuarios; i++)
        imprimirUsuario(usuario[i]); 

    int opcao = -1;
    while (opcao != 0) {
        imprimirMenu();
        scanf("%i", &opcao);
        switch (opcao){
            case 1:
                printf("Crie o novo evento nesse exato formado:<ano> <mes> <dia> <hora> <minutos> <duracao> <nome utilizador>:<descricao evento>\n");
                scanf(" ");
                gets(buffer);
                //buffer[strlen(buffer) - 1] = '\0';
                separarStringEvento(buffer, usuario, numeroUsuarios, dataAtual);
                break;
            case 2:
                printf("Qual a descricao do evento que deseja apagar?\n");
                scanf(" ");
                gets(buffer);
                apagarEvento(usuario, buffer, numeroUsuarios);
                break;
            case 3:
                printf("Qual ultilizador deseja listar os eventos associados?\n");
                scanf(" ");
                gets(buffer);
                imprimirUsuario(usuario[1]);
                imprimirUsuario(usuario[3]);
                for (i = 0; i < numeroUsuarios; i++)
                    if (strcmp(getNome(usuario[i]), buffer) == 0) {
                        imprimirUsuario(usuario[i]);
                        break;
                    }                  
                break;
            case 4:
                printf("Listando eventos de hoje : %i/%i/%i\n", dia, mes, ano);
                listarEventosPorData(usuario, numeroUsuarios, dataAtual);//ta juntando eventos 
                for (i = 0; i < numeroUsuarios; i++)
                    imprimirUsuario(usuario[i]); 
                break;
            case 5:
                printf("Indique a data a qual deseja imprimir os eventos dia/mes/ano:\n");
                int diaImprimir, mesImprimir, anoImprimir;
                scanf("%i %i %i", &diaImprimir, &mesImprimir, &anoImprimir);
                int dataImprimir[] = { anoImprimir,mesImprimir,diaImprimir };
                listarEventosPorData(usuario, numeroUsuarios, dataImprimir);//ta juntando eventos 

                break;
            case 6:
                printf("Quantos eventos deseja listar:\n");
                int numEventos;
                scanf("%i", &numEventos);
                ImprimirNeventos(usuario, numeroUsuarios, numEventos);
                break;
            case 7:
                printf("Avancando um dia...\n");
                int* dataAvancada = avancarUmDia(usuario, numeroUsuarios, dataAtual);
                dataAtual[2] = dataAvancada[2];// {dataAvancada[0], dataAvancada[1], dataAvancada[2]};
                for (i = 0; i < numeroUsuarios; i++)
                    imprimirUsuario(usuario[i]);
                printf("% i / % i / % i\n", dataAtual[0], dataAtual[1], dataAtual[2]);

                break;
            case 8:
                sprintf(buffer, "agenda-%d-%02d-%02d.txt", ano, mes, dataAtual[2]);
                printf("String final: %s\n", buffer);
                escreverEventosEmArquivo(usuario, numeroUsuarios, dataAtual[2], dataAtual[1], dataAtual[0], buffer);
                printf("Obrigado ate mais. FIMM *******\n");
                opcao = 0;
                break;

            default:
                break;
        }
        
    }


    return 0;

}