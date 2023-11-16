#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * process_file - Process the Monty bytecode file.
 * @file: Pointer to the opened Monty bytecode file.
 * @stack: Double pointer to the head of the stack.
 */
void process_file(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;

	/* Read each line from the file */
	while ((getline(&line, &len, file)) != -1)
	{
		if (line != NULL)
		{
			/* Tokenize the line to get opcode*/
			char *opcode = strtok(line, DELIMITERS);

			/* Execute opcode and check for errors */
			exec_opcode(opcode, stack, line_number);
		}
		line_number++;
	}

	/* Free allocated memory */
	if (line)
		free(line);
}
