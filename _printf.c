#include "main.h"

/**
 * _printf - chooses the correct function to print.
 * @format: identifier
 * Return: the length of the string.
 */

int _printf(const char * const format, ...)
{
	convert a[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", print_37},
		{"%i", printf_int}, {"%d", printf_deci}, 
		{"%r", print_string_reverse},
		{"%R", print_rot13}, {"%b", print_binary},
		{"%u", print_unsigned},
		{"%o", print_octal}, {"%x", print_hex}, {"%X", print_HEX},
		{"%S", print_STRING_special}, {"%p", print_pointer}
	};

	va_list args;
	int k = 0, m, length = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[k] != '\0')
	{
		m = 13;
		while (m >= 0)
		{
			if (a[m].integer[0] == format[k] && a[m].integer[1] == format[k + 1])
			{
				length += a[m].function(args);
				k = k + 2;
				goto Here;
			}
			m--;
		}
		_putchar(format[k]);
		length++;
		k++;
	}
	va_end(args);
	return (length);
}
