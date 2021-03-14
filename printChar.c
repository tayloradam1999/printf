#include "holberton.h"

/**
 * printChar - Handles specifier char
 * @arg_list: va_list
 */

int printChar(va_list arg_list, int count)
{
	_putchar(va_arg(arg_list, int) + '\0');
	count++;
	return (count);
}

/**
 * printPercent - Handles specifier %
 * @arg_list: va_list
 */

int printPercent(va_list arg_list, int count)
{
	(void)arg_list;
	_putchar('%');
	count++;
	return (count);
}

/**
 * printString - Handles specifier string
 * @arg_list: va_list
 */

int printString(va_list arg_list, int count)
{
	/* Puts given string into variable my_string */
	char* my_string = va_arg(arg_list, char*);

	int x;
	/* Iterates through string and prints every character */
	for (x = 0; my_string[x] != '\0'; x++)
	{
		_putchar(my_string[x]);
		count++;
	}
	return (count);
}
