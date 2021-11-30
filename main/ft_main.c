/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:35:57 by msukri            #+#    #+#             */
/*   Updated: 2021/11/30 08:33:25 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	char	s;
	char	*t;
	char	*u;
	char	**v;

	s = 'A';
	t = "HelloWorld";
	u = "asd";
	*v = &s;
	ft_printf("%c\n", s);
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%05c| |%-5c|", s, s)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%s|", t)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%.2s| |%15.9s|", t, t)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%.s|", t)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%p|", v)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%020.17p|", v)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%-20.8p|", v)));
	ft_printf("Return:%d", (ft_printf("|%d|\n", -1)));
	ft_printf("|%i|\n", 0);
	ft_printf("|%i|\n", -250);
	ft_printf("|%u|\n", 2312);
	ft_printf("|%u|\n", -2312);
	ft_printf("|%x|\n", 231212);
	ft_printf("|%X|\n", 231212);
	ft_printf("%%%%\n");
	return (0);
}
