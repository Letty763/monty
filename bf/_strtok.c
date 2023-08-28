#include "monty.h"

char **_strtok(char *str, const char *delim, int *size);
int countTok(char *str, const char *delim);
int tokLen(char *str, const char *delim, int index);
int isDelim(char c, const char *delim);

/**
 * _strtok - this will make a string tokenized
 * @str: this is the string
 * @delim: this is the delimiter
 * @size: this will be the size
 * Return: tokens in an array
 */
char **_strtok(char *str, const char *delim, int *size)
{
	char **arrtok;
	int i, j = 0, k, toklen = 0;

	if (str == NULL || delim == NULL || str[0] == '\0')
		return (NULL);
	*size = countTok(str, delim);
	if (*size == 0)
		return (NULL);
	arrtok = malloc(sizeof(char *) * (*size + 1));
	if (arrtok == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < *size; i++)
	{
		while (isDelim(str[j], delim))
			j++;

		toklen = tokLen(str, delim, j);
		arrtok[i] = malloc(sizeof(char) * (toklen + 1));
		if (arrtok[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		for (k = 0; k < toklen; k++)
		{
			arrtok[i][k] = str[j];
			j++;
		}
		arrtok[i][k] = '\0';
	} arrtok[i] = NULL;
	return (arrtok);
}

/**
 * countTok - this will count the amount of tokens
 * @str: this will hold the tokens
 * @delim: this is the delimiter
 * Return: amount of tokens
 */
int countTok(char *str, const char *delim)
{
	int i, count = 0;

	if (str == NULL || delim == NULL)
		return (0);
	for (i = 0; i < (int)strlen(str); i++)
	{
		if (!isDelim(str[i], delim))
		{
			count++;
			i += tokLen(str, delim, i);
		}
	}
	return (count);
}
/**
 * tokLen - this gets the length of the tokens
 * @str: this is the string
 * @delim: this is the delimiter
 * @index: this is the index
 * Return: must be an integer
 */
int tokLen(char *str, const char *delim, int index)
{
	int len;

	for (len = 0; str[index + len] && str[index + len] != '\n'; len++)
	{
		if (isDelim(str[index + len], delim))
		{
			break;
		}
	}
	return (len);
}

/**
 * isDelim - this will examine if a character is equal to a delimiter
 * @c: this is the character which needs to be examined
 * @delim: this is the delimiter
 * Return: 1 if it is a delimiter and 0 if it is not
 */
int isDelim(char c, const char *delim)
{
	int i;

	for (i = 0; i < (int)strlen(delim); i++)
	{
		if (c == delim[i])
			return (1);
	}

	return (0);
}
