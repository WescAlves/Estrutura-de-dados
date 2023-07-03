
typedef struct no{
	struct no* anterior;
	char nome[30];  //neste campo, implemente a estrutura de dados desejada. neste caso, funcionario.
	struct no* prox;	
}No;

typedef struct lista{
	No* inicio;
}Lista; 

//funcoes dedicadas a operacoes com funcionarios

No* localizar(No* no, char nome[50]);

void adicionar(Lista* lista);

void remover(Lista* lista);
