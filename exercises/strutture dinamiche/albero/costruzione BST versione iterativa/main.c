#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    char dato;
    struct nodo *sx, *dx;
} NODO;

typedef enum {false,true} boolean;

// implemento una versione iterativa della creazione di un Binary Search Tree
void create_bst(NODO **root) {
	short continua = 1;
	NODO *curr, *ins;

	// alloco dinamicamente spazio per il nodo che sarà la radice
	*root = malloc(sizeof(NODO));

	printf("\nInserire radice dell'albero -> ");
	fflush(stdin);
	(*root)->dato = getchar();
	(*root)->dx = (*root)->sx = NULL; // inizializzo a NULL i due puntatori sx e dx

	while(continua == 1) { // se si vuole continuare
		curr = *root; // il nodo corrente sarà la radice all'inizio di ogni iterazione
		ins = malloc(sizeof(NODO)); // alloco dinamicamente spazio per il nuovo nodo

		printf("\nInserire dato del nuovo nodo -> ");
		fflush(stdin);
		ins->dato = getchar(); // do un dato al nodo da inserire

		/* utilizzo due costrutti iterativi while per posizionare il puntatore al nodo corrente nella posizione
		giusta in cui inserire il nuovo nodo; itero questa operazione se e solo se il dato da inserire è minore
		o uguale(risp. maggiore o uguale) del dato corrente e se esistono nodi nel sottoalbero sinistro(risp. destro) */
		while(ins->dato <= curr->dato && curr->sx != NULL)
			curr = curr->sx;

		while(ins->dato >= curr->dato && curr->dx != NULL)
			curr = curr->dx;

		// se il dato da inserire è minore o uguale del dato del nodo corrente allora va inserito sulla sinistra
		if(ins->dato <= curr->dato) {
			// il nodo puntato dal puntatore sx del nodo corrente sarà uguale al nodo da inserire
			curr->sx = ins;
			// e i puntatori dx e sx del nodo da inserire punteranno a NULL
			ins->dx = ins->sx = NULL;
		} else { // se invece il dato da inserire è maggiore del dato del nodo corrente allora va inserito sulla destra
			// allora il nodo puntato dal puntatore dx del nodo corrente sarà uguale al nodo da inserire
			curr->dx = ins;
			// e i puntatori dx e sx del nodo da inserire punteranno a NULL
			ins->dx = ins->sx = NULL;
		}
		printf("\nVuoi inserire ancora? 1[Si] 0[No] ");
		scanf("%hi", &continua);
		fflush(stdin);
	}
}

/* implemento una function ricorsiva di ricerca binaria che controlli se la chiave passata è presente
all'interno del BST */
boolean search_key(char key, NODO *root) {
	NODO *curr = root;
	if(curr == NULL) // se il nodo considerato è NULL
		return false; // allora ritorniamo false perchè la chiave non è stata trovata
	else if(curr->dato == key) // se il nodo considerato è uguale alla chiave
		return true; // allora ritorniamo true perchè la chiave è stata trovata
	else if(key < curr->dato) // se la chiave è minore del nodo considerato
		search_key(key,curr->sx); // allora autoattiviamo la ricerca della chiave solo nel sottoalbero sx
	else // se invece la chiave è maggiore del nodo considerato
		search_key(key,curr->dx); // allora autoattiviamo la ricerca della chiave solo nel sottoalbero dx
}

int main() {
    NODO *root;
    char key;

    create_bst(&root);
    system("PAUSE");
    system("cls");

    printf("\nInserire chiave da ricercare -> ");
    fflush(stdin);
    key = getchar();

    if(search_key(key,root))
        printf("\nChiave trovata!\n");
    else
        printf("\nChiave non trovata...\n");
}