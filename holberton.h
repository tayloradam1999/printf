#ifndef PRINT_F
#define PRINT_F
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct copy_string {
	char input;
	int (*f)(va_list, int count);
} copy_string;

int printChar(va_list, int count);
int printPercent(va_list, int count);
int printInteger(va_list full_int, int count);
int _printf(const char *format, ...);
int _putchar(char c);
int printString(va_list arg_list, int count);
int printIntHelper(unsigned int num);
#endif
