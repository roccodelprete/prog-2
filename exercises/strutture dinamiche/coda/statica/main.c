#include <stdlib.h>
#include<stdio.h>

#define MAX 10

typedef enum {false, true} boolean;

void enqueue(char *queue, char element, short *bottom) {
	if (*bottom < MAX) {
		queue[(*bottom)++] = element;
	} else {
		printf("\nCoda piena...");
	}
}

void dequeue(short *head) {
	if (*head < MAX) {
		(*head)++;
	}
}

void show_queue(char *queue, short head, short bottom) {
	if (head < MAX && bottom != head) {
		for (int i = bottom - 1; i >= head; i--) {
			printf("\t[%d] -> %c\n", i, queue[i]);
		}
		printf("\n");
		fflush(stdin);
	}
}

int main () {
	int scelta;
	boolean exit = false;
	char queue[MAX], element;
	short head = 0, bottom = 0;

	do {
		printf("1) Enqueue -> inserisci un elemento nella coda\n2) Dequeue -> elimini un elemento dalla coda\n3) Visualizza coda\n4) Exit\n\n");
		scanf("%d", &scelta);
		fflush(stdin);
		switch (scelta)	{
		case 1:
			printf("Inserisci un carattere -> ");
			element = getchar();
			printf("\n");
			enqueue(queue, element, &bottom);
			break;
		case 2:
			if (bottom != head)
				dequeue(&head);
			else
				printf("\nCoda vuota...");
			break;
		case 3:
			show_queue(queue, head, bottom);
			break;
		case 4:
			exit = true;
			break;
		default:
			printf("\nScelta errata...");
			break;
		}
	} while (!exit);

	return 0;
}