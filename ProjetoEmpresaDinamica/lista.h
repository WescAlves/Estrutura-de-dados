//funcoes dedicadas a operacoes com lista
#include <stdlib.h>
typedef struct no{
	struct no* anterior;
	char nome[30];  //neste campo, implemente a estrutura de dados desejada. neste caso, funcionario.
	struct no* prox;	
}No;

typedef struct lista{
	No* inicio;
}Lista; 

Lista* criar_Lista();

void ver_funcionarios (No* no);

void percorrer_lista (Lista* lista);

void adicionar_no_inicio (No* novo, Lista* lista);

int remover_da_lista(No* no, Lista* lista);

void deletarLista(Lista* lista);

