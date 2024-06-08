#include "lib.h"

int main() {
	FILE *fp, *xp;
    char scelta_c[2];
    int scelta, dim = 0, dim2 = 0;
    studente *elenco = malloc(MAX_SIZE * sizeof(studente));
    esameProg2 *esame = malloc(MAX_SIZE * sizeof(esameProg2));

    if((fp = fopen("studente.dat","w+b")) == NULL) {
	    puts("Errore apertura file");
	    exit(1);
	}

    do {
        printf("1 - Crea studente\n");
		printf("2 - Visualizza elenco\n");
		printf("3 - Aggiorna elenco\n");
		printf("4 - Exit");
		printf("\nScelta -> ");
        fflush(stdin);
        gets(scelta_c);
        if(strlen(scelta_c) > 1)
        	puts("Scelta errata!\n");
        else {
	        scelta = atoi(scelta_c);
	        fflush(stdin);
	        switch(scelta) {
	            case 1:
	                elenco = crea(elenco,&dim);
	                if(dim>1)
	                	selection_sort_min(elenco,dim);
	                scrittura(elenco,fp,dim);
	                system("pause");
	                system("cls");
	                break;
	            case 2:
	        		if(fseek(fp,0,SEEK_SET) != 0) {
						puts("Errore posizionamento file");
						exit(1);
					} else
						lettura(fp, dim);
	                break;
	            case 3:
	            	if((xp = fopen("esameProg2.dat","w+b")) == NULL) {
					    puts("Errore apertura file");
					    exit(1);
					}
					esame = crea_esame(esame,&dim2);
					scrittura_esame(esame,xp,dim2);
	            	aggiorna_elenco(elenco,dim,fp,dim2,xp);
	            	fclose(xp);
	            	break;
	            case 4:
	            	break;
	            default:
	                break;
	        }
		}
    } while(scelta != 4 || strlen(scelta_c) > 1);
	fclose(fp);
    free(elenco);
	free(esame);
	return 0;
}