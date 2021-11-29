/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:04:41 by msukri            #+#    #+#             */
/*   Updated: 2021/11/29 17:47:56 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	char_flagwidth(t_set *set)
{
	if (set->width > 1)
	{
		set->total_len = set->total_len + (set->width - 1);
		if (set->flag[e_zero] == '1' && set->flag[e_minus] != '1')
			while (--set->width > 0)
				ft_putchar('0');
		else
			while (--set->width > 0)
				ft_putchar(' ');
	}
}

void	ft_solve_char(t_set *set)
{
	char	c;

	c = va_arg(set->arg, int);
	if (set->flag[e_minus] == '1')
		ft_putchar(c);
	char_flagwidth(set);
	if (set->flag[e_minus] != '1')
		ft_putchar(c);
	set->total_len++;
	set->format++;
}
