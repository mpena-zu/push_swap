/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:27:01 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/14 13:22:21 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **stack);
void				pb(t_stack **stack, t_stack **stack_b);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack, t_stack **stack_b);
void				pa(t_stack **stack, t_stack **stack_b);
void				ra(t_stack **stack);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack, t_stack **stack_b);
void				rra(t_stack **stack);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack, t_stack **stack_b);
long				ft_atol(const char *nptr);
int					is_sorted(t_stack *stack);
int					check_long(long value);
int					is_duplicate(t_stack *stack);
int					is_number(const char *str);
void				push(t_stack **stack, int value);
int					check_split(char *argv, t_stack **stack);
void				init(t_stack **stack, t_stack **stack_b, int i);
int					count_argc(t_stack *stack);
void				get_first_min(t_stack **stack, t_stack **stack_b);

#endif