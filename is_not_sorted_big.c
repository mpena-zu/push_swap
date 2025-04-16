/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_sorted_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:34:49 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/16 18:18:24 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valuate(t_stack **stack, t_stack **stack_b)
{
	if ((*stack_b)->value < (*stack)->value)
		pa(stack, stack_b);
	else
	{
		while ((*stack_b)->value > (*stack)->value)
			ra(stack);
		if ((*stack_b)->value < (*stack)->value)
			pa(stack, stack_b);
	}
}

int		get_first_min_to_stackb(t_stack **stack_b)
{
	int		min;
	t_stack	*temp;

	min = (*stack_b)->value;
	temp = (*stack_b);
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

void	move_to_stack_b(t_stack **stack, t_stack **stack_b)
{
	int	size;

	size = count_argc(*stack);
	while (size > 3)
	{
		pb(stack, stack_b);
		size--;
	}
	sort_three_stack(stack);
}

void	sort_big(t_stack **stack, t_stack **stack_b)
{
	int	min;

	move_to_stack_b(stack, stack_b);
	while (*stack_b)
	{
		min = get_first_min_to_stackb(stack_b);
		while ((*stack_b)->value != min)
			rb(stack_b);
		valuate(stack, stack_b);
	}
	while (!is_sorted(*stack))
		ra(stack);
}
