#include "monty.h"

/**
 * custom_strtok - custom implementation of strtok function
 *
 * @str: the string to tokenize
 * @delim: the delimeter characters
 *
 * Return: pointer to the next token in the string
 * or NULL if no more tokens
 */

char *custom_strtok(char *str, const char *delim)

{
	static char *current;
	char *start, *end;

	if (str != NULL)
	{
		current = str;
	}

	if (current == NULL || *current == '\0')
	{
		return (NULL);
	}

	while (*current != '\0' && strchr(delim, *current) != NULL)
	{
		++current;
	}
	if (*current == '\0')
	{
		return (NULL);
	}

	start = current;
	end = strpbrk(start, delim);

	if (end == NULL)
	{
		current += strlen(start);
	}
	else
	{
		*end = '\0';
		current = end + 1;
	}
	return (start);
}
