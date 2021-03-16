#include "holberton.h"

/**
 * printLowerHex - Converts an int to lowercase hexidecimal
 * @arg_list: Given input
 * @count: How many characters are being outputted
 * Return: count
 */

int printLowerHex(va_list arg_list, int count)
{
	int decNum, rem, i = 0;
	char hexNum[30];
	decNum = (va_arg(arg_list, int));

	while (decNum != 0)
	{
		rem = decNum % 16;
		if (rem < 10)
		{
			rem = rem + 48;
		}
		else
		{
			rem = rem + 55;
		}
		hexNum[i] = rem;
		i++;
		decNum = decNum / 16;
	}

	for (i = i - 1; i >= 0; i--)
	{
		putchar(hexNum[i] + '0');
	}
	return (count);
}
