
#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	second->n += top->n;

	/* Pop the top element */
	*stack = second;
	if (second->next)
		second->next->prev = NULL;
	free(top);
}
