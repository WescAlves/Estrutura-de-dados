#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMa 2
#define TAMp 2
#define TAMc 2
#define TAMt 2

typedef struct{
    char nome[50];
    char mat[20];
}Pessoa;


typedef struct{
    char nome[20];
}Turma;


typedef struct{
    char nome[30];
    int tipo;
}Curso;


typedef struct{
    Pessoa **alunos;
    Pessoa **profs;
    Turma **turmas;
    Curso **cursos;
    int tamA;
    int tamP;
    int tamT;
    int tamC;
    int tamL;
}Lista;


Lista* cria_lista();


Curso* cria_curso();

Pessoa* cria_aluno();


Pessoa* cria_prof();


Turma* cria_turma();

void adicionar_c(Lista *l);


void adicionar_a(Lista *l);


void adicionar_p(Lista *l);


void adicionar_t(Lista *l);

Pessoa* remover_a(Lista *l);


Pessoa* remover_p(Lista *l);


Turma* remover_t(Lista *l);


Curso* remover_c(Lista *l);


void imprimir_a(Lista *l);


void imprimir_p(Lista *l);


void imprimir_c(Lista *l);


void imprimir_t(Lista *l);

Pessoa* buscar_a(Lista *l);


Pessoa* buscar_p(Lista *l);

Turma* buscar_t(Lista *l);


Curso* buscar_c(Lista *l);

