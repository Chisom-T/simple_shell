#include "main.h"

/**
 * print_num - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_num(int n)
{
	int div, len;
	unsigned int num;

	div = 1;
	len = 0;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _putchar('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}


/**
 * _strcmp - compares two strings
 * @s1: First string param
 * @s2: Second string param
 * Return: int
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	if (_strlen(s1) != _strlen(s2))
		return (-1);
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 * _strdup - create a copy of a string
 * @src: param
 * Return: char
 */

char *_strdup(char *src)
{
	int i;
	int len;
	char *dest;

	len = _strlen(src);
	dest = malloc(sizeof(char) * (len + 1));

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * print_str - Prints a string character by character to STDOUT
 * @str: param
 */

void print_str(char *str, int new_line)
{
	int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		write(STDOUT_FILENO, &str[i], 1);

	if (new_line == 0)
		write(STDOUT_FILENO, "\n", 1);
}
