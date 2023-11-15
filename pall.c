#include "monty.h"

/**
 * pall - Prints all values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *current = *stack;

	if (current == NULL)
		return;

	/* Print all values on the stack */
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
