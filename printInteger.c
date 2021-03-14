#include "holberton.h"

/**
 *
 *
 *
 */

int printIntHelper(unsigned int num)
{
	int newCount = 0;
	int output;

	if (num == 0)
		return (newCount);
	else
	{
		output = num % 10;
		newCount = printIntHelper(num / 10);
		_putchar(output + '0');
		newCount++;
	}
	return (newCount);
}

/**
 * printInteger - prints any integer
 * @full_int: integer passed in
 * Return: number of bytes used
 */

int printInteger(va_list full_int, int count)
{
	int my_int = (va_arg(full_int, int));

	if (my_int < 0)
	{
		my_int = -my_int;
		_putchar('-');
		count++;
	}

	count += printIntHelper((unsigned int)my_int);
	return (count);
}
