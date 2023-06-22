#ifndef GERENCIADOR_DATA_H
#define GERENCIADOR_DATA_H
#include "EstruturaUser.h"
//nem precisa
struct data {
    int anoAtual;
    int diaAtual;
    int mesAtual;
    int horaAtual;
    int minutoAtual;
};

int comparaDataAtualEvento(link evento, ptrUser user, int* dataAtual);
float daHoraFimDoEvento(ptrEvento evento);
int* avancarUmDia(ptrUser* user, int numUsers, int* dataAtual);
int verificaConflitoHorario(ptrEvento evento, link listaEventos);
void imprimirMenu();
#endif  // GERENCIADOR_DATA_H
