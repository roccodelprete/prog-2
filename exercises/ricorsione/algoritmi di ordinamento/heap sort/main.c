#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *create_heap(int size_array) {
	int *heap = (int*)calloc(size_array, sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < size_array; i++)
		*(heap + i) = 1 + rand() % 100;
	return heap;
}

// Function to swap the the position of two elements
void swap(int *first_var, int *second_var) {
	int temp = *first_var;
	*first_var = *second_var;
	*second_var = temp;
}

void heapify(int heap[], int size_heap, int index_current_element) {
	// Find largest among root, left_child and right_child
	int largest = index_current_element, left_child = 2 * index_current_element + 1, right_child = 2 * index_current_element + 2;

	if (left_child < size_heap && heap[left_child] > heap[largest])
		largest = left_child;

	if (right_child < size_heap && heap[right_child] > heap[largest])
		largest = right_child;

	// Swap and continue heapifying if root is not largest
	if (largest != index_current_element) {
		swap(&heap[index_current_element], &heap[largest]);
		heapify(heap, size_heap, largest);
	}
}

// Main function to do heap sort
void heap_sort(int heap[], int size_heap) {
	// Build max heap in modalità bottom-up
	for (int i = size_heap / 2 - 1; i >= 0; i--)
		heapify(heap, size_heap, i);

	// Heap sort in modalità top-down
	for (int i = size_heap - 1; i >= 0; i--) {
		swap(&heap[0], &heap[i]);
		// Heapify root element to get highest element at root again
		heapify(heap, i, 0);
	}
}

// Print an array
void print_heap(int heap[], int size_heap) {
	for (int i = 0; i < size_heap; i++)
		printf("heap[%d] -> %d\t\t", i, heap[i]);
	printf("\n");
}

int main() {
	int size_heap;
	printf("Dimensione heap -> ");
	scanf("%d", &size_heap);
	fflush(stdin);

	int *heap = create_heap(size_heap);

	printf("INITIAL HEAP\n");
	print_heap(heap, size_heap);

	heap_sort(heap, size_heap);

	printf("\nSORTED HEAP\n");
	print_heap(heap, size_heap);
}