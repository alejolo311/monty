#include "monty.h"
/**
 * exec_swap - this function executes the swap opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_swap(stack_t **stack, unsigned int line_number)
{
	int aux;
	stack_t *actual = *stack, *next;

	if (actual == NULL || actual->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = actual->next;
	aux = actual->n;
	actual->n = next->n;
	next->n = aux;
}
