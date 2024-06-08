#ifndef RUBRICA_TELEFONICA_LIB_HPP
#define RUBRICA_TELEFONICA_LIB_HPP

#include <iostream>
#include <string>
using namespace std;

// dichiaro e implemento una classe per la creazione di un nodo singolo
class Elemento {

private: // attributi privati

	string nome;
	string cognome;
	string numero;

public: // metodi pubblici

	Elemento() {} // costruttore di default
	~Elemento() {} // distruttore di default

	// implemento tre metodi che restituiscono i tre campi di ogni nodo
	string get_nome() { return nome; }
	string get_cognome() { return cognome; }
	string get_numero() { return numero; }

	// implemento tre metodi per settare i valori dei tre campi di ogni nodo
	void set_nome(string nome) { this->nome = nome; }
	void set_cognome(string cognome) { this->cognome = cognome;	}
	void set_numero(string numero) { this->numero = numero;	}

};

// dichiaro e implemento una classe per le gestione di una rubrica
class Rubrica {

private:
	/* dichiaro una struct i cui elementi saranno un oggetto della classe elemento
	e un puntatore al nodo successivo in rubrica */
	struct Node {
		Elemento elemento;
		Node *next;
	};

	Node *head; // dichiaro un puntatore di tipo nodo che mi servirà come testa della lista

public:

	Rubrica() { // il costruttore mi inizializza il puntatore alla testa a NULL
		head = NULL;
	}

	~Rubrica() { // il distruttore cancella il nodo in testa alla lista
		while (head != NULL) { // se la testa non è NULL
			Node* n = head->next; // dichiaro un nodo e lo inizializzo al nodo successivo alla testa
			delete head; // elimino la testa
			head = n; // la nuova testa sarà il nodo che era puntato dalla vecchia testa
		}
	}

	// metodi pubblici
	void add(string,string,string);
	void remove(string,string);
	void print_rubrica();
	void trova_numero(string,string);

private:
	void sort(); // metodo privato
};

// definizione prototipi delle procedure
void trova_numero_cont(Rubrica);
void rimuovi_cont(Rubrica*);
void aggiungi_cont(Rubrica*);

#endif //RUBRICA_TELEFONICA_LIB_HPP
