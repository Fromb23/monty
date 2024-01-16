#include "monty.h"

/**
 * _strlen - Calculates the length of a string.
 * @s: The input string.
 *
 * Return: The length of the string.
 **/

int _strlen(char *s)
{
	int _len = 0;

	if (s == NULL)
		return (1);

	while (*s != '\0')
	{
		_len++;
		s++;
	}
	return (_len);
}
