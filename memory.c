#include "shell.h"

/**
 * bfree - NULLizes the address and releases a pointer
 * @ptr: address of the free pointer
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
