#include "main.h"

/**
 * functions_width - Calculates the width of arguments for printing
 * @format: Formatted string of arguments.
 * @k: arguments.
 * @list: list of arguments.
 *
 * Return: width.
 */

int functions_width(const char *format, int *k, va_list list)
{
	int net_k;
	int width = 0;

	for (net_k = *k + 1; format[net_k] != '\0'; net_k++)
	{
		if (our_digit(format[net_k]))
		{
			width *= 10;
			width += format[net_k] - '0';
		}
		else if (format[net_k] == '*')
		{
			net_k++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*k = net_k - 1;

	return (width);
}

