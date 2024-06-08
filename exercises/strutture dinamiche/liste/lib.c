#include "lib.h"

// implemento una function che restituisce vero o falso in base a se la lista e' vuota o meno
logical isEmptyList(struct PERSONA *testa) {
	if(testa == NULL)
		return true;
	else
		return false;
}

// implemento una function per la creazione di una lista
struct PERSONA *crea_lista() {
	struct PERSONA *testa;
	testa = NULL; // il puntatore alla testa viene inizializzato a NULL
	return testa; // ritorno il puntatore alla testa della  lista
}

// implemento una procedura per l'inserimento in testa ad una lista 
void ins_testa(INFO_FIELD dato,struct PERSONA **testa) {
	struct PERSONA *nodo; // dichiaro un puntatore alla struttura
	nodo = calloc(1,sizeof(struct PERSONA)); // alloco dinamicamente lo spazio per un nuovo nodo
	
	nodo->info = dato; // le info del nuovo nodo saranno uguali al dato che si vuole inserire
	// il puntatore al prossimo elemento del nuovo nodo punter? all'elemento precedentemente in testa
	nodo->next = *testa;
	*testa = nodo; // aggiorno la testa al nuovo nodo
}

// implemento una procedura per l'inserimento di un nodo, dopo il nodo corrente, in una lista
void ins_nodo(INFO_FIELD dato,struct PERSONA **curr) {
	struct PERSONA *nodo; // dichiaro un puntatore alla struttura
	nodo = calloc(1,sizeof(struct PERSONA)); // alloco dinamicamente lo spazio per un nuovo nodo
	
	nodo->info = dato; // le info del nuovo nodo saranno uguali al dato che si vuole inserire
	// il puntatore al prossimo elemento del nuovo nodo punter? all'elemento precedentemente puntato dal nodo corrente
	nodo->next = (*curr)->next;
	(*curr)->next = nodo; // il puntatore al prossimo elemento del nodo corrente invece punter? al nuovo nodo
	*curr = nodo; // aggiorno il nodo corrente al nuovo nodo

}

// implemento una procedura per l'eliminazione dalla testa di una lista
void elim_testa(struct PERSONA **testa) {
	/* dichiaro e inizializzo un puntatore alla struttura ad un valore NULL, che ci servir? come variabile temporanea
	per salvare il nuovo nodo che andr? in testa, ossia il secondo nodo */
	struct PERSONA *nodo = NULL;
	
	if(!isEmptyList(*testa)) { // se la lista non ? vuota
		nodo = (*testa)->next; // salviamo il nodo successivo a quello in testa
		free(*testa); // liberiamo il nodo in testa
		*testa = nodo; // la nuova testa sar? il nodo precedentemente salvato
	} else 
		printf("\nLa lista e' vuota!\n");
}

// implemento una procedura per l'eliminazione di un nodo da una lista
void elim_nodo(INFO_FIELD dato,struct PERSONA *testa) {
	/* dichiaro ed inizializzo due puntatori alla struttura che permetteranno di scorrere la lista per cercare
	il nodo da eliminare */
	struct PERSONA *prec,*curr;
	prec = NULL;
	curr = testa;
	
	if(!isEmptyList(testa)) { // se la lista non ? vuota	
		// scorro tutta la lista fin quando non ? finita o fin quando viene trovato il dato ricercato
		while(curr != NULL && ((strcmp(dato.nome,curr->info.nome) != 0) && dato.eta != curr->info.eta)) {
			prec = curr; // aggiorno il nodo precedente al nodo corrente
			curr = curr->next; // aggiorno il nodo corrente al successivo
		} // se il dato ricercato ? uguale ad uno dei nodi
		if((strcmp(dato.nome,curr->info.nome) == 0) && dato.eta == curr->info.eta) {
			/* allora il puntatore al nodo successivo del nodo precedente a quello trovato punter? al nodo successivo
			a quello che abbiamo trovato e che andremo ad eliminare */
			prec->next = curr->next;
			free(curr); // libero il nodo ricercato
		} else
			printf("\nPersona non trovata!\n");
	} else
		printf("\nLa lista e' vuota!\n");
}

// implemento una function che legga un determinato nodo
INFO_FIELD legge_nodo(struct PERSONA *punt) {
	if(!isEmptyList(punt))
		return punt->info; // ritorno il campo informazioni del nodo corrente
}

// implemento una funzione per stampare l'intera lista
void printList(struct PERSONA *ptr) {
	if(!isEmptyList(ptr)) { // controllo che la lista non sia vuota, se lo ? stampo un messaggio di errore
		while(ptr!=NULL) { // scorro la lista
			printf("\nNome: %s",ptr->info.nome);
			printf("\nEta': %d",ptr->info.eta);
			ptr = ptr->next; // aggiorno il puntatore come puntatore all'elemento successivo
		}
		printf("\n");	
	} else 
		printf("\nLista vuota!\n");
}

// implemento una procedura per l'input di una stringa, con annessa allocazione dinamica
char *input_stringa(unsigned int n) {
	char *s;
	// allocazione dinamica sovradimensionata poich? non conosciamo quale sar? la dimensione della stringa
	s = (char*)malloc((n+1)*sizeof(char));
	/* inserendo una stringa in input tramite fgets verr? letto come carattere anche "\n" e di conseguenza la strlen
	della stringa immessa espliciter? un carattere in pi? di quelli immessi realmente */
	fgets(s,n+1,stdin);
	fflush(stdin);
	// visto che fgets considera anche "\n" come carattere, andiamo a inserire il terminatore al posto giusto
	*(s+strlen(s)-1) = '\0';
	// riallochiamo dinamicamente la stringa dopo averne conosciuto la dimensione
	s = (char*)realloc(s,strlen(s)+1); // si passa strlen + 1 in modo da considerare anche il terminatore
	return s;
}

// implemento una function per la visita di una lista, in modo da conoscere il nodo richiesto
struct PERSONA *visitList(struct PERSONA *testa) {
	struct PERSONA *prec=NULL;
    struct PERSONA *curr=testa;
	while(curr->next != NULL && strcmp(prec->info.nome, curr->info.nome)<0) { // fin quando il nodo successivo a quello corrente non ? nullo
		prec=NULL; // si scorre la lista aggiornando il puntatore al nodo corrente
		curr=curr->next;
	}
	return prec; // ritorno il puntatore al nodo corrente
}
