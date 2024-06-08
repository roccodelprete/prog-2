#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *array, int size_array) {
	for (int i = 0; i < size_array; i++) {
		printf("array[%d] = %d\t\t", i, *(array+i));
	}
	printf("\n");
}

void swap(int *first_var, int *second_var) {
	int temp = *first_var;
	*first_var = *second_var;
	*second_var = temp;
}

int *crea_array(int size_array) {
	int *array = (int*)calloc(size_array, sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < size_array; i++) {
		*(array+i) = 1 + rand() % 100;
	}
	return array;
}

int partition(int *array, int begin, int end) {
	int pivot = *(array+end), i = begin;
	for (int j = begin; j < end; j++) {
		if (*(array+j) <= pivot) {
			swap(array + i, array + j);
			i++;
		}
	}
	swap(array+i, array+end);
	return i;
}

void quick_sort(int *array, int begin, int end) {
	if (begin < end) {
		int pivot = partition(array, begin, end);
		quick_sort(array, begin, pivot - 1);
		quick_sort(array, pivot + 1, end);
	}
}

int main() {
	int size_array;

	printf("Inserisci il size dell'array -> ");
	scanf("%d", &size_array);
	fflush(stdin);

	int *array = crea_array(size_array);

	printf("ARRAY PRIMA\n\t");
	print_array(array, size_array);

	quick_sort(array, 0, size_array - 1);

	printf("ARRAY DOPO\n\t");
	print_array(array, size_array);

	return 0;
}
