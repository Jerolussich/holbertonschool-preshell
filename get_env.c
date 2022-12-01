#include "main.h"

char * get_env(char *name)
{
	int i;
	char *buff, *token, *str;
	
	buff = malloc(sizeof(char *) * 100);
	for (i = 0; environ[i]; i++)
	{
		str = strtok(environ[i], "=");
		if (strcmp(str, name) == 0)
		{
			str = strtok(NULL, "=");
			free(buff);
			return (str);
		}
	}
}
char * attach_path(char *str, char const *input)
{
	int fk = 0, status, found;
	struct stat st;
	char * buff;

	strtok(str, ":");
	buff = malloc(sizeof(char) * strlen(str));
	strcat(buff, str);
	strcat(buff, "/");
	strcat(buff, input);
	while (stat(buff, &st) == -1)
	{
		found = stat(buff, &st);
		str = strtok(NULL, ":");
		if (!str)
			break;
		buff = NULL;
		strcat(buff, str);
		strcat(buff, "/");
		strcat(buff, input);
	}
	free(buff);
	if (found == 0)
		return (buff);
	else
		return(NULL);
}
