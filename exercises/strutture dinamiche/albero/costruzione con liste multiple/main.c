#include <stdio.h>
#include <stdlib.h>

// definiamo una struct che, oltre al campo nome, ha 2 puntatori che scendono verso sx e dx; essendo un albero binario
typedef struct nodo {
	char nome;
	struct nodo *sx, *dx;
} NODO;

// implemento una procedura ricorsiva per la creazione di un albero binario
void create_tree(NODO **nodo_corr) {
	short scelta;
	*nodo_corr = malloc(sizeof(NODO)); // alloco spazio per un nuovo nodo

	printf("\nInserire nome del nodo -> ");
	fflush(stdin);
	(*nodo_corr)->nome = getchar(); // do un nome al nuovo nodo

	// controllo se il nodo appena immesso abbia un figlio sinistro
	printf("\nNodo %c ha un figlio sinistro? 1[SI] - 0[NO] -> ", (*nodo_corr)->nome);
	scanf("%hi",&scelta);
	fflush(stdin);

	if(scelta == 1) // se ce l'ha allora autoattivo la procedura di creazione di un nodo
		create_tree(&(*nodo_corr)->sx);
	else
		(*nodo_corr)->sx = NULL; // se non ha un figlio sinistro allora il puntatore a sx punterà a NULL

	// controllo se il nodo appena immesso abbia un figlio destro
	printf("\nNodo %c ha un figlio destro? 1[SI] - 0[NO] : ",(*nodo_corr)->nome);
	scanf("%hi", &scelta);
	fflush(stdin);

	if(scelta==1) // se ce l'ha allora autoattivo la procedura di creazione di un nodo
		create_tree(&(*nodo_corr)->dx);
	else
		(*nodo_corr)->dx = NULL; // se non ha un figlio sinistro allora il puntatore a dx punterà a NULL
}

// implemento la visita preorder, ossia radice, sottoalbero sinistro, sottoalbero destro
void preorder_visit(NODO *nodo_corr, short i) {
	if(nodo_corr != NULL) { // se ci sono ancora nodi
		printf("Visita %d - Dato -> %c\n", i++, nodo_corr->nome); // stampo il nodo corrente
		preorder_visit(nodo_corr->sx, i); // autoattivo la visita preorder verso il sottoalbero sinistro
		preorder_visit(nodo_corr->dx, i); // autoattivo la visita preorder verso il sottoalbero destro
	}
}

// implemento la visita inorder, ossia sottoalbero sinistro, radice, sottoalbero destro
void inorder_visit(NODO *nodo_corr, short i) {
	if(nodo_corr != NULL) { // se ci sono ancora nodi
		inorder_visit(nodo_corr->sx, i); // autoattivo la visita preorder verso il sottoalbero sinistro
		printf("Visita %d - Dato -> %c\n", i++, nodo_corr->nome); // stampo il nodo corrente
		inorder_visit(nodo_corr->dx, i); // autoattivo la visita preorder verso il sottoalbero destro
	}
}

// implemento la visita postorder, ossia sottoalbero sinistro, sottoalbero destro, radice
void postorder_visit(NODO *nodo_corr, short i) {
	if(nodo_corr != NULL) { // se ci sono ancora nodi
		postorder_visit(nodo_corr->sx, i); // autoattivo la visita preorder verso il sottoalbero sinistro
		postorder_visit(nodo_corr->dx, i); // autoattivo la visita preorder verso il sottoalbero destro
		printf("Visita %d - Dato -> %c\n", i++, nodo_corr->nome); // stampo il nodo corrente
	}
}

int main() {
	NODO *nodo_radice;
	create_tree(&nodo_radice);

	system("PAUSE");
	system("cls");
	printf(">> PREORDER VISIT <<\n");
	preorder_visit(nodo_radice,0);

	system("PAUSE");
	system("cls");
	printf(">> INORDER VISIT <<\n");
	inorder_visit(nodo_radice,0);

	system("PAUSE");
	system("cls");
	printf(">> POSTORDER VISIT <<\n");
	postorder_visit(nodo_radice,0);

	return 0;
}