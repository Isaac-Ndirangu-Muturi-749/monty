#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 * @data: Argument passed to push.
 */
void push(stack_t **stack, unsigned int line_number, char *data)
{
	int value, i;
	stack_t *new_node;

	/* Check if there is an argument after push */
	if (!data)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; data[i]; i++)
	{
		if (data[0] == '-' && i == 0)
			continue;
		if (!isdigit(data[i]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	/* Convert the argument to an integer using atoi */
	value = atoi(data);

	/* Create a new stack element */
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
