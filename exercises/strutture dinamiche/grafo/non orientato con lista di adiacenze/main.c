#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	char nome;
	struct nodo *adiacenti;
} NODO;

void crea_grafo(NODO *grafo, short dim) {
	char c = 'A', c_ad;
	short grado;

	for (short i = 0; i < dim; i++) {
		NODO *current = calloc(dim, sizeof(NODO));
		grafo[i].nome = c++;
		printf(">> GRADO NODO %c -> ", grafo[i].nome);;
		scanf("%hd", &grado);
		fflush(stdin);
		for (short j = 0; j < grado; j++) {
			printf("Nodo adiacente %hd -> ", j + 1);
			scanf("%c", &c_ad);
			fflush(stdin);
			if (j == 0) {
				grafo[i].adiacenti = &grafo[c_ad-'A'];
				current->adiacenti = grafo[i].adiacenti;
			} else {
				current->adiacenti = &grafo[c_ad-'A'];
				current = current->adiacenti;
				current->adiacenti = NULL;
			}
		}
		current->adiacenti = grafo[i].adiacenti;
		printf("Primo nodo adiacente = %c\n\n", current->nome);
	}
}

int main() {
	short size_grafo;
	printf("Inserire numero di nodi del grafo -> ");
	scanf("%hd", &size_grafo);
	fflush(stdin);

	NODO *grafo = (NODO*)calloc(size_grafo, sizeof(NODO));

	crea_grafo(grafo, size_grafo);
	return 0;
}
