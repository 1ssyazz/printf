/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:16:15 by msukri            #+#    #+#             */
/*   Updated: 2021/12/01 14:01:53 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	per_flagwidth(t_set *set)
{
	if (set->width > 1)
	{
		set->total_len = set->total_len + (set->width - 1);
		set->width++;
		if (set->flag[e_zero] == '1' && set->flag[e_minus] != '1')
			while (--set->width > 1)
				ft_putchar('0');
		else
			while (--set->width > 1)
				ft_putchar(' ');
	}
}

void	ft_solve_per(t_set *set)
{
	if (set->flag[e_minus] == '1')
		ft_putchar('%');
	per_flagwidth(set);
	if (set->flag[e_minus] != '1')
		ft_putchar('%');
	set->total_len++;
	set->format++;
}
