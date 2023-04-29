#include "main.h"

/**
 * len_counter - counts the number of words in a string
 * @str: string input
 *
 * Return: amount of words counted
 */
int len_counter(char *str)
{
	int count = 0;
	char *token = NULL, *str_copy = NULL;

	str_copy = strdup(str); /*copy the str for further tokenization*/
	token = strtok(str_copy, DELIM); /*first token*/

	for (count = 1; token; count++) /*count = 1 cause already tokenized once*/
	{
		token = strtok(NULL, DELIM); /*tokenizing in loop*/
	}
	free(str_copy);
	return (count); /*amount of words is returned*/
}
