#include "monty.h"
/**
 * add_dnodeint - function
 * @head: head of list
 * @n: n value of new node
 * Return: address of new element
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (!(*head))
	{
		*head = new;
		return (*head);
	}

	while ((*head)->prev)
		*head = (*head)->prev;

	(*head)->prev = new;
	new->next = *head;
	*head = new;

	return (*head);
}
