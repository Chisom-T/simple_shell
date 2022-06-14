#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: Character that will be written to stdout
 * Return: Upon success how many characters were written.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
