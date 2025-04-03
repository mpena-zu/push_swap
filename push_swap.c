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
#include "libft/libft.h"

int	is_sorted(t_stack_a *stack_a)
{
	if (!stack_a || !stack_a->next)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void print_stack(t_stack_a *stack)
{
    while (stack != NULL)
    {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}

void	push(t_stack_a **stack_a, int value)
{
	t_stack_a *new_node;

	new_node = malloc(sizeof(t_stack_a));
	if (!new_node)
		return;
	new_node->value = value;
    new_node->next = *stack_a;
    *stack_a = new_node;
}
int main(int argc, char **argv)
{
	int			value;
	int			i;
	t_stack_a	*stack_a;

	stack_a = NULL;
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
		push(&stack_a, value);
		printf("El valor del argumento del stack es: %d\n", value);
		i++;
	}
	printf("Antes de sa:\n");
    print_stack(stack_a);
	if (!is_sorted(stack_a))
		sa(&stack_a);	printf("Después de sa:\n");
    print_stack(stack_a);
	return (0);
}
