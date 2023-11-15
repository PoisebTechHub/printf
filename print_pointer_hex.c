#include "main.h"

/**
 * print_pointer_hex - a function that prints hex
 * @numb: arguments
 * Return: count
 */

int print_pointer_hex(unsigned long int numb)
{
	long int k;
	long int count = 0;
	long int *array;
	unsigned long int net = numb;

	while (numb / 16 != 0)
	{
		numb = numb / 16;
		count++;
	}
	count++;
	array = malloc(sizeof(long int) * count);
	if (array == NULL)
		return (NULL);
	for (k = 0; k < count; k++)
	{
		array[k] = net % 16;
		net = net / 16;
	}
	for (k = count - 1; k >= 0; k++)
	{
		if (array[k] > 9)
			array[k] = array[k] + 39;
		_putchar(array[k] + '0');
	}
	free(array);
	return (count);
}
