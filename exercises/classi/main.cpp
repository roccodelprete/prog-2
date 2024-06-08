#include <string>
#include <iostream>
using namespace std;

class Studente{
	private:
		string nome, cognome, matricola;
		unsigned int voto;

	public:
		Studente(const char *pnome, const char *pcognome, const char *pmatricola, unsigned int pvoto) { /* costruttore */ 
			nome=pnome;
			cognome=pcognome;
			matricola=pmatricola;
			voto=pvoto;
		}

		Studente(Studente *s) { /* costruttore di copia */
			nome=s->nome;
			cognome=s->cognome;
			matricola=s->matricola;
			voto=s->voto;
		}

		~Studente() { /* distruttore -> distrugge la classe liberando le risorse */
			/* sempre presente di default, ma elimina le variabili statiche */
		}

		/* void insertData(const char *pnome, const char *pcognome, const char *pmatricola, unsigned int pvoto){
			nome=pnome;
			cognome=pcognome;
			matricola=pmatricola;
			voto=pvoto;
		} */
		/* metodo inutile dato che abbiamo definito il costruttore */

		string getNome(){
			return nome;
		}

		string getCognome(){
			return cognome;
		}

		string getMatricola(){
			return matricola;
		}

		unsigned int getVoto(){
			return voto;
		}
};

int main(){
	Studente s1("Mario", "Rossi", "123", 30);
	Studente s2("Giorgio", "Bianchi", "456", 28);

	cout<<"Nome s1: "<<s1.getNome()<<" "<<s1.getCognome()<<endl;
	cout<<"Nome s2: "<<s2.getNome()<<" "<<s2.getCognome()<<endl; 

	return 0;
}
