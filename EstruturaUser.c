//Matheus Rauan Silva Do Nascimento 23484
//CAMILA MAYARA LENKE VIEIRA 21872
#include "EstruturaUser.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Data.h"
#define Less(A,B) (compararEventos(A,B))
#define exch(A, B) { Item t = A; A= B; B=t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)
struct user {
	char* nome;
	link listaEventos;
};

ptrUser criarAlocarUser(char* nome, link listaEventos) {

	ptrUser usuario = (ptrUser)malloc(sizeof(struct user));
	usuario->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(usuario->nome, nome);
	usuario->listaEventos = listaEventos;
	return usuario;

}

/*Recebe uma string de um evento, separa e aloca nas devidas estruturas, recebe os usuarios e o numero de usuarios,
percorre o array de usuarios, incrementa o evento na lista de eventos do usuario correspondente ao evento lido e verifica se sua data 
eh apos a data atual*/
void separarStringEvento(char* stringCompleta, ptrUser* usuarios, int numUsuarios, int* dataAtual) {
	char* token = strtok(stringCompleta, " ");
	// Extrai os parâmetros para o usuário e o evento
	int ano = atoi(token);
	token = strtok(NULL, " ");
	int mes = atoi(token);
	token = strtok(NULL, " ");
	int dia = atoi(token);
	token = strtok(NULL, " ");
	int hora = atoi(token);
	token = strtok(NULL, " ");
	int minuto = atoi(token);
	token = strtok(NULL, " ");
	int duracao = atoi(token);
	token = strtok(NULL, ":");
	char* nomeUsuario = token;
	token = strtok(NULL, ":");
	char* descricaoEvento = token;
	// Cria a estrutura do usuario
	ptrEvento evento = criarAlocarEvento(ano, mes, dia, hora, minuto, duracao, descricaoEvento);
	link noEvento = newNode(evento, NULL);
	for (int i = 0; i < numUsuarios; i++) {
		if (strcmp(usuarios[i]->nome, nomeUsuario) == 0) {//encontrou o usuario a quem pertence o evento
			if (usuarios[i]->listaEventos == NULL) {
				adicionarEventoUsuario(usuarios[i], evento);//cria um novo no para o usuario caso esteja vazio
				break;
			}
			int verificacaoSeDataPassada= comparaDataAtualEvento(evento, usuarios[i], dataAtual);
			int verificaConfltoEntreEventoeEventos = verificaConflitoHorario(evento, usuarios[i]->listaEventos);
			int verificarSeEventoJaexiste = verificarSeEventoJaExiste(usuarios[i], evento);
			if (verificacaoSeDataPassada == 2) {
				printf("Nao e possivel adicionar eventos com datas anteriores a data atual, descricao do evento antigo: %s.\n", getDescricao(evento));
				break;
			}
			if (verificarSeEventoJaexiste == 1) {
				printf("Evento %s com a mesma descricao ja existe\n",getDescricao(evento));
				break;

			}
			if (verificacaoSeDataPassada == 1 && verificaConfltoEntreEventoeEventos==1) {
				adicionarEventoUsuario(usuarios[i], evento);
				printf("Novo evento adicionado, sem conflitos, descricao do evento: % s.\n", getDescricao(evento));
				break;
			}
			if (verificaConfltoEntreEventoeEventos == 0) {
				printf("Ja existe um evento na lista no mesmo horario do evento %s, evento nao adicionado\n", getDescricao(evento));
				break;
			}


		}
	}
}
int verificarSeEventoJaExiste(ptrUser user, ptrEvento evento) {
	link eventoAtual = user->listaEventos;
	while (eventoAtual != NULL) {
		if (strcmp(getDescricao(item(eventoAtual)), getDescricao(evento)) == 0)
			return 1;
		eventoAtual = nextEvento(eventoAtual);
	}
	return 0;
}
void apagarEvento(ptrUser* user, char* descricao,int numUsers) {
	
	link eventoAnterior = NULL;
	for (int i = 0; i < numUsers; i++) {//verificar todos os eventos
		eventoAnterior = NULL;
		link eventoAtual = user[i]->listaEventos;
		while (eventoAtual != NULL) {
			//puts(getDescricao(item(eventoAtual)));
			if (strcmp(getDescricao(item(eventoAtual)), descricao) == 0) {
				if (eventoAnterior == NULL) {
					link proximo = nextEvento(user[i]->listaEventos);
					user[i]->listaEventos = proximo;
					printf("Apagado com sucesso\n");
				}
				else {
					deleteNext(eventoAnterior);
					printf("Apagado com sucesso\n");
				}
				return; // Evento removido, encerra a função
			}

			// Evento não encontrado, avança para o próximo
			eventoAnterior = eventoAtual;
			eventoAtual = nextEvento(eventoAtual);
		}
	}

	printf("Evento nao encontrado.\n");
}

/*Recebe o usuario e o evento e usando o insertion sort aloca o evento no No exato da sua posicao na lista de eventos do user*/
void adicionarEventoUsuario(ptrUser usuario, ptrEvento evento) {
	link novoNo = newNode(evento, NULL);

	// Se a lista de eventos do usuário estiver vazia, o novo evento se torna o primeiro
	if (usuario->listaEventos == NULL) {
		usuario->listaEventos = novoNo;
	}
	else {
		link ultimoNo = usuario->listaEventos;

		// Percorre a lista até encontrar o último nó
		while (nextEvento(ultimoNo) != NULL) {
			ultimoNo = nextEvento(ultimoNo);
		}

		// Adiciona o novo evento como próximo do último nó usando a função insertNext
		insertNext(ultimoNo, novoNo);
	}
	link ordenarUser = newNode(NULL, NULL);// cria um primeiro no para uma nova lista ordenada
	ordenarUser = juntarListas(ordenarUser, usuario->listaEventos);//junta o no com a lista do usuario preexistente
	ordenarUser = insertionSort(ordenarUser);//faz a nova ordenacao com o novo evento
	usuario->listaEventos = ordenarUser;//aponta para o usuario onde esta sua nova lista ordenada
}// tem que comparar os eventos existentes e o que deseja adiconar para fazer algumas verificaceos e verificar se ja existe esse evento


char* getNome(ptrUser usuario) {
    return usuario->nome;
}

void setNome(ptrUser usuario, char* novoNome) {
    free(usuario->nome);
    usuario->nome = (char*)malloc(sizeof(char) * (strlen(novoNome) + 1));
}

link getListaEventos(ptrUser usuario) {
    return usuario->listaEventos;
}

void setListaEventos(ptrUser usuario, link novaListaEventos) {
    usuario->listaEventos = novaListaEventos;
}

void imprimirUsuario(ptrUser usuario) {
    printf("Nome do usuario: %s\n", usuario->nome);
    printf("Lista de eventos associados ao usuario:\n");
    printLista(usuario->listaEventos);
}
/*Compara eventos e retorna numero negativo se o primeiro evento for antes que o segundo e positivo se for depois*/
int compararEventos(ptrEvento evento1, ptrEvento evento2) {
	if (getAno(evento1) != getAno(evento2)) {
		return getAno(evento1) - getAno(evento2);
	}
	else if (getMes(evento1) != getMes(evento2)) {
		return getMes(evento1) - getMes(evento2);
	}
	else if (getDia(evento1) != getDia(evento2)) {
		return getDia(evento1) - getDia(evento2);
	}
	else if (getHora(evento1) != getHora(evento2)) {
		return getHora(evento1) - getHora(evento2);
	}
	else if (getMinuto(evento1) != getMinuto(evento2)) {
		return getMinuto(evento1) - getMinuto(evento2);
	}
	else {
		// Caso as datas sejam iguais, desempate pelo nome em ordem alfabética so sera usado na hora de listar todos os eventos como desempate
		return strcmp(getNome(evento1), getNome(evento2));
	}
}
/*recebe um ponteiro para o nó de cabeçalho da lista e retorna o ponteiro para o novo nó de cabeçalho da lista ordenada*/
link insertionSort(link head) {
	link x, t, u, out = NULL;
	for (t = nextEvento(head); t != NULL; t = u) {
		u = nextEvento(t);
		if (out == NULL || compararEventos(item(t), item(out)) < 0) {
			setNext(t, out);
			out = t;
		}
		else {
			for (x = out; nextEvento(x) != NULL; x = nextEvento(x)) {
				if (compararEventos(item(t), item(nextEvento(x))) < 0)
					break;
			}
			setNext(t, nextEvento(x));
			setNext(x, t);
		}
	}
	return out;
}


void listarEventosPorData(ptrUser* user, int numUsers, int* dataAtual) {  
	int anoAtual = dataAtual[0];
	int mesAtual = dataAtual[1];
	int diaAtual = dataAtual[2];
	int i, j;
	link eventosParaImprimir = newNode(NULL, NULL);
	for (i = 0; i < numUsers; i++) {
		ptrUser usuario = user[i]; 
		link listaEventos = getListaEventos(usuario);
		link eventoAtual = listaEventos;
		while (eventoAtual != NULL) {
			if (anoAtual == getAno(item(eventoAtual)) && mesAtual == getMes(item(eventoAtual)) && diaAtual == getDia(item(eventoAtual))) {
				//tem que copiar o evento colocar na lista auxiliar de eventos para depois essa lista mandar ordenar e depois imprimir 
				//printf("Dia evento hoje: %i %i %i dia do evento comparado: %i %i %i\n", diaAtual, mesAtual, anoAtual, getDia(item(eventoAtual)), getMes(item(eventoAtual)), getAno(item(eventoAtual)));				
				link listaUm = newNode(item(eventoAtual), NULL);//cria um no clone com o elemento a ser impresso
				eventosParaImprimir = juntarListas(eventosParaImprimir, listaUm);//junta com o anterior
			}

			eventoAtual = nextEvento(eventoAtual);//passar para o proximo no 
		}

	}
	eventosParaImprimir = insertionSort(eventosParaImprimir);
	printLista(eventosParaImprimir);
}
void ImprimirNeventos(ptrUser* user, int numUsers, int n) {//ta juntando os todos os eventos e atribuindo aos utilizadores que ja tinham eventos todos juntos ERROR
	int i;
	link eventosParaImprimir = newNode(NULL,NULL);//criar primerio no

	for (i = 0; i < numUsers; i++) {
		ptrUser usuario = user[i];
		link listaEventos = getListaEventos(usuario);
		// listaUm = newNode(item(listaEventos), NULL);//lista com um no auxiliar para a copia e nao modficar a original (nao funcionou)
		eventosParaImprimir = juntarListas(eventosParaImprimir, listaEventos); 
	}

	eventosParaImprimir = insertionSort(eventosParaImprimir);
	int contador = 0;
	link eventoAtual = eventosParaImprimir;

	while (contador < n && eventoAtual != NULL) {
		imprimirEvento(item(eventoAtual));
		eventoAtual = nextEvento(eventoAtual);
		contador++;
	}
}




void apagarEventoUsuario(ptrUser usuario, ptrEvento evento) {
	link atual = usuario->listaEventos;
	link anterior = NULL;

	// Percorre a lista até encontrar o evento desejado ou o final da lista
	while (atual != NULL && item(atual) != evento) {
		anterior = atual;
		atual = nextEvento(atual);
	}

	// Verifica se o evento foi encontrado
	if (atual == NULL) {
		printf("Evento não encontrado na lista do usuário.\n");
		return;
	}

	// Remove o evento da lista
	if (anterior == NULL) {
		// Se o evento é o primeiro da lista
		link proximo = nextEvento(usuario->listaEventos);
		usuario->listaEventos = proximo;
	}

	else {
		// Caso contrário
		deleteNext(anterior);
	}

}

void escreverEventosEmArquivo(ptrUser * usuarios, int numUsuarios, int dia,int mes, int ano, const char* nomeArquivo) {
		FILE* arquivo = fopen(nomeArquivo, "w");
		if (arquivo == NULL) {
			printf("Erro ao criar o arquivo.\n");
			return;
		}

		fprintf(arquivo, "%d %02d %02d\n", ano,mes,dia);
		fprintf(arquivo, "%d\n", numUsuarios);

		for (int i = 0; i < numUsuarios; i++) {
			fprintf(arquivo, "%s\n", getNome(usuarios[i]));
		}
		int j = 0;
		for (int i = 0; i < numUsuarios; i++) {
			ptrUser usuario = usuarios[i];
			link listaEventos = getListaEventos(usuario);
			link eventoAtual = listaEventos;
			int contador = 0;
			while (eventoAtual != NULL) {
				contador++;
				eventoAtual = nextEvento(eventoAtual);
			}
			j += contador;
		}
		fprintf(arquivo, "%d\n", j);

		for (int k = 0; k < numUsuarios; k++) {
			ptrUser usuario = usuarios[k];
			link listaEventos = getListaEventos(usuario);
			link eventoAtual = listaEventos;
			while (eventoAtual != NULL) {
				fprintf(arquivo, "%d %02d %02d %02d %02d %d %s:%s\n", getAno(item(eventoAtual)),
					getMes(item(eventoAtual)), getDia(item(eventoAtual)), getHora(item(eventoAtual)),
					getMinuto(item(eventoAtual)), getDuracao(item(eventoAtual)), getNome(usuario), getDescricao(item(eventoAtual)));
				eventoAtual = nextEvento(eventoAtual);
			}

		}
		

		fclose(arquivo);

		printf("As informacoes foram escritas no arquivo '%s' com sucesso.\n", nomeArquivo);
	}



