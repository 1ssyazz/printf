/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:01:19 by msukri            #+#    #+#             */
/*   Updated: 2021/11/22 14:37:38 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_solve_string(t_set *set)
{
	char	*tmp;
	char	*str;
	int		strlen;

	tmp = va_arg(set->arg, char *);
	if (tmp == NULL)
		tmp = "(null)";
	str = ft_strnew(ft_strlen(tmp));
	ft_strcpy(str, tmp);
	strlen = ft_strlen(str);
	ft_putstr(str);
	set->total_len = set->total_len + strlen;
	set->format++;
	free(str);
}
