#include "monty.h"
/**
 * error_handler - this function executes the div opcode
 * @opcode: opcode generates error
 * @errorcode: the number of the error
 * @ln: number of line that is executed
 * Return: void function
 */
void error_handler(char *opcode, int errorcode, int ln)
{
	if (errorcode == -98)
		dprintf(STDERR_FILENO,
		"L%u: can't %s, stack empty\n", ln, opcode), exit(EXIT_FAILURE);
	if (errorcode == -99)
		dprintf(STDERR_FILENO,
		"L%u: can't %s, stack too short\n", ln, opcode), exit(EXIT_FAILURE);
	if (errorcode == -126)
		dprintf(STDERR_FILENO,
		"L%u: division by zero\n", ln), exit(EXIT_FAILURE);
	if (errorcode == -127)
		dprintf(STDERR_FILENO,
		"L%u: can't %s, value out of range\n", ln, opcode), exit(EXIT_FAILURE);
	if (errorcode == -128)
		dprintf(STDERR_FILENO,
		"L%d: unknown instruction %s\n", ln, opcode), exit(EXIT_FAILURE);
}
