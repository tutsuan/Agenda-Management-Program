//Matheus Rauan Silva Do Nascimento 23484
//CAMILA MAYARA LENKE VIEIRA 21872
#include "nodeEvento.h"
#include <stdio.h>




struct node {
	ptrEvento evento;
	link nextEvento;
};

link newNode(ptrEvento evento, link next) {
	link t = (link)malloc(sizeof(struct node));
	t->nextEvento = next;
	t->evento = evento;
	return t;
}


void freeNode(link t) {
		//free(t->evento);  // Libera a memória do evento dentro do nó
		free(t);  // Libera a memória do próprio nó
	
}

link nextEvento(link t) {

	if (t == NULL)
		return NULL;
	else
		return t->nextEvento;

}
void setNextEvento(link t, link next) {
	if (t != NULL) {
		t->nextEvento = next;
	}
}

ptrEvento item(link t) {
	return t->evento;
}

void insertNext(link x, link t) {
	t->nextEvento = x->nextEvento;
	x->nextEvento = t;
}

link deleteNext(link x) {
	link t = x->nextEvento;
	x->nextEvento = t->nextEvento;  //x->next = x->next->next;
	t->nextEvento = NULL;
	return t;
}

void printLista(link head)
{
	link t;

	printf("[");
	for (t = head; t != NULL; t = t->nextEvento)
		imprimirEvento(t->evento);
	printf("]\n");
}


link insereNoFim(link head, ptrEvento item) {
	link t;
	if (head == NULL)
		head = newNode(item, head);
	else {
		t = head;
		while (nextEvento(t) != NULL) {
			t = nextEvento(t);//atingiu o fim da lista

		}
		insertNext(t, newNode(item, NULL));//acrescentou no fim da lista
	}
	return head;
}

link insereNoInicio(link head, ptrEvento item) {
	return newNode(item, head);

}
ptrEvento pop(link* head) {
	if (*head == NULL) {
		return NULL;
	}
	link poppedNode = *head;
	ptrEvento poppedItem = poppedNode->evento;
	*head = poppedNode->nextEvento;
	free(poppedNode);
	return poppedItem;
}
void push(link* head, ptrEvento item) {
	link newNode = (link)malloc(sizeof(struct node));
	newNode->evento = item;
	newNode->nextEvento = *head;
	*head = newNode;
}
void setNext(link t, link next) {
	//if(t!=NULL && next!=NULL)
		t->nextEvento = next;
}
link juntarListas(link lista1, link lista2) {
	if (lista1 == NULL) {
		return lista2;
	}
	if (lista2 == NULL) {
		return lista1;
	}

	link aux = lista1;
	while (aux->nextEvento != NULL) {
		aux = aux->nextEvento;
	}

	aux->nextEvento = lista2;

	return lista1;
}

