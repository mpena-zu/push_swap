/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:59:58 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/15 16:16:22 by mpena-zu         ###   ########.fr       */
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
	if (count_argc(*stack) != 3 && !is_sorted(*stack))
	{
		pb(stack, stack_b);
		get_first_min(stack, stack_b);
	}
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

void		sort_array(int	*array, int	size)
{
	int	i;
	int	temp;
	int	is_swapped;

	is_swapped = 1;
	while (is_swapped)
	{
		is_swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array [i + 1];
				array[i + 1] = temp;
				is_swapped = 1;
			}
			i++;
		}
	}
}

int		*make_array(t_stack *stack, int size)
{
	int		i;
	int		*array;
	t_stack	*temp;

	i = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	temp = stack;
	while (temp)
	{
		array[i] = temp->value;
		temp = temp->next;
		i++;
	}
	sort_array(array, size);
	return (array);
}
void	sort_big(t_stack **stack, t_stack **stack_b)
{
	int	*array;
	int	num_chunks;
	int	chunks_size;
	int	rest;
	int	size;
	int	i = 0;

	(void)stack_b;
	size = count_argc(*stack);
	num_chunks = 5;
	i = 0;
	chunks_size = size / num_chunks;
	rest = size % num_chunks;
	array = make_array(*stack, size);
	while (i < chunks_size)
	{
	}
}

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
