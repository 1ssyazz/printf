/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:29:28 by msukri            #+#    #+#             */
/*   Updated: 2021/12/01 21:04:38 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ptr_hex(unsigned long long addr)
{
	if (addr > 15)
	{
		ptr_hex(addr / 16);
		ptr_hex(addr % 16);
	}
	else
	{
		if (addr > 9)
			ft_putchar(addr - 10 + 'a');
		else
			ft_putchar(addr + '0');
	}
}

static void	out_ptr2(t_set *set, unsigned long long addr, int addrlen, int prec)
{
	if (set->width > addrlen && (set->point != 0 || set->flag[e_zero] != '1'))
		while (--set->width > addrlen + prec)
			ft_putchar(' ');
	if (set->width > addrlen && set->point == 0 && set->flag[e_zero] == '1')
		ft_putstr("0x");
	while (--set->width > addrlen + prec)
		ft_putchar('0');
	if (set->width < addrlen && set->point != 0)
		ft_putstr("0x");
	ft_putnchar('0', prec);
	if (set->point != 1 || addr != 0)
		ptr_hex(addr);
}

static void	out_ptr(t_set *set, unsigned long long addr, int addrlen, int prec)
{
	set->width++;
	if (set->flag[e_minus] == '1')
	{
		ft_putstr("0x");
		ft_putnchar('0', prec);
		if (set->point != 1 || addr != 0)
			ptr_hex(addr);
		if (set->width > addrlen)
			while (--set->width > addrlen + prec)
				ft_putchar(' ');
	}
	else
		out_ptr2(set, addr, addrlen, prec);
}

void	ft_solve_pointer(t_set *set)
{
	unsigned long long	addr;
	unsigned long long	tmp;
	int					addrlen;
	int					prec;

	addr = (unsigned long long)va_arg(set->arg, void *);
	addrlen = 2;
	tmp = addr;
	if (addr == 0 && set->point != 1)
		addrlen++;
	while (tmp > 0)
	{
		tmp /= 16;
		addrlen++;
	}
	prec = set->precision - addrlen + 2;
	if (prec < 0)
		prec = 0;
	if (prec != 0 && set->width <= set->precision)
		set->total_len = set->total_len + prec;
	if (set->width > addrlen && set->width > set->precision)
		set->total_len = set->total_len + (set->width - addrlen);
	out_ptr(set, addr, addrlen, prec);
	set->total_len = set->total_len + addrlen;
	set->format++;
}
