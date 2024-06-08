#include "lib.h"

void push(int element, int *stack, int *head) {
	*(stack + ++*head) = element;
}

void pop(int *element, int *stack, int *head) {
	*element = *(stack + (*head)--);
}

void show_stack(int *stack, int head) {
	for(short i = head; i > 0; i--)
		printf("\tposizione %d -> %d\n", i, *(stack + i));
	printf("\n");
}

void invert(int *stack, int size) {
	/* inverte l'ordine degli elementi dello stack */
	printf("INVERTO...\n");
	int *temp = calloc(size, sizeof(stack[0]));
	int head=-1;
	for(short i = 0; i < size; i++)
		push(stack[i], temp, &head);
	for(short i = 0; i < size; i++)
		pop(stack+i, temp, &head);
	free(temp);
	printf("\n");
}
