#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_array(int *array, int size_array) {
	for (int i = 0; i < size_array; i++) {
		printf("array[%d] = %d\t\t", i, *(array+i));
	}
	printf("\n");
}

int *crea_array(int size_array) {
	int *array = (int*)calloc(size_array, sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < size_array; i++) {
		*(array+i) = 1 + rand() % 100;
	}
	return array;
}

void merge(int *array, int begin, int mid, int end) {
	int i, j, k;
	int size_left_subarray = mid - begin + 1, size_right_subarray = end - mid;
	int *left_subarray = calloc(size_left_subarray, sizeof(int));
	int *right_subarray = calloc(size_right_subarray,sizeof(int));

	for (i = 0; i < size_left_subarray; i++)
		*(left_subarray+i) = *(array+begin+i);

	for (j = 0; j < size_right_subarray; j++)
		*(right_subarray+j) = *(array+mid+1+j);

	i = 0;
	j = 0;
	k = begin;

	while (i < size_left_subarray && j < size_right_subarray) {
		if (*(left_subarray+i) <= *(right_subarray+j)) {
			*(array+k) = *(left_subarray+i);
			i++;
		} else {
			*(array+k) = *(right_subarray+j);
			j++;
		}
		k++;
	}

	while (i < size_left_subarray) {
		*(array+k) = *(left_subarray+i);
		i++;
		k++;
	}

	while (j < size_right_subarray) {
		*(array+k) = *(right_subarray+j);
		j++;
		k++;
	}

	free(left_subarray);
	free(right_subarray);
}

void merge_sort (int *array, int begin, int end) {
	int mid;
	if (end + 1 <= 1)
		return;
	else if (begin < end) {
		mid = (begin + end) / 2;
		merge_sort(array, begin, mid);
		merge_sort(array, mid + 1, end);
		merge(array, begin, mid, end);
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

	merge_sort(array, 0, size_array-1);

	printf("ARRAY DOPO\n\t");
	print_array(array, size_array);

	return 0;
}