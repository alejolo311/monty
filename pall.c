#include "monty.h"
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
