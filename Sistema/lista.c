
Lista* criar_Lista() {
	Lista* lista = (Lista*) malloc(sizeof(Lista));
	if (lista != NULL){
	lista -> inicio = NULL;
	return lista;
	}
	else {
		return NULL;
	}
}
