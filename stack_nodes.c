#include "monty.h"
/**
 * push_stack - function
 * @head: head of list
 * @n: n value of new node
 * Return: address of new element
 */
stack_t *push_stack(stack_t **head, const int n)
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
/**
 * push_queue - function
 * @head: head of list
 * @n: n value of new node
 * Return: address of new element
 */
stack_t *push_queue(stack_t **head, const int n)
{
	stack_t *new, *actual;

	actual = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->n = n;

	if (actual == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (actual->next)
	{
		actual = actual->next;
	}
	actual->next = new;
	new->prev = actual;
	return (new);
}
