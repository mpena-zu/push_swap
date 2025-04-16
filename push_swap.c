/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:26:41 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/16 18:19:10 by mpena-zu         ###   ########.fr       */
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

int	count_argc(t_stack *stack)
{
	int	cont;

	if (!stack)
		return (0);
	cont = 0;
	while (stack)
	{
		stack = stack->next;
		cont++;
	}
	return (cont);
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
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_duplicate(t_stack *stack)
{
	t_stack	*temp;

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

int	is_number(const char *str)
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

	if (!argv || *argv == '\0' || (argv[0] == ' ' && ft_strlen(argv) == 1))
		return (1);
	words = ft_split(argv, ' ');
	i = 0;
	if (words != NULL)
	{
		while (words[i] != NULL)
		{
			value = ft_atol(words[i]);
			if (!check_long(value) || !is_number(words[i]))
				return (1);
			push(stack, value);
			if (is_duplicate(*stack) == 0)
				return (1);
			i++;
		}
	}
	return (0);
}

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
	//print_stack_debug(stack);
	//print_stack_debug(stack_b);
	return (0);
}
