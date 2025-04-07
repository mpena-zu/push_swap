/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:26:41 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/07 17:53:12 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("NULL\n");
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
		printf("El valor del argumento del stack es: %d\n", value);
		i++;
	}
	printf("\n");
	
	printf("Antes de sa:\n");
	print_stack(stack);
	printf("\n");
	
	printf("Después de sa:\n");
	sa(&stack);
	print_stack(stack);
	printf("\n");
	
	printf("Antes de pb:\n");
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");
	
	printf("Despues de pb:\n");
	pb(&stack, &stack_b);
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");
	
	printf("Después 2 de pb:\n");
	pb(&stack, &stack_b);
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");

	printf("Después 3 de pb:\n");
	pb(&stack, &stack_b);
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");

	printf("Después 4 de pb:\n");
	pb(&stack, &stack_b);
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");

	printf("Antes de sb:\n");
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");

	printf("Después de sb:\n");
	sb(&stack_b);
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");

	/* printf("Antes de ss:\n");
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");

	printf("Despues de ss:\n");
	ss(&stack, &stack_b);
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");

	printf("Antes de pa:\n");
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");
	
	printf("Despues de pa:\n");
	pa(&stack, &stack_b);
	print_stack(stack);
	print_stack(stack_b);
	printf("\n"); */
	
	printf("Antes de ra:\n");
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");
	
	printf("Despues de ra:\n");
	ra(&stack);
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");
	
	printf("Antes de rb:\n");
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");
	
	printf("Despues de rb:\n");
	rb(&stack_b);
	print_stack(stack);
	print_stack(stack_b);
	printf("\n");
	return (0);
}

