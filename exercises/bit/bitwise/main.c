#include "lib.h"

int main() {
	/* Estrarre i primi 5 bit più significativi */
	/*unsigned char number, mask;
	msb_extraction(&number, &mask);*/
	/* ---------------------------------------- */

	/* Estrarre gli n_bit bit meno significativi */
	/*unsigned char number, mask;
	short n_bit = 0;
	lsb_extraction(&number, &mask, n_bit);*/
	/* ----------------------------------------- */

	/* Conversione di due caratteri da maiuscolo a minuscolo e viceversa */
	/*char c;
	printf("Inserisci carattere -> ");
	scanf("%c", &c);
	printf("\nCarattere convertito -> %c", conversion_upper_lower_char(c));*/
	/* ------------------------------------------------------------------ */

	/* Scambiare il contenuto di due variabili senza variabile di appoggio */
	/*short c, z;
	printf("Inserisci primo valore -> ");
	scanf("%hi", &c);
	fflush(stdin);
	printf("Inserisci secondo valore -> ");
	scanf("%hi", &z);
	fflush(stdin);
	printf("\nPrima -> c = %hi | z = %hi\n", c, z);
	swap_xor(&c, &z);
	printf("\nDopo -> c = %hi | z = %hi\n", c, z);*/
	/* ------------------------------------------------------------------- */

	/* Estrazione bit pari */
	/*unsigned char c;
	printf("Inserisci carattere -> ");
	scanf("%c", &c);
	fflush(stdin);
	printf("CARATTERE INSERITO");
	bit_show(c);
	even_extraction(&c);
	printf("\nRISULTATO ESTRAZIONE");
	bit_show(c);*/
	/* ------------------- */

	/* Inversione dei bit */
	/*unsigned char c;
	printf("Inserisci carattere -> ");
	scanf("%c", &c);
	fflush(stdin);
	printf("\nCARATTERE INSERITO");
	bit_show(c);
	unsigned char inversion = invert(c);
	printf("\nRISULTATO INVERSIONE");
	bit_show(inversion);*/
	/* ------------------ */

	/* Ruotare una variabile char di n_bit mediante operatori bitwise */
	/*unsigned char c, c_rotated;
	short n_bit;
	printf("Inserisci carattere -> ");
	scanf("%c", &c);
	fflush(stdin);
	printf("\nCARATTERE INSERITO");
	bit_show(c);
	printf("\nInserisci il numero di bit da shiftare (numero < 0 -> shift a sinistra | numero > 0 shift a destra) -> ");
	scanf("%hd", &n_bit);
	fflush(stdin);
	c_rotated = rotate(c, n_bit);
	printf("\nRISULATO ROTAZIONE");
	bit_show(c_rotated);*/
	/* -------------------------------------------------------------- */

	/* Conversione di un numero intero in base 10 a binario */
	/*int int_number, bit[8], i;
	printf("Inserire il numero decimale da convertire -> ");
	scanf("%d", &int_number);
	for(i=0; i<8; i++)
	bit[i]=0;
	convert_binary_decimal(int_number, bit);
	show_converted(bit);*/
	/* ---------------------------------------------------- */

	/* Conversione di un numero float in base 10 a binario */
	/*unsigned char bit[8];
	float number;
	int num_mul;
	printf("Inserire il numero decimale da convertire -> ");
	scanf("%f", &number);
	fflush(stdin);
	printf("Inserire il numero di moltiplicazioni da effettuare -> ");
	scanf("%d", &num_mul);
	fflush(stdin);
	for(int i = 0; i < 8; i++)
		bit[i] = 0;
	convert_float_decimal(num_mul, number, bit);
	printf("\nNumero binario -> ");
	for(int i = 7; i >= 0; i--) {
		if (i == 6)
			printf(".%d", (int)bit[i]);
		else
			printf("%d", (int)bit[i]);
	}
	printf("\n");*/
	/* ----------------------------------------------------- */

	/* Somma binaria */
	/*short var_1, var_2;
	printf("Primo addendo -> ");
	scanf("%hi", &var_1);
	fflush(stdin);
	bit_show(var_1);
	printf("\nSecondo addendo -> ");
	scanf("%hi", &var_2);
	fflush(stdin);
	bit_show(var_2);
	short sum = binary_sum(var_1, var_2);
	printf("\nSOMMA BINARIA -> %hi + %hi = %hi", var_1, var_2, sum);
	bit_show(sum);*/
	/* ------------- */

	/* Sottrazione binaria */
	/*short var_1, var_2;
	printf("Primo valore -> ");
	scanf("%hi", &var_1);
	fflush(stdin);
	bit_show(var_1);
	printf("\nSecondo valore -> ");
	scanf("%hi", &var_2);
	fflush(stdin);
	bit_show(var_2);
	short sub = binary_sub(var_1, var_2);
	printf("\nSOTTRAZIONE BINARIA -> %hi - %hi = %hi", var_1, var_2, sub);
	bit_show(sub);*/
	/* ------------------- */

	/* Complemento a due */
	/*short number, n_bit;
	printf("Numero da convertire in complemento a due -> ");
	scanf("%hi", &number);
	fflush(stdin);
	bit_show(number);
	printf("\nNumero di bit -> ");
	scanf("%hi", &n_bit);
	fflush(stdin);
	short converted_number = complemento_a_2(n_bit, number);
	printf("\nCOMPLEMENTO A DUE DI %d -> %d", number, converted_number);
	bit_show(converted_number);*/
	/* ----------------- */

	/* Biased */
	/*short number, n_bit;
	printf("Numero da rappresentare in biased -> ");
	scanf("%hi", &number);
	fflush(stdin);
	bit_show(number);
	printf("\nNumero di bit -> ");
	scanf("%hi", &n_bit);
	fflush(stdin);
	short biased_number = biased(number, n_bit);
	printf("\nBIASED DI %d -> %d", number, biased_number);
	bit_show(biased_number);*/
	/* ------ */

	/* Estrazione esponente da un float */
	/*u_type number;
	printf("Numero -> ");
	scanf("%f", &number.float_number);
	fflush(stdin);
	printf("Esponente -> %hi", extract_esponent(number.int_number));*/
	/* -------------------------------- */

	/* Visualizzazione mantissa, esponente esponent segno di un floating-point */
	/*Floating_Point number;
	printf("Numero -> ");
	scanf("%g", &number.f);
	fflush(stdin);
	print_floating(number);*/
	/* ------------------------------------------------------------------------ */

	/* Visualizzazione mantissa, esponente e segno di un floating-point con array */
	/*Floating_Point number;
	short size_array;
	printf("Inserire il numero di caratteri (compreso il punto) del numero floating point che si vuole inserire -> ");
	scanf("%d", &size_array);
	fflush(stdin);
	char *array = (char*)calloc(size_array, sizeof(short));
	printf("\nInserire numero reale -> ");
	fgets(array,size_array+1,stdin);
	print_floating_array(number, array, size_array);*/
	/* --------------------------------------------------------------------------------- */
	return 0;
}