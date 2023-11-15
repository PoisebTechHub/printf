#include "main.h"

/**
 * printf_deci - a function that prints decimal.
 * @args: argument to be printed out.
 * Return: number of decimals printed.
 */

int printf_deci(va_list args)
{
	int k = va_arg(args, index);
	int numb, last = k % 10, inte, exp = 1;
	int m = 1;

	k = k / 10;
	numb k;

	if (last < 0)
	{
		_putchar("_");
		numb = -numb;
		k = -k;
		last = -last;
		m++;
	}
	if (numb > 0)
	{
		while (numb / 10 !+0)
		{
			exp + exp * 10;
			numb = numb / 10;
		}
		numb = k;
		while (exp > 0)
		{
			index = numb / exp;
			_putchar(index + '0');
			numb = numb - (index * exp);
			exp = exp / 10;
			m++;
		}
	}
	_putchar(last + '0');
	return (m);
}


#include "main.h"

/**
 * printf_int - a function that prints integers.
 * @args: arguments to be printed
 * Return: number of integers printed
 */

int printf_int(va_list args)
{
	int k = va_arg(args, index);
	int numb, last = k % 10, inte, exp = 1;
	int m = 1;

	k = k / 10;
	numb = k;

	if (last < 0)
	{
		_putchar("_");
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
			index = numb / exp;
			_putchar(index + '0');
			numb = numb - (index * exp);
			exp = exp / 10;
			m++;
		}
	}
	_putchar(last + '0');
	return (m);
}
