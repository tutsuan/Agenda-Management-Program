//Matheus Rauan Silva Do Nascimento 23484
//CAMILA MAYARA LENKE VIEIRA 21872
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
//char dataAtual[12]; // Definindo dataAtual como uma matriz de caracteres


int comparaDataAtualEvento(link evento, ptrUser user, int dataAtual[]) { //vendo se a data ja passou  
   
    int anoAtual = dataAtual[0];
    int mesAtual = dataAtual[1];
    int diaAtual =dataAtual[2];
    // Extrai a data e hora do evento
    //ptrEvento evento = item(noEvento);
    int anoEvento = getAno(evento);
    int diaEvento = getDia(evento);
    int mesEvento = getMes(evento);
    int horaEvento = getHora(evento);
    int minutoEvento = getMinuto(evento);

    // Compara as datas
    if (anoEvento < anoAtual || (anoEvento == anoAtual && (mesEvento < mesAtual || (mesEvento == mesAtual && (diaEvento < diaAtual))))) {
        // A data do evento ocorreu antes da data atual
        // A data j� passou, ent�o o evento n�o pode ser adicionado
        return 2;
    }
    else {
        // A data do evento ocorre depois ou � igual � data atual
        // O evento pode ser adicionado na agenda
        

        return 1;
    }
}

int verificaConflitoHorario(ptrEvento evento, link listaEventos) {
    int minutoEvento = getMinuto(evento);
    float horaEvento = getHora(evento) + minutoEvento / 60;
    float horaFimEvento = daHoraFimDoEvento(evento);
    int diaEvento = getDia(evento);
    int mesEvento = getMes(evento);
    int anoEvento = getAno(evento);
    link eventoAtual = listaEventos;
    //printf("Data: %02d/%02d/%d\n", diaEvento, mesEvento, anoEvento);
    while (eventoAtual != NULL) {
        int minutoInicioProximoEvento = getMinuto(item(eventoAtual));
        float horaInicioProximoEvento = getHora(item(eventoAtual)) + minutoInicioProximoEvento / 60;
        float horaFimProximoEvento = daHoraFimDoEvento(item(eventoAtual));
        int diaProximo = getDia(item(eventoAtual));
        int mesProximo = getMes(item(eventoAtual));
        int anoProximo = getAno(item(eventoAtual));
        //printf("Data do evento comparando: %02d/%02d/%d\n", diaProximo, mesProximo, anoProximo);
        if (diaEvento == diaProximo && mesEvento == mesProximo && anoEvento == anoProximo) {
            //printf("\n CONFLITO %f-%f e %f-%f\n", horaInicioProximoEvento, horaFimProximoEvento, horaEvento, horaFimEvento);
            if ((horaInicioProximoEvento >= horaEvento && horaInicioProximoEvento < horaFimEvento) ||
                (horaFimProximoEvento > horaEvento && horaFimProximoEvento <= horaFimEvento) ||
                (horaInicioProximoEvento <= horaEvento && horaFimProximoEvento >= horaFimEvento)) {
                //printf("\nCONFLITO hora de inicio de um dos eventos: %.2f e hora do fim do evento comparado: %.2f\n", horaInicioProximoEvento, horaFimEvento);
                return 0;  // H� conflito de hor�rio, o evento n�o pode ser adicionado
            }
        }

        eventoAtual = nextEvento(eventoAtual);
    }

    return 1;  // N�o h� conflito de hor�rio, o evento pode ser adicionado
}

float daHoraFimDoEvento(ptrEvento evento) {
    // Obt�m a hora de in�cio e a dura��o do evento
    int horaInicio = getHora(evento);
    int minutoInicio = getMinuto(evento);
    int duracao = getDuracao(evento);  // somente em horas

    // Calcula a hora final do evento
    float minutoFim = minutoInicio / 60.0;  // Mant�m os minutos de in�cio, caso a dura��o n�o ultrapasse uma hora
    float horaFim = horaInicio + duracao + minutoFim;
    // Retorna a hora final do evento

    return horaFim;
}

int* avancarUmDia(ptrUser* user, int numUsers, int* dataAtual) {//funcionando 100%
    // Avan�a um dia no dia atual e apaga todos os eventos passados da lista de eventos de todos os usu�rios
    // Faz a verifica��o novamente

    // Avan�a um dia na data atual
    int anoAtual = dataAtual[0];
    int mesAtual = dataAtual[1];
    int diaAtual = dataAtual[2];
    printf("Data: %02d/%02d/%d\n", diaAtual, mesAtual, anoAtual);
    //fazer um switch para manipular essas datas caso seja um mes com 28, 30 ou 31 dias no mes e avanca um dia muda o mes e tambem o ano caso seja 31/12
    switch (mesAtual) {
        case 1: // Janeiro
        case 3: // Mar�o
        case 5: // Maio
        case 7: // Julho
        case 8: // Agosto
        case 10: // Outubro
        case 12: // Dezembro
            if (diaAtual == 31) {
                // �ltimo dia do m�s, avan�a para o pr�ximo m�s
                diaAtual = 1;
                if (mesAtual == 12) {
                    // �ltimo m�s do ano, avan�a para o pr�ximo ano
                    mesAtual = 1;
                    anoAtual++;
                }
                else {
                    // Avan�a para o pr�ximo m�s
                    mesAtual++;
                }
            }
            else {
                // Ainda n�o � o �ltimo dia do m�s, apenas avan�a um dia
                diaAtual++;
            }
            break;
        case 4: // Abril
        case 6: // Junho
        case 9: // Setembro
        case 11: // Novembro
            if (diaAtual == 30) {
                // �ltimo dia do m�s, avan�a para o pr�ximo m�s
                diaAtual = 1;
                mesAtual++;
            }
            else {
                // Ainda n�o � o �ltimo dia do m�s, apenas avan�a um dia
                diaAtual++;
            }
            break;
        case 2: // Fevereiro
            if (diaAtual == 28) {
                // �ltimo dia do m�s, avan�a para o pr�ximo m�s
                diaAtual = 1;
                mesAtual++;
            }
            else {
                // Ainda n�o � o �ltimo dia do m�s, apenas avan�a um dia
                diaAtual++;
            }
            break;
        default:
            // M�s inv�lido
            // Voc� pode adicionar uma l�gica de tratamento de erro aqui, se necess�rio
            break;
    }

    // Atualiza a data atual verificar se altera a data no main principal ou precisa retornar e la re-atribuir
    dataAtual[0] = anoAtual;
    dataAtual[1] = mesAtual;
    dataAtual[2] = diaAtual;
    printf("Data avancada: %02d/%02d/%d\n", diaAtual, mesAtual, anoAtual);

    // Apaga eventos passados da lista de eventos de todos os usu�rios
    int i, j;
    for (i = 0; i < numUsers; i++) {
        ptrUser usuario = user[i];
        link listaEventos = getListaEventos(usuario);
        link eventoAtual = listaEventos;// nao eh pra copiar eh pra apontar 
        link proximo = nextEvento(eventoAtual);

        //printLista(listaEventos);

        while (eventoAtual != NULL) {
            //printf("\nteste\n");
            if(nextEvento(eventoAtual)!=NULL)
                proximo = nextEvento(eventoAtual);
            int anoEvento = getAno(item(eventoAtual));
            int mesEvento = getMes(item(eventoAtual));
            int diaEvento = getDia(item(eventoAtual));
            //printf("Data evento passado: %02d/%02d/%d\n", diaEvento, mesEvento, anoEvento);
            if (anoEvento < anoAtual || (anoEvento == anoAtual && (mesEvento < mesAtual || (mesEvento == mesAtual && diaEvento < diaAtual)))) {
                // O evento ocorreu antes da data atual
                // Remove o evento da lista de eventos
                printf("\nEvento removido data antiga: %s Usuario: %s\n", getDescricao(item(eventoAtual)), getNome(user[i]));
                /*if (nextEvento(eventoAtual) == NULL) {
                    freeNode(eventoAtual);
                    setListaEventos(usuario, NULL);
                    break;//need to fix
            }*/
                apagarEventoUsuario(user[i], item(eventoAtual));
            }
            else
                break;

            eventoAtual = proximo;
        }

        // Atualiza a lista de eventos do usu�rio
      // setListaEventos(usuario, listaEventos);
    }
    return dataAtual;
}



void imprimirMenu() {
    printf("*****MENU*****\n");
    printf("1-Registrar um novo evento\n");
    printf("2-Apagar evento\n");
    printf("3-Listar eventos de um utilizador\n");
    printf("4-Listar eventos de hoje\n");
    printf("5-Listar eventos para um determinado dia\n");
    printf("6-Listar os proximos n eventos\n");
    printf("7-Avancar 1 dia\n");
    printf("8-Sair do menu\n");


}