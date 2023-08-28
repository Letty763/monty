#include "monty.h"

int _getLine(data_t *data, int *size, int stream);
int lineHelper(data_t *data, int rd, int i);

/**
 * _getLine - this will scan a line from the stream
 * @data: this will hold the data
 * @size: this is the lines size
 * @stream: this is the source which needs to be scanned
 * Return: characters scanned if successful or -1 if failed
 */
int _getLine(data_t *data, int *size, int stream)
{
	int i = 0, rd = 0, flag = 0;
	char c = '\0', *tmp = NULL;

	if (data->lineptr == NULL)
		*size = 0;
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		if (i >= *size)
		{
			*size += BUFFSIZE;
			tmp = _realloc(data->lineptr, *size - BUFFSIZE, *size);
			if (tmp == NULL)
			{
				free(data->lineptr), data->lineptr = NULL;
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			} data->lineptr = tmp;
		} fflush(stdout);
		rd = read(stream, &c, 1);
		rd = lineHelper(data, rd, i);
			if (rd == 0)
				break;
		if (rd == -1)
			return (-1);
		if (flag == 0 && c == ' ')
		{
			i--;
			continue;
		} else
			flag = 1;
		if (c == '\n')
		{
			data->lineptr[(i++)] = c;
			break;
		} data->lineptr[i] = c;
	} data->lineptr[i] = '\0';
	return (i);
}

/**
 * lineHelper - this will manage what is scanned
 * @data: this holds the data
 * @rd: this will scan the status
 * @i: this will be the character count
 * Return: 0 if empty and -1 if it failed
 */
int lineHelper(data_t *data, int rd, int i)
{
	stack_t *tmp = NULL;

	if (rd == 0)
	{
		if (i == 0)
		{
			free(data->lineptr);
			data->lineptr = NULL;
			while (data->head_s != NULL)
			{
				tmp = data->head_s->next;
				free(data->head_s);
				data->head_s = NULL;
				if (tmp != NULL)
					data->head_s = tmp;
			}
			exit(0);
		}
		return (0);
	}
	if (rd == -1)
	{
		free(data->lineptr);
		data->lineptr = NULL;
		return (-1);
	}
	return (rd);
}
