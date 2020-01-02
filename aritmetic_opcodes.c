#include "monty.h"
/**
 * exec_div - this function executes the div opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_div(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;
	stack_t *next;

	if (actual == NULL || actual->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (actual->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = actual->next;
	next->n =  next->n / actual->n;
	exec_pop(stack, line_number);
}