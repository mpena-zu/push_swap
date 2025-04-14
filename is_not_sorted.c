/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:59:58 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/14 16:58:40 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack **stack, t_stack **stack_b, int min)
{
	while ((*stack)->value != min)
	{
		if ((*stack)->next->value == min || (*stack)->next->next->value == min)
			ra(stack);
		else
			rra(stack);
	}
	pb(stack, stack_b);
	if (count_argc(*stack) != 3)
		get_first_min(stack, stack_b);
}

void	get_first_min(t_stack **stack, t_stack **stack_b)
{
	int		min;
	t_stack	*temp;

	min = (*stack)->value;
	temp = (*stack);
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	get_position(stack, stack_b, min);
}

void	sort_three_stack(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second > third)
	{
		ra(stack);
		sa(stack);
	}
	else if (first > second && second < third && first < third)
		sa(stack);
	else if (first < second && second > third && first > third)
		rra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else
		ra(stack);
}

/* int		sort_array(t_stack **stack)
{
	int		i;
	int		*temp;
	
	temp = malloc(stack) * sizeof(int);
	if (!temp)
		return (NULL);
	i = 0;
	while ((*stack))
	{
		temp[i] = (*stack)->value;
		i++;
		*stack = (*stack)->next;
	}
	return (temp);
}
void	sort_big(t_stack **stack, t_stack **stack_b)
{
	sort_array(stack);
} */

void	init(t_stack **stack, t_stack **stack_b, int i)
{
	if (!is_sorted(*stack))
	{
		if (i == 2)
			sa(stack);
		else if (i == 3)
			sort_three_stack(stack);
		else if (i == 4 || i == 5)
		{
			get_first_min(stack, stack_b);
			if (!is_sorted(*stack))
				sort_three_stack(stack);
			pa(stack, stack_b);
			if (i == 5)
				pa(stack, stack_b);
		}
	}
}
