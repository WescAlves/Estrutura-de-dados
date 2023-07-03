#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criar_lista(Lista *list){   
    list->fim = NULL;
    list->prim = NULL;
    list->tam = 0;
}
void criar_func(Funcionario *f){
    f->cpf = -1;
    strcpy(f->nome,"");
    strcpy(f->cargo,"");
    f->salario = -1;
}
Funcionario preenche_func(){
    Funcionario f;
    printf("Informe o nome do Funcionario:");
    scanf("%49[^\n]",f.nome);
    getchar(); //removendo o \n do buffer do teclado
    printf("Informe o CPF:");
    scanf("%d",&f.cpf);
    getchar();
    printf("Informe o cargo:");
    scanf("%49[^\n]",f.cargo);
    getchar(); //removendo o \n
    printf("Informe o salario:");
    scanf("%f",&f.salario);
    getchar();
    //retorna o funcionário preenchido
    return f;
}
int inserir(Lista *list,Funcionario f){
    No *novo = malloc(sizeof(No));
    No *aux = list->prim;
    
    if(novo){
        //preenchendo o novo No da lista
        strcpy(novo->func.nome,f.nome);
        strcpy(novo->func.cargo,f.cargo);
        novo->func.salario = f.salario;
        novo->func.cpf = f.cpf;
        
        if(!aux){
            //Se o novo for o primeiro
            list->prim = novo;
            novo->ant = NULL;
            list->fim = novo;
            novo->prx = NULL;
        }
        else{
            //Se ele for adicionado depois de alguém 
            
            //Percorrendo a lista até chegar na posição de adicionar o novo funcionário
            //Ordem alfabética (Tabela ASCII)
            while(aux && strcmp(novo->func.nome,aux->func.nome) > 0){                
                aux = aux->prx;
            }
            if(aux){
                //Adicionando o funcionário no meio da lista
                novo->prx = aux;
                aux->ant = novo;
                aux->ant->prx = novo;
                novo->ant = aux->ant;
            }
            else{
                //Adicionando o funcionário no final da lista 
                novo->ant = list->fim;
                list->fim->prx = novo;
                novo->prx = NULL;
                list->fim = novo;
            }
        }
        list->tam++;
        return 1;
    }
    return 0;
}
void imprimir(Lista *list){
    No *aux = list->prim;
    system("cls");
    if(!aux){
        printf("Lista Vazia!\n");
    }
    else{
        printf("%d Funcionarios Cadastrados\n",list->tam);
        while(aux){
            printf("\n----------------------\n");
            printf("Nome: %s\n",aux->func.nome);
            printf("CPF: %d\n",aux->func.cpf);
            printf("Cargo: %s\n",aux->func.cargo);
            printf("Salario: %.2f\n",aux->func.salario);
            printf("\n----------------------\n");
            aux = aux->prx;
        }
    }
}


No* remover(Lista *list){
    char nome[50];
    No *aux = list->prim;
    if(!aux){
        printf("Lista Vazia!\nImpossivel Remover!\n");
        return NULL;
    }
    else{        
        imprimir(list);
        printf("Informe o nome do funcionario a ser removido:");
        scanf("%49[^\n]",nome);
        getchar();
        //Percorrendo até a posição do elemento a ser removido
        while(aux && strcmp(nome,aux->func.nome) > 0){
            aux = aux->prx;
        }
        if(!aux || strcmp(nome,aux->func.nome) < 0){
            printf("Funcionario nao encontrado!\n");
            return NULL;
        }
        else{
            No *removido = aux;  
            //Removendo se for o único elemento na lista
            if(list->prim == aux && list->fim == aux){
                list->prim = NULL;
                list->fim = NULL;
            }         
            //Removendo o elemento do final da lista
            else if(aux == list->fim){
                aux->ant->prx = NULL;
                list->fim = aux->ant;
            }
            //Removendo o elemento do começo da lista
            else if(aux == list->prim){
                aux->prx->ant = NULL;
                list->prim = aux->prx;
            }
            //Removendo em qualquer outra posição
            else{
                aux->ant->prx = aux->prx;
                aux->prx->ant = aux->ant;
            }
            list->tam--;
            return removido;
        }
    }
}


void esvazia_lista(Lista *list){
    No *aux = list->prim;
    while(aux){
        No *aux2 = aux;
        aux = aux->prx;
        free(aux2);
    }
    list->prim = NULL;
    list->fim = NULL;
}

