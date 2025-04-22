/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:05:27 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/22 14:23:17 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = count_argc(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_a(t_stack *stack, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (stack)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack->target_node = find_max(stack_b);
		else
			stack->target_node = target_node;
		stack = stack->next;
	}
}

void	set_target_b(t_stack *stack, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		current_a = stack;
		while (current_a)
		{
			if (current_a->value > stack_b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = find_min(stack);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_a(t_stack *stack, t_stack *stack_b)
{
	current_index(stack);
	current_index(stack_b);
	set_target_a(stack, stack_b);
	cost_analysis_a(stack, stack_b);
	set_cheapest(stack);
}

void	init_nodes_b(t_stack *stack, t_stack *stack_b)
{
	current_index(stack);
	current_index(stack_b);
	set_target_b(stack, stack_b);
}
