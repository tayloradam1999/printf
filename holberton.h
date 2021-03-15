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
	char input; /* Corresponding character that comes after % */
	int (*f)(va_list, int count); /* Function pointer to printing functions */
} print_all;

int _putchar(char c);

int printChar(va_list, int count);
int printString(va_list arg_list, int count);
int printPercent(va_list, int count);
int printInteger(va_list arg_list, int count);
int printIntHelper(unsigned int num);

int _printf(const char *format, ...);
int parser(const char *format, va_list arg_list, print_all chooseF[],
	   int struct_index, int *string_index);

#endif
