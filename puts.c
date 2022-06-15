#include <string.h>
#include <stdio.h>

/**
* _puts - prints a string
* @str: pointer to string
* Return: number of chars written
*/
int _puts(char *str)
{
	int num_of_char = 0;

	if (str)
	{
		for (; *str; str++)
		{
			num_of_char += putchar(*str);
		}
	}
	return (num_of_char);
}
