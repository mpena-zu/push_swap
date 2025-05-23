/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:33:06 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/04/24 15:20:51 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stdint.h>

int	ft_printf(char const *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_printf_u(unsigned int n);
int	ft_hexa(unsigned int n);
int	ft_hexa_upper(unsigned int n);
int	ft_printf_p(void *n);

#endif
