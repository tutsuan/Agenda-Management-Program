//Matheus Rauan Silva Do Nascimento 23484
//CAMILA MAYARA LENKE VIEIRA 21872
#include "EstruturaEvento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct evento{

	int ano;
	int mes;
	int dia;
	int hora;
	int minuto;
	int duracao;
	char* descricao;

};


ptrEvento criarAlocarEvento(int ano,int mes,int dia,int hora,int minuto, int duracaoEvento, char* descricao) {
	ptrEvento e;
	e = (ptrEvento)malloc(sizeof(struct evento));	
	e->descricao = (char*)malloc(sizeof(char)* (strlen(descricao) + 1));
	e->ano = ano;
	e->mes = mes;
	e->dia = dia;
	e->hora = hora;
	e->minuto = minuto;
	e->duracao = duracaoEvento;
	strcpy(e->descricao, descricao);
	return e;
}



void imprimirEvento(ptrEvento evento) {
	printf("Descricao: %s -> ", evento->descricao);
	printf("Data: %02d/%02d/%d ", evento->dia, evento->mes, evento->ano);
	printf("Hora: %02d:%02d ", evento->hora, evento->minuto);
	printf("Duracao: %d h \n", evento->duracao);
}
void liberarEvento(ptrEvento evento) {
	free(evento->descricao);
	free(evento);
}

// Funções getter
int getAno(ptrEvento evento) {
	return evento->ano;
}

int getMes(ptrEvento evento) {
	return evento->mes;
}

int getDia(ptrEvento evento) {
	return evento->dia;
}

int getHora(ptrEvento evento) {
	return evento->hora;
}

int getMinuto(ptrEvento evento) {
	return evento->minuto;
}

int getDuracao(ptrEvento evento) {
	return evento->duracao;
}

char* getDescricao(ptrEvento evento) {
	return evento->descricao;
}

// Funções setter
void setAno(ptrEvento evento, int ano) {
	evento->ano = ano;
}

void setMes(ptrEvento evento, int mes) {
	evento->mes = mes;
}

void setDia(ptrEvento evento, int dia) {
	evento->dia = dia;
}

void setHora(ptrEvento evento, int hora) {
	evento->hora = hora;
}

void setMinuto(ptrEvento evento, int minuto) {
	evento->minuto = minuto;
}

void setDuracao(ptrEvento evento, int duracao) {
	evento->duracao = duracao;
}

void setDescricao(ptrEvento evento, char* descricao) {
	free(evento->descricao);
	evento->descricao = (char*)malloc(sizeof(char) * (strlen(descricao) + 1));
	strcpy(evento->descricao, descricao);
}



