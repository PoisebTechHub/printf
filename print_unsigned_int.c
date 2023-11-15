#include "main.h"

/**
 * print_unsigned - a function that prints decimal.
 * @args: argument to be printed out.
 * Return: number of decimals printed.
 */

int print_unsigned(va_list args)
{
	unsigned int k = va_arg(args, unsigned int);
	int numb, last = k % 10, inte, exp = 1;
	int m = 1;

	k = k / 10;
	numb = k;

	if (last < 0)
	{
		_putchar('-');
		numb = -numb;
		k = -k;
		last = -last;
		m++;
	}
	if (numb > 0)
	{
		while (numb / 10 != 0)
		{
			exp = exp * 10;
			numb = numb / 10;
		}
		numb = k;
		while (exp > 0)
		{
			inte = numb / exp;
			_putchar(inte + '0');
			numb = numb - (inte * exp);
			exp = exp / 10;
			m++;
		}
	}
	_putchar(last + '0');
	return (m);
}
