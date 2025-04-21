/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_metod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:44:43 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/21 16:25:58 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *stack)
{
	long			min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node); 
}

t_stack	*find_max(t_stack *stack)
{
	long			max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

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

void	rev_rotate_both(t_stack **stack,t_stack **stack_b, t_stack *cheapest_node)
{
	while (*stack_b != cheapest_node->target_node
		&& *stack != cheapest_node)
		rrr(stack, stack_b);
	current_index(*stack);
	current_index(*stack_b);
}

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
		++i;
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

void	init_nodes_a(t_stack *stack, t_stack *stack_b)
{
	current_index(stack);
	current_index(stack_b);
	set_target_a(stack, stack_b);
	cost_analysis_a(stack, stack_b);
	set_cheapest(stack);
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

void	set_target_b(t_stack *stack, t_stack *stack_b)
{
	t_stack		*current_a;
	t_stack		*target_node;
	long		best_match_index;

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

void	init_nodes_b(t_stack *stack, t_stack *stack_b)
{
	current_index(stack);
	current_index(stack_b);
	set_target_b(stack, stack_b);
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
