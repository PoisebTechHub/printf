#include "main.h"

/**
 * print_rot13 - convert to rot13
 * @args: arguments to be cilled
 * Return: count
 */

int print_rot13(va_list args)
{
	int q, m, count = 0;
	int k = 0;
	char *s = va_arg(args, char*);
	char ab[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char cd[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (q = 0; s[q]; q++)
	{
		k = 0;
		for (m = 0; ab[m] && !k; m++)
		{
			if (s[q] == ab[m])
			{
				_putchar(cd[m]);
				count++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(s[q]);
			count++;
		}
	}
	return (count);
}
