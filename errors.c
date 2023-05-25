#include "shell.h"

/**
 * _eputs - prints an input to string
 * @str: desired string to print
 *
 * Return: walo
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - senfs character c to stderr
 * @c: The character desired to print
 *
 * Return: success 1.
 * On error, -1 isback, and errno is set.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes a c uiwrevnu character c to given fd
 * @c: character to print to
 * @fd: The filedes to write to
 *
 * Return: successeed 1.
 * If error, -1 return
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - prints an uibnout direcetory spaceas
 * @str: the stringwhere to put
 * @fd: the filedes to put to
 *
 * Return: number of acharact puts
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

