#include "monty.h"


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void freeMemory(data_t *data, int end);


/**

 * _realloc - this will relocate the memory block

 * @ptr: this is the previous pointer

 * @old_size: this is the old size

 * @new_size: this is the new size

 * Return: new pointer if successful or NULL if failed

 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)

{

        char *p, *cp = ptr;

        unsigned int i, min;


        if (old_size == new_size)

                return (ptr);


        if (new_size == 0 && ptr != NULL)

        {

                free(ptr);

                return (NULL);

        }


        min = old_size < new_size ? old_size : new_size;


        p = malloc(new_size);

        if (p == NULL)

        {

                free(ptr);

                return (NULL);

        }


        if (new_size != old_size && ptr != NULL)

        {

                for (i = 0; i < min; i++)

                        p[i] = cp[i];

                free(ptr);

        }


        return (p);

}


/**

 * freeMemory - this is allocated data which is free

 * @data: this is the processed information

 * @end: the end is one to free the stack

 */

void freeMemory(data_t *data, int end)

{

        int i;

        stack_t *tmp;


        free(data->lineptr);

        data->lineptr = NULL;


        for (i = 0; i < data->cmdSize; i++)

                free(data->cmd[i]);

        free(data->cmd);

        data->cmd = NULL;


        if (end == 1)

        {

                while (data->head_s != NULL)

                {

                        tmp = data->head_s->next;

                        free(data->head_s);

                        data->head_s = NULL;

                        if (tmp != NULL)

                                data->head_s = tmp;

                }

                data->head_s = NULL;

        }

}
