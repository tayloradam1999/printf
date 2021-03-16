#include "holberton.h"

/**
 * printLowerHex - Converts an int to lowercase hexidecimal
 * @arg_list: Given input
 * @count: How many characters are being outputted
 * Return: count
 */

int printLowerHex(va_list arg_list, int count)
{
	unsigned int decNum;
	int rem, i = 0;
	char hexNum[30];

	decNum = (unsigned int)(va_arg(arg_list, int));

	while (decNum != 0)
	{
		rem = decNum % 16;
		if (rem < 10)
		{
			rem = rem + 80; /* 'a' is 97 */
		}
		else
		{
			rem = rem + 87; /* 'f' is 102 */
		}
		hexNum[i] = rem;
		i++;
		decNum = decNum / 16;
	}

	for (i = i - 1; i >= 0; i--)
	{
		_putchar(hexNum[i]);
		count++;
	}
	return (count);
}

/**
 * printUpperHex - Converts an int to uppercase hexidecimal
 * @arg_list: Given input
 * @count: characters printed until now
 * Return: total characters printed so far
 */

int printUpperHex(va_list arg_list, int count)
{
	unsigned int decNum;
	int remainder, i = 0;
	char hexNum[30];

	decNum = (unsigned int)(va_arg(arg_list, int));

	while (decNum != 0)
	{
		remainder = decNum % 16;
		if (remainder < 10)
		{
			remainder += 48; /* 'A' is 65 */
		}
		else
		{
			remainder += 55; /* 'F' is 70 */
		}
		hexNum[i] = remainder;
		i++;
		decNum = decNum / 16;
	}
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(hexNum[i]);
		count++;
	}
	return (count);
}
