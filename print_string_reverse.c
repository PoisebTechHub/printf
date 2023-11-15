#include "main.h"

/**
 * print_string_reverse - function that prints a string in reverse
 * @args: allocated arguments
 *
 * Return: the string
 */

int print_string_reverse(va_list args)
{

	char *s = va_arg(args, char*);
	int k;
	int m = 0;

	if (s == NULL)
		s = "(null)";
	while (s[m] != '\0')
		m++;
	for (k = m - 1; k >= 0; k--)
		_putchar(s[k]);
	return (m);
}
