#include "main.h"

/**
 * execute_opcode - Execute Monty opcode based on the parsed line.
 * @opcode: The opcode to execute.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void execute_opcode(const char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t op_funcs[] = {
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
		{
			if (op_funcs[i].f == NULL)
			{
				fprintf(stderr, "L%u: Function %s not implemented\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
			op_funcs[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
