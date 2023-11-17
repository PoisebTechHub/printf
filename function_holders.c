#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_print_char - function prints a string
 * @q: char types.
 * @buffer: Buffer array
 * @flags:  Calculates active flags.
 * @width: width of arguument
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: Number of chars printed.
 */

int handle_print_char(char q, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[k++] = q;
	buffer[k] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (k = 0; k < width - 1; k++)
			buffer[BUFF_SIZE - k - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - k - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - k - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}



/************************* WRITE NUMBER *************************/
/**
 * print_strnum - a function that prints a string
 * @num_negative: List of arguments
 * @index: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: computes width.
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: Number of characters printed
 */

int print_strnum(int num_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padd = ' ', add_q = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (num_negative)
		add_q = '-';
	else if (flags & F_PLUS)
		add_q = '+';
	else if (flags & F_SPACE)
		add_q = ' ';

	return (create_number(index, buffer, flags, width, precision,
		length, padd, add_q));
}



/**
 * create_number - create a number using buffer
 * @index: location where the number begins to buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading character
 * @add_q: Extra character
 * Return: Number of created characters
 */
int create_number(int index, char buffer[], int flags, int width,
	int prec, int length, char padd, char add_q)
{
	int k, padd_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0);
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padd = ' ';
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--index] = '0', length++;
	if (add_q != 0)
		length++;
	if (width > length)
	{
		for (k = 1; k < width - length + 1; k++)
			buffer[k] = padd;
		buffer[k] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (add_q)
				buffer[--index] = add_q;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], k - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (add_q)
				buffer[--index] = add_q;
			return (write(1, &buffer[1], k - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (add_q)
				buffer[--padd_start] = add_q;
			return (write(1, &buffer[padd_start], k - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start)));
		}
	}
	if (add_q)
		buffer[--index] = add_q;
	return (write(1, &buffer[index], length));
}

/**
 * create_unsigned - Writes an unsigned integer
 * @num_negative: negative number indicator
 * @index: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: computes Width
 * @precision: specifies precision
 * @size: specifies size
 *
 * Return: Number of created characters
 */

int create_unsigned_int(int num_negative, int index,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1, k = 0;
	char padd = ' ';

	UNUSED(num_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (k = 0; k < width - length; k++)
			buffer[k] = padd;

		buffer[k] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], k));
		}
		else
		{
			return (write(1, &buffer[0], k) + write(1, &buffer[index], length));
		}
	}

	return (write(1, &buffer[index], length));
}

/**
 * create_pointer - a function that creates memory address
 * @buffer: Arrays of characters
 * @index: Index of numbers starting in the buffer
 * @length: Length of variable
 * @width: Wwidth specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @add_q: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of created chars.
 */

int create_pointer(char buffer[], int index, int length,
	int width, int flags, char padd, char add_q, int padd_start)
{
	int k;

	if (width > length)
	{
		for (k = 3; k < width - length + 3; k++)
			buffer[k] = padd;
		buffer[k] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (add_q)
				buffer[--index] = add_q;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], k - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (add_q)
				buffer[--index] = add_q;
			return (write(1, &buffer[3], k - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (add_q)
				buffer[--padd_start] = add_q;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], k - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (add_q)
		buffer[--index] = add_q;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

