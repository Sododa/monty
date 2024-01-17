#include "monty.h"
/**
 * f_push - where <int> is an integer
 * @head: stack of head
 * @counter: line_number no new line
 * Return:exit with the status EXIT_FAILURE
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, a = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			a++;
		for (; bus.arg[a] != '\0'; a++)
		{
			if (bus.arg[a] > 57 || bus.arg[a] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
