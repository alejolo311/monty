#include "monty.h"
/**
 * exec_rotl - this function executes the pchar opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack, *next;
	int aux;

	(void) line_number;
	if (actual != NULL)
	{
		next = actual->next;
		aux = actual->n;
		while (actual->next != NULL)
		{
			actual->n = next->n;
			actual = next;
			next = actual->next;
		}
		actual->n = aux;
	}
}
/**
 * exec_rotr - this function executes the rotr opcode
 * @stack: the stack to read the numbers
 * @line_number: number of line that is executed
 * Return: void function
 */
void exec_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *actual = *stack;
	int aux;

	(void) line_number;

	if (actual != NULL && actual->next != NULL)
	{
		for (; actual->next; actual = actual->next)
			;

		aux = actual->n;
		(actual->prev)->next = NULL;
		free(actual);
		*stack = add_dnodeint(&(*stack), aux);
	}
}
