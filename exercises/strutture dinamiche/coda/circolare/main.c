#include <stdlib.h>
#include<stdio.h>

#define LEN_QUEUE 10

typedef enum {false, true} boolean;

void enqueue(char *queue, char element, short head, short *n_element) {
    short bottom = head + *n_element;
    bottom = bottom % LEN_QUEUE;
    queue[bottom] = element;
    (*n_element)++;
}

void dequeue(short *head, short *n_element) {
    *head = *head + 1;
    *head = *head % LEN_QUEUE;
    (*n_element)--;
}

void show_queue(char *queue, short head, short *n_element) {
    short bottom = *n_element + head;
	if (head < LEN_QUEUE && bottom != head) {
		for (int i = *n_element - 1; i >= 0; i--)
			printf("\t[%d] -> %c\n", (i + head) % LEN_QUEUE, queue[(i + head) % LEN_QUEUE]);
		printf("\n");
		fflush(stdin);
	}
}

int main () {
	int scelta;
	boolean exit = false;
	char queue[LEN_QUEUE], element;
	short head = 0, n_element = 0;

	do {
		printf("1) Enqueue -> inserisci un elemento nella coda\n2) Dequeue -> elimini un elemento dalla coda\n3) Visualizza coda\n4) Exit\n\n");
		scanf("%7d", &scelta);
		fflush(stdin);
		switch (scelta)	{
		case 1:
			printf("\nInserisci un carattere -> ");
			element = getchar();
			printf("\n");
			if (n_element < LEN_QUEUE) {
                enqueue(queue, element, head, &n_element);
            } else {
                printf("Coda piena...\n\n");
            }
			break;
		case 2:
			if (n_element) {
                dequeue(&head, &n_element);
            } else {
                printf("Coda vuota...\n\n");
            }
			break;
		case 3:
			show_queue(queue, head, &n_element);
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