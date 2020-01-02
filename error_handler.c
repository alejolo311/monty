#include "monty.h"
/**
 * exec_div - this function executes the div opcode
 * @opcode: opcode generates error
 * @errorcode: the stack to read the numbers
 * @ln: number of line that is executed
 * Return: void function
 */
void error_handler(char *opcode, int errorcode, int ln)
{
    if (errorcode == -99)
        dprintf(STDERR_FILENO, "L%u: can't %s, stack too short\n", ln, opcode), exit(EXIT_FAILURE);
    if (errorcode == -126)
        dprintf(STDERR_FILENO, "L%u: division by zero\n", ln), exit(EXIT_FAILURE);
}