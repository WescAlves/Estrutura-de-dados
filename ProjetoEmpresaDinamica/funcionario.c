#include <stdio.h>
#include "funcionario.h"
No* localizar(No* no, char nome[50]){
	if(no == NULL){
		return NULL;
	}
	int comp = strcmp(no -> nome, nome);
	if (comp == 0 ){
		return no;
	}
	return localizar(no -> prox, nome);
}

void adicionar(Lista* lista){
    No* novo =(No*) malloc(sizeof(No));
	printf("\n-------------------------------\n");
	printf("\nQual o nome do funcionario?\n");
	scanf("%s", &novo -> nome);
	adicionar_no_inicio(novo, lista);
}

void remover(Lista* lista){
	if (lista -> inicio == NULL){
		printf("a lista esta vazia");
	}
	else {
		char nome[50];
		printf("\n Qual funcionario deseja remover?");
		scanf("%s", nome);
    	No* funcionario = localizar(lista -> inicio , nome);
		int removido = remover_da_lista(funcionario, lista);
		if(removido == 1){
			printf("\nFuncionario removido!\n");
		} 
		else {
			printf("\nFuncionario n existe ou n existe nenhum!\n");
		}
	}
}
