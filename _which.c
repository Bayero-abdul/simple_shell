#include "shell.h"


char *_which(char *cmd)
{
	char *path;
	char *c_path;
	char **arr;
	struct stat sb;
	int i = 0;

	path = _getenv("PATH");
	arr = split_words(path, ':');


	while (arr[i])
	{
		c_path = malloc(sizeof(char) * (strlen(cmd) + strlen(arr[i]) + 2));
		strcpy(c_path, arr[i]);
		c_path = strcat(c_path, "/");
		c_path = strcat(c_path, cmd);
		printf("c_path: %s\n", c_path);
		if (stat(c_path, &sb) == 0)
		{
			free_array(arr);
			return(c_path);
		}
		free(c_path);
		i++;
	}
	free_array(arr);
	return (NULL);
}