/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:27:01 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/08 15:29:28 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>

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

#endif