#include <stdlib.h>
#include <stdio.h>
#include "impressora.h"

const int Tam = 3;

//inicializa os valores dos campos da fila
//cria e zera

Imp *cria_imp(){
    Imp *imp = malloc(sizeof(Imp));

    printf("Informe o seu cargo:\n");
    printf("[1]Diretor\n");
    printf("[2]Coordenador\n");
    printf("[3]Funcionario\n");
    scanf("%d",&imp->priori);
    getchar();

    printf("Informe o conteudo a ser impresso:");
    scanf("%29[^\n]",imp->conteudo);
    getchar();
    
    return imp;
}
//inicializa os valores dos campos da fila
//cria e zera
Fila* cria_fila(){
    Fila *f = malloc(sizeof(Fila));
    f->dado = calloc(Tam,sizeof(Imp));
    f->tail = 0;
    f->head = 0;
    f->cheia = 0;
    f->vazia = 1;
    return f;
}


//cria e preenche um novo tipo Impressao


//adiciona um novo elemento no fim da fila
//baseado na sua prioridade
void push(Fila *f){
    if(f->cheia){
        printf("Fila Cheia!\n");
    }
    else{
        //preenchendo a nova impressão 
        Imp *nova_imp = cria_imp();
        //setando os auxiliares k e i
        int i = f->head;
        int k = f->tail;
        //percorrendo a fila enquanto a prioridade for menor que a nova
        while(i != k && nova_imp->priori >= f->dado[i]->priori){
            i++;
            if(i == Tam){
                i = 0;
            }
        }
        //se chegar no final e a prioridade for sempre menor ele será o último da fila
        if(i == k){
            f->dado[f->tail] = nova_imp;
        }
        //se o i estiver no lugar certo
        else{
             //movendo todos os elementos entre o tail e o i uma posição pra frente
             while(k != i){
                 k--;
                 if(k < 0){
                     k = Tam-1;
                 }
                 if(k+1 == Tam){
                     f->dado[0] = f->dado[k];
                 }
                 else{
                     f->dado[k+1] = f->dado[k];
                 }                 
             };
             //adicionando a nova impressão no lugar que ficou vago
             //posição i
             f->dado[i] = nova_imp;
        }
        
        //setando o pivô tail e a flag vazia
        f->tail++;
        f->vazia = 0;
        if(f->tail == Tam){
            f->tail = 0;
        }
        if(f->tail == f->head){
            f->cheia = 1;
        }
    }
}


//remove o valor do começo da fila
//retorna o removido
Imp* pop(Fila *f){
    if(f->vazia){
        printf("Fila Vazia!\n");
        return NULL;
    }
    else{
        //sempre será removida a primeira posição (head)
        
        //salvando os dados antes da remoção 
        Imp *rem = f->dado[f->head];
        //zerando a posição removida
        f->dado[f->head] = NULL;
        
        //setando o pivô head e a flag cheia
        f->head++;
        f->cheia = 0;
        if(f->head == Tam){
            f->head = 0;
        }
        if(f->head == f->tail){
            f->vazia = 1;
        }
        
        return rem;
    }
}


//imprimi a fila do começo até o fim
//do head até o tail
void imprimir(Fila *f){
    if(f->vazia){
        printf("Fila Vazia!\n");
    }
    else{
        int k = f->head;
        printf("\n===========================\n\n");
        do{
            printf("Prioridade: %d \n Conteudo: %s",f->dado[k]->priori, f->dado[k]->conteudo);
            k++;
            if(k == Tam){
                k = 0;
            }
            printf("\n===========================\n");
        }while(k != f->tail);
        
    }
}
