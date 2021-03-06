/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:17:15 by msukri            #+#    #+#             */
/*   Updated: 2021/11/30 14:14:06 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(long long nbr)
{
	if (nbr < 0)
		ft_putnbr(nbr * -1);
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

static void	di_width(t_set *set, int nbr, int nbrlen, int prec)
{
	if (set->flag[e_zero] == '1' && prec == 0)
	{
		if (set->point != 0)
			while (--set->width > nbrlen)
				ft_putchar(' ');
		if (nbr < 0)
			ft_putchar('-');
		if (set->point == 0)
			while (--set->width > nbrlen)
				ft_putchar('0');
	}
	else
	{
		while (--set->width > (nbrlen + prec))
			ft_putchar(' ');
		if (nbr < 0)
			ft_putchar('-');
	}
	ft_putnchar('0', prec);
	if (set->point != 1 || nbr != 0)
		ft_putnbr(nbr);
}

static void	out_di(t_set *set, int nbr, int nbrlen, int prec)
{
	if (set->width > nbrlen && set->flag[e_minus] != '1')
		di_width(set, nbr, nbrlen, prec);
	else
	{
		if (nbr < 0)
			ft_putchar('-');
		ft_putnchar('0', prec);
		if (set->point != 1 || nbr != 0)
			ft_putnbr(nbr);
		if (set->flag[e_minus] == '1' && set->width > nbrlen)
			while (--set->width > nbrlen + prec)
				ft_putchar(' ');
	}
}

void	ft_solve_di(t_set *set)
{
	long long	nbr;
	int			nbrlen;
	int			prec;

	nbr = (int)(va_arg(set->arg, long long));
	nbrlen = ft_nbrlen(nbr);
	prec = set->precision - nbrlen;
	if (nbr < 0)
		nbrlen++;
	if (set->point == 1 && nbr == 0)
		nbrlen--;
	if (prec < 0)
		prec = 0;
	if (set->width <= set->precision)
		set->total_len = set->total_len + prec;
	if (set->width > nbrlen && set->width > set->precision)
	{
		set->total_len = set->total_len + (set->width - nbrlen);
		set->width++;
	}
	out_di(set, nbr, nbrlen, prec);
	set->total_len = set->total_len + nbrlen;
	set->format++;
}
