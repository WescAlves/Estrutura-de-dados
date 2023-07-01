#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#include "lista.h"

int menu(){
	int opcao;
	printf ("\n                  ---------- Controle de RH ----------- \n");
	printf("                                --- gdLOG ---");
	printf("\n                               Menu de opcoes:\n\n");
	printf("/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/\n\n");
	printf ("			| 1-Inserir funcionario |\n");
	printf ("			| 2-Remover Funcionario |\n");
	printf ("			| 3- Ver Funcionarios   |\n");
	printf ("			| 4- Deletar lista   |\n");
	scanf ("%d",&opcao);
    return opcao;
}

void controlador(Lista* lista, int opcao){
	
	switch (opcao) {
			case 0 :
				break;
			case 1 :
				adicionar(lista);
				break;
			case 2 :
				remover(lista);
				break;
			case 3:
				percorrer_lista(lista);
				break;
			case 4:
				deletarLista(lista);
				break;
			default:
				printf ("Opcao invalida. Digite uma opcao valida!");
				break;
    }
}

int main (void){
	Lista* lista = criar_Lista();
	do {
		int opcao = menu();
        controlador(lista, opcao);
		//system("clear");
	}
	while(1);
	
	return 0;
}
