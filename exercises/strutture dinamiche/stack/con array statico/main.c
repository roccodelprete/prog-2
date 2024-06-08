#include <stdlib.h>
#include <stdio.h>

typedef enum{false, true} boolean;

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
	int head = -1;
	for(short i = 0; i < size; i++)
		push(stack[i], temp, &head);
	for(short i = 0; i < size; i++)
		pop(stack+i, temp, &head);
	printf("\n");
	free(temp);
}

int main() {
	int stack[100];
	int element, num_element = 0, size, head = 0, chosen;
	boolean exit = false;
	printf("*** Gestione di uno stack ***\n");
	printf("\n\tInserire la dimensione dello stack -> ");
	scanf("%d", &size);
	do {
		printf("\nScegli una voce dal menu");
		printf("\n\t1- Push\n\t2- Pop\n\t3- Visualizzazione stack\n\t4- Inverti ordine\n\t5- Exit\n\n\t");
		scanf("%d", &chosen);
		fflush(stdin);
		switch (chosen) {
			case 1:
				printf("\n\t*** CARICAMENTO DI UN ELEMENTO NELLO STACK ***\n");
				fflush(stdin);
				printf("\n\tElemento da inserire nello stack -> ");
				scanf("%d", &element);
				fflush(stdin);
				if (num_element < size) {
					push(element, stack, &head);
					num_element++;
				} else
					printf("\n\tStack pieno...");
				printf("\n");
				break;
			case 2:
				printf("\n\t*** ELIMINAZIONE DI UN ELEMENTO DALLO STACK ***\n");
				if (num_element > 0) {
					pop(&element, stack, &head);
					num_element--;
				} else
					printf("\n\tStack vuoto...\n");
				printf("\n");
				break;
			case 3:
				printf("\n\t*** VISUALIZZAZIONE DELLO STACK ***\n");
				show_stack(stack, num_element);
				break;
			case 4:
				invert(stack, size);
				show_stack(stack, head);
			case 5:
				exit = true;
				break;
			default:
				printf("\n\tScelta errata... Riprovare\n");
				break;
		}
	} while (!exit);

	//invert(stack, size);

	return 0;
}
