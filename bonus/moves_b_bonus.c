/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:47:03 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/23 13:01:29 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	rrb(t_stack **stack_b)
{
	t_stack	*first_number_b;
	t_stack	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while (temp->next && temp->next->next)
		temp = temp->next;
	first_number_b = temp->next;
	temp->next = NULL;
	first_number_b->next = *stack_b;
	*stack_b = first_number_b;
}
