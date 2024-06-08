//
// Created by rocco on 14/06/2022.
//

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
Persona *push(INFO_FIELD, Persona*);
Persona *pop(Persona*);
char *input_stringa(unsigned int);
void visualizza_stack(Persona*);

#endif //CON_LISTA_LIB_H
