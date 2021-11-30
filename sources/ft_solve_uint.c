/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:49:57 by msukri            #+#    #+#             */
/*   Updated: 2021/11/30 20:12:44 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_put_u(unsigned long long nbr)
{
	if (nbr > 9)
	{
		ft_put_u(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + '0');
}

static void	u_width(t_set *set, unsigned long long nbr, int nbrlen, int prec)
{
	if (set->flag[e_zero] == '1' && (set->flag[e_minus] != '1' && prec == 0))
	{
		if (set->point != 0)
			while (--set->width > nbrlen)
				ft_putchar(' ');
		else
			while (--set->width > nbrlen)
				ft_putchar('0');
	}
	else
	{
		if (set->point != 1 || nbr != 0)
			while (--set->width > nbrlen + prec)
				ft_putchar(' ');
		else
			while (--set->width > 0)
				ft_putchar(' ');
	}
}

static void	out_u(t_set *set, unsigned long long nbr, int nbrlen, int prec)
{
	if (set->flag[e_minus] == '1' && (set->point != 1 || nbr != 0))
	{
		ft_putnchar('0', prec);
		ft_put_u(nbr);
	}
	if (set->width > nbrlen)
	{
		set->width++;
		u_width(set, nbr, nbrlen, prec);
	}
	if (set->flag[e_minus] != '1' && (set->point != 1 || nbr != 0))
	{
		ft_putnchar('0', prec);
		ft_put_u(nbr);
	}
}

void	ft_solve_uint(t_set *set)
{
	unsigned long long	nbr;
	unsigned long long	tmp;
	int					nbrlen;
	int					prec;

	nbr = (unsigned int)(va_arg(set->arg, long long));
	nbrlen = 0;
	tmp = nbr;
	if (set->point != 1 && tmp == 0)
		nbrlen++;
	while (tmp > 0)
	{
		tmp /= 10;
		nbrlen++;
	}
	prec = set->precision - nbrlen;
	if (prec < 0)
		prec = 0;
	if (set->width <= set->precision)
		set->total_len = set->total_len + prec;
	if (set->width > nbrlen && set->width > set->precision)
		set->total_len = set->total_len + (set->width - nbrlen);
	out_u(set, nbr, nbrlen, prec);
	set->total_len = set->total_len + nbrlen;
	set->format++;
}
