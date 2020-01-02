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
	char *op, *line, *val;
    FILE *montyfile;
    stack_t *stack;

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
        
    }
    exec_monty(&stack, op, ln);
    ln++;
    }    
}

void exec_monty(stack_t **stack, char *opcode, int ln)
{   
    int i;
	instruction_t instructions[] = {
		{"pall", exec_pall},
		{"pint", exec_pint},
		{"pop", exec_pop},
		{"swap", exec_swap},
        {"nop", exec_nop},
		{NULL, NULL}
	};
	for (i = 0; instructions[i].opcode; i++)
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, ln);
			return;
		}
	dprintf(STDERR_FILENO, "L%d: ", ln);
	dprintf(STDERR_FILENO, "unknown instruction %s\n", opcode);
	exit(EXIT_FAILURE);

}