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
    int i = 0;
	char *op, *line, *token, **tokens, *val;
    FILE *montyfile;

    tokens = malloc(sizeof(char *) * 64);

    montyfile = fopen(f, "r");
    do {
    r = getline(&line, &l, montyfile);
    token = strtok(line, " \t\r\n\a");
    while (token)
    {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " \t\r\n\a");
    }
    op = tokens[0];
    val = tokens[1];
    if (*op == '#' || *op == '\n')
	    {
			ln++;
			continue;
		}
    printf("opcode -> (%s) value -> (%s)\n", op, val);
    ln++;
    } while (r != -1);
}
