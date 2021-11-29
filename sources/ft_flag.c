/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:19:24 by msukri            #+#    #+#             */
/*   Updated: 2021/11/29 16:24:30 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flag(t_set *set)
{
	set->flag[e_minus] = '0';
	set->flag[e_zero] = '0';
	while (*set->format == '-' || *set->format == '0')
	{
		if (*set->format == '-')
			set->flag[e_minus] = '1';
		if (*set->format == '0')
			set->flag[e_zero] = '1';
		set->format++;
	}
}
