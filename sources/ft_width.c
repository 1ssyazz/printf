/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:04:29 by msukri            #+#    #+#             */
/*   Updated: 2021/11/29 17:36:11 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_width(t_set *set)
{
	set->width = 0;
	if (*set->format == '*')
	{
		set->width = va_arg(set->arg, int);
		if (set->width < 0)
		{
			set->width = set->width * -1;
			set->flag[e_minus] = '1';
		}
		set->format++;
	}
	if (*set->format >= '0' && *set->format <= '9')
		set->width = ft_atoi(set->format);
	while (*set->format >= '0' && *set->format <= '9')
		set->format++;
}
