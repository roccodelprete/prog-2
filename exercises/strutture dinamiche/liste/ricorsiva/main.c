#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

struct linked_list {
	DATA dato;
	struct linked_list *next;
};
typedef struct linked_list ELEMENT;
typedef ELEMENT *LINK;

LINK array_to_list(DATA s[]) {
	LINK head;
	if (s[0] == '\0')
		return NULL;
	else {
		head = malloc(sizeof(ELEMENT));
		head->dato = s[0];
		head->next = array_to_list(s+1);
		return head;
	}
}

int main() {
	DATA testo[] = "questa e' una prova";
	LINK header_list = array_to_list(testo), list_pointer = header_list;
	while (list_pointer != NULL) {
		putchar(list_pointer->dato);
		list_pointer = list_pointer->next;
	}
	puts("");

	return 0;
}
