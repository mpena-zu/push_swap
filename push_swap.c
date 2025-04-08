/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:26:41 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/08 16:19:48 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("NULL\n");
}

int	is_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_duplicate(t_stack *stack)
{
	t_stack		*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->value == temp->value)
				return (0);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

void	push(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = *stack;
	*stack = new_node;
}

int	main(int argc, char **argv)
{
	int			value;
	int			i;
	t_stack		*stack;
	t_stack		*stack_b;

	stack = NULL;
	stack_b = NULL;
	i = 1;
	if (argc == 1)
	{
		printf("Error\n");
		return (1);
	}
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (value == 0)
		{
			printf("Error, letra\n");
			return (1);
		}
		push(&stack, value);
		if (is_duplicate(stack) == 0)
		{
			printf("Error, duplicado\n");
			return (0);
		}
		if (is_sorted(stack) == 0)
		{
			printf("No esta ordenado\n");
			return (0);
		}
		i++;
	}
	return (0);
}
