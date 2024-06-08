#ifndef lib_h
#define lib_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char nome[20];
	int eta;
}INFO_FIELD;

struct PERSONA {
	INFO_FIELD info;
	struct PERSONA *next;
};

typedef enum{false,true} logical;

logical isEmptyList(struct PERSONA*);
struct PERSONA *crea_lista();
struct PERSONA *visitlist(struct PERSONA*);
void ins_testa(INFO_FIELD,struct PERSONA**);
void ins_nodo(INFO_FIELD,struct PERSONA**);
void elim_testa(struct PERSONA**);
void elim_nodo(INFO_FIELD,struct PERSONA*);
INFO_FIELD legge_nodo(struct PERSONA*);
void printList(struct PERSONA*);
char *input_stringa(unsigned int);

#endif
