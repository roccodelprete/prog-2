#ifndef lib_h
#define lib_h

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Studente{
	char nome[32];
	char mat[12];
	short exam;
	float media;
	int crediti;
} studente;

typedef struct esame{
	char nome[32];
	unsigned int voto;
	unsigned int cfu;
} esameProg2;

void swap(studente*, studente*);
void min_val_ind(studente*, int, char*, short*);
void selection_sort_min(studente*, int);
studente *crea(studente*, int*);
void scrittura(studente*, FILE*, int);
void lettura(FILE*, int);
void scrittura_esame(esameProg2*, FILE*, int);
esameProg2 *crea_esame(esameProg2*, int*);
int binary_search(char*, studente*, int);
void aggiorna_elenco(studente*, int, FILE*, int, FILE*);

#endif