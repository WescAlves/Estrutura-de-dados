
#include <stdlib.h>



typedef struct{
    int priori;        
    char conteudo[30];    
}Imp;


typedef struct {
    Imp **dado;   
    int head;         
    int tail;        
    int cheia;        
    int vazia;        
}Fila;

Fila* cria_fila();

Imp *cria_imp();

Fila* cria_fila();

void push(Fila *f);

Imp* pop(Fila *f);

void imprimir(Fila *f);
