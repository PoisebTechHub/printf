#include "main.h"

/**
 * _strlen - function that returns length of string.
 * @str: string pointer
 * Return: 1
 */

int _strlen(char *str)
{
	int k;

	for (k = 0; str[k] != 0; k++)
		;
	return (k);
}

/**
 * _strlencon - function that returns length of string for constant
 * char pointer  to a string
 * @str: string pointer
 * Return: 1
 */

int _strlencon(const char *str)
{
	int k;

	for (k = 0; str[k] != 0; k++)
		;
	return (k);
}
