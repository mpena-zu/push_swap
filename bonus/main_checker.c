/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:57:31 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/23 13:01:15 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*line;
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
			return (ft_printf("Error\n"), 1);
		i++;
	}
	line = get_next_line(0);
	while (line != NULL)
	{
		read_input(&stack, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	final_check(&stack, &stack_b);
	return (0);
}
