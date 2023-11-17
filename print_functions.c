#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * team_pointer - function that prints the value of a pointer
 * @types: arguments
 * @buffer: Buffer array
 * @flags: computes active flags
 * @width: computes width
 * @precision: specifies precision
 * @size: specifies size
 * Return: number of characters printed
 */

int team_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char add_q = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long numb_address;
	char map[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	numb_address = (unsigned long)address;

	while (numb_address > 0)
	{
		buffer[index--] = map[numb_address % 16];
		numb_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		add_q = '+', length++;
	else if (flags & F_SPACE)
		add_q = ' ', length++;

	index++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (create_pointer(buffer, index, length,
		width, flags, padd, add_q, padd_start));
}




/************************* PRINT NON PRINTABLE *************************/
/**
 * print_non_printable - function prints ascii codes in hex
 * of non printable chars
 * @types: list of arguments
 * @buffer: Buffer array of print
 * @flags:  computes active flags
 * @width: computes width
 * @precision: specifies precision
 * @size: specifies size
 * Return: number of characters printed
 */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 0, offset = 0;
	char *strp = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (strp == NULL)
		return (write(1, "(null)", 6));

	while (strp[k] != '\0')
	{
		if (team_printable(strp[k]))
			buffer[k + offset] = strp[k];
		else
			offset += append_hex_code(strp[k], buffer, k + offset);

		k++;
	}

	buffer[k + offset] = '\0';

	return (write(1, buffer, k + offset));
}




/************************* PRINT REVERSE *************************/
/**
 * print_reverse_string - function that prints reverse string
 * @types: list of arguments
 * @buffer: buffer array
 * @flags: computes active flags
 * @width: computes width
 * @precision: specifies precision
 * @size: specifies size
 * Return: number of characters printed
 */

int print_reverse_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *strp;
	int k, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	strp = va_arg(types, char *);

	if (strp == NULL)
	{
		UNUSED(precision);

		strp = ")Null(";
	}
	for (k = 0; strp[k]; k++)
		;

	for (k = k - 1; k >= 0; k--)
	{
		char q = strp[k];

		write(1, &q, 1);
		count++;
	}
	return (count);
}



/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char q;
	char *strp;
	unsigned int k, m;
	int compute = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	strp = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (strp == NULL)
		strp = "(AHYY)";
	for (k = 0; strp[k]; k++)
	{
		for (m = 0; in[m]; m++)
		{
			if (in[m] == strp[k])
			{
				q = out[m];
				write(1, &q, 1);
				compute++;
				break;
			}
		}
		if (!in[m])
		{
			q = strp[k];
			write(1, &q, 1);
			compute++;
		}
	}
	return (compute);
}
