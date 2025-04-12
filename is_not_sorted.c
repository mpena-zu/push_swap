/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:59:58 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/12 16:21:45 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_stack(t_stack **stack)
{
	int		first;
	int		second;
	int		third;

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

void    init(t_stack **stack, int i)
{
	if(!is_sorted(*stack))
	{
		if (i == 2)
			sa(stack);
		if (i == 3)
			sort_three_stack(stack);
	}
}
