/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:04:41 by msukri            #+#    #+#             */
/*   Updated: 2021/11/19 16:28:15 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_solve_char(t_set *set)
{
	char	c;

	c = va_arg(set->arg, int);
	if (set->flag[e_minus] != 1)
		ft_putchar(c);
	set->total_len++;
	set->format++;
}
