//Matheus Rauan Silva Do Nascimento 23484
//CAMILA MAYARA LENKE VIEIRA 21872
#ifndef ESTRUTURA_USER_H
#define ESTRUTURA_USER_H
#include "nodeEvento.h"

typedef struct user* ptrUser;

ptrUser criarAlocarUser(char* nome, link listaEventos);
char* getNome(ptrUser usuario);
void setNome(ptrUser usuario, char* novoNome);
link getListaEventos(ptrUser usuario);
void setListaEventos(ptrUser usuario, link novaListaEventos);
void imprimirUsuario(ptrUser usuario);
void separarStringEvento(char* stringCompleta, ptrUser* usuarios, int numUsuarios, int* dataAtual);
void adicionarEventoUsuario(ptrUser usuario, ptrEvento evento);
void apagarEventoUsuario(ptrUser usuario, ptrEvento evento);
int compararEventos(ptrEvento evento1, ptrEvento evento2);
void ordenarEventosUsuario(link* head);
ptrEvento* listaParaArray(ptrEvento lista, int* tamanho);
link insertionSort(link head);
void listarEventosPorData(ptrUser* user, int numUsers, int* dataAtual);
void ImprimirNeventos(ptrUser* user, int numUsers,int n);
void apagarEvento(ptrUser* user, char* descricao, int numUsers);
void escreverEventosEmArquivo(ptrUser* usuarios, int numUsuarios, int dia, int mes, int ano, const char* nomeArquivo);
#endif // !ESTRUTURA_USER_H