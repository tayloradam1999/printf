#include "holberton.h"

/**
 * printChar - Handles specifier c and prints single character
 * @arg_list: whatever character matches %c
 * @count: number of characters printed so far
 * Return: number of characters printed so far + 1 for the new line
 */

int printChar(va_list arg_list, int count)
{
	_putchar(va_arg(arg_list, int));
	count++;

	return (count);
}

/**
 * printPercent - Handles specifier % and prints %
 * @arg_list: it will be a %
 * @count: number of characters printed so far
 * Return: number of characters printed so far + 1 for the new line
 */

int printPercent(va_list arg_list, int count)
{
	(void)arg_list;
	_putchar('%');
	count++;
	return (count);
}

/**
 * printString - Handles specifier s and prints strings
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
		count += _putchar(my_string[x]);
	}
	return (count);
}

/**
 * printRot13 - Handles specifier R and prints string in rot13
 * @arg_list: whatever string matches %R
 * @count: number of characters printed so far
 * Return: number of characters printed with this function + count
 */

int printRot13(va_list arg_list, int count)
{
	char *c = va_arg(arg_list, char*);
	int output, x;

	if (c == NULL)
	{
		c = "(null)";
		for (x = 0; c[x] != '\0'; x++)
			count += _putchar(c[x]);
	}
	for (x = 0; c[x] != '\0'; x++)
	{
		/* converts capital chars - A-M + 13 and N-Z - 13 */
		if (c[x] >= 'A' && c[x] <= 'Z')
		{
		output = c[x] + 13;
			if (output <= 'Z')
				count += _putchar(output);
			else
			{
				output = c[x] - 13;
				count += _putchar(output);
			}
		}
		/* converts lowercase chars - a-m + 13 and n-z - 13 */
		else if (c[x] >= 'a' && c[x] <= 'z')
		{
		output = c[x] + 13;
			if (c[x] + 13 <= 'z')
				count += _putchar(output);
			else
			{
				output = c[x] - 13;
				count += _putchar(output);
			}
		}
		/* if not character, prints value */
		else
			count += _putchar(c[x]);
	}
	return (count);
}
