/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:35:07 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/24 15:18:19 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **stack_b)
{
	t_stack	*first_number;
	t_stack	*second_number;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first_number = *stack_b;
	second_number = (*stack_b)->next;
	first_number->next = second_number->next;
	second_number->next = first_number;
	*stack_b = second_number;
	ft_printf("sb\n");
}

void	pb(t_stack **stack, t_stack **stack_b)
{
	t_stack	*first_number_a;

	if (*stack == NULL)
		return ;
	first_number_a = *stack;
	*stack = first_number_a->next;
	first_number_a->next = *stack_b;
	*stack_b = first_number_a;
	ft_printf("pb\n");
}

void	rb(t_stack **stack_b)
{
	t_stack	*last_number_b;
	t_stack	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last_number_b = *stack_b;
	*stack_b = last_number_b->next;
	last_number_b->next = NULL;
	temp = *stack_b;
	while (temp->next)
		temp = temp->next;
	temp->next = last_number_b;
	ft_printf("rb\n");
}

void	rrb(t_stack **stack_b)
{
	t_stack		*first_number_b;
	t_stack		*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while (temp->next && temp->next->next)
		temp = temp->next;
	first_number_b = temp->next;
	temp->next = NULL;
	first_number_b->next = *stack_b;
	*stack_b = first_number_b;
	ft_printf("rrb\n");
}
