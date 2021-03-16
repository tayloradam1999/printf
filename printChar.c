#include "holberton.h"

/**
 * printChar - Handles specifier c
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
 * printPercent - Handles specifier %
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
		count += _putchar(my_string[x]);
	}
	return (count);
}

/**
 * printRot13 - Alters input string using rot13
 * @arg_list: Passed string
 * @count: Number of characters printed so far
 * Return: Number of characters printed with this function + count
 */

int printRot13(va_list arg_list, int count)
{
	int x = 0, y = 0;
	char *my_string = va_arg(arg_list, char*);
	char before[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char after[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (my_string == NULL)
		my_string = "(null)";

	for (; my_string[x] != '\0'; x++)
	{
	y = 0;
		while (before[y] != '\0')
		{
			if (my_string[x] == before[y])
			{
				my_string[x] = after[y];
				break;
			}
		}
	}
	return (count);
}
