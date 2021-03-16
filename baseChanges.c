#include "holberton.h"

/**
 * printBinary - Converts unsigned int to binary
 * @arg_list: Given input
 * @count: characters printed until now
 * Return: total characters printed after this
 */

int printBinary(va_list arg_list, int count)
{
	unsigned int decNum;
	int digit = 0;
	int binaryNum[30];

	decNum = (unsigned int)(va_arg(arg_list, int));

	if (decNum == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	/* finds binaryNum and stores in reverse order */
	while (decNum != 0)
	{
		binaryNum[digit] = decNum % 2;
		decNum = decNum / 2;
		digit++;
	}
	/* prints reversed digits in reverse */
	for (digit = digit - 1; digit >= 0; digit--)
	{
		_putchar(binaryNum[digit] + '0');
		count++;
	}
	return (count);
}

/**
 * printOctal - Converts unsigned int to octal number
 * @arg_list: Given input
 * @count: characters printed until now
 * Return: total characters printed after this
*/

int printOctal(va_list arg_list, int count)
{
	unsigned int decNum;
	int digit = 0;
	int octalNum[30];

	decNum = (unsigned int)(va_arg(arg_list, int));

	if (decNum == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	/* finds octalNum and stores in reverse order */
	while (decNum != 0)
	{
		octalNum[digit] = decNum % 8;
		decNum = decNum / 8;
		digit++;
	}
	/* prints reversed digits in reverse */
	for (digit = digit - 1; digit >= 0; digit--)
	{
		_putchar(octalNum[digit] + '0');
		count++;
	}
	return (count);
}


/**
 * printLowerHex - Converts unsigned int to lowercase hexidecimal
 * @arg_list: Given input
 * @count: characters printed until now
 * Return: total characters printed after this
 */

int printLowerHex(va_list arg_list, int count)
{
	unsigned int decNum;
	int remainder, digit = 0;
	char hexNum[30];

	decNum = (unsigned int)(va_arg(arg_list, int));
	/* find hexNum and stores in reverse order */

	if (decNum == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	while (decNum != 0)
	{
		remainder = decNum % 16;
		/* '0' is 48 so under 10 add to get 0-9 */
		if (remainder < 10)
		{
			remainder = remainder + 48;
		}
		/* 'a' is 97 so over 10 add to get a-f */
		else
		{
			remainder = remainder + 87;
		}
		hexNum[digit] = remainder;
		digit++;
		decNum = decNum / 16;
	}
	/* prints reversed digits in reverse */
	for (digit = digit - 1; digit >= 0; digit--)
	{
		_putchar(hexNum[digit]);
		count++;
	}
	return (count);
}

/**
 * printUpperHex - Converts unsigned int to uppercase hexidecimal
 * @arg_list: Given input
 * @count: characters printed until now
 * Return: total characters printed after this
 */

int printUpperHex(va_list arg_list, int count)
{
	unsigned int decNum;
	int remainder, digit = 0;
	char hexNum[30];

	decNum = (unsigned int)(va_arg(arg_list, int));

	if (decNum == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	/* finds hexNum and stores in reverse order */
	while (decNum != 0)
	{
		remainder = decNum % 16;
		/* '0' is 48 so under 10, add 48 to get 0-9 */
		if (remainder < 10)
		{
			remainder += 48;
		}
		/* 'A' is 65 so over 10 add 55 to get A-F */
		else
		{
			remainder += 55;
		}
		hexNum[digit] = remainder;
		digit++;
		decNum = decNum / 16;
	}
	/* prints reversed digits in reverse */
	for (digit = digit - 1; digit >= 0; digit--)
	{
		_putchar(hexNum[digit]);
		count++;
	}
	return (count);
}
