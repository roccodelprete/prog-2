#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input_string(unsigned int string_size) {
	// allocazione dinamica sovradimensionata poichè non conosciamo quale sarà la dimensione della stringa
	char *str = (char*)malloc((string_size + 1) * sizeof(char));
	printf("Inserisci stringa -> ");
	/* inserendo una stringa in input tramite fgets verrà letto come carattere anche "\string_size" e di conseguenza la strlen
	della stringa immessa espliciterà un carattere in più di quelli immessi realmente */
	fgets(str, string_size + 1, stdin);
	fflush(stdin);
	// visto che fgets considera anche "\string_size" come carattere, andiamo a inserire il terminatore al posto giusto
	*(str + strlen(str) - 1) = '\0';    /*str[strlen(str) - 1] = '\0';*/
	// riallochiamo dinamicamente la stringa dopo averne conosciuto la dimensione
	str = (char*)realloc(str, strlen(str) + 1); // si passa strlen + 1 in modo da considerare anche il terminatore
	return str;
}

// implemento una procedura per la concatenazione di due stringhe senza l'utilizzo della funzione strcat
char *string_concatenation(char *s1, char *s2) {
	short j = strlen(s1); // la variabile j avrà il valore della dimensione di s1
	// rialloco dinamicamente la dimensione di s1, in modo che possa contenere anche la stringa s2 al suo interno
	s1 = (char*)realloc(s1,(strlen(s1) + strlen(s2)));
	for(short i = 0; *(s2+i) != '\0'; i++) // imposto un costrutto iterativo for che scorra s2 fino al terminatore
		*(s1+j++) = *(s2+i); // metto gli i-simi caratteri di s2 in coda a s1, effettuando così la concatenazione
	*(s1+j) = '\0'; // riposiziono il terminatore come ultimo carattere di s1
	return s1;
}

int main() {
	unsigned int MAXSIZE = 100;
	char *str1, *str2;

	str1 = input_string(MAXSIZE);
	str2 = input_string(MAXSIZE);

	str1 = string_concatenation(str1, str2);
	printf("Concatenazione -> %s",str1);

	free(str1);
	free(str2); // libero la memoria allocata dinamicamente per memorizzare le stringhe

	return 0;
}
