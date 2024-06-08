//
// Created by rocco on 05/06/2022.
//

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

typedef enum{false,true} boolean;

boolean isEmptyList(struct PERSONA*);
struct PERSONA *crea_lista();
struct PERSONA *visit_list(struct PERSONA*);
void ins_testa(INFO_FIELD,struct PERSONA**);
void ins_nodo(INFO_FIELD,struct PERSONA**);
void elim_testa(struct PERSONA**);
void elim_nodo(INFO_FIELD,struct PERSONA*);
INFO_FIELD legge_nodo(struct PERSONA*);
void print_list(struct PERSONA*);
char *input_stringa(unsigned int);

#endif //lib_h
