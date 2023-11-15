#include "main.h"

/**
 * print_octal - a function that converts to octal
 * @val: arguments to be filled
 * Return: count
 */

int print_octal(va_list val)
{
	int k, count = 0;
	int *array;
	unsigned int numb = va_arg(val, unsigned int);
	unsigned int net = numb;

	while (numb / 8 != 0)
	{
		numb = numb / 8;
		count++;
	}
	count++;
	array = malloc(sizeof(int) * count);
	for (k = 0; k < count; k++)
	{
		array[k] = net % 8;
		net = net / 8;
	}
	for (k = count - 1; k >= 0; k--)
		_putchar(array[k] + '0');
	free(array);
	return (count);
}
