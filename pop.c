#include "monty.h"
/**
 * exec_pop - this function executes the pop opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = tmp->next;

	if (tmp->next)
		tmp->next->prev = NULL;

	free(tmp);
}
