#include "monty.h"
/**
 * exec_pchar - this function executes the pchar opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;

	actual == NULL ? error_handler("pchar", -98, line_number) : (void) actual;
	actual->n < 0 || actual->n > 127 ?
	error_handler("pchar", -127, line_number) : (void)actual;
	putchar(actual->n);
	putchar('\n');
}
