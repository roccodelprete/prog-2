#include <stdio.h>
#include <stdlib.h>

int potenza_ricorsiva_lineare(int numero, int esponente) {
	if (esponente == 1)
		return numero;
	else if (esponente == 0)
		return 1;
	else
		return numero * potenza_ricorsiva_lineare(numero, esponente - 1);
}

int potenza_ricorsiva_binaria(int numero, int esponente) {
	if (esponente == 1)
		return numero;
	else if (esponente == 0)
		return 1;
	else
		return potenza_ricorsiva_binaria(numero, esponente / 2) * potenza_ricorsiva_binaria(numero, esponente - esponente / 2);
}

int main() {
	int numero, esponente;
	printf("Inserisci la base -> ");
	scanf("%d", &numero);
	fflush(stdin);

	printf("Inserisci l'esponente -> ");
	scanf("%d", &esponente);
	fflush(stdin);

	printf("\nRISULTATO POTENZA LINEARE\n\t%d ^ %d = %d\n", numero, esponente, potenza_ricorsiva_lineare(numero, esponente));
	printf("\nRISULTATO POTENZA BINARIA\n\t%d ^ %d = %d\n", numero, esponente, potenza_ricorsiva_binaria(numero, esponente));

	return 0;
}
