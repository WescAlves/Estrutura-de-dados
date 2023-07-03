//funcoes dedicadas a operacoes com lista

#include "lista.h"
#include "funcionario.h"

Lista* criar_Lista(){
	Lista* lista = (Lista*) malloc(sizeof(Lista));
	if (lista != NULL){
	lista -> inicio = NULL;
	return lista;
	}
	else {
		return NULL;
	}
}

void ver_funcionarios (No* no) {
	printf("\n-------------------------------------\n");
	printf("\nNome: %s\n", no -> nome);
	printf("\n------------------------------\n");
}

void percorrer_lista (Lista* lista){ //este subprograma percorre a lista inteira e faz chamada para o subprograma desejado a cada la�o
	if(lista -> inicio == NULL){
		printf("\n A lista esta vazia!\n");
		
	}
	else {
		No* aux = lista -> inicio;
		while(aux != NULL){
			ver_funcionarios(aux);
			aux = aux -> prox;
		}	
	}
}

void adicionar_no_inicio (No* novo, Lista* lista){
	if (novo != NULL) {
		novo -> prox = lista -> inicio;
		if (lista -> inicio != NULL){
			novo -> anterior = NULL;
			lista -> inicio -> anterior = novo;
			lista -> inicio = novo;
		}
		else {
			lista -> inicio = novo;	
			novo -> anterior = NULL;
			novo -> prox = NULL;
		}
	}
	else {
		printf("n foi possivel adicionar");
	}
}

int remover_da_lista(No* no, Lista* lista){
	No* aux = no;

	if(aux -> anterior != NULL) {
		aux -> anterior -> prox = aux -> prox;
	}
	if (aux -> anterior == NULL){
		lista -> inicio = aux -> prox;
	}
	if(aux -> prox != NULL){
		aux -> prox -> anterior = aux -> anterior;
	}
	free(aux);
	return 1;
}

void deletarLista(Lista* lista) {
    No* pivo = lista -> inicio;
    No* temp;
    while (pivo != NULL) {
        temp = pivo;
        pivo = pivo -> prox;
        free(temp);
    }
    free(lista);
	lista -> inicio = NULL; 
}

