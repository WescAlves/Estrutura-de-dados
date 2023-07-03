//Estrutura Funcionário
typedef struct{
    int cpf;
    char nome[50];
    float salario;
    char cargo[20];
}Funcionario;
    

//Estrutura de um "nó" da lista    
typedef struct no{
    struct no *prx;
    struct no *ant;
    Funcionario func;
}No;


//Estrutura lista
typedef struct{
    No *prim;
    No *fim;
    int tam;
}Lista;


void criar_lista(Lista *list);


void criar_func(Funcionario *f);


Funcionario preenche_func();


int inserir(Lista *list,Funcionario f);


void imprimir(Lista *list);


No* remover(Lista *list);


void esvazia_lista(Lista *list);

