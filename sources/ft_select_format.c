/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:39:56 by msukri            #+#    #+#             */
/*   Updated: 2021/12/02 20:31:12 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_select_format(t_set *set)
{
	int		number;

	number = 0;
	if (*set->format == 'c')
		number = e_char;
	else if (*set->format == 's')
		number = e_string;
	else if (*set->format == 'p')
		number = e_pointer;
	else if (*set->format == 'd' || *set->format == 'i')
		number = e_decimal_int;
	else if (*set->format == 'u')
		number = e_u_dec_int;
	else if (*set->format == 'x' || *set->format == 'X')
		number = e_u_hex_int;
	else if (*set->format == '%')
		number = e_percentage;
	else
		ft_putstr("[ERROR]->");
	return (number);
}
