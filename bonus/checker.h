/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:25:59 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/22 22:00:24 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 1000
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;
int					check_split(char *argv, t_stack **stack);
void	free_stacks(t_stack **stack);
void	free_words(char **words);
void	push(t_stack **stack, int value);
int					check_long(long value);
long				ft_atol(const char *nptr);
int					is_sorted(t_stack *stack);
int					is_duplicate(t_stack *stack);
int					is_number(const char *str);
void				push(t_stack **stack, int value);
void    read_input(t_stack **stack, t_stack **stack_b, char *line);
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
char	*get_next_line(int fd);
void	final_check(t_stack **stack, t_stack **stack_b);
void	check_error(t_stack **stack, t_stack **stack_b);

#endif