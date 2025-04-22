/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:06:16 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/22 15:06:36 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stacks(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

void	free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
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
				return (free_words(words), free_stacks(stack), 1);
			push(stack, value);
			if (is_duplicate(*stack) == 0)
				return (free_words(words), free_stacks(stack), 1);
			i++;
		}
	}
	free_words(words);
	return (0);
}