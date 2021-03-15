#include "holberton.h"

/**
 * printIntHelper - Recursive function for printing integer
 * @num: Integer to print
 * Return: character printing counter inside recursive function
 */

int printIntHelper(unsigned int num)
{
	int newCount = 0;
	int output;

	if (num == 0)
		return (newCount);

	else
	{
		/* Strips last digit of integer */
		output = num % 10;
		/* Sends back the integer minus last digit for recursion */
		newCount = printIntHelper(num / 10);
		/* Putting digits in order */
		_putchar(output + '0');
		newCount++;
	}
	return (newCount);
}

/**
 * printInteger - Calls recursive function
 * @arg_list: full integer passed in by _printf
 * @count: number of characters printed so far
 * Return: count of characters printed so far plus integers printed
 */

int printInteger(va_list arg_list, int count)
{
	/* Puts value of arg_list into my_int */
	int my_int = (va_arg(arg_list, int));

	if (my_int == 0)
	{
		_putchar(0 + '0');
		count++;
		return (count);
	}

	if (my_int < 0)
	{
		my_int = my_int * -1;
		_putchar('-');
		count++;
	}
	/* Casts as unsigned to account for positive INT_MIN */
	count += printIntHelper((unsigned int)my_int);
	return (count);
}
