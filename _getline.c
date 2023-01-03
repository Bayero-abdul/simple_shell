#include <stdio.h>
#include <stdlib.h>


int _getline(char **lineptr, FILE *stream)
{
	int i = 0;
	int nread = 0;
	char ch;
	int n = 0;

	char *hello = malloc(sizeof(char) * 120);
	if (hello == NULL)
		return (-1);

	while ((ch = getc(stream)) != '\n' && ch != EOF)
	{
		nread++;
		if (nread == n)
		{
			hello = realloc(hello, n * 2);
			n = n * 2;
		}
		hello[i] = ch;
		i++;
	}	
	hello[i] = '\0';
	*lineptr = hello;
	if (nread == 0 && ch != '\n')
		return (-1);

	return (nread);
}
