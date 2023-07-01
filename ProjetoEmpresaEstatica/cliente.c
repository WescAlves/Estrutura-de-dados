#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionario.h"

void menu(){
    printf("\n\tMENU\n");
    printf("[1]Adicionar Funcionario\n");
    printf("[2]Imprimir Lista\n");
    printf("[3]Remover Funcionario\n");
    printf("[4]Esvaziar Lista\n"); 
    printf("[5]Sair\n");   
}    


int main(){
    int resp,ok,insere;
    No *removido;
    Lista list;
    Funcionario f;
    criar_lista(&list);
    criar_func(&f);
    do{
        menu();
        scanf("%d",&resp);
        getchar();
        switch(resp){
            case 1:
                f = preenche_func();
                if(inserir(&list,f)){
                    //imprimir(&list);
                    printf("Funcionario %s adicionado com sucesso!\n",f.nome);
                }
                else{
                    printf("ERRO ao alocar memoria!\n");
                }
                break;
            case 2:
                imprimir(&list);
                break;
            case 3:
                removido = remover(&list);
                if(removido){
                    //imprimir(&list);
                    printf("Funcionario %s removido com sucesso!\n",removido->func.nome);
                }
                break;
            case 4:
                esvazia_lista(&list);
                //imprimir(&list);
                break;
            default:
                if(resp != 5){
                    printf("Informe uma Opcao Valida!\n");
                }
        }
    }while(resp != 5);

    return 0;
}
