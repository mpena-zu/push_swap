/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:08:39 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/22 14:22:59 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	cost_analysis_a(t_stack *stack, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = count_argc(stack);
	len_b = count_argc(stack_b);
	while (stack)
	{
		stack->push_cost = stack->index;
		if (!(stack->above_median))
			stack->push_cost = len_a - (stack->index);
		if (stack->target_node->above_median)
			stack->push_cost += stack->target_node->index;
		else
			stack->push_cost += len_b - (stack->target_node->index);
		stack = stack->next;
	}
}
