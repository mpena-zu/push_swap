#include "push_swap.h"

void    sa(t_stack_a **stack_a)
{
    t_stack_a   *first_node;
    t_stack_a   *second_node;

    if(*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    first_node = *stack_a;
    second_node = (*stack_a)->next;
    first_node->next = second_node->next;
    second_node->next = first_node;
    *stack_a = second_node;
}