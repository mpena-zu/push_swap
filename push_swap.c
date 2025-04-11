/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:26:41 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/08 16:50:51 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_debug(t_stack *stack)
{
	while (stack != NULL)
	{
		ft_printf("%d -> ", stack->value);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

int	check_long(long value)
{
	if (value < -2147483648 || value > 2147483647)
		return (0);
	return (1);
}

int	is_sorted(t_stack *stack)
{
	if (!stack || !stack->next)
		return (1);
	while (stack->next)
	{
		if (stack->value < stack->next->value)
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

int		is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	push(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
}

int	check_split(char *argv, t_stack **stack)
{
	char	**words;
	int		i;
	long	value;

	if (argv == NULL || *argv == '\0' || (argv[0] == ' ' && ft_strlen(argv) == 1))
		return (1);
	words = ft_split(argv, ' ');
	i = 0;
	if (words != NULL)
	{
		while (words[i] != NULL)
		{
			value = ft_atol(words[i]);
			if (!check_long(value))
			{
				ft_printf("Error, numero grande\n"); //puedo juntarlo con el de abajo
				return (1);
			}
			if (!is_number(words[i]))
			{
				ft_printf("Error, no es numero\n"); //esto luego hay que quitarlo
				return (1);
			}
			push(stack, value);
			i++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_stack		*stack;
	//t_stack		*stack_b;

	stack = NULL;
	//stack_b = NULL;
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
		if (is_duplicate(stack) == 0)
		{
			ft_printf("Error, duplicado\n");
			return (1);
		}
		/*if (is_sorted(stack) == 0)
		{
			ft_printf("No esta ordenado\n");
			return (1);
		} */
		i++;
	}
	print_stack_debug(stack);
	return (0);
}
