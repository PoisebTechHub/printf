#include "main.h"

/**
 * flag_functions - function that calculates active flags
 * @format: Formatted string for arguments
 * @k: take a parameter.
 * Return: Flags:
 */
int flag_functions(const char *format, int *k)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int n, net_k;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (net_k = *k + 1; format[net_k] != '\0'; net_k++)
	{
		for (n = 0; FLAGS_CHAR[n] != '\0'; n++)
			if (format[net_k] == FLAGS_CHAR[n])
			{
				flags |= FLAGS_ARR[n];
				break;
			}

		if (FLAGS_CHAR[n] == 0)
			break;
	}

	*k = net_k - 1;

	return (flags);
}

