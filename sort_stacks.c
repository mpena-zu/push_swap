/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:44:43 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/22 11:13:09 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_on_top(t_stack **stack)
{
	while ((*stack)->value != find_min(*stack)->value)
	{
		if (find_min(*stack)->above_median)
			ra(stack);
		else
			rra(stack);
	}
}

void	sort_stacks(t_stack **stack, t_stack **stack_b)
{
	int	size;

	size = count_argc(*stack);
	if (size-- > 3 && !is_sorted(*stack))
		pb(stack, stack_b);
	if (size-- > 3 && !is_sorted(*stack))
		pb(stack, stack_b);
	while (size-- > 3 && !is_sorted(*stack))
	{
		init_nodes_a(*stack, *stack_b);
		move_a_to_b(stack, stack_b);
	}
	sort_three_stack(stack);
	while (*stack_b)
	{
		init_nodes_b(*stack, *stack_b);
		move_b_to_a(stack, stack_b);
	}
	current_index(*stack);
	min_on_top(stack);
}
