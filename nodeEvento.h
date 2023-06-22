//Matheus Rauan Silva Do Nascimento 23484
//CAMILA MAYARA LENKE VIEIRA 21872
#pragma once
#ifndef NODE_EVENTO_H
#define NODE_EVENTO_H
#include "EstruturaEvento.h"

typedef struct node* link;


link newNode(ptrEvento, link);//criar nova estrutura
void freeNode(link);//apagar estrutura
link nextEvento(link);// retorna o proximo 
ptrEvento item(link);// retorna o item (inteiro) 
void insertNext(link, link);// link do no que ja existe e o link que vai inserir
link deleteNext(link); // return the deleted link tirar da lista mas nao apagar 
void printLista(link);
link insereNoInicio(link, ptrEvento);
void push(link* head, ptrEvento item);
ptrEvento pop(link* head);//apaga o primeiro item da lista
void push(link* head, ptrEvento item);
link insereNoFim(link, ptrEvento);
void setNext(link t, link next);
link juntarListas(link head1, link head2);
link getLastNode(link lista);
void setNextEvento(link t, link next);

#endif // !NODE_EVENTO_H
