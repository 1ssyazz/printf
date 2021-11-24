/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:16:15 by msukri            #+#    #+#             */
/*   Updated: 2021/11/23 15:29:59 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_solve_per(t_set *set)
{
	if (set->flag[e_minus] != '1')
		ft_putchar('%');
	set->total_len++;
	set->format++;
}
