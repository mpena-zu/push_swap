/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:26:41 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/03/24 13:26:43 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_atoi.c"

void	push(t_stack **stack, int value)
{
	t_stack *new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return;
	new_node->value = value;
    new_node->next = *stack;
    *stack = new_node;
}
int main(int argc, char **argv)
{
	int			value;
	int			i;
	t_stack		*stack;

	stack = NULL;
	i = 1;
	if (argc == 1)
	{
		printf("Error\n");
		return (1);
	}
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if(value == 0)
		{
			printf("Error, letra\n");
			return (1);
		}
		push(&stack, value);
		printf("El valor del argumento del stack es: %d\n", value);
		i++;
	}
	return (0);
}
