#include "main.h"

/**
 * main - Main entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE otherwise.
 */
int main(int argc, char *argv[])
{
    // Check if the correct number of arguments is provided
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    // Open the Monty bytecode file
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Initialize the stack
    stack_t *stack = NULL;

    // Buffer to read lines from the file
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;

    while ((read = getline(&line, &len, file)) != -1)
    {
        if (line != NULL)
        {
            char *opcode = strtok(line, DELIMITERS);
            char *data = strtok(NULL, DELIMITERS);

            if (!strcmp(opcode, "push"))
            {
                push(&stack, line_number, data);
            }
            else
            {
                // Check the opcode and call the corresponding function
                execute_opcode(opcode, &stack, line_number);
            }
        }
        line_number++;
    }

    // Free allocated memory
    if (line)
        free(line);

    // Close the file
    fclose(file);

    // Clean up the stack
    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}
