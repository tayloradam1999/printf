#include "holberton.h"

/**
 * printChar - Handles specifier c
 * @arg_list: whatever character matches %c
 * @count: number of characters printed so far
 * Return: number of characters printed so far + 1
 */

int printChar(va_list arg_list, int count)
{
	char c = va_arg(arg_list, int);

	if (c != '\0')
	{
		_putchar(c);
		count++;
	}

	return (count);
}

/**
 * printPercent - Handles specifier %
 * @arg_list: it will be a %
 * @count: number of characters printed so far
 * Return: number of characters printed so far + 1
 */

int printPercent(va_list arg_list, int count)
{
	int p = va_arg(arg_list, int);

	if (p != '\0')
	{
		_putchar('%');
		count++;
	}
	return (count);
}

/**
 * printString - Handles specifier s
 * @arg_list: whatever string matches %s
 * @count: number of characters printed so far
 * Return: number of characters printed with this function + count
 */

int printString(va_list arg_list, int count)
{
	int x;

	/* Puts given string into variable my_string */
	char *my_string = va_arg(arg_list, char*);

	if (my_string == NULL)
		my_string = "(null)";

	/* Iterates through string and prints every character */
	for (x = 0; my_string[x] != '\0'; x++)
	{
		_putchar(my_string[x]);
		count++;
	}
	return (count);
}
