#include "main.h"

/**
 * print_STRING_special - function that prints special string
 * @val: value
 * Return: number of variables printed
 */

int print_STRING_special(va_list val)
{
	char *s;
	int k, length = 0;
	int value;

	s = va_arg(val, char *);
	if (s == NULL)
		s = "(null)";
	for (k = 0; s[k] != '\0'; k++)
	{
		if (s[k] < 32 || s[k] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			length = length + 2;
			value = s[k];
			if (value < 16)
			{
				_putchar('0');
				length++;
			}
			length = length + print_STRING_HEX(value);
		}
		else
		{
			_putchar(s[k]);
			length++;
		}
	}
	return (length);
}
