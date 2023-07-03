//Programa para uma impressora
//Fila de execução com prioridades (estática circular)
/*
    1- Direror
    2- Coordenador
    3- Funcionário 
*/

#include <stdio.h>
#include <stdlib.h>
#include "impressora.h"

//tamanho da fila


void menu(){
	printf("==== Fila de Impressao! ====\n\n");
    printf("[1]Adicionar\n");
    printf("[2]Remover\n");
    printf("[3]Imprimir\n");
    printf("[4]Sair\n");
}


int main(){
    int resp;
    Imp *rem;
    Fila *f1 = cria_fila();    //criando a nova fila
    do{
        //printf de teste dos pivôs e das flags
        //printf("\nvazia = %d\ncheia = %d\nhead = %d\ntail = %d\n",f1->vazia,f1->cheia,f1->head,f1->tail);
        
        menu();
        scanf("%d",&resp);
        getchar();
        switch(resp){
            case 1:
                push(f1);
                break;
            case 2:
                rem = pop(f1);
                if(rem){    //se rem não for NULL
                    printf("Removido:\n-Prioridade %d\n-Conteudo %s\n",rem->priori,rem->conteudo);
                }
                break;
            case 3:
                imprimir(f1);
                break;
            default:
                if(resp != 4){
                    printf("Informe uma Opcao Válida!\n");
                }
        }
    }while(resp != 4);
    
    return 0;
}
