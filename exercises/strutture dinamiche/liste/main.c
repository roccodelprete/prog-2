#include "lib.h"

int main(){
    unsigned int MAX_SIZE = 20;
	struct PERSONA *head,*punt;
	INFO_FIELD dato,letto;
	short scelta;
	char scelta_c[2];
	
	head = crea_lista();
	
	do {
		printf("1 - Inserire un nodo in testa\n");
		printf("2 - Inserire un nodo\n");
		printf("3 - Elimina il nodo in testa\n");
		printf("4 - Elimina un nodo\n");
		printf("5 - Visualizza un determinato nodo\n");
		printf("6 - Visualizza lista\n");
		printf("7 - Exit\n");
		printf("\nScelta: ");
		gets(scelta_c); // inserisco come stringa la scelta dal men�
		fflush(stdin);
		if(strlen(scelta_c) > 1) // controllo che la lunghezza della scelta inserita sia ad una cifra
			puts("Scelta errata!\n");
		else {
			scelta = atoi(scelta_c); // se � una sola cifra allora la converto in un intero tramite atoi
			switch(scelta) {
				case 1:
					printf("\nInserire nome: ");
					strcpy(dato.nome,input_stringa(MAX_SIZE));
					printf("\nInserire eta': ");
					scanf("%d",&dato.eta);
					printf("\n");
					fflush(stdin);
					ins_testa(dato,&head);
					dato.eta = 0;
					break;
				case 2:
					printf("\nInserire nome: ");
					strcpy(dato.nome,input_stringa(MAX_SIZE));
					printf("\nInserire eta': ");
					scanf("%d",&dato.eta);
					fflush(stdin);
					punt = visitList(head);
					ins_nodo(dato,&punt);
					dato.eta = 0;
					break;
				case 3:
					elim_testa(&head);
					break;
				case 4:
					printf("\nInserire dati da cercare:\n");
					printf("\nInserire nome: ");
					strcpy(dato.nome,input_stringa(MAX_SIZE));
					printf("\nInserire eta': ");
					scanf("%d",&dato.eta);
					fflush(stdin);
					elim_nodo(dato,head);
					dato.eta = 0;
					break;
				case 5:
					printf("\nNodo corrente:\n");
					punt = visitList(head);
					letto = legge_nodo(punt);
					printf("\nNome: %s",letto.nome);
					printf("\nEta': %d",letto.eta);
					printf("\n");
					break;
				case 6:
					printList(head);
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
