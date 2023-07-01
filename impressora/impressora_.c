//Programa para uma impressora
//Fila de execução com prioridades (estática circular)
/*
    1- Direror
    2- Coordenador
    3- Funcionário 
*/

#include <stdio.h>
#include <stdlib.h>

//tamanho da fila
const int Tam = 3;

//tipo Impressao
typedef struct{
    int priori;        //Quem vai imprimir
    char conteudo[30];    //Conteudo a ser impresso
}Imp;

//tipo Fila
typedef struct {
    Imp **dado;   //vetor girante
    int head;         //inicio
    int tail;         //fim
    int cheia;        //se está cheia
    int vazia;        //se está vazia
}Fila;


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
        printf("\nInicio -> ");
        do{
            printf("%d ",f->dado[k]->priori);
            k++;
            if(k == Tam){
                k = 0;
            }
        }while(k != f->tail);
        printf("<- Fim\n");
    }
}


void menu(){
    printf("\n\tVetor Girante\n\n");
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
        printf("\nvazia = %d\ncheia = %d\nhead = %d\ntail = %d\n",f1->vazia,f1->cheia,f1->head,f1->tail);
        
        menu();
        scanf("%d",&resp);
        getchar();
        switch(resp){
            case 1:
                push(f1);
                imprimir(f1);
                break;
            case 2:
                rem = pop(f1);
                if(rem){    //se rem não for NULL
                    printf("Removido:\n-Prioridade %d\n-Conteudo %s\n",rem->priori,rem->conteudo);
                    imprimir(f1);
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