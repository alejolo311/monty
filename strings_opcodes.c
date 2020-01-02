#include "monty.h"
/**
 * pchar_list - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to the head of the list
 * @line_number: line number of instruction
 */
void exec_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;

	if (actual == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (actual->n < 0 || actual->n > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, ", line_number);
		dprintf(STDERR_FILENO, "value out of range\n");
		exit(EXIT_FAILURE);
	}
	putchar(actual->n);
	putchar('\n');
}