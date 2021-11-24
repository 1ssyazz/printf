/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:29:56 by msukri            #+#    #+#             */
/*   Updated: 2021/11/19 16:12:36 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_set		*set;
	int			length;

	set = (t_set *)ft_calloc(1, sizeof(t_set));
	if (!set)
		return (-1);
	va_start(set->arg, format);
	set->format = format;
	while (*set->format)
	{
		while (*set->format && *set->format != '%')
		{
			ft_putchar(*set->format);
			set->format++;
			set->total_len++;
		}
		if (*set->format && *set->format == '%')
			ft_settings(set);
	}
	va_end(set->arg);
	length = set->total_len;
	free(set);
	return (length);
}
