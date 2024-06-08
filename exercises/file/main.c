#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 40

/* implemento una procedura per leggere, mediante buffer da 200 caratteri, un file di testo e visualizzo 40 caratteri
per riga e 25 righe per schermata */
void visualize(FILE *fp) {
    char buffer[BUFSIZE];
    short row = 25, i;
    /* itera le operazioni nel blocco fin quando il file non raggiunge la fine e continua a stampare da file
    fin quando non si è raggiunto il limite massimo di row */
    while(!feof(fp) && getchar() == '\n') {
        while (!feof(fp) && i < row){
            fgets(buffer, BUFSIZE, fp);
            printf("%s\n",buffer);
            i++;
        }
        i = 0;
        system("pause");
    }
}

int main() {
    unsigned int MAXSIZE = 60;
    FILE *fp;
    char *file_name = (char*)malloc(MAXSIZE);
    // inserire nome del file di testo, riposizionamento del terminatore e aggiunta dell'estensione al nome del file
    puts("Inserire nome del file di testo -> ");
    fgets(file_name, 56, stdin);
    *(file_name + strlen(file_name) - 1) = '\0';
    strcat(file_name, ".txt");

	file_name = (char*)realloc(file_name, strlen(file_name) + 1);

    if((fp = fopen(file_name, "r")) == NULL) { // apro il file in modalità lettura
        puts("Errore apertura file!");
        exit(1);
    }

	visualize(fp);

    fclose(fp);

    return 0;
}

