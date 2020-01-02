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
/**
 * exec_pstr - this function executes the pstr opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;
	(void) line_number;
	while (actual)
	{
		if ((actual->n > 0) && actual->n < 127)
		{
			putchar(actual->n);
			actual = actual->next;
		} else
			break;
	}
	putchar('\n');
}
