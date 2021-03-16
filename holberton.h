#ifndef PRINT_F
#define PRINT_F

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/**
 * struct print_all - struct that pairs specifier with function pointer
 * @input: character after %
 * @f: printing function associated
 */

typedef struct print_all
{
	/* Character that comes after % for matching */
	char input;
	/* Function pointer to printing functions */
	int (*f)(va_list, int count);
} print_all;

int _putchar(char c);
int printChar(va_list, int count);
int printString(va_list arg_list, int count);
int printPercent(va_list, int count);
int printInteger(va_list arg_list, int count);
int printIntHelper(unsigned int num);
int printUnsignedInt(va_list arg_list, int count);
int printBinary(va_list arg_list, int count);
int printOctal(va_list arg_list, int count);
int printLowerHex(va_list arg_list, int count);
int printUpperHex(va_list arg_list, int count);
int printRot13(va_list arg_list, int count);

int _printf(const char *format, ...);
int parser(const char *format, va_list arg_list, print_all chooseF[],
	   int struct_index, int *string_index);

#endif
