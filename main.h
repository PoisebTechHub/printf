#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct op
 *
 * @format: The format.
 * @fn: The function associated.
 */

struct format
{
	char format;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_t - Struct op
 *
 * @format: The format.
 * @forma_t: The function associated.
 */

typedef struct format format_t;

int _printf(const char *format, ...);
int handle_team_print(const char *format, int *k,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_characters(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_integer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffeir[],
	int flags, int width, int precision, int size);
int print_HEX_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hex(va_list types, char map[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int team_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int flag_functions(const char *format, int *k);
int functions_width(const char *format, int *k, va_list list);
int functions_precision(const char *format, int *k, va_list list);
int cast_size(const char *format, int *k);

/*Function to print string in reverse*/
int print_reverse_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_print_char(char q, char buffer[],
	int flags, int width, int precision, int size);
int print_strnum(int num_negative, int index, char buffer[],
	int flags, int width, int precision, int size);
int create_number(int index, char buffer[], int flags, int width,
	int prec, int length, char padd, char add_q);
int create_pointer(char buffer[], int index, int length,
	int width, int flags, char padd, char add_q, int padd_start);

int create_unsigned_int(int num_negative, int index, char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int team_printable(char);
int append_hex_code(char, char[], int);
int our_digit(char);

long int cast_size_integer(long int numb, int size);
long int cast_size_unsigned_int(unsigned long int numb, int size);

#endif

