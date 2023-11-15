#include "main.h"

/**
 * print_HEX - a function that converts to HEX in capitals
 * @val: variables to be converted
 * Return: count
 */

int print_HEX(va_list val)
{
	int k, count = 0;
	int *array;
	unsigned int numb = va_arg(val, unsigned int);
	unsigned int net = numb;

	while (numb / 16 != 0)
	{
		numb = numb / 16;
		count++;
	}
	count++;
	array = malloc(sizeof(int) * count);
	for (k = 0; k < count; k++)
	{
		array[k] = net % 16;
		net = net / 16;
	}
	for (k = count - 1; k >= 0; k--)
	{
		if (array[k] > 9)
			array[k] = array[k] + 7;
		_putchar(array[k] + '0');
	}
	free(array);
	return (count);
}
