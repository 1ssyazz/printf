/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:41:54 by msukri            #+#    #+#             */
/*   Updated: 2021/11/29 21:34:25 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_settings(t_set *set)
{
	int					number;
	static t_formatter	*functions_array[7] = {
	[e_char] = ft_solve_char,
	[e_string] = ft_solve_string,
	[e_pointer] = ft_solve_pointer,
	[e_decimal_int] = ft_solve_di,
	[e_u_dec_int] = ft_solve_uint,
	[e_u_hex_int] = ft_solve_hex,
	[e_percentage] = ft_solve_per};

	set->format++;
	ft_flag(set);
	ft_width(set);
	ft_precision(set);
	number = ft_select_format(set);
	functions_array[number](set);
}
