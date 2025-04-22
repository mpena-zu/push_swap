/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:12:42 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/22 14:23:25 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_both(t_stack **stack, t_stack **stack_b,
		t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack != cheapest_node)
		rrr(stack, stack_b);
	current_index(*stack);
	current_index(*stack_b);
}

void	rotate_both(t_stack **stack, t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node && *stack != cheapest_node)
		rr(stack, stack_b);
	current_index(*stack);
	current_index(*stack_b);
}

void	move_a_to_b(t_stack **stack, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(stack, stack_b, cheapest_node);
	prep_for_push(stack, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack, stack_b);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_b_to_a(t_stack **stack, t_stack **stack_b)
{
	prep_for_push(stack, (*stack_b)->target_node, 'a');
	pa(stack, stack_b);
}
