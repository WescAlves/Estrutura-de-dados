/*sistema acadêmico 
//Lista estática

-----------------------
    -Alunos
    -Professores
    -Turmas
    -Cursos
-----------------------

*Adicionar
*Remover
*Buscar
*Listar todos de cada tipo e todos no geral
*/


/*
    Ideia de associar Pessoas,Turmas e Cursos
    Meio ("-")
    =====----=====
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema.h"

void menu_main(){
    printf("\n\tLista Academica\n\n");
    printf("[1]Adicionar\n");
    printf("[2]Remover\n");
    printf("[3]Imprimir\n");
    printf("[4]Buscar\n");
    printf("[5]Sair\n");
}


void menu_tipos(){
    printf("[1]Curso\n");
    printf("[2]Turma\n");
    printf("[3]Aluno\n");
    printf("[4]Professor\n");
}


int main(){
    Lista *list = cria_lista();
    int opcao,resp;
    
    do{
        menu_main();
        scanf("%d",&opcao);
        getchar();
        switch(opcao){
            case 1:
                menu_tipos();
                scanf("%d",&resp);
                getchar();
                switch(resp){
                    case 1:
                        adicionar_c(list);
                        break;
                    case 2:
                        adicionar_t(list);
                        break;
                    case 3:
                        adicionar_a(list);
                        break;
                    case 4:
                        adicionar_p(list);
                        break;
                    default:
                        printf("Opcao Invalida!\n");
                }
                break;
            case 2:
                menu_tipos();
                scanf("%d",&resp);
                getchar();
                switch(resp){
                    case 1:{
                        Curso *rem = remover_c(list);
                        if(rem){
                            printf("Curso removido:%s\nTipo:%d\n",rem->nome,rem->tipo);
                        }
                        break;
                    }
                    case 2:{
                        Turma *rem = remover_t(list);
                        if(rem){
                            printf("Turma removida:%s\n",rem->nome);
                        }
                        break;
                    }
                    case 3:{
                        Pessoa *rem = remover_a(list);
                        if(rem){
                            printf("Aluno removido:\nNome:%s\nMatricula:%s\n",rem->nome,rem->mat);
                        }
                        break;
                    }
                    case 4:{
                        Pessoa *rem = remover_p(list);
                        if(rem){
                            printf("Professor removido:\nNome:%s\nMatricula:%s\n",rem->nome,rem->mat);
                        }
                        break;
                    }
                    default:
                        printf("Opcao Invalida!\n");
                }
                break;
            case 3:
                menu_tipos();
                scanf("%d",&resp);
                getchar();
                switch(resp){
                    case 1:
                        imprimir_c(list);
                        break;
                    case 2:
                        imprimir_t(list);
                        break;
                    case 3:
                        imprimir_a(list);
                        break;
                    case 4:
                        imprimir_p(list);
                        break;
                    default:
                        printf("Opcao Invalida!\n");
                }
                break;
            case 4:
                menu_tipos();
                scanf("%d",&resp);
                getchar();
                switch(resp){
                    case 1:{
                        Curso *ret = buscar_c(list);
                        if(ret){
                            printf("Curso encontrado:\n");
                            printf("Tipo: %d\nNome: %s\n",ret->tipo,ret->nome);
                        }
                        break;
                    }
                    case 2:{
                        Turma *ret = buscar_t(list);
                        if(ret){
                            printf("Turma encontrada:\n");
                            printf("Nome: %s\n",ret->nome);
                        }
                        break;
                    }
                    case 3:{
                        Pessoa *ret = buscar_a(list);
                        if(ret){
                            printf("Aluno encontrado:\n");
                            printf("Matricula: %s\nNome: %s\n",ret->mat,ret->nome);
                        }
                        break;
                    }
                    case 4:{
                        Pessoa *ret = buscar_p(list);
                        if(ret){
                            printf("Professor encontrado:\n");
                            printf("Matricula: %s\nNome: %s\n",ret->mat,ret->nome);
                        }
                        break;
                    }
                    default:
                        printf("Opcao Invalida!\n");
                }
                break;
            default:
                if(opcao != 5){
                    printf("Opcao Invalida!\n");
                }
        }
    }while(opcao != 5);
    
    return 0;
}
