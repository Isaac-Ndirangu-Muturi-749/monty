
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
	char *opcode;

	/* Read each line from the file */
	while ((getline(&line, &len, file)) != -1)
	{
		/* Skip empty lines or lines with only whitespace */
		if (strspn(line, " \t\r\n") == strlen(line))
		{
			line_number++;
			continue;
		}

		/* Tokenize the line to get opcode*/
		opcode = strtok(line, DELIMITERS);

		/* Execute opcode */
		exec_opcode(opcode, stack, line_number);

		line_number++;
	}

	/* Free allocated memory */
	if (line)
		free(line);
}

