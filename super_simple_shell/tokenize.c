#include "main.h"

/**
 * tokenize - tokenizes a string
 * @str: string input
 *
 * Return: the string tokenized
 */
char **tokenize(char *str)
{
	char **str_tokenized = NULL, *token = NULL;
	size_t count = 0;
	int len = 0;

	len = len_counter(str);
	str_tokenized = malloc(sizeof(char *) * len);
	token = strtok(str, DELIM);

	for (; token; count++) /* stores each token */
	{
		str_tokenized[count] = token;
		token = strtok(NULL, DELIM);
	}
	return (str_tokenized);
}
