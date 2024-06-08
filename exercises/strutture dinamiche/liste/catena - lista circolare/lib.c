#include "lib.h"

// implemento una function per la creazione di una lista
struct PERSONA *crea_lista() {
	struct PERSONA *testa = NULL;
	return testa;
}

// implemento una function per creare un dato
INFO_FIELD crea_dato() {
	INFO_FIELD new_dato;
	unsigned int MAX_SIZE = 20;

	printf("\nInserire nome: ");
	strcpy(new_dato.nome,input_stringa(MAX_SIZE));
	printf("\nInserire eta': ");
	scanf("%d",&new_dato.eta);
	printf("\n");
	fflush(stdin);

	return new_dato;
}

// implemento una function per inserire il primo nodo in una lista circolare vuota
struct PERSONA *ins_empty(struct PERSONA* last,INFO_FIELD dato) {
	if(last != NULL) // controllo che la lista sia vuota
		printf("La lista non e' vuota!\n");
	else {
		struct PERSONA *nodo = malloc(sizeof(struct PERSONA));
		nodo->info = dato; // assegno il dato inserito al campo informazioni del nuovo nodo che stiamo creando
		last = nodo; // l'ultimo elemento della lista è il nodo che abbiamo appena creato
		last->next = last; // il puntatore al nodo successivo all'ultimo nodo è se stesso poichè vi è 1 solo nodo
	}
	return last;
}

// implemento una function per l'inserimento di un nodo all'inizio di una lista circolare
struct PERSONA *ins_testa(struct PERSONA *last,INFO_FIELD dato) {
	if(last == NULL) // se la lista è vuota inserisco il nuovo nodo come primo elemento
		return ins_empty(last,dato); // richiamando la funzione ad hoc
	else {
		struct PERSONA *nodo = malloc(sizeof(struct PERSONA));
		nodo->info = dato; // assegno il dato inserito al campo informazioni del nuovo nodo che stiamo creando
		nodo->next = last->next; // il nodo che stiamo inserendo punterà al nodo precedentemente puntato da last
		last->next = nodo; // il nodo sul fondo punterà al nodo che stiamo inserendo in testa
		return last;
	}
}

// implemento una function per inserire un nodo tra due nodi già presenti nella lista circolare
void ins_between(struct PERSONA *last,INFO_FIELD dato,INFO_FIELD after) {
	struct PERSONA *nodo, *ptr = last->next; // posiziono il puntatore alla testa della lista circolare per scorrerlo

	do { // imposto un costrutto do-while per posizionare il puntatore alla posizione corretta
		ptr = ptr->next; // se il nodo dopo cui inserire il nuovo nodo non è stato trovato allora scorro la lista
	} while(ptr != last->next && (strcmp(ptr->info.nome, after.nome) != 0 && ptr->info.eta != after.eta));

	if(strcmp(ptr->info.nome,after.nome) == 0 && ptr->info.eta == after.eta) {
		struct PERSONA *nodo = malloc(sizeof(struct PERSONA));
		nodo->info = dato; // il cui campo info sarà uguale al dato immesso in precedenza
		nodo->next = ptr->next; // il nuovo nodo punterà al nodo precedentemente puntato dal nodo precedente
		ptr->next = nodo; // il nodo precedente punterà al nodo appena creato
	}
}

// implemento una function per l'inserimento di un nodo sul fondo della lista
struct PERSONA *ins_fondo(struct PERSONA *last,INFO_FIELD dato) {
	if(last == NULL) // se la lista è vuota inserisco il nuovo nodo come primo elemento
		return ins_empty(last,dato); // richiamando la funzione ad hoc
	else {
		struct PERSONA *nodo = malloc(sizeof(struct PERSONA));
		nodo->info = dato; // assegno il dato inserito al campo informazioni del nuovo nodo che stiamo creando
		nodo->next = last->next; // il nodo che stiamo inserendo punterà al nodo precedentemente puntato da last
		last->next = nodo; // il nodo sul fondo punterà al nodo che stiamo inserendo in testa
		last = nodo; // il nodo che stiamo inserendo sarà il nuovo nodo sul fondo
		return last;
	}
}

// implemento una procedura per scorrere e visualizzare una lista circolare
void traverse(struct PERSONA *last) {
	struct PERSONA *ptr;
	if(last == NULL)
		printf("\nLa lista e' vuota!\n");
	else {
		printf("\nLista:\n");
		ptr = last->next; // posiziono il puntatore alla testa della lista circolare per scorrerlo
		do {
			printf("\nNome: %s",ptr->info.nome);
			printf("\nEta': %d",ptr->info.eta);
			ptr = ptr->next; // aggiorno il puntatore
		} while(ptr != last->next); // visualizzo a schermo i nodi della lista fin quando non viene raggiunta la fine
		printf("\n\n");
	}
}

// implemento una procedura per l'eliminazione di un nodo da una lista circolare
void elim_nodo(struct PERSONA **last,INFO_FIELD dato) {
	/* dichiaro ed inizializzo due puntatori alla struttura che permetteranno di scorrere la lista per cercare
	il nodo da eliminare */
	struct PERSONA *prec = NULL, *curr = (*last)->next, *nodo;

	if(*last != NULL) { // se la lista non è vuota	
		do { // scorro tutta la lista fin quando non è finita o fin quando viene trovato il dato ricercato
			prec = curr; // aggiorno il nodo precedente al nodo corrente
			curr = curr->next; // aggiorno il nodo corrente al successivo
		} while(curr != (*last)->next && ((strcmp(dato.nome,curr->info.nome) != 0) && dato.eta != curr->info.eta));

		// se il dato ricercato è uguale ad uno dei nodi
		if((strcmp(dato.nome,curr->info.nome) == 0) && dato.eta == curr->info.eta) {
			if(curr == (*last)->next) { // se il dato è stato trovato in testa
				nodo = curr->next; // salvo il nodo successivo a quello in testa
				free(curr); // liberiamo il nodo in testa
				curr = nodo; // la nuova testa sarà il nodo precedentemente salvato
				(*last)->next = curr; // il nodo sul fondo punterà alla nuova testa
			}
			else if(curr == *last) { // se il nodo è stato trovato sul fondo
				nodo = prec; // salvo il nodo precedente a quello sul fondo
				nodo->next = (*last)->next; // che punterà al nodo in testa
				free(*last); // dealloco il nodo sul fondo
				*last = nodo; // il nuovo fondo sarà il nodo precedentemente in penultima posizione nella lista
			}
			else {
				/* allora il puntatore al nodo successivo del nodo precedente a quello trovato punterà al nodo successivo
				a quello che abbiamo trovato e che andremo ad eliminare */
				prec->next = curr->next;
				free(curr); // libero il nodo ricercato
			}
		} else
			printf("\nPersona non trovata!\n");
	} else
		printf("\nLa lista e' vuota!\n");
}

// implemento una procedura per l'input di una stringa, con annessa allocazione dinamica
char *input_stringa(unsigned int n) {
	// allocazione dinamica sovradimensionata poichè non conosciamo quale sarà la dimensione della stringa
	char *s = (char*)malloc((n+1)*sizeof(char));
	/* inserendo una stringa in input tramite fgets verrà letto come carattere anche "\n" e di conseguenza la strlen
	della stringa immessa espliciterà un carattere in più di quelli immessi realmente */
	fgets(s,n+1,stdin);
	fflush(stdin);
	// visto che fgets considera anche "\n" come carattere, andiamo a inserire il terminatore al posto giusto
	*(s+strlen(s)-1) = '\0';
	// riallochiamo dinamicamente la stringa dopo averne conosciuto la dimensione
	s = (char*)realloc(s,strlen(s)+1); // si passa strlen + 1 in modo da considerare anche il terminatore
	return s;
}