#include "lib.h"

void msb_extraction(unsigned char *number, unsigned char *mask) {
	/* function che estrae i 5 bit più significativi
	 * attraverso maschera */
	printf("Inserisci carattere -> ");
	scanf("%c", number);
	printf("CARATTERE INSERITO");
	bit_show(*number);
	*mask = 31 << 3;    /* 31 decimale = 0001 1111 binario; 31 << 3 = 1111 1000 */
	*number &= *mask;
	printf("\nCARATTERE DOPO AND BITWISE CON MASCHERA");
	bit_show(*number);
	printf("\nMASCHERA");
	bit_show(*mask);
}

void lsb_extraction(unsigned char *number, unsigned char *mask, short n_bit) {
	/* function che estrae i 5 bit meno significativi
	 * attraverso maschera */
	*mask = 0;
	printf("Inserisci carattere -> ");
	scanf("%c", number);
	fflush(stdin);
	printf("Inserisci il numero di bit da estrarre -> ");
	scanf("%hi", &n_bit);
	fflush(stdin);
	printf("\nCARATTERE INSERITO");
	bit_show(*number);
	/* *mask = 31;*/     /* 31 decimale = 0001 1111 */
	for (short i = 0; i < n_bit; i++)
		*mask = *mask << 1|1;
	*number &= *mask;
	printf("\nCARATTERE DOPO AND BITWISE CON MASCHERA");
	bit_show(*number);
	printf("\nMASCHERA");
	bit_show(*mask);
}

char conversion_upper_lower_char(char c) {
	/* function che converte da maiuscolo in minuscolo
	 * (e viceversa) un carattere */
	if (c >= 65 && c <= 122)
		return c ^ 32;
	else
		return c;
}

void even_extraction(unsigned char *a) {
	/* function che estrae i bit pari di una variabile */
	unsigned char b = *a & 1, c = *a & 4, d = *a & 16, e = *a & 64; /* 2^0 - 2^2 - 2^4 - 2^6 */
	c >>= 1;
	d >>= 2;
	e >>= 3;
	*a = 0;
	*a |= e;
	*a |= d;
	*a |= c;
	*a |= b;
}

void swap_xor(short *var_1, short *var_2) {
	/* function che scambia il valore di due variabili
	 * eseguendo la xor (^) tra di esse */
	*var_1 ^= *var_2;
	*var_2 ^= *var_1;
	*var_1 ^= *var_2;
}

unsigned char invert(unsigned char number) {
	unsigned char tmp = 0, inverted;
	short k = 1, mask;
	for (int i = 0; i < 7; ++i) {
		if (i < 4) {
			mask = pow(2, i);
			tmp = number & mask;
			tmp <<= 7-i*2;
			inverted |= tmp;
			tmp = 0;
		} else {
			mask = pow(2, i);
			tmp = number & mask;
			tmp >>= k;
			inverted |= tmp;
			k += 2;
			tmp = 0;
		}
	}
	return inverted;
}

unsigned char rotate(unsigned char ch, char n_bit) {
	/* funcion che effettua la rotazione dei bit di una variabile */
	/* con ch si effettua lo shift principale */
	unsigned char tmp = ch; /* tmp viene shiftata in modo da ottenere i bit ruotati */
	/* con il segno di n_bit si indica la direzione;
	 * il suo modulo indica il numero di shift */
	if (n_bit > 0) {
		/* shif verso destra */
		ch >>= n_bit;
		tmp <<= (sizeof(ch) * 8 - n_bit);
	} else if (n_bit < 0) {
		/* shift verso sinistra */
		n_bit = -n_bit;
		ch <<= n_bit;
		tmp >>= (sizeof(ch) * 8 - n_bit);
	}
	return ch | tmp; /* si unisce ch e tmp eseguendo la or (|) */
}

void bit_show(unsigned char ch) {
	/* 16 stringhe possibili, lunghe 5 (0010+\0)*/
	unsigned char bit[16][5] = {"0000","0001","0010","0011",
	                            "0100","0101","0110","0111",
	                            "1000","1001","1010","1011",
	                            "1100","1101","1110","1111"
	};
	unsigned char C, dx, sx;
	C = ch;
	sx = C >> 4;
	dx = C << 4;
	dx = dx >> 4;
	printf("\nchar = %c\t dec = %d\t \n", C, C);
	printf("hex  = %x\t bin = %s %s \n", C, bit[sx], bit[dx]); //indirizzo base
}

void convert_binary_decimal(int n, int *bit){
	/* algoritmo delle divisioni successive */
	/* converte un numero intero da base 10 a base 2 */
	int k = 0;
	do {
		bit[k++] = n % 2;
		n = n / 2;
	} while(n > 0);
	for(int j = k; j < 8; j++)
		bit[j] = 0;
}

void convert_float_decimal(int num_mul, float number, unsigned char *bit){
	/* algoritmo delle moltiplicazioni successive */
	/* converte un numero decimale da base 10 a base 2 */
	for(int k = 0; k < num_mul; k++) {
		number *= 2;
		bit[k] = (char)number;
		number -= bit[k];
	}
	for(int k = num_mul; k < 23; k++)
		bit[k] = 0;
}

void show_converted(int *bit){
	printf("\nNumero binario -> ");
	for(int i = 7; i >= 0; i--)
		printf("%d", bit[i]);
	printf("\n");
}

short binary_sum(short addend_1, short addend_2) {
	/* function che esegue la somma binaria, tenendo conto anche del riporto */
	short sum, carry;
	do {                           // imposto un costrutto do-while per iterare le operazioni per effettuare la sum completa
		sum = addend_1 ^ addend_2; // effettuo un'operazione di XOR per prendere il risultato della sum
		carry = addend_1 & addend_2; // effettuo un'operazione di AND per controllare i riporti
		carry <<= 1;                // shifto di 1 a sinistra i bit della variabile che memorizza i riporti
		addend_1 = sum; // all'iterazione successiva il primo numero(addend_1) avrà il valore della prima sum
		addend_2 = carry; // esponent il secondo numero(addend_2) avrà il valore della variabile che memorizza i riporti
	} while(addend_2 > 0);
	return sum;
}

short binary_sub(short x, short y) {
	/* function che esegue la sottrazione binaria, tenendo conto anche del prestito */
	short sub, loan;
	do { // imposto un costrutto do-while per iterare le operazioni per effettuare la sottrazione completa
		sub = x ^ y; // effettuo un'operazione di XOR per prendere il risultato della sottrazione
		loan = ~x & y; // nego i bit del primo numero esponent poi effettuo un'operazione di AND per controllare i prestiti
		loan <<= 1; // shifto di 1 a sinistra i bit della variabile che memorizza i prestiti
		x = sub; // all'iterazione successiva il primo numero(float_number) avrà il valore della prima sottrazione
		y = loan; // esponent il secondo numero(y) avrà il valore della variabile che memorizza i prestiti
	} while(y > 0);
	return sub;
}

short complemento_a_2(short n_bit, short number) {
	/* function che converte un numero in complemento a due */
	if (number >= 0)
		return number;
	else
		return pow(2, n_bit) + number;
}

short biased(short number, short n_bit) {
	/* function che converte un numero in rappresentazione biased */
	return (pow(2, n_bit-1) - 1 + number);
}

short extract_esponent(int number) {
	/* function che estrae l'esponente di un numero float */
	/* dichiaro una maschera a cui assegno il valore, in esadecimale, che mi permetterà di avere ad 1 tutti i bit
	relativi all'esponente, nella rappresentazione di un floating point */
	int esponent, mask = 0x7f800000;

	esponent = number & mask; // effettuo un'operazione di AND bitwise per estrarre i bit relativi all'esponente
	esponent >>= 23; // shifto a destra di 23 bit le cifre dell'esponente in modo da metterle nei bit meno significativi
	esponent -= bias; // per poi decodificarle dalla rappresentazione biased alla classica rappresentazione decimale

	return (short)esponent;
}

void print_floating(Floating_Point number) {
	printf("Numero floating point di partenza -> %g\n", number.f);
	printf("\tSegno -> %d\n", number.field.sign); // stampo il bit del segno
	// stampo il valore dell'esponente dopo decodifica da bias a decimale
	printf("\tEsponente dopo decodifica da bias -> %d\n", number.field.esponent - bias);
	// stampo il valore della mantissa, che equivale ai numeri dopo la virgola del nostro numero reale di partenza
	printf("\tMantissa -> %g\n", number.field.mantissa / (float)(1 << 23));
}

short search_element(char *array, short size, char key) {
	/* function che data una chiave, esegue la ricerca all'interno di un array
	 * se la chiave è presente, viene ritornata la posizione all'interno dell'array */
	short index;
	for(short i = 0; i < size; i++) {
		if(key == *(array + i)) {
			index = i;
		}
	}
	return index;
}

void print_floating_array(Floating_Point number, char *array, short size_array) {
	short i = size_array - 1, j = 0;
	float b = 0.0f;

	while(i >= 0) {
		if(*(array + i) != '.') {
			b += (*(array + i) - 48) * pow(10, j);
			j++;
		}
		i--;
	}

	number.f = b * pow(10, search_element(array, size_array, '.') * -1);

	printf("Numero floating point di partenza -> %g\n", number.f);
	printf("\tSegno -> %d\n", number.field.sign); // stampo il bit del segno
	// stampo il valore dell'esponente dopo decodifica da bias a decimale
	printf("\tEsponente dopo decodifica da bias -> %d\n", number.field.esponent - bias);
	// stampo il valore della mantissa, che equivale ai numeri dopo la virgola del nostro numero reale di partenza
	printf("\tMantissa -> %g\n", number.field.mantissa / (float)(1 << 23));
}