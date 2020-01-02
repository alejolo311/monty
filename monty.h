#ifndef MONTY_H
#define MONTY_H

/* Libraries */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/* helpers */
int verify_args(int argc);
void open_and_read(char *f);
void exec_monty(stack_t **stack, char *opcode, int ln);


/* Instructions */
void exec_pall(stack_t **stack, unsigned int line_number);
void exec_pop(stack_t **stack, unsigned int line_number);
void exec_pint(stack_t **stack, unsigned int line_number);
void exec_swap(stack_t **stack, unsigned int line_number);
void exec_nop(stack_t **stack, unsigned int line_number);

/* String Instructions */
void exec_pchar(stack_t **stack, unsigned int line_number);

/* Aritmetic Instructions */
void exec_div(stack_t **stack, unsigned int line_number);
void exec_mod(stack_t **stack, unsigned int line_number);
void exec_add(stack_t **stack, unsigned int line_number);
void exec_sub(stack_t **stack, unsigned int line_number);
void exec_mul(stack_t **stack, unsigned int line_number);


/* Errors managements */

void error_handler(char *opcode, int errorcode, int ln);

/* Nodes Managements */

stack_t *add_dnodeint(stack_t **head, const int n);
#endif
