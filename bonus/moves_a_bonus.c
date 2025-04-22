/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:46:04 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/22 16:36:21 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_stack **stack)
{
	t_stack	*first_number;
	t_stack	*second_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first_number = *stack;
	second_number = (*stack)->next;
	first_number->next = second_number->next;
	second_number->next = first_number;
	*stack = second_number;
}

void	pa(t_stack **stack, t_stack **stack_b)
{
	t_stack	*first_number_b;

	if (*stack_b == NULL)
		return ;
	first_number_b = *stack_b;
	*stack_b = first_number_b->next;
	first_number_b->next = *stack;
	*stack = first_number_b;
}

void	ra(t_stack **stack)
{
	t_stack	*last_number_a;
	t_stack	*temp;

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

void	rra(t_stack **stack)
{
	t_stack		*firs_number_a;
	t_stack		*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next && temp->next->next)
		temp = temp->next;
	firs_number_a = temp->next;
	temp->next = NULL;
	firs_number_a->next = *stack;
	*stack = firs_number_a;
}