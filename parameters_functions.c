#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_characters - function that prints characters
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: computes active flags
 * @width: computes Width
 * @precision: specifies precision
 * @size: specifies size
 * Return: number of characters printed
 */

int print_characters(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char q = va_arg(types, int);

	return (handle_print_char(q, buffer, flags, width, precision, size));
}



/************************* PRINT A STRING *************************/
/**
 * print_string - function that prints a string
 * @types: list arguments
 * @buffer: Buffer array
 * @flags: computes active flags
 * @width: computes width.
 * @precision: specifies precision
 * @size: specifies size
 * Return: number of characters printed
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, k;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (k = width - length; k > 0; k--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (k = width - length; k > 0; k--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}



/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - function that prints a percent sign
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: computes active flags
 * @width: computes width.
 * @precision: specifies precision
 * @size: specifies size
 * Return: Number of characters printed
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}



/************************* PRINT INT *************************/
/**
 * print_integer - function that prints integers
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: computes active flags
 * @width: computes width.
 * @precision:cspecifies precision
 * @size: specifies size
 * Return: number of characters printed
 */

int print_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	int num_negative = 0;
	long int j = va_arg(types, long int);
	unsigned long int numb;

	j = cast_size_integer(j, size);

	if (j == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)j;

	if (j < 0)
	{
		numb = (unsigned long int)((-1) * j);
		num_negative = 1;
	}

	while (numb > 0)
	{
		buffer[k--] = (numb % 10) + '0';
		numb /= 10;
	}

	k++;

	return (print_strnum(num_negative, k, buffer, flags, width, precision, size));
}



/************************* PRINT BINARY *************************/
/**
 * print_binary - Pfunction that prints an unsigned integer
 * @types: list of arguments
 * @buffer: Buffer array
 * @flags: computes active flags
 * @width: compute width.
 * @precision: specificies precision
 * @size: specifies size
 * Return: Number of characters printed.
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int y, w, k, sum;
	unsigned int j[32];
	int compute;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	y = va_arg(types, unsigned int);
	w = 2147483648; /* (2 ^ 31) */
	j[0] = y / w;
	for (k = 1; k < 32; k++)
	{
		w /= 2;
		j[k] = (y / w) % 2;
	}
	for (k = 0, sum = 0, compute = 0; k < 32; k++)
	{
		sum += j[k];
		if (sum || k == 31)
		{
			char z = '0' + j[k];

			write(1, &z, 1);
			compute++;
		}
	}
	return (compute);
}
