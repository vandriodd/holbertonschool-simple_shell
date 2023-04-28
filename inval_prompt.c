#include "main.h"
/**
 * inval_prompt - checks wether the input is one of the specified chars
 *
 * @input: the input
 *
 * Return: 0 if coincidence, 1 if not
 */
int inval_prompt(char *input)
{
	char **inv_arr = {" ", '\n', '\t', '\0'};
	int i, j;

	for (i = 0; input[i]; i++)
	{
		for (j = 0; input[j]; j++)
		{
			if(strcmp(input[j], inv_arr[i]) == 1)
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
