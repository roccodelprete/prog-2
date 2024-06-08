#include <stdio.h>
#include <stdlib.h>

// implemento una procedura per lo scambio tra due valori
void swap_num(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

// implemento la procedura heapify che permette di "ordinare" un albero
void heapify(int *heap, unsigned int i) {
	if(i%2 == 0) { // se la divisione per 2 dell'indice del nodo dell'albero nell'array d� resto 0
		// allora controllo che il nodo i-simo sia maggiore sia del fratello che del padre
		if(*(heap + i) > *(heap + i + 1) && *(heap + i) > *(heap + i / 2))
			swap_num(heap + i / 2, heap + i); // se cos� fosse, scambio il padre con il figlio
	} else { // se la divisione per 2 d� resto 1 significa che ci troviamo in un nodo destro
		// ma ugualmente controllo che il nodo i-simo sia maggiore sia del fratello che del padre
		if(*(heap + i) > *(heap + i - 1) && *(heap + i) > *(heap + i / 2))
			swap_num(heap + i / 2, heap + i); // se cos� fosse, scambio il padre con il figlio
	}
}

// implemento una procedura per la costruzione di un albero heap mediante array
void heap_construction(int *array, unsigned int size_array) {
	unsigned int i;
	for(i = 1; i <= size_array; i++) { // inserisco gli elementi nell'array
		printf("Inserire l'elemento %d -> ", i);
		scanf("%d", array + i);
		fflush(stdin);
		if(i != 1) // se l'indice i che scorre l'array � diverso da 1
			heapify(array, i); // allora richiamo la procedura di heapify
		/* se l'indice i � maggiore della met� dell'array allora significa che bisogna controllare
		anche se il nodo che stiamo considerando deve salire di livello pi� volte */
		if(i > 4)
			heapify(array, i / 2); // se fosse cos� allora richiamo la procedura di heapify passando l'indice i diviso 2
	}
	printf("\n");
}

int main() {
	unsigned int size;
	printf("Inserire la dimensione dell'heap -> ");
	scanf("%d", &size);
	fflush(stdin);
	printf("\n");

	// alloco dinamicamente la dimensione dell'array in cui simuleremo la struttura heap
	int *heap = (int*)calloc((size + 1), sizeof(int));
	heap_construction(heap, size);

	for(int i = 1; i <= size; i++)
		printf("Elemento %d -> padre %d -> %d\n", i, i/2, *(heap+i));

	return 0;
}