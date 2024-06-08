#include "lib.h"

int main() {

	unsigned int MAXSIZE = 30;
	char scelta_c[2];
	Persona *testa = crea_lista();
	short scelta;
	INFO_FIELD new_dato;

	do {
		printf("1 - Inserire un elemento\n");
		printf("2 - Eliminazione di un elemento\n");
		printf("3 - Visualizza queue\n");
		printf("4 - Exit\n");
		printf("\nScelta: ");
		gets(scelta_c); // inserisco come stringa la scelta dal men�
		fflush(stdin);
		if(strlen(scelta_c) > 1) // controllo che la lunghezza della scelta inserita sia ad una cifra
			puts("Scelta errata!\n");
		else {
			scelta = atoi(scelta_c); // se � una sola cifra allora la converto in un intero tramite atoi
			switch(scelta) {
				case 1:
					printf("\nElemento da inserire nella queue: ");
					printf("\n\nInserire nome: ");
					strcpy(new_dato.nome,input_stringa(MAXSIZE));
					printf("\n");
					fflush(stdin);
					printf("Inserire eta': ");
					scanf("%d",&new_dato.eta);
					fflush(stdin);
					enqueue(new_dato,testa);
					break;
				case 2:
					if(testa != NULL) {
						testa = dequeue(testa);
						printf("\nEstrazione avvenuta con successo!\n\n");
					} else
						printf("\nLa queue e' vuota!\n\n");
					break;
				case 3:
					if(testa != NULL)
						visualizza_queue(testa);
					else
						printf("\nLa queue e' vuota!\n\n");
					break;
				case 4:
					break;
				default:
					break;
			}
		}
		// se la scelta � diversa da 4 o sono stati inseriti caratteri diversi da una cifra, allora si esce dal ciclo
	} while(scelta != 4 || strlen(scelta_c) > 1);

	return 0;
}