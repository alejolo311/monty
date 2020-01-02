#include "monty.h"
/**
 * exec_pint - this function executes the pint opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;

	if (actual == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", actual->n);
}
