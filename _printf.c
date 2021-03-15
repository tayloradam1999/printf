#include "holberton.h"

/**
 * _printf - Prints anything
 * @format: Full string passed to function
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int struct_index, string_index = 0, count = 0;
	print_all chooseF[] = {
		{'c', printChar},
		{'s', printString},
		{'%', printPercent},
		{'d', printInteger},
		{'i', printInteger},
		{'\0', NULL}
	};
	va_list arg_list;
	/* If statement to throw error */
	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	/* Iterating through the given string */
	while (format != NULL && format[string_index] != '\0')
	{
		struct_index = 0;
			/* When the iterator encounters %, jump to parser function */
			if (format[string_index] == '%')
			{
				count += parser(format, arg_list, chooseF, struct_index, &string_index);
			}
			/* If no % is found, prints string as is */
			else
			{
				count += _putchar(format[string_index]);
			}
		string_index++;
	}
	va_end(arg_list);
	return (count);
}

/**
 * parser - Chooses function pointer that matches specifier char after %
 * @format: Given string - looking at c, d, non-specifier, etc
 * @arg_list: Arguments passed - passing in whatever matches %d, etc
 * @chooseF: Name of our array of structs
 * @struct_index: Moves through the array of structs
 * @string_index: Moves through format
 * Return: Count
 */

int parser(const char *format, va_list arg_list, print_all chooseF[],
	   int struct_index, int *string_index)
{
	int count = 0;
	/* Iterating through our array of structs */
	while (chooseF[struct_index].input != '\0')
	{
		/* Iterating finds corresponding conversion specifier */
		if (format[*string_index + 1] == chooseF[struct_index].input)
		{
			/* Jumps to function that deals with specifier */
			count = chooseF[struct_index].f(arg_list, count);
			(*string_index)++;
			break;
		}
		struct_index++;
	}
	/* If no match found, prints character after % */
	if (chooseF[struct_index].input == '\0')
	{
		_putchar(format[*string_index]);
		count++;
	}
	return (count);
}
