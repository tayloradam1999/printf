#include "holberton.h"

/**
 * _printf - Prints anything
 * @format: List of types of arguments passed to function
 * @Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	int struct_index, string_index = 0, count = 0;
	copy_string chooseF[] = {
		{'c', printChar},
		{'s', printString},
		{'%', printPercent},
		{'d', printInteger},
		{'i', printInteger},
		{'\0', NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	while (format != NULL && *(format + string_index) != '\0')
	{
		struct_index = 0;
			if (*(format + string_index) == '%')
			{
				while (chooseF[struct_index].input != '\0')
				{
					if (format[string_index + 1] == chooseF[struct_index].input)
					{
						count = chooseF[struct_index].f(arg_list, count);
						string_index++;
						break;
					}
					struct_index++;
				}
				if (chooseF[struct_index].input == '\0')
				{
					_putchar(format[string_index]);
					count++;
				}
			}
			else
			{
				_putchar(format[string_index]);
				count++;
			}
		string_index++;
	}
	va_end(arg_list);
	return (count);
}
