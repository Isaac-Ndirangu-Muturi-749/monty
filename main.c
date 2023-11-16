#include "monty.h"

/**
 * main - Main entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;

	/* Check if the correct number of arguments is provided */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/* Open the Monty bytecode file */
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* Process the Monty bytecode file */
	process_file(file, &stack);

	/* Clean up the stack */
	cleanup_stack(&stack);

	/* Close the file */
	fclose(file);

	return (EXIT_SUCCESS);
}
