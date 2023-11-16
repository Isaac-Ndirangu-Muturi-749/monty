#define _POSIX_C_SOURCE 200809L

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
	process_file(file);

	/* Close the file */
	fclose(file);

	return (EXIT_SUCCESS);
}

/**
 * process_file - Process the Monty bytecode file.
 * @file: Pointer to the opened Monty bytecode file.
 */
void process_file(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	/* Read each line from the file */
	while ((getline(&line, &len, file)) != -1)
	{
		if (line != NULL)
		{
			/* Tokenize the line to get opcode and data */
			char *opcode = strtok(line, DELIMITERS);
			char *data = strtok(NULL, DELIMITERS);

			/* Check opcode and execute corresponding function */
			if (!strcmp(opcode, "push"))
			{
				push(&stack, line_number, data);
			} else
			{
				exec_opcode(opcode, &stack, line_number);
			}
		}
		line_number++;
	}

	/* Free allocated memory */
	if (line)
		free(line);

	/* Clean up the stack */
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
