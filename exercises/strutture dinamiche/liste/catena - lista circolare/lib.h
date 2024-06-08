#ifndef CATENA___LISTA_CIRCOLARE_LIB_H
#define CATENA___LISTA_CIRCOLARE_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[20];
	int eta;
}INFO_FIELD;

struct PERSONA {
	INFO_FIELD info;
	struct PERSONA *next;
};

typedef enum {false,true} logical;

struct PERSONA *crea_lista();
INFO_FIELD crea_dato();
struct PERSONA *ins_empty(struct PERSONA*, INFO_FIELD);
struct PERSONA *ins_testa(struct PERSONA*, INFO_FIELD);
void ins_between(struct PERSONA*,INFO_FIELD, INFO_FIELD);
struct PERSONA *ins_fondo(struct PERSONA*, INFO_FIELD);
void traverse(struct PERSONA*);
void elim_nodo(struct PERSONA**, INFO_FIELD);
char *input_stringa(unsigned int);

#endif //CATENA___LISTA_CIRCOLARE_LIB_H
