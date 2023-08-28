#include "monty.h"


void add(unsigned int line_number, data_t *data);

void sub(unsigned int line_number, data_t *data);

void divi(unsigned int line_number, data_t *data);

void mul(unsigned int line_number, data_t *data);

void mod(unsigned int line_number, data_t *data);


/**

 * add - this will sum up the top 2 components of the stack

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void add(unsigned int line_number, data_t *data)

{

        int temp = 0;


        if (data->stackSize < 2)

        {

                fprintf(stderr, "L%u: can't add, stack too short\n", line_number);

                freeMemory(data, 1);

                exit(EXIT_FAILURE);

        }

        temp = data->head_s->n + data->head_s->next->n;

        pop_top(data, 0);

        pop_top(data, 0);

        add_top(temp, data, 0);

}


/**

 * sub - this will substitute the top component of the stack

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void sub(unsigned int line_number, data_t *data)

{

        int temp;


        if (data->stackSize < 2)

        {

                fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);

                freeMemory(data, 1);

                exit(EXIT_FAILURE);

        }

        temp = data->head_s->next->n - data->head_s->n;

        pop_top(data, 0);

        pop_top(data, 0);

        add_top(temp, data, 0);

}


/**

 * divi - this will divide the second top component of the stack by the first component

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void divi(unsigned int line_number, data_t *data)

{

        int temp;


        if (data->stackSize < 2)

        {

                fprintf(stderr, "L%u: can't div, stack too short\n", line_number);

                exit(EXIT_FAILURE);

        }

        if (data->head_s->n == 0)

        {

                fprintf(stderr, "L%u: division by zero\n", line_number);

                freeMemory(data, 1);

                exit(EXIT_FAILURE);

        }

        temp = data->head_s->next->n / data->head_s->n;

        pop_top(data, 0);

        pop_top(data, 0);

        add_top(temp, data, 0);

}


/**

 * mul - this will multiply the top component with the second one

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void mul(unsigned int line_number, data_t *data)

{

        int temp;


        if (data->stackSize < 2)

        {

                fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);

                freeMemory(data, 1);

                exit(EXIT_FAILURE);

        }

        temp = data->head_s->n * data->head_s->next->n;

        pop_top(data, 0);

        pop_top(data, 0);

        add_top(temp, data, 0);

}


/**

 * mod - this will divide the second top component by the first one

 * @line_number: the number of the line of code

 * @data: this is the processed information

 */

void mod(unsigned int line_number, data_t *data)

{

        int temp;


        if (data->stackSize < 2)

        {

                fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);

                freeMemory(data, 1);

                exit(EXIT_FAILURE);

        }

        if (data->head_s->n == 0)

        {

                fprintf(stderr, "L%u: division by zero\n", line_number);

                freeMemory(data, 1);

                exit(EXIT_FAILURE);

        }

        temp = data->head_s->next->n % data->head_s->n;

        pop_top(data, 0);

        pop_top(data, 0);

        add_top(temp, data, 0);

}
