/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:25:45 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/22 23:24:24 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	final_check(t_stack **stack, t_stack **stack_b)
{
	if (is_sorted(*stack))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(stack);
	free_stacks(stack_b);
}

void	check_error(t_stack **stack, t_stack **stack_b)
{
	free_stacks(stack);
	free_stacks(stack_b);
	ft_printf("Error\n");
	exit(1);
}

void    read_input(t_stack **stack, t_stack **stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		sa(stack);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(stack, stack_b);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		pa(stack, stack_b);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		pb(stack, stack_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		ra(stack);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		rr(stack, stack_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(stack);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(stack, stack_b);
	else
		check_error(stack, stack_b);
}
