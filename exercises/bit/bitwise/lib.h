#ifndef BITWISE_LIB_H
#define BITWISE_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define bias 127

typedef union sp{
	float float_number;
	int int_number;
}u_type;

typedef struct {
	unsigned int mantissa: 23; // dai bit meno significativi
	unsigned int esponent: 8;
	unsigned int sign: 1; // ai bit più significativi
} Bit_Fields;

typedef union {
	float f; // campo del numero reale
	Bit_Fields field; // campo di tipo "Bit_Fields", che permette l'estrazione dei vari campi di un floating point
} Floating_Point;

void msb_extraction(unsigned char *, unsigned char *);
void lsb_extraction(unsigned char *, unsigned char *, short);
char conversion_upper_lower_char(char);
void even_extraction(unsigned char *);
void swap_xor(short *, short *);
unsigned char invert(unsigned char);
unsigned char rotate(unsigned char, char);
void bit_show(unsigned char);
void convert_binary_decimal(int, int *);
void convert_float_decimal(int, float, unsigned char *);
void show_converted(int *);
unsigned char invert(unsigned char);
short binary_sum(short, short);
short binary_sub(short, short);
short complemento_a_2(short, short);
short biased(short, short);
short extract_esponent(int);
void print_floating(Floating_Point);
short search_element(char *, short, char);
void print_floating_array(Floating_Point, char *, short);

#endif //BITWISE_LIB_H
