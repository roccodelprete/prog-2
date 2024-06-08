#include "lib.h"

// implemento una function per la creazione di una lista
Persona *crea_lista() {
	Persona *head = NULL; // il puntatore alla testa viene inizializzato a NULL
	return head; // ritorno il puntatore alla testa della  lista
}

/* implemento una procedura per effettuare l'operazione di push, ossia di inserimento, di un elemento alla testa
dello stack, o pila, poich� l'accesso a questra struttura avviene solo mediante la testa */
Persona *push(INFO_FIELD dato, Persona *head) {
	Persona *nodo = (Persona*)calloc(1,sizeof(Persona));

	nodo->info = dato; // le info del nuovo nodo saranno uguali al dato che si vuole inserire
	// il puntatore al prossimo elemento del nuovo nodo punter� all'elemento precedentemente in testa
	nodo->next = head;
	head = nodo; // aggiorno la testa al nuovo nodo

	return head;
}

/* implemento una procedura per effettuare l'operazione di pop, ossia di estrazione, di un elemento dalla testa
dello stack, o pila, poich� l'accesso a questra struttura avviene solo mediante la testa */
Persona *pop(Persona *head) {
	Persona *nodo = NULL;

	nodo = head->next; // salviamo il nodo successivo a quello in testa
	free(head); // liberiamo il nodo in testa
	head = nodo; // la nuova testa sar� il nodo precedentemente salvato

	return head;
}

// implemento una procedura per l'input di una stringa, con annessa allocazione dinamica
char *input_stringa(unsigned int n) {
	// allocazione dinamica sovradimensionata poich� non conosciamo quale sar� la dimensione della string
	char *s = (char*)malloc((n+1)*sizeof(char));
	/* inserendo una stringa in input tramite fgets verr� letto come carattere anche "\0" e di conseguenza la strlen
	della stringa immessa espliciter� un carattere in pi� di quelli immessi realmente */
	fgets(s,n+1,stdin);
	fflush(stdin);
	// visto che fgets considera anche "\n" come carattere, andiamo a inserire il terminatore al posto giusto
	*(s+strlen(s)-1) = '\0';
	// riallochiamo dinamicamente la stringa dopo averne conosciuto la dimensione
	s = (char*)realloc(s,strlen(s)+1); // si passa strlen + 1 in modo da considerare anche il terminatore
	return s;
}

// implemento una procedura per la visualizzazione di uno stack
void visualizza_stack(Persona *head) {
	printf("\nStack:\n\n");
	while(head != NULL) {
		printf("Nome: %s\n",head->info.nome);
		printf("Eta': %d\n",head->info.eta);
		head = head->next;
	}
	printf("\n");
}