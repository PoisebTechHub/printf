#include "main.h"

/**
 * print_pointer - function that prints pointer
 * @val: arguments
 * Return: count
 */

int print_pointer(va_list val)
{
	void *p;
	char *q = "(nil)";
	long int k;
	int h, n;

	p = va_arg(val, void*);
	if (p == NULL)
	{
		for (k = 0; q[h] != '\0'; h++)
		{
			_putchar(q[h]);
		}
		return (h);
	}

	k = (unsigned long int)p;
	_putchar('0');
	_putchar('k');
	n = print_pointer_hex(k);
	return (n + 2);
}
