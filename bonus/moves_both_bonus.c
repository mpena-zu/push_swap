/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_both_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:47:59 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/23 13:02:19 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stack **stack, t_stack **stack_b)
{
	t_stack	*first_number_a;
	t_stack	*second_number_a;
	t_stack	*first_number_b;
	t_stack	*second_number_b;

	if (*stack == NULL || (*stack)->next == NULL || *stack_b == NULL
		|| (*stack_b)->next == NULL)
		return ;
	first_number_a = *stack;
	first_number_b = *stack_b;
	second_number_a = (*stack)->next;
	second_number_b = (*stack_b)->next;
	first_number_a->next = second_number_a->next;
	first_number_b->next = second_number_b->next;
	second_number_a->next = first_number_a;
	second_number_b->next = first_number_b;
	*stack = second_number_a;
	*stack_b = second_number_b;
}

void	rr(t_stack **stack, t_stack **stack_b)
{
	t_stack	*last_number_a;
	t_stack	*last_number_b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (*stack_b == NULL || *stack == NULL || (*stack)->next == NULL
		|| (*stack_b)->next == NULL)
		return ;
	last_number_a = *stack;
	last_number_b = *stack_b;
	*stack = last_number_a->next;
	*stack_b = last_number_b->next;
	last_number_a->next = NULL;
	last_number_b->next = NULL;
	temp_a = *stack;
	temp_b = *stack_b;
	while (temp_a->next)
		temp_a = temp_a->next;
	while (temp_b->next)
		temp_b = temp_b->next;
	temp_a->next = last_number_a;
	temp_b->next = last_number_b;
}

void	rrr(t_stack **stack, t_stack **stack_b)
{
	t_stack	*first_number_a;
	t_stack	*first_number_b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (*stack == NULL || (*stack)->next == NULL || *stack_b == NULL
		|| (*stack_b)->next == NULL)
		return ;
	temp_a = *stack;
	temp_b = *stack_b;
	while (temp_a->next && temp_a->next->next)
		temp_a = temp_a->next;
	while (temp_b->next && temp_b->next->next)
		temp_b = temp_b->next;
	first_number_a = temp_a->next;
	first_number_b = temp_b->next;
	temp_a->next = NULL;
	temp_b->next = NULL;
	first_number_a->next = *stack;
	first_number_b->next = *stack_b;
	*stack = first_number_a;
	*stack_b = first_number_b;
}
