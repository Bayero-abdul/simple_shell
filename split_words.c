#include "shell.h"

int count_words(char *str, char del)
{
	int i = 0, count = 0;

	/** Counting the number of words */
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == del)
		{
			i++;
			continue;
		}
		else if ( (str[i] == del || !(str[i+1])) && str[i-1] != del)
			count++;
		i++;
	}
	return (count);
}

char **split_words(char *str, char del)
{
	int i = 0, j = 0, count;
	int prev = 0, cur = 0;
	char **arr, buf;

	count = count_words(str, del);
	if (count == 0)
		return (NULL);
	arr = malloc(sizeof(char *) * (count + 1));
	while (str[i])
	{
		if (i == 0 && str[i++] == del)
			continue;
		else if ( (str[i] == del || !(str[i+1])) && str[i-1] != del)
		{
			cur = i;
			if (str[i + 1])
			{
				buf = str[cur];
				str[cur] = '\0';
			}

			while (str[prev] == del || str[prev] == '\n')
				prev++;
			arr[j] = malloc(sizeof(char) * (cur - prev + 2));
			if (!(arr[j]))
			{
				while (--j)
				{
					free(arr[j]);
				}
				free(arr[j]), free(arr);
			}
			strcpy(arr[j++], &(str[prev]));
			str[i] = buf;
			prev = cur;
		}
		i++;
	}
	arr[count] = NULL;
	return (arr);
}


/*int main(void)
{
	char str[] = "";
	int count;

	count = count_words(str, ' ');
	printf("%d", count);
}*/































