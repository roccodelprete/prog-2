#include "lib.h"

// implemento una function per la creazione di una lista
Persona *crea_lista() {
	Persona *ptr = NULL; // il puntatore viene inizializzato a NULL
	return ptr; // ritorno il puntatore
}

/* implemento una procedura per effettuare l'operazione di enqueue, ossia di inserimento, di un elemento dal fondo
della queue, o coda */
void enqueue(INFO_FIELD dato, Persona *top) {
	Persona *nodo = (Persona*)calloc(1, sizeof(Persona));
	Persona *ptr = visit_list(top);

	nodo->info = dato; // le info del nuovo nodo saranno uguali al dato che si vuole inserire
	// il puntatore al prossimo elemento del nuovo nodo punter� all'elemento precedentemente sul fondo
	nodo->next = NULL;
	ptr->next = nodo;
	ptr = nodo; // aggiorno il fondo al nuovo nodo
}

/* implemento una procedura per effettuare l'operazione di dequeue, ossia di estrazione, di un elemento dalla testa
della queue, o coda */
Persona *dequeue(Persona *top) {
	Persona *nodo = NULL;

	nodo = top->next; // salviamo il nodo successivo a quello in testa
	free(top); // liberiamo il nodo in testa
	top = nodo; // la nuova testa sar� il nodo precedentemente salvato

	return top;
}

// implemento una procedura per l'input di una stringa, con annessa allocazione dinamica
char *input_stringa(unsigned int n) {
	// allocazione dinamica sovradimensionata poich� non conosciamo quale sar� la dimensione della stringa
	char *s = (char*)malloc((n+1)*sizeof(char));
	/* inserendo una stringa in input tramite fgets verr� letto come carattere anche "\n" e di conseguenza la strlen
	della stringa immessa espliciter� un carattere in pi� di quelli immessi realmente */
	fgets(s,n+1,stdin);
	fflush(stdin);
	// visto che fgets considera anche "\n" come carattere, andiamo a inserire il terminatore al posto giusto
	*(s+strlen(s)-1) = '\0';
	// riallochiamo dinamicamente la stringa dopo averne conosciuto la dimensione
	s = (char*)realloc(s,strlen(s)+1); // si passa strlen + 1 in modo da considerare anche il terminatore
	return s;
}

// implemento una function per la visita di una lista, in modo da conoscere il nodo richiesto
Persona *visit_list(Persona *top) {
	Persona *prec = NULL, *curr = top;; // puntatore alla struttura inizializzato con il puntatore alla testa
	while(curr != NULL) { // fin quando il nodo successivo a quello corrente non � nullo
		prec = curr; // si scorre la lista aggiornando il puntatore al nodo corrente
		curr = curr->next;
	}
	return prec; // ritorno il puntatore al fondo
}

// implemento una procedura per la visualizzazione di una queue
void visualizza_queue(Persona *top) {
	printf("\nStack:\n\n");
	while(top != NULL) {
		printf("Nome -> %s\n",top->info.nome);
		printf("Eta' -> %d\n",top->info.eta);
		top = top->next;
	}
	printf("\n\n");
}