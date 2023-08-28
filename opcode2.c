#include "monty.h"


void stack(unsigned int line_number, data_t *data);

void queue(unsigned int line_number, data_t *data);

void rotl(unsigned int line_number, data_t *data);

void rotr(unsigned int line_number, data_t *data);

int _isint(char *str);


/**

 * stack - this sets the format of the stack to LIFO

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void stack(unsigned int line_number, data_t *data)

{

        (void)line_number;

        data->stackMode = 0;

}


/**

 * queue - this sets the format for the stack to FIFO

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void queue(unsigned int line_number, data_t *data)

{

        (void)line_number;

        data->stackMode = 1;

}


/**

 * _isint - this will examine if the value has been pushed

 * @str: the amount which needs to be examined

 * Return: 0 if it is an int, and 1 if it is not

 */

int _isint(char *str)

{

        int i, flag = 0;


        if (str[0] == '-' || str[0] == '+')

        {

                flag = 1;

                str++;

        }

        for (i = 0; i < (int)strlen(str); i++)

        {

                if (!isdigit(str[i]))

                        return (0);

        }

        if (flag == 1 && i == 0)

                return (0);

        return (1);

}


/**

 * rotl - this will rotate the stack to the head

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void rotl(unsigned int line_number, data_t *data)

{

        stack_t *h;


        (void) line_number;

        if (data->stackSize < 2)

                return;



        h = data->tail_s;

        data->head_s->prev = h;

        h->next = data->head_s;

        data->head_s = data->head_s->next;

        data->tail_s = data->tail_s->next;

        h->next->next = NULL;

}


/**

 * rotr - this will rotate the stack to the end

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void rotr(unsigned int line_number, data_t *data)

{

        stack_t *h;


        (void) line_number;

        if (data->stackSize < 2)

                return;


        h = data->tail_s;

        data->tail_s = data->tail_s->prev;

        h->next = data->head_s;

        h->prev->next = NULL;

        h->prev = NULL;

        data->head_s = h;

}
