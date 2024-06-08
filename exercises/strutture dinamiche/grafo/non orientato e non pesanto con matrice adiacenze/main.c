#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void crea_grafo(int *mat, int size_grafo) {
	int num_adiacenze = 0, nodo_adiacente, i, j;
	for (i = 0; i < size_grafo; i++) {
		printf("\nQuante adiacenze ha il nodo %d? -> ", i);
		scanf("%d", &num_adiacenze);
		fflush(stdin);
		for (j = 0; j < num_adiacenze; j++) {
			printf("Con quale nodo e' adiacente? -> ");
			scanf("%d", &nodo_adiacente);
			fflush(stdin);
			*(mat + size_grafo * i + nodo_adiacente) = 1;  // flag che indica se c'è adiacenza
		}
	}
}

int calcola_grado(int *mat, int n, int nodo) {
	int grado = 0;
	for (int i = 0; i < n; i++) {
		if (*(mat+n*nodo+i) == 1)
			grado++;
	}
	return grado;
}

int main() {
	int size_grafo, nodo;

	printf("Inserire il numero di nodi del grafo -> ");
	scanf("%d", &size_grafo);
	fflush(stdin);

	int *mat = (int*)calloc(pow(size_grafo, 2), sizeof(int));

	crea_grafo(mat, size_grafo);

	printf("\nDi quale nodo vuoi conoscere il grado? -> ");
	scanf("%d", &nodo);
	fflush(stdin);
	printf("\nIl grado del nodo %d e' -> %d\n", nodo, calcola_grado(mat, size_grafo, nodo));

	return 0;
}