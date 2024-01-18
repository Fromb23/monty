#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t* instructions;

void subFunction(stack_t **stack, unsigned int line_number);
void divFunction(stack_t **stack, unsigned int line_number);
void modFunction(stack_t **stack, unsigned int line_number);
void mulFunction(stack_t **stack, unsigned int line_number);
void addFunction(stack_t **stack, unsigned int line_number);
instruction_t* get_instructions(void);
void free_instructions(instruction_t *instructions);
void free_malloc(stack_t **head);
int isInteger(const char *str);
void pullFunction(stack_t **start, unsigned int line_number);
void pallFunction(stack_t **stack, unsigned int line_number);
void pintFunction(stack_t **stack, unsigned int line_number);
void popFunction(stack_t **stack, unsigned int line_number);
void swapFunction(stack_t **stack, unsigned int line_number);
void nopFunction(stack_t **stack, unsigned int line_number);
void processBuffer(char *buffer, int line_number, stack_t **stack, instruction_t instructions[]);

int _strlen(char *s);
char *custom_strtok(char *str, const char *delim);
#endif
