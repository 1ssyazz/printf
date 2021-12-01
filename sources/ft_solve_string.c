/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:01:19 by msukri            #+#    #+#             */
/*   Updated: 2021/12/01 15:23:26 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	str_width(t_set *set, int strlen)
{
	if (set->width > strlen)
	{
		set->total_len = set->total_len + (set->width - strlen);
		while (set->width > strlen)
		{
			ft_putchar(' ');
			set->width--;
		}
	}
}

static void	out_strflag(t_set *set, char *str, int strlen)
{
	if (set->flag[e_minus] == '1' && set->point != 1)
		ft_putstr(str);
	str_width(set, strlen);
	if (set->flag[e_minus] != '1' && set->point != 1)
		ft_putstr(str);
	set->total_len = set->total_len + strlen;
	set->format++;
	free(str);
}

void	ft_solve_string(t_set *set)
{
	char	*tmp;
	char	*str;
	int		strlen;

	tmp = va_arg(set->arg, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (set->precision == 0)
	{
		str = ft_strnew(ft_strlen(tmp));
		ft_strcpy(str, tmp);
	}
	else
	{
		str = ft_strnew(ft_strlen(tmp));
		ft_strncpy(str, tmp, set->precision);
	}
	if (set->point == 1)
		strlen = 0;
	else
		strlen = ft_strlen(str);
	out_strflag(set, str, strlen);
}
