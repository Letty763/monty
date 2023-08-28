#include "monty.h"


void dataInit(data_t *data, char **argv);


/**

 * main - this interprets the monty

 * @argc: this is the count for the argument

 * @argv: this is the vectors argument

 * Return: 0 if successful

 */

int main(int argc, char **argv)

{

        data_t data;


        if (argc != 2)

        {

                fprintf(stderr, "USAGE: monty file\n");

                exit(EXIT_FAILURE);

        }


        /* initialize data */

        dataInit(&data, argv);


        /* start the interpreter */

        interpreter(&data);


        return (0);

}


/**

 * dataInit - this will start the data

 * @data: this is the processed information

 * @argv: this is the vectors argument

 */

void dataInit(data_t *data, char **argv)

{

        data->argv = argv;

        data->cmd = NULL;

        data->head_s = NULL;

        data->tail_s = NULL;

        data->lineptr = NULL;

        data->stackSize = 0;

        data->stackMode = 0;

        data->cmdSize = 0;

}
