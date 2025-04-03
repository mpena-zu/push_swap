/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:27:01 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/03/24 13:27:04 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>

typedef struct s_stack_a
{
    int               value;
    struct  s_stack_a *next;    
}   t_stack_a;

typedef struct s_stack_b
{
    int               value;
    struct  s_stack_b *next;    
}   t_stack_b;
void    sa(t_stack_a **stack_a);

#endif