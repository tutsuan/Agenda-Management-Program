//Matheus Rauan Silva Do Nascimento 23484
//CAMILA MAYARA LENKE VIEIRA 21872
#ifndef ESTRUTURA_EVENTO_H
#define ESTRUTURA_EVENTO_H


typedef struct evento* ptrEvento;

ptrEvento criarAlocarEvento(int ano, int mes, int dia, int hora, int minuto, int duracaoEvento, char* descricao);
void separarDataAtual(char* dataDaAgenda);//vai receber a data da primeira linha do ficheiro da agenda para fazer as verificacoes e separacoes  
void imprimirEvento(ptrEvento evento);
int getAno(ptrEvento evento);
void setDescricao(ptrEvento evento, char* descricao);
void setDuracao(ptrEvento evento, int duracao);
void setMinuto(ptrEvento evento, int minuto);
void setHora(ptrEvento evento, int hora);
void setDia(ptrEvento evento, int dia);
void setMes(ptrEvento evento, int mes);
void setAno(ptrEvento evento, int ano);
int getAno(ptrEvento evento);
int getMes(ptrEvento evento);
int getDia(ptrEvento evento);
int getDuracao(ptrEvento evento);
char* getDescricao(ptrEvento evento);
int getHora(ptrEvento evento);
int getMinuto(ptrEvento evento);






#endif // !ESTRUTURA_EVENTOS_H
