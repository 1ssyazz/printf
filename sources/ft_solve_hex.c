/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:37:32 by msukri            #+#    #+#             */
/*   Updated: 2021/11/30 21:05:52 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_hex(unsigned long long nbr, char format)
{
	if (nbr > 15)
	{
		ft_put_hex(nbr / 16, format);
		ft_put_hex(nbr % 16, format);
	}
	else
	{
		if (nbr < 10)
			ft_putchar(nbr + '0');
		else
		{
			if (format == 'x')
				ft_putchar(nbr - 10 + 'a');
			else
				ft_putchar(nbr - 10 + 'A');
		}
	}
}

static void	out_hex(t_set *set, unsigned long long nbr, int nl, int prec)
{
	set->width++;
	if (set->flag[e_minus] == '1')
	{
		ft_putnchar('0', prec);
		if (set->point != 1 || nbr != 0)
			ft_put_hex(nbr, *set->format);
		if (set->width > nl)
			while (--set->width > nl + prec)
				ft_putchar(' ');
	}
	else
	{
		if (set->width > nl && (set->point != 0 || set->flag[e_zero] != '1'))
			while (--set->width > nl + prec)
				ft_putchar(' ');
		if (set->width > nl && set->point == 0 && set->flag[e_zero] == '1')
			while (--set->width > nl + prec)
				ft_putchar('0');
		ft_putnchar('0', prec);
		if (set->point != 1 || nbr != 0)
			ft_put_hex(nbr, *set->format);
	}
}

void	ft_solve_hex(t_set *set)
{
	unsigned long long	nbr;
	unsigned long long	tmp;
	int					nbrlen;
	int					prec;

	nbr = (unsigned int)(va_arg(set->arg, unsigned long long));
	tmp = nbr;
	nbrlen = 0;
	if (tmp == 0 && set->point != 1)
		nbrlen++;
	while (tmp > 0)
	{
		tmp /= 16;
		nbrlen++;
	}
	prec = set->precision - nbrlen;
	if (prec < 0)
		prec = 0;
	if (set->width <= set->precision)
		set->total_len = set->total_len + prec;
	if (set->width > nbrlen && set->width > set->precision)
		set->total_len = set->total_len + (set->width - nbrlen);
	out_hex(set, nbr, nbrlen, prec);
	set->total_len = set->total_len + nbrlen;
	set->format++;
}
