#include "monty.h"
/**
*f_swap- sustration
*@head: stack head
*@counter: line_number
*Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
{
stack_t *h;
int len = 0, aux;

h = *head; /*'h' is a temporary variable pointing to the top of the stack */
while (h)
{
h = h->next;
len++;
}
if (len < 2)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
fclose(bus.file);  /*'bus.file' is used to close a file in this code */
free(bus.content); /* bus.content' is used 2 free dynamically allocated mem */
free_stack(*head); /*free_stack' is a function dat frees d memory of d stack */
exit(EXIT_FAILURE);
}
h = *head; /* resetting 'h' to d top of d stack */
aux = h->n; /* aux is a temporary variable storing d value of d top element */
h->n = h->next->n;
h->next->n = aux;/* update the 2nd element with the value stored in aux */
}

