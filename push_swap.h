/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:27:01 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/22 12:16:02 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
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
void				sort_three_stack(t_stack **stack);
void	free_stacks(t_stack **stack);
void	free_words(char **words);

void	sort_stacks(t_stack **stack, t_stack **stack_b);
t_stack	*get_cheapest(t_stack *stack);
void	rev_rotate_both(t_stack **stack,t_stack **stack_b, t_stack *cheapest_node);
void	current_index(t_stack *stack);
void	set_target_a(t_stack *stack, t_stack *stack_b);
void	cost_analysis_a(t_stack *stack, t_stack *stack_b);
void	set_cheapest(t_stack *stack);
void	init_nodes_a(t_stack *stack, t_stack *stack_b);
void	rotate_both(t_stack **stack, t_stack **stack_b, t_stack *cheapest_node);
void	move_a_to_b(t_stack **stack, t_stack **stack_b);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	move_b_to_a(t_stack **stack, t_stack **stack_b);
void	min_on_top(t_stack **stack);
void	set_target_b(t_stack *stack, t_stack *stack_b);
void	init_nodes_b(t_stack *stack, t_stack *stack_b);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

#endif