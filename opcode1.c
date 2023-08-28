void push(unsigned int line_number, data_t *data);

void pall(unsigned int line_number, data_t *data);

void pint(unsigned int line_number, data_t *data);

void pchar(unsigned int line_number, data_t *data);

void pstr(unsigned int line_number, data_t *data);


/**

 * push - pushes an element to the stack

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void push(unsigned int line_number, data_t *data)

{

        if (data->cmdSize < 2 || !_isint(data->cmd[1]))

        {

                fprintf(stderr, "L%u: usage: push integer\n", line_number);

                freeMemory(data, 1);

                exit(EXIT_FAILURE);

        }

        add_top(atoi(data->cmd[1]), data, data->stackMode);

}


/**

 * pall - prints all the values on the stack,

 * starting from the top of the stack

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void pall(unsigned int line_number, data_t *data)

{

        stack_t *h;


        (void) line_number;

        h = data->head_s;


        while (h)

        {

                printf("%d\n", h->n);

                h = h->next;

        }

}


/**

 * pint - print the value of the top element of the stack

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void pint(unsigned int line_number, data_t *data)

{

        stack_t *h;


        if (!data->head_s)

        {

                fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);

                freeMemory(data, 1);

                exit(EXIT_FAILURE);

        }


        h = data->head_s;

        printf("%d\n", h->n);

}


/**

 * pchar - print the value of the top element of the stack

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void pchar(unsigned int line_number, data_t *data)

{

        if (!data->stackSize)

        {

                fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);

                freeMemory(data, 1);

                exit(EXIT_FAILURE);

        }

        if (data->head_s->n < 0 || data->head_s->n > 127)

        {

                fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);

                freeMemory(data, 1);

                exit(EXIT_FAILURE);

        }

        printf("%c\n", data->head_s->n);

}


/**

 * pstr - this will print a string in the stack

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void pstr(unsigned int line_number, data_t *data)

{

        stack_t *h;


        (void) line_number;

        for (h = data->head_s; h; h = h->next)

        {

                if (h->n <= 0 || h->n > 127)

                        break;

                printf("%c", h->n);

        }

        printf("\n")
