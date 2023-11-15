#include "main.h"

/**
 *_putchar - a function that writes the character c to stdout.
 *@c: the character to be printed.
 *Return: 1 success, if not -1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
