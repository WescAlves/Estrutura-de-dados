#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema.h"



Lista* cria_lista(){
    Lista *l = malloc(sizeof(Lista));
    l->alunos = calloc(TAMa,sizeof(Pessoa));
    l->profs = calloc(TAMp,sizeof(Pessoa));
    l->turmas = calloc(TAMt,sizeof(Turma));
    l->cursos = calloc(TAMc,sizeof(Curso));
    
    l->tamA = 0;
    l->tamP = 0;
    l->tamT = 0;
    l->tamC = 0;
    l->tamL = 0;
    
    return l;
}


Curso* cria_curso(){
    Curso *c = malloc(sizeof(Curso));
    printf("Informe o curso:");
    scanf("%29[^\n]",c->nome);
    getchar();
    
    printf("Informe o tipo do curso:\n");
    printf("[1]Bacharelado\n");
    printf("[2]Tecnologo\n");
    printf("[3]Licenciatura\n");
    scanf("%d",&c->tipo);
    getchar();
    
    return c;
}


Pessoa* cria_aluno(){
    Pessoa *a = malloc(sizeof(Pessoa));
    printf("Informe o nome do aluno:");
    scanf("%49[^\n]",a->nome);
    getchar();
    
    printf("Informe o numero de matricula:");
    scanf("%19[^\n]",a->mat);
    getchar();
    
    return a;
}


Pessoa* cria_prof(){
    Pessoa *p = malloc(sizeof(Pessoa));
    printf("Informe o nome do professor:");
    scanf("%49[^\n]",p->nome);
    getchar();
    
    printf("Informe o numero de matricula:");
    scanf("%19[^\n]",p->mat);
    getchar();
    
    return p;
}


Turma* cria_turma(){
    Turma *t = malloc(sizeof(Turma));
    printf("Informe o nome da turma:");
    scanf("%29[^\n]",t->nome);
    getchar();
    
    return t;
}


void adicionar_c(Lista *l){
    if(l->tamC == TAMc){
        printf("Maximo de cursos cadastrados!\n");
    }
    else{
        Curso *c = cria_curso();
        l->cursos[l->tamC] = c;
        l->tamC++;
        l->tamL++;
    }
}


void adicionar_a(Lista *l){
    if(l->tamA == TAMa){
        printf("Maximo de alunos cadastrados!\n");
    }
    else{
        Pessoa *a = cria_aluno();
        l->alunos[l->tamA] = a;
        l->tamA++;
        l->tamL++;
    }
}


void adicionar_p(Lista *l){
    if(l->tamP == TAMp){
        printf("Maximo de professores cadastrados!\n");
    }
    else{
        Pessoa *p = cria_prof();
        l->profs[l->tamP] = p;
        l->tamP++;
        l->tamL++;
    }
}


void adicionar_t(Lista *l){
    if(l->tamT == TAMt){
        printf("Maximo de turmas cadastrados!\n");
    }
    else{
        Turma *t = cria_turma();
        l->turmas[l->tamT] = t;
        l->tamT++;
        l->tamL++;
    }
}


Pessoa* remover_a(Lista *l){
    if(!l->tamA){
        printf("Nenhum aluno cadastrado!\nImpossivel remover!\n");
        return NULL;
    }
    else{
        int aux = 0;
        char rem[20];
        Pessoa *aluno_rem;
        printf("Informe o numero da matricula a ser removida:");
        scanf("%19[^\n]",rem); 
        getchar();  
            
        while(aux < l->tamA && strcmp(l->alunos[aux]->mat,rem)){
            aux++;
            }
        if(aux == l->tamA){
            printf("Aluno nao encontrado!\n");
            return NULL;
        }
        else{
            aluno_rem = l->alunos[aux];
            while(aux+1 < l->tamA){
                l->alunos[aux] = l->alunos[aux+1];
                aux++;
            }
            l->tamA--;
            l->tamL--;
            return aluno_rem;
        }
    }
}


Pessoa* remover_p(Lista *l){
    if(!l->tamP){
        printf("Nenhum professor cadastrado!\nImpossivel remover!\n");
        return NULL;
    }
    else{
        int aux = 0;
        char rem[20];
        Pessoa *prof_rem;
        printf("Informe o numero da matricula a ser removida:");
        scanf("%19[^\n]",rem); 
        getchar();           
        
        while(aux < l->tamP && strcmp(l->profs[aux]->mat,rem)){
            aux++;
        }
        if(aux == l->tamP){
            printf("Professor nao encontrado!\n");
            return NULL;
        }
        else{
            prof_rem = l->profs[aux];
            while(aux+1 < l->tamP){
                l->profs[aux] = l->profs[aux+1];
                aux++;
            }
            l->tamP--;
            l->tamL--;
            return prof_rem;
        }
    }
}


Turma* remover_t(Lista *l){
    if(!l->tamT){
        printf("Nenhuma turma cadastrada!\nImpossivel remover!\n");
        return NULL;
    }
    else{
        int aux = 0;
        char rem[20];
        Turma *turma_rem;
        printf("Informe o nome da turma a ser removida:");
        scanf("%19[^\n]",rem);
        getchar();
        
        while(aux < l->tamT && strcmp(l->turmas[aux]->nome,rem)){
            aux++;
        }
        if(aux == l->tamT){
            printf("Turma nao encontrada!\n");
            return NULL;
        }
        else{
            turma_rem = l->turmas[aux];
            while(aux+1 < l->tamT){
                l->turmas[aux] = l->turmas[aux+1];
                aux++;
            }
            l->tamT--;
            l->tamL--;
            return turma_rem;
        }
    }
}


Curso* remover_c(Lista *l){
    if(!l->tamC){
        printf("Nenhum curso cadastrado!\nImpossivel remover!\n");
        return NULL;
    }
    else{
        int aux = 0;
        char rem[20];
        Curso *curso_rem;
        printf("Informe o nome do curso a ser removida:");
        scanf("%19[^\n]",rem);
        getchar();
        
        while(aux < l->tamC && strcmp(l->cursos[aux]->nome,rem)){
            aux++;
        }
        if(aux == l->tamC){
            printf("Curso nao encontrado!\n");
            return NULL;
        }
        else{
            curso_rem = l->cursos[aux];
            while(aux+1 < l->tamC){
                l->cursos[aux] = l->cursos[aux+1];
                aux++;
            }
            l->tamC--;
            l->tamL--;
            return curso_rem;
        }
    }
}


void imprimir_a(Lista *l){
    if(!l->tamA){
        printf("Nenhum aluno cadastrado!\n");
    }
    else{
        int k;
        printf("Alunos:\n\n");
        printf("--------------------\n");
        for(k=0;k<l->tamA;k++){
            printf("-Nome:%s\n-Matricula:%s\n",l->alunos[k]->nome,l->alunos[k]->mat);
            printf("--------------------\n");
        }
    }
}


void imprimir_p(Lista *l){
    if(!l->tamP){
        printf("Nenhum professor cadastrado!\n");
    }
    else{
        int k;
        printf("Professores:\n\n");
        printf("--------------------\n");
        for(k=0;k<l->tamP;k++){
            printf("-Nome:%s\n-Matricula:%s\n",l->profs[k]->nome,l->profs[k]->mat);
            printf("--------------------\n");
        }
    }
}


void imprimir_c(Lista *l){
    if(!l->tamC){
        printf("Nenhum curso cadastrado!\n");
    }
    else{
        int k;
        printf("Cursos:\n\n");
        printf("--------------------\n");
        for(k=0;k<l->tamC;k++){
            printf("-Nome:%s\n-Tipo:%d\n",l->cursos[k]->nome,l->cursos[k]->tipo);
            printf("--------------------\n");
        }
    }
}


void imprimir_t(Lista *l){
    if(!l->tamT){
        printf("Nenhuma turma cadastrada!\n");
    }
    else{
        int k;
        printf("Turmas:\n\n");
        printf("--------------------\n");
        for(k=0;k<l->tamT;k++){
            printf("-Nome:%s\n",l->turmas[k]->nome);
            printf("--------------------\n");
        }
    }
}


Pessoa* buscar_a(Lista *l){
    if(!l->tamA){
        printf("Nenhum aluno cadastrado!\nImpossivel pesquisar!\n");
        return NULL;
    }
    else{
        int aux = 0;
        char ret[20];
        Pessoa *aluno_ret;
        printf("Informe o numero da matricula a ser pesquisada:");
        scanf("%19[^\n]",ret); 
        getchar();  
            
        while(aux < l->tamA && strcmp(l->alunos[aux]->mat,ret)){
            aux++;
        }
        if(aux == l->tamA){
            printf("Aluno nao encontrado!\n");
            return NULL;
        }
        else{
            aluno_ret = l->alunos[aux];
            return aluno_ret;
        }
    }
}


Pessoa* buscar_p(Lista *l){
    if(!l->tamP){
        printf("Nenhum professor cadastrado!\nImpossivel pesquisar!\n");
        return NULL;
    }
    else{
        int aux = 0;
        char ret[20];
        Pessoa *prof_ret;
        printf("Informe o numero da matricula a ser pesquisada:");
        scanf("%19[^\n]",ret); 
        getchar();           
        
        while(aux < l->tamP && strcmp(l->profs[aux]->mat,ret)){
            aux++;
        }
        if(aux == l->tamP){
            printf("Professor nao encontrado!\n");
            return NULL;
        }
        else{
            prof_ret = l->profs[aux];
            return prof_ret;
        }
    }
}


Turma* buscar_t(Lista *l){
    if(!l->tamT){
        printf("Nenhuma turma cadastrada!\nImpossivel pesquisar!\n");
        return NULL;
    }
    else{
        int aux = 0;
        char ret[20];
        Turma *turma_ret;
        printf("Informe o nome da turma a ser pesquisada:");
        scanf("%19[^\n]",ret);
        getchar();
        
        while(aux < l->tamT && strcmp(l->turmas[aux]->nome,ret)){
            aux++;
        }
        if(aux == l->tamT){
            printf("Turma nao encontrada!\n");
            return NULL;
        }
        else{
            turma_ret = l->turmas[aux];
            return turma_ret;
        }
    }
}


Curso* buscar_c(Lista *l){
    if(!l->tamC){
        printf("Nenhum curso cadastrado!\nImpossivel pesquisar!\n");
        return NULL;
    }
    else{
        int aux = 0;
        char ret[20];
        Curso *curso_ret;
        printf("Informe o nome do curso a ser pesquisada:");
        scanf("%19[^\n]",ret);
        getchar();
        
        while(aux < l->tamC && strcmp(l->cursos[aux]->nome,ret)){
            aux++;
        }
        if(aux == l->tamC){
            printf("Curso nao encontrado!\n");
            return NULL;
        }
        else{
            curso_ret = l->cursos[aux];
            return curso_ret;
        }
    }
}

