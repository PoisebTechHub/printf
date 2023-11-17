#include "main.h"
/**
 * handle_team_print - function that prints arguments
 * @format: formatted string of arguments
 * @list: list of arguments
 * @index: location to be printed
 * @buffer: Buffer array to handle print
 * @flags: computes active flags
 * @width: computes width
 * @precision: specifies precision
 * @size: specifies size
 * Return: 1 or 2;
 */

int handle_team_print(const char *format, int *index, va_list list,
	char buffer[], int flags, int width, int precision, int size)
{
	int k, unknown_length = 0, printed_chars = -1;
	format_t format_types[] = {
		{'c', print_characters}, {'s', print_string}, {'%', print_percent},
		{'i', print_integer}, {'d', print_integer}, {'b', print_binary},
		{'u', print_unsigned_int}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_HEX_upper}, {'p', team_pointer}, {'S', print_non_printable},
		{'r', print_reverse_string}, {'R', print_rot13}, {'\0', NULL}
	};
	for (k = 0; format_types[k].format != '\0'; k++)
		if (format[*index] == format_types[k].format)
			return (format_types[k].fn(list, buffer, flags, width, precision, size));

	if (format_types[k].format == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		unknown_length += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			unknown_length += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		unknown_length += write(1, &format[*index], 1);
		return (unknown_length);
	}
	return (printed_chars);
}

