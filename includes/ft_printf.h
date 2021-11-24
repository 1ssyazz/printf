/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:57:06 by msukri            #+#    #+#             */
/*   Updated: 2021/11/15 12:57:06 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

enum				e_flags
{
	e_minus,
	e_zero
};

enum				e_printables
{
	e_char,
	e_string,
	e_pointer,
	e_decimal_int,
	e_u_dec_int,
	e_u_hex_int,
	e_percentage,
	e_length,
};

typedef struct s_set
{
	const char		*format;
	va_list			arg;
	int				width;
	int				precision;
	char			flag[2];
	int				point;
	int				total_len;
}					t_set;

int					ft_printf(const char *format, ...);
void				ft_solve_char(t_set *set);
void				ft_solve_string(t_set *set);
void				ft_solve_pointer(t_set *set);
void				ft_solve_di(t_set *set);
void				ft_solve_uint(t_set *set);
void				ft_solve_hex(t_set *set);
void				ft_solve_per(t_set *set);

void				ft_settings(t_set *set);

typedef void		t_formatter(t_set *set);
int					ft_select_format(t_set *set);

#endif
