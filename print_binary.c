#include "main.h"

/**
 * print_binary - create a function that converts to binary
 * @val: argument to be filled
 * Return: integer
 */

int print_binary(va_list val)
{
	int dex = 0;
	int kal = 0;
	int k, n = 1, b;
	unsigned int numb = va_arg(val, unsigned int);
	unsigned int h;

	for (k = 0; k < 32; k++)
	{
		h = ((n << (32 - k)) & numb);
		if (h >> (31 - k))
			dex = 1;
		if (dex)
		{
			b = h >> (31 - k);
			_putchar(b + 48);
			kal++;
		}
	}
	if (kal == 0)
	{
		kal++;
		_putchar('0');
	}
	return (kal);
}
