#include "shell.h"

/**
 * handler - Handles crtl c signal
 * @num: signal
 * Return: void
 */
void handler(int num)
{
	(void)num;
	_puts("\n#cisfun$ ");
}
