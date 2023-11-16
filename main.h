#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct format - converter for the function of printf
 * @integer: type char pointer of the specifier
 * @function: function for the conversion specifier
 *
 */

typedef struct format
{
	char *integer;
	int (*function)();
} convert;

int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list val);
int printf_string(va_list val);
int _strlen(char *str);
int _strlencon(const char *str);
int print_37(void);
int printf_deci(va_list args);
int printf_int(va_list args);
int print_binary(va_list val);
int print_unsigned(va_list args);
int print_octal(va_list val);
int print_hex(va_list val);
int print_HEX(va_list val);
int print_STRING_HEX(unsigned int numb);
int print_STRING_special(va_list val)`;
int print_pointer(va_list val);
int print_pointer_hex(unsigned long int numb);
int print_string_reverse(va_list args);
int print_rot13(va_list args)i;

#endif
