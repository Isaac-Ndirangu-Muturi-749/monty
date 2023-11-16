#include "monty.h"

/**
 * cleanup_stack - Frees all memory allocated for the stack.
 * @stack: Double pointer to the head of the stack.
 */
void cleanup_stack(stack_t **stack)
{
	while (*stack != NULL)
	{
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
