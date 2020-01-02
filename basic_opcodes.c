#include "monty.h"
/**
 * exec_pall - this function executes the pall opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void) line_number;

	if (!stack || !(*stack))
		return;

	tmp = *stack;

	while (tmp->prev)
		tmp = tmp->prev;

	for (; tmp->next; tmp = tmp->next)
		printf("%d\n", tmp->n);

	printf("%d\n", tmp->n);
}
/**
 * exec_nop - this function executes the nop opcode does nothing jeje
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
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