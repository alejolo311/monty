#include "monty.h"

/**
 * verify_args - verify the args
 * @argc: arguments
 * Return: 0 in succes -1 in fail
 */

int verify_args(int argc)
{
	if (argc > 2 || argc < 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (-1);
	}
	return (1);
}

/**
 * open_and_read - open the monty file and read his content
 * @f: the file to open
 * Return: Void no return
 */
void open_and_read(char *f)
{
	size_t l = 0;
	ssize_t r;
	unsigned int ln = 1;
	int value;
	char *op, *line, *val;
	FILE *montyfile;
	stack_t *head = NULL;

	montyfile = fopen(f, "r");
	while ((r = getline(&line, &l, montyfile)) != -1)
	{
		op = strtok(line, " ");
		if (*op == '#' || *op == '\n')
		{
			ln++;
			continue;
		}
		val = strtok(NULL, " \n");
		if (val != NULL && strcmp(op, "push") == 0)
		{
			if (is_number(val))
			{
				value = atoi(val);
				!queue ? push_stack(&head, value) : push_queue(&head, value);
			} else
			{
				dprintf(STDERR_FILENO,
				"L%d: usage: push integer\n", ln), exit(EXIT_FAILURE);
			}
		} else
		{
			exec_monty(&head, op, ln);
		}
		ln++;
	}
}
/**
 * exec_monty - execute the opcode funcion
 * @stack: head of the stack
 * @opcode: opcode instruction
 * @ln: number of line
 */
void exec_monty(stack_t **stack, char *opcode, int ln)
{
	int i;
	char *op;
	instruction_t instructions[] = {
		{"pall", exec_pall},
		{"pint", exec_pint},
		{"pop", exec_pop},
		{"swap", exec_swap},
		{"nop", exec_nop},
		{"pchar", exec_pchar},
		{"pstr", exec_pstr},
		{"add", exec_add},
		{"sub", exec_sub},
		{"mul", exec_mul},
		{"div", exec_div},
		{"mod", exec_mod},
		{"rotl", exec_rotl},
		{"rotr", exec_rotr},
		{"stack", exec_stack},
		{"queue", exec_queue},
		{NULL, NULL}
	};
	op = strtok(opcode, " \n");
	for (i = 0; instructions[i].opcode; i++)
		if (strcmp(op, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, ln);
			return;
		}
	error_handler(opcode, -128, ln);
}
