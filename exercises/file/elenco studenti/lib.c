#include "lib.h"

void swap(studente *v1,studente *v2) {
	studente temp = *v1;
	*v1 = *v2;
	*v2 = temp;
}

void min_val_ind(studente *v, int n, char *min, short *i_min) {
	short i = 0;
	memcpy(min,(v+i)->mat,strlen((v+i)->mat));
	*i_min = 0;
	for(i=1;i<n;i++) {
		if(strcmp((v+i)->mat,min)<0) {
			memcpy(min,(v+i)->mat,strlen((v+i)->mat)+1);
			*i_min = i;
		}
	}
}

void selection_sort_min(studente *v, int n) {
	short indice_min;
	char min_array[11];

	for(short i=0;i<n-1;i++) {
		min_val_ind(v+i,n-i,min_array,&indice_min);
		swap(v+i,v+indice_min+i);
	}
}

studente *crea(studente *elenco, int *n) {
	studente new_stud;
	int sum = 0, cfu_sum = 0, voto, cfu;

	printf("\nCognome e nome -> ");
	fgets(new_stud.nome,32,stdin);
	new_stud.nome[strlen(new_stud.nome)-1]='\0';

	printf("\nMatricola -> ");
	fgets(new_stud.mat,12,stdin);
	new_stud.mat[strlen(new_stud.mat)-1]='\0';

	printf("\nEsami superati -> ");
	scanf("%d",&new_stud.exam);
	fflush(stdin);

	for(short i = 0; i < new_stud.exam; i++) {
		printf("\nVoto esame %d -> ", i+1);
		scanf("%d",&voto);
		printf("\nCFU esame %d -> ", i+1);
		scanf("%d",&cfu);
		sum += cfu * voto;
		cfu_sum += cfu;
	}

	new_stud.media = (float)sum / (float)cfu_sum;
	new_stud.crediti = cfu_sum;

	elenco = (studente*)realloc(elenco,*(n+1)*sizeof(studente));
	*(elenco+(*n)++) = new_stud;

	return elenco;
}

void scrittura(studente *scheda, FILE *fp, int n) {
	if(fseek(fp,0,SEEK_SET) != 0) {
		puts("Errore posizionamento file");
		exit(1);
	}

	if(fwrite(scheda,sizeof(studente),n,fp) != n) {
		puts("Errore scrittura file");
		exit(1);
	}
}

void lettura(FILE *fp,int dim) {
	studente a;
	short i = 1;
	do {
		if(fread(&a, sizeof(studente), 1, fp) == 1) {
			printf("Studente %d -> \n",i++);
			printf("Cognome e Nome -> %s\n",a.nome);
			printf("Matricola -> %s\n",a.mat);
			printf("Esami superati -> %d\n",a.exam);
			printf("Media pesata -> %f\n",a.media);
			printf("CFU -> %d\n\n",a.crediti);
		} else
			puts("\nFine del file...\n");
	} while(!feof(fp));
}

esameProg2 *crea_esame(esameProg2 *esame,int *n) {
	esameProg2 new_exam;

	printf("Nome dello studente -> ");
	fgets(new_exam.nome,32,stdin);
	new_exam.nome[strlen(new_exam.nome)-1] = '\0';

	printf("Voto -> ");
	scanf("%d", &new_exam.voto);
	fflush(stdin);

	printf("CFU -> ");
	scanf("%d", &new_exam.cfu);
	fflush(stdin);

	esame = (esameProg2*)realloc(esame,*(n+1)*sizeof(esameProg2));
	*(esame+(*n)++) = new_exam;

	return esame;
}

void scrittura_esame(esameProg2 *esame,FILE *xp,int n) {
	if(fseek(xp,0,SEEK_SET) != 0) {
		puts("Errore posizionamento file...");
		exit(1);
	}
	if(fwrite(esame,sizeof(esameProg2),n,xp) != n) {
		puts("Errore scrittura file...");
		exit(1);
	}
}

int binary_search(char *key, studente *elenco, int size) {
	int mediano, primo = 0, ultimo = size - 1;
	while(primo <= ultimo) {
		mediano = (primo+ultimo)/2;
		if(strcmp(key, (elenco + mediano)->nome) == 0)
			return mediano;
		else if(strcmp(key, (elenco + mediano)->nome) < 0)
			ultimo=mediano-1;
		else
			primo=mediano+1;
	}
	return -1;
}

void aggiorna_elenco(studente *elenco,int n,FILE *fp,int m,FILE *xp) {
	esameProg2 *a;
	int i=0,j=0,pos,somma,somma_cfu;

	if(fseek(xp,0,SEEK_SET) != 0) {
		puts("Errore posizionamento file");
		exit(1);
	}

	do {
		if(fread(a+i,sizeof(esameProg2),1,xp) == 1)
			i++;
		else
			puts("\nFine del file\n");
	} while(!feof(xp));

	do {
		pos = binary_search((a + j)->nome, elenco, n);
		if(pos != -1) {
			somma = (elenco+pos)->media * (elenco+pos)->crediti + (a+j)->voto * (a+j)->cfu;
			somma_cfu = (elenco+pos)->crediti + (a+j)->cfu;
			(elenco+pos)->media = (float)somma/(float)somma_cfu;
			(elenco+pos)->crediti = somma_cfu;
			(elenco+pos)->exam++;
		}
		else
			puts("Lo studente non e' stato trovato!\n");
		j++;
	} while (pos == -1 && j<m);
	scrittura(elenco,fp,n);
}