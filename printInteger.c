#include "holberton.h"

/**
 * printIntHelper - Recursive function for printing integer
 * @num: Integer to print
 * Return: newCount
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
 * @full_int: integer passed in
 * Return: count
 */

int printInteger(va_list full_int, int count)
{
	/* Puts value of full_int into my_int */
	int my_int = (va_arg(full_int, int));

	if (my_int < 0)
	{
		my_int = -my_int;
		_putchar('-');
		count++;
	}
	/* Casts as unsigned to account for positive INT_MIN */
	count += printIntHelper((unsigned int)my_int);
	return (count);
}
