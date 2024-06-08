#ifndef CON_LISTA_LIB_H
#define CON_LISTA_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[30];
	int eta;
} INFO_FIELD;

typedef struct PERSONA {
	INFO_FIELD info;
	struct PERSONA *next;
} Persona;

Persona *crea_lista();
void enqueue(INFO_FIELD,Persona*);
Persona *dequeue(Persona*);
Persona *visit_list(Persona*);
char *input_stringa(unsigned int);
void visualizza_queue(Persona*);

#endif //CON_LISTA_LIB_H
