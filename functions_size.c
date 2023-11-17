#include "main.h"

/**
 * cast_size - computes the size of argument
 * @format: Formatted string to print arguments
 * @k: List of arguments
 *
 * Return: Precision.
 */

int cast_size(const char *format, int *k)
{
	int curr_k = *k + 1;
	int size = 0;

	if (format[curr_k] == 'l')
		size = S_LONG;
	else if (format[curr_k] == 'h')
		size = S_SHORT;

	if (size == 0)
		*k = curr_k - 1;
	else
		*k = curr_k;

	return (size);
}

