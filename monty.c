#include "monty.h"
/**
 * main - entry point
 * @argc: count of arguments
 * @argv: The arguments
 * Description: entry point for the program to exec monty code
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	queue = false;
	if (verify_args(argc) == 1)
		open_and_read(*(argv + 1));
	else
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
