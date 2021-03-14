#include "holberton.h"
#include <unistd.h>

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 * Return: 1 on success, -1 on error
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - Returns the length of a string
 * @s: String
 * Return: Length
 */

int _strlen(char *s)
{
	int x = 0;

	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}
