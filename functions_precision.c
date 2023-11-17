#include "main.h"

/**
 * functions_precision - Calculates the precision for printing a function
 * @format: Formatted string in which to print the arguments
 * @k: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int functions_precision(const char *format, int *k, va_list list)
{
	int net_k = *k + 1;
	int precision = -1;

	if (format[net_k] != '.')
		return (precision);

	precision = 0;

	for (net_k += 1; format[net_k] != '\0'; net_k++)
	{
		if (our_digit(format[net_k]))
		{
			precision *= 10;
			precision += format[net_k] - '0';
		}
		else if (format[net_k] == '*')
		{
			net_k++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*k = net_k - 1;

	return (precision);
}

