#include "push_swap.h"

void    sa(t_stack **stack)
{
    t_stack     *first_node;
    t_stack     *second_node;

    if(*stack == NULL || (*stack)->next == NULL)
        return ;
    first_node = *stack;
    second_node = (*stack)->next;
    first_node->next = second_node->next;
    second_node->next = first_node;
    *stack = second_node;
}

void    sb(t_stack **stack_b)
{
    t_stack     *first_number;
    t_stack     *second_number;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    first_number = *stack_b;
    second_number = (*stack_b)->next;
    first_number->next = second_number->next;
    second_number->next = first_number;
    *stack_b = second_number;
}

void    ss(t_stack **stack, t_stack **stack_b)
{
    t_stack     *temp;

    temp = *stack;
    *stack = *stack_b;
    *stack_b = temp;
}

void    pa(t_stack **stack, t_stack **stack_b)
{
    t_stack     *first_number_b;

    if (*stack_b == NULL)
        return ;
    first_number_b = *stack_b;
    *stack_b = first_number_b->next;
    first_number_b->next = *stack;
    *stack = first_number_b;
}

void    pb(t_stack **stack, t_stack **stack_b)
{
    t_stack     *first_number_a;

    if (*stack == NULL)
        return ;
    first_number_a = *stack;
    *stack = first_number_a->next;
    first_number_a->next = *stack_b;
    *stack_b = first_number_a;
}

void    ra(t_stack **stack)
{
    t_stack     *last_number_a;
    t_stack     *temp;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    last_number_a = *stack;
    *stack = last_number_a->next;
    last_number_a->next = NULL;
    temp = *stack;
    while (temp->next)
        temp = temp->next;
    temp->next = last_number_a;
}

void    rb(t_stack **stack_b)
{
    t_stack     *last_number_b;
    t_stack     *temp;

    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return ;
    last_number_b = *stack_b;
    *stack_b = last_number_b->next;
    last_number_b->next = NULL;
    temp = *stack_b;
    while (temp->next)
        temp = temp->next;
    temp->next = last_number_b;
}