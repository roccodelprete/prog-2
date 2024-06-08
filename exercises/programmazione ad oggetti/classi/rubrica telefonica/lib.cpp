#include "lib.hpp"

// implemento un metodo per l'aggiunta di un contatto in rubrica
void Rubrica::add(string nome,string cognome,string numero) {
	cout << "Adding (";
	cout << nome << " - ";
	cout << cognome << " - ";
	cout << numero << ")" << endl << endl;

	Elemento e; // dichiaro un oggetto della classe elemento
	// setto i valori dei tre campi che formano un contatto in rubrica tramite il metodo set della classe elemento
	e.set_nome(nome);
	e.set_cognome(cognome);
	e.set_numero(numero);

	Node *n = new Node; // alloco dinamicamente lo spazio per un nuovo nodo
	n->elemento = e; // il campo info del nuovo nodo sarà uguale all'oggetto di classe elemento appena settato
	n->next = head; // inserisco il nuovo nodo in testa
	head = n; // e quindi assegno alla testa il valore del nuovo nodo
	sort(); // richiamo il metodo privato di ordinamento della rubrica per cognome
}

// implemento un metodo per rimuovere un contatto dalla rubrica tramite i campi nome e cognome
void Rubrica::remove(string nome,string cognome) {
	Node *prec = NULL;
	Node *curr = head;

	while (curr != NULL) { // scorro la lista fino alla fine
		// se i campi nome e cognome inseriti vengono trovati nella rubrica
		if (curr->elemento.get_nome() == nome && curr->elemento.get_cognome() == cognome) {
			// allora avviene l'eliminazione del contatto
			cout << "Removing (";
			cout << curr->elemento.get_nome() << " - ";
			cout << curr->elemento.get_cognome() << ")" << endl << endl;

			if(curr == head) { // se il contatto ricercato viene trovato alla testa della lista
				head = head->next; // allora la nuova testa sarà il nodo precedentemente puntato dalla testa
				delete(curr); // dealloco la vecchia testa
			} else { // se invece il contatto non si trova alla testa della lista
				prec->next = curr->next; // il nodo in precedenza puntato da curr verrà puntato da prec
				delete(curr); // dealloco curr
			}

			return; // se sono entrato nell'if e quindi ho rimosso un contatto allora ritorno al chiamante
		}
		// aggiorno i valori dei puntatori prec e curr ad ogni iterazione per scorrere la lista
		prec = curr;
		curr = curr->next;
	}
}

// implemento un metodo per la stampa della rubrica, che equivale ad una classica visita di una lista
void Rubrica::print_rubrica() {
	Node* ptr = head;
	while (ptr != NULL) {
		cout << ptr->elemento.get_nome() << " - ";
		cout << ptr->elemento.get_cognome() << endl << endl;
		ptr = ptr->next;
	}
}

// implemento un metodo per cercare il numero di un contatto in rubrica tramite i campi nome e cognome
void Rubrica::trova_numero(string nome,string cognome) {
	Node *ptr = head;
	while (ptr != NULL) { // scorro la lista fin quando non è finita
		// se i campi nome e cognome immessi da tastiera vengono trovati all'interno della rubrica
		if (ptr->elemento.get_nome() == nome && ptr->elemento.get_cognome() == cognome)
		{
			cout << "Numero trovato ("; // allora stampo il numero del contatto cercato
			cout << ptr->elemento.get_numero() << ")" << endl << endl;
			return; // e esco dal metodo
		}
		ptr = ptr->next; // aggiorno il puntatore per continuare a scorrere la lista se no si è ancora usciti
	}
	// se si esce dal while e si arriva qui significa che il numero non è stato trovato
	cout << "Numero non trovato per la persona (";
	cout << nome << " - ";
	cout << cognome << ")" << endl << endl;
}

// implemento un metodo privato per l'ordinamento della rubrica per cognome
void Rubrica::sort() {
	Elemento temp;
	Node* ptr = head;

	while(ptr->next != NULL) { // fin quando la lista non è finita la scorro
		// se il cognome di un nodo viene alfabeticamente dopo il cognome del nodo successivo, effettuo lo scambio
		if(ptr->elemento.get_cognome() > (ptr->next)->elemento.get_cognome()) {
			// mi servo di un oggetto temporaneo della classe elemento e salvo i campi dell'oggetto in tempo
			temp = ptr->elemento;
			ptr->elemento = (ptr->next)->elemento; // il nodo corrente prenderà i campi del nodo successivo
			(ptr->next)->elemento = temp; // il nodo successivo prenderà i campi del nodo di partenza
		}
		ptr = ptr->next; // aggiorno il puntatore all'elemento successivo
	}
}

// implemento una procedura per la ricerca di un numero in rubrica a partire da nome e cognome
void trova_numero_cont(Rubrica r) {
	string nome;
	string cognome;

	cout << "Inserire Nome: ";
	cin >> nome;
	cout << "Inserire Cognome: ";
	cin >> cognome;

	r.trova_numero(nome,cognome); // richiamo il metodo per la ricerca di un numero in rubrica tramite nome e cognome
}

// implemento una procedura per rimuovere un contatto dalla rubrica
void rimuovi_cont(Rubrica* r) {
	string nome;
	string cognome;

	cout << "Inserire Nome: ";
	cin >> nome;
	cout << "Inserire Cognome: ";
	cin >> cognome;
	cout << endl;

	r->remove(nome,cognome); // richiamo il metodo per rimuovere un contatto
}

// implemento una procedura per aggiungere un nuovo contatto in rubrica
void aggiungi_cont(Rubrica* r) {
	string nome;
	string cognome;
	string numero;

	cout << "Inserire Nome: ";
	cin >> nome;
	cout << "Inserire Cognome: ";
	cin >> cognome;
	cout << "Inserire Numero: ";
	cin >> numero;
	cout << endl;

	r->add(nome,cognome,numero); // richiamo il metodo per inserire un nuovo contatto in rubrica
}
