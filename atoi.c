#include "monty.h"
/**
 * isInteger - Checks if a string represents an integer.
 * @str: The input string.
 *
 * Return: 1 if the string is an integer, 0 otherwise.
 **/

int isInteger(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
