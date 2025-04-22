/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 11:26:25 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/22 12:15:45 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack	*stack_b;

	stack = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (check_split(argv[i], &stack))
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	i = count_argc(stack);
	init(&stack, &stack_b, i);
    free_stacks(&stack);
    free_stacks(&stack_b);
	return (0);
}
