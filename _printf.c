#include "main.h"

void team_print_buffer(char buffer[], int *buff_index);

/**
 * _printf - creates Printf function
 * @format: format of function
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int k, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (k = 0; format && format[k] != '\0'; k++)
	{
		if (format[k] != '%')
		{
			buffer[buff_index++] = format[k];
			if (buff_index == BUFF_SIZE)
				team_print_buffer(buffer, &buff_index);
			printed_chars++;
		}
		else
		{
			team_print_buffer(buffer, &buff_index);
			flags = flag_functions(format, &k);
			width = functions_width(format, &k, list);
			precision = functions_precision(format, &k, list);
			size = cast_size(format, &k);
			++k;
			printed = handle_team_print(format, &k, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	team_print_buffer(buffer, &buff_index);

	va_end(list);

	return (printed_chars);
}



/**
 * team_print_buffer - Prints the contents of the buffer
 * @buffer: Array of characters
 * @buff_index: location at which to add next char
 */

void team_print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}

