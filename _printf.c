#include "holberton.h"

/**
 * _printf - Prints anything
 * @format: Full string passed to function
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int struct_index, string_index = 0, count = 0, x = 0;
	print_all chooseF[] = {
		{'c', printChar}, {'s', printString}, {'%', printPercent},
		{'d', printInteger}, {'i', printInteger}, {'u', printUnsignedInt},
		{'b', printBinary}, {'x', printLowerHex}, {'X', printUpperHex},
		{'o', printOctal}, {'R', printRot13}, {'r', printReverse},
		{'\0', NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	/* Iterating through the given string */
	while (format != NULL && format[string_index] != '\0')
	{
		struct_index = 0;
			/* When the iterator encounters %, jump to parser function */
			/* x is the return value of the corresponding function */
			if (format[string_index] == '%')
			{
				x = parser(format, arg_list, chooseF, struct_index, &string_index);
				if (x == -1)
					return (-1); /* -1 if no spec after % */
				count += x;
			}
			/* If no % is found, prints string as is */
			else
				count += _putchar(format[string_index]);
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
	/* if there is no char after %, output -1 */
	if (format[*string_index + 1] == '\0')
		return (-1);
	/* Iterating through our array of structs */
	while (chooseF[struct_index].input != '\0')
	{
		/* Iterating until matching specifier is found */
		if (format[*string_index + 1] == chooseF[struct_index].input)
		{
			/* Jumps to function that deals with specifier */
			count = chooseF[struct_index].func_pointer(arg_list, count);
			(*string_index)++;
			break;
		}
		struct_index++;
	}
	/* If no match found, prints % */
	if (chooseF[struct_index].input == '\0')
	{
		_putchar(format[*string_index]);
		count++;
	}
	return (count);
}

/**
 * _putchar - Writes single character to stdout
 * @c: The character to print
 * Return: Number of characters printed (meaning 1 on success)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
