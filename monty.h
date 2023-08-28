#ifndef MONTY_H

#define MONTY_H


#include <ctype.h>

#include <stdio.h>

#include <string.h>

#include <unistd.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <stdarg.h>

#include <stdlib.h>


#define DELIM " \t\n"

#define BUFFSIZE 128


/**

 * struct stack_s - representation of a stacks doubly linked list

 * @n: this is the integer

 * @prev: this directs to the previous component of the queue

 * @next: this will direct to the following component of the queue

 * Description: the structure of the double linked list

 */

typedef struct stack_s

{

        int n;

        struct stack_s *prev;

        struct stack_s *next;

} stack_t;


/*******data_structure***************/

/**

 * struct data_t - struct holding program's data

 * @argv: this is the vectors argument

 * @cmd: this is the command array

 * @head_s: this is the head of the stack

 * @tail_s: this is the tail of the stack

 * @lineptr: this points to the line

 * @stackSize: this is the number of components

 * @stackMode: this is the stack mode

 * @cmdSize: the number of components in the command size

 */

typedef struct data_t

{

        char **argv;

        char **cmd;

        stack_t *head_s;

        stack_t *tail_s;

        char *lineptr;

        int stackSize;

        int stackMode;

        int cmdSize;

} data_t;


/*****************main.c*************/

void dataInit(data_t *data, char **argv);


/**************interprete.cr*********/

void interpreter(data_t *data);

void opHandler(data_t *data, int idx);


/**************file_handler*********/

int openFile(data_t *data);

void closeFile(data_t *data, int fd);


/***************_strtok************/

char **_strtok(char *str, const char *delim, int *size);

int countTok(char *str, const char *delim);

int tokLen(char *str, const char *delim, int index);

int isDelim(char c, const char *delim);


/**************getline.c************/

int _getLine(data_t *data, int *size, int stream);

int lineHelper(data_t *data, int rd, int i);


/*************Memory_handler******/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

void freeMemory(data_t *data, int end);


/***********opcode_struct********/

/**

 * struct instruction_s - this is opcodes functions

 * @opcode: this is the opcode

 * @f: this is the function which handles the opcode

 */

typedef struct instruction_s

{

        char *opcode;

        void (*f)(unsigned int line_number, data_t *data);

} instruction_t;


/***********opcode_functions*****/

/*opcode1.c*/

void push(unsigned int line_number, data_t *data);

void pall(unsigned int line_number, data_t *data);

void pint(unsigned int line_number, data_t *data);

void pchar(unsigned int line_number, data_t *data);

void pstr(unsigned int line_number, data_t *data);

/*opcode4*/

void add_top(int n, data_t *data, int mode);

void pop_top(data_t *data, int mode);

void pop(unsigned int line_number, data_t *data);

void swap(unsigned int line_number, data_t *data);

/*opcode3*/

void add(unsigned int line_number, data_t *data);

void sub(unsigned int line_number, data_t *data);

void divi(unsigned int line_number, data_t *data);

void mul(unsigned int line_number, data_t *data);

void mod(unsigned int line_number, data_t *data);

/*opcode2*/

void stack(unsigned int line_number, data_t *data);

void queue(unsigned int line_number, data_t *data);

void rotl(unsigned int line_number, data_t *data);

void rotr(unsigned int line_number, data_t *data);

int _isint(char *str);

#endif
