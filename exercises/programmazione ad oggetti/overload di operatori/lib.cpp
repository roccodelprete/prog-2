#include "lib.hpp"

// implemento un metodo per settare i valori delle due coordinate del vettore2D
void vettore2D::set_component(float v1,float v2) {
	// gli attributi privati prenderanno il valore dei due valori passati
	this->Vx = v1;
	this->Vy = v2;
}

// implemento un metodo per ritornare un vettore2D con le sue componenti
float* vettore2D::get_component() {
	float *pt = new float+2; // alloco dinamicamente un vettore di size 2
	*pt = Vx; // alla prima posizione inseriamo la coordinata x
	*(pt+1) = Vy; // alla seconda posizione inseriamo la coordinata y
	return pt; // ritorniamo l'indirizzo base del vettore
}

// ridefinisco l'operatore di somma, per effettuare tramite questo operatore la somma vettoriale
vettore2D vettore2D::operator+(vettore2D v2) {
	vettore2D tmp;
	/* le coordinate del vettore temporaneo saranno uguali al valore degli attributi privati più le rispettive
	coordinate del vettore passato */
	tmp.Vx = this->Vx + v2.Vx;
	tmp.Vy = this->Vy + v2.Vy;
	return tmp;
}

/* ridefinisco l'operatore di prodotto, per effettuare tramite questo operatore il prodotto scalare
tra due vettori */
float vettore2D::operator*(vettore2D v2) {
	float dot;
	// il prodotto scalare è uguale alla somma tra i prodotti delle stesse componenti di due vettori
	dot = this->Vx*v2.Vx + this->Vy*v2.Vy;
	return dot;
}