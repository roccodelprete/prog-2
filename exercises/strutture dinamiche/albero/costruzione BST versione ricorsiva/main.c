#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	char dato;
	struct nodo *sx,*dx;
} NODO;

typedef enum {false,true} boolean;

// implemento una versione ricorsiva della creazione di un Binary Search Tree
void create_bst(int size_array, char *array, NODO *root, NODO *ptr) {
	NODO *NEW;
	if(size_array <= 0) // se la dimensione dell'array � minore o uguale a 0
		return; // allora non ritorno nulla
	// se l'indice base dell'array contenente le chiavi � maggiore del dato puntato dal puntatore di lavoro
	if(*array > ptr->dato) {
		if(ptr->dx != NULL) // e se il puntatore verso il sottoalbero destro non � nullo
			create_bst(size_array, array, root, ptr->dx); // allora autoattivo la procedura verso il sottoalbero destro
		else {
			NEW = (NODO*)malloc(sizeof(NODO)); // alloco spazio per il nuovo nodo dell'albero
			// inserisco il nuovo nodo
			NEW->dx = NEW->sx = NULL; // inizializzo a NULL i due puntatori verso il sottoalbero dx e sx
			NEW->dato = *array; // il nuovo nodo avr� come dato l'indirizzo base attuale dell'array con le chiavi
			ptr->dx = NEW; // il nuovo nodo verr� inserito nella posizione puntata dal puntatore verso destra
			/* autoattivo la procedura passando la dimensione diminuita e l'array che ha come indirizzo base
			l'elemento successivo */
			create_bst(size_array - 1, array + 1, root, root);
		}
	} else { // se l'indice base dell'array contenente le chiavi non � maggiore del dato puntato dal puntatore di lavoro
		if(ptr->sx != NULL) // e se il puntatore verso il sottoalbero sinistro non � nullo
			create_bst(size_array, array, root, ptr->sx); // allora autoattivo la procedura verso il sottoalbero sinistro
		else {
			NEW = (NODO*)malloc(sizeof(NODO)); // alloco spazio per il nuovo nodo dell'albero
			// inserisco il nuovo nodo
			NEW->dx = NEW->sx = NULL; // inizializzo a NULL i due puntatori verso il sottoalbero dx e sx
			NEW->dato = *array; // il nuovo nodo avr� come dato l'indirizzo base attuale dell'array con le chiavi
			ptr->sx = NEW; // il nuovo nodo verr� inserito nella posizione puntata dal puntatore verso destra
			/* autoattivo la procedura passando la dimensione diminuita e l'array che ha come indirizzo base
			l'elemento successivo */
			create_bst(size_array - 1, array + 1, root, root);
		}
	}
}

/* implemento una function ricorsiva di ricerca binaria che controlli se la chiave passata � presente
all'interno del BST */
boolean search_key(char chiave, NODO *root) {
	NODO *curr = root;
	if(curr == NULL) // se il nodo considerato � NULL
		return false; // allora ritorniamo false perch� la chiave non � stata trovata
	else if(curr->dato == chiave) // se il nodo considerato � uguale alla chiave
		return true; // allora ritorniamo true perch� la chiave � stata trovata
	else if(chiave < curr->dato) // se la chiave � minore del nodo considerato
		search_key(chiave,curr->sx); // allora autoattiviamo la ricerca della chiave solo nel sottoalbero sx
	else // se invece la chiave � maggiore del nodo considerato
		search_key(chiave,curr->dx); // allora autoattiviamo la ricerca della chiave solo nel sottoalbero dx
}

// implemento la visita inorder, ossia sottoalbero sinistro, radice, sottoalbero destro
void inorder_visit(NODO *curr, short index) {
	if(curr != NULL) { // se ci sono ancora nodi
		inorder_visit(curr->sx, index); // autoattivo la visita preorder verso il sottoalbero sinistro
		printf("Visita %d - Dato -> %c\n", index++, curr->dato); // stampo il nodo corrente
		inorder_visit(curr->dx, index); // autoattivo la visita preorder verso il sottoalbero destro
	}
}

int main() {
	NODO *root = malloc(sizeof(NODO));
	char key[] = {'5','7','8','1','6','0','3','4','9','2'};
	char chiave;
	int size_array = 10;

	// inserisco nodo radice
	root->dato = *key; // inizializzo il dato con l'elemento iniziale dell'array di chiavi
	root->dx = root->sx = NULL; // inizializzo a NULL i due puntatori verso il sottoalbero dx e sx
	create_bst(size_array - 1, key + 1, root, root); // richiamo la procedura di creazione di un binary search tree

	system("PAUSE");
	system("cls");

	inorder_visit(root,0); // richiamo la visita e la stampa di un binary search tree

	printf("\nInserire chiave da ricercare -> ");
	fflush(stdin);
	chiave = getchar();

	if(search_key(chiave,root)) // controllo se la chiave ricercata viene trovata all'interno dell'albero
		printf("\nChiave trovata!\n");
	else
		printf("\nChiave non trovata!\n");
}