#include "lib.h"

int main() {
	struct PERSONA *fondo = crea_lista();
	INFO_FIELD dopo;
	short scelta;
	char scelta_c[2];

	do {
		printf("1 - Inserire un nodo in lista vuota\n");
		printf("2 - Inserire un nodo in testa\n");
		printf("3 - Inserire un nodo dopo un dato\n");
		printf("4 - Inserire un nodo in fondo\n");
		printf("5 - Elimina un nodo\n");
		printf("6 - Visualizza lista\n");
		printf("7 - Exit\n");
		printf("\nScelta: ");
		gets(scelta_c); // inserisco come stringa la scelta dal menù
		fflush(stdin);
		if(strlen(scelta_c) > 1) // controllo che la lunghezza della scelta inserita sia ad una cifra
			puts("Scelta errata!\n");
		else {
			scelta = atoi(scelta_c); // se è una sola cifra allora la converto in un intero tramite atoi
			switch(scelta) {
				case 1:
					printf("\nDato da inserire:\n");
					fondo = ins_empty(fondo,crea_dato());
					break;
				case 2:
					printf("\nDato da inserire:\n");
					fondo = ins_testa(fondo,crea_dato());
					break;
				case 3:
					if(fondo != NULL) {
						printf("\nDopo quale nodo se ne vuole inserire uno nuovo?\n");
						dopo = crea_dato();
						printf("\nDato da inserire:\n");
						ins_between(fondo,crea_dato(),dopo);
					} else
						printf("\nLa lista e' vuota!\n\n");
					break;
				case 4:
					printf("\nDato da inserire:\n");
					fondo = ins_fondo(fondo,crea_dato());
					break;
				case 5:
					elim_nodo(&fondo,crea_dato());
					break;
				case 6:
					traverse(fondo);
					break;
				case 7:
					break;
				default:
					break;
			}
		}
	} while(scelta != 7 || strlen(scelta_c) > 1);
	return 0;
}