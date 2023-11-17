#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned integer
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: calculates active flags
 * @width: computes width
 * @precision: specifies precision
 * @size: specifies size
 * Return: Number of characters printed.
 */

int print_unsigned_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);

	numb = cast_size_unsigned_int(numb, size);

	if (numb == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[k--] = (numb % 10) + '0';
		numb /= 10;
	}

	k++;

	return (create_unsigned_int(0, k, buffer, flags, width, precision, size));
}


/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int k = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = cast_size_unsigned_int(numb, size);

	if (numb == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[k--] = (numb % 8) + '0';
		numb /= 8;
	}

	if (flags & F_HASH && init_numb != 0)
		buffer[k--] = '0';

	k++;

	return (create_unsigned_int(0, k, buffer, flags, width, precision, size));
}



/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: computes active flags
 * @width: computes width
 * @precision: specifies precision
 * @size: specifies size
 * Return: Number of characters printed
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}



/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_HEX_upper - function prints in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Calculates active flags
 * @width: computes width
 * @precision: specifies precision
 * @size: specifies size
 * Return: Number of characters printed
 */

int print_HEX_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hex - prints a hexadecimal number in lower or upper
 * @types: list of arguments
 * @map: array of values
 * @buffer: buffer array
 * @flags: calculates active flags
 * @flag_ch: computes flag characters
 * @width: calculates width
 * @precision: specifies precision
 * @size: specifies size
 * Return: Number of characters printed
 */

int print_hex(va_list types, char map[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int numb = va_arg(types, unsigned long int);
	unsigned long int init_numb = numb;

	UNUSED(width);

	numb = cast_size_unsigned_int(numb, size);

	if (numb == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (numb > 0)
	{
		buffer[k--] = map[numb % 16];
		numb /= 16;
	}

	if (flags & F_HASH && init_numb != 0)
	{
		buffer[k--] = flag_ch;
		buffer[k--] = '0';
	}

	k++;

	return (create_unsigned_int(0, k, buffer, flags, width, precision, size));
}

