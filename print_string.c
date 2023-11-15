#include "main.h"

/**
 *printf_string - a function that prints string.
 *@val: takes argument.
 *Return: Length of the string to be printed.
 */

int printf_string(va_list val)
{
	char *str;
	int k;
	int length;

	str = va_arg(val, char *);
	if (str == NULL)
	{
		str = "(null)";
		length = _strlen(str);
		for (k = 0; k < length; k++)
			_putchar(str[k]);
		return (length);
	}
	else
	{
		length = _strlen(str);
		for (k = 0; k < length; k++)
			_putchar(str[k]);
		return (length);
	}
}
