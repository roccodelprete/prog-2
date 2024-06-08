#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem{
	char nome[15];
	struct elem *next;
} ELEM;

// implemento una function per la costruzione di una lista ordinata a partire da un array frastagliato
ELEM *array_to_list(ELEM *testa, char **a, short n) {
	ELEM *prec, *curr, *nodo;
	short i = 0;

	while(i < n) { // itero questo blocco di operazioni fino a quando l'indice i non raggiunge la dimensione dell'array
		prec = NULL; // inizializzo il puntatore al nodo precedente a quello considerato a NULL
		curr = testa; // inizializzo il puntatore al nodo corrente alla testa

		nodo = malloc(sizeof(ELEM));
		// copio l'i-esima stringa dell'array frastagliato nel campo nome del nodo da inserire
		strcpy(nodo->nome, *(a+i));

		/* effettuo una visita della lista per posizionare prec e curr al posto giusto prima di inserire una stringa;
		il blocco è iterato fino a quando non viene raggiunto NULL, oppure quando il nome del nodo corrente è minore,
		alfabeticamente, dell'i-esima stringa dell'array frastagliato */
		while(curr != NULL && strcmp(curr->nome,*(a+i))<0) {
			// aggiorno prec e curr ai nodi successivi ad ogni iterazione
			prec = curr;
			curr = curr->next;
		}

		/* se prec è uguale a NULL significa che si è usciti subito dalla visita e che quindi il nodo va inserito
		in testa */
		if(prec == NULL) {
			nodo->next = testa; // in tal caso il nodo da inserire punterà alla testa come elemento successivo
			testa = nodo; // la nuova testa sarà il nodo che stiamo inserendo
		} /* se curr è uguale a NULL significa che la visita si è interrotta poichè si è raggiunta
		la fine della lista e quindi il nodo va inserito alla fine */
		else if(curr == NULL) {
			prec->next = nodo; // il nodo successivo a prec sarà il nodo che vogliamo inserire
			nodo->next = NULL; // il nodo che stiamo inserendo avrà come successivo il valore NULL
		} /* se non è soddisfatta nessuna delle due condizioni allora significa che l'inserimento
		va effettuato in mezzo */
		else {
			prec->next = nodo; // il nodo successivo al precedente sarà il nodo da inserire
			nodo->next = curr; // il nodo che stiamo inserendo avrà come successivo curr
		}
		i++; // incremento l'indice i per passare al controllo di una nuova stringa dell'array frastagliato
	}
	return testa;
}

// implemento una procedura per stampare la lista
void print_list(ELEM *ptr) {
	while(ptr != NULL) {
		puts(ptr->nome);
		ptr = ptr->next;
	}
}

int main() {
	char *array[] = {"Anna","Mario","Giuseppe","Angela","Valeria","Fabrizio","Marianna","Giovanni","Patrizia",
	                 "Valentina","Sara"};

	ELEM *head = NULL;

	head = array_to_list(head,array,11);

	print_list(head);

	return 0;
}