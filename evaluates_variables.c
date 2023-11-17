#include "main.h"

/**
 * team_printable - checks whether a character is printable
 * @q: character to be evaluated
 *
 * Return: 1 if q is printable, 0 otherwise
 */

int team_printable(char q)
{
	if (q >= 32 && q < 127)
		return (1);

	return (0);
}




/**
 * append_hex_code - function that appends ascci
 * in hexadecimal code
 * @buffer: Array of characters
 * @k: location to start appending
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */

int append_hex_code(char ascii_code, char buffer[], int k)
{
	char map[] = "0123456789ABCDEF";
	/* The hex format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[k++] = '\\';
	buffer[k++] = 'x';

	buffer[k++] = map[ascii_code / 16];
	buffer[k] = map[ascii_code % 16];

	return (3);
}



/**
 * our_digit - checks whether a character is a digit
 * @q: Character to be evaluated
 *
 * Return: 1 if q is a digit, 0 otherwise
 */

int our_digit(char q)
{
	if (q >= '0' && q <= '9')
		return (1);

	return (0);
}



/**
 * cast_size_integer - function that casts an integer to specific size
 * @numb: integers to be casted
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of integer
 */

long int cast_size_integer(long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((short)numb);

	return ((int)numb);
}



/**
 * cast_size_unsigned_int - casts an unsigned integer to specific size
 * @numb: unsigned integers to be casted
 * @size: size of integers to be casted
 *
 * Return: Casted value of integer
 */

long int cast_size_unsigned_int(unsigned long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((unsigned short)numb);

	return ((unsigned int)numb);
}

