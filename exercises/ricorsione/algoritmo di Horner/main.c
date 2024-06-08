#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *array, int grado_polinomio) {
	for (int i = 0; i < grado_polinomio; i++)
		printf("array[%d] = %d\t\t", i, *(array+i));
	printf("\n");
}

int *crea_array(int grado_polinomio) {
	int *array = (int*)calloc(grado_polinomio, sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < grado_polinomio; i++)
		*(array+i) = 1 + rand() % 5;
	return array;
}

int horner_iterativo(int *array, int grado_polinomio, int incognita) {
	int result = *array;
	for (int i = 1; i < grado_polinomio; i++)
		result = *(array+i) + incognita * result;
	return result;
}

int horner_ricorsivo(int *array, int grado_polinomio, int incognita) {
	if (grado_polinomio == 1)
		return *array;
	else
		return (*(array+grado_polinomio-1) + incognita * horner_ricorsivo(array, grado_polinomio-1, incognita));
}

int main() {
	int incognita, grado_polinomio;

	printf("\nGrado polinomio -> ");
	scanf("%d", &grado_polinomio);

	int *array = crea_array(grado_polinomio);
	print_array(array, grado_polinomio);

	printf("\nIncognita -> ");
	scanf("%d", &incognita);

	printf("\nHORNER ITERATIVO\n\tIl polinomio secondo Horner vale -> %d\n", horner_iterativo(array, grado_polinomio, incognita));
	printf("\nHORNER RICORSIVO\n\tIl polinomio secondo Horner vale -> %d\n", horner_ricorsivo(array, grado_polinomio, incognita));

	return 0;
}
