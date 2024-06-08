#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void crea_grafo(int *mat, int n) {
	int adiacenze = 0, pos;
	for (int i = 0; i < n; i++) {
		printf("\nQuanti nodi raggiungibili ha il nodo %d? -> ", i);
		scanf("%d", &adiacenze);
		fflush(stdin);
		for (int j = 0; j < adiacenze; j++) {
			printf("Quale nodo raggiunge? -> ");
			scanf("%d", &pos);
			fflush(stdin);
			*(mat+n*i+pos) = 1; // indica presenza di adiacenza
		}
	}
}

int calcola_archi_entranti(int *mat, int n, int nodo) {
	int entranti = 0;
	for (int i = 0; i < n; i++) {
		if (*(mat+n*i+nodo) == 1)
			entranti++;
	}
	return entranti;
}

int calcola_archi_uscenti(int *mat, int n, int nodo) {
	int uscenti = 0;
	for (int i = 0; i < n; i++) {
		if (*(mat+n*nodo+i) == 1)
			uscenti++;
	}
	return uscenti;
}

int main() {
	int dim, nodo;

	printf("Inserire il numero di nodi del grafo -> ");
	scanf("%d", &dim);
	fflush(stdin);

	int *mat = (int*)calloc(pow(dim, 2), sizeof(int));

	crea_grafo(mat, dim);

	printf("\nDi quale nodo vuoi conoscere il numero di archi uscenti ed entranti? -> ");
	scanf("%d", &nodo);
	fflush(stdin);
	printf("\nNodo -> %d\n\tArchi entranti -> %d\n\tArchi uscenti -> %d\n", nodo, calcola_archi_entranti(mat, dim, nodo),
	       calcola_archi_uscenti(mat, dim, nodo));

	return 0;
}