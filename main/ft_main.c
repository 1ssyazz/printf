/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:35:57 by msukri            #+#    #+#             */
/*   Updated: 2021/11/24 16:54:13 by msukri           ###   ########.fr       */
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
	ft_printf("%d", (ft_printf("%s\n", t)));
	ft_printf("%p\n", v);
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
