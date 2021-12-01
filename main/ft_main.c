/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:35:57 by msukri            #+#    #+#             */
/*   Updated: 2021/12/01 21:57:16 by msukri           ###   ########.fr       */
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
	ft_printf("Character\n");
	ft_printf("|%0c|\n", s);
	printf("|%c|\n", s);
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%05c| |%-5c|", s, s)));
	ft_printf("String\n");
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%.*s|", 20, t)));
	printf("  LENGTH printf : %d\n", (printf("|%.*s|", 20, t)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%.*s|", 222, "okkkkkkkkkkkkkkkkk")));
	printf("  LENGTH printf : %d\n", (printf("|%.*s|", 222, "okkkkkkkkkkkkkkkkk")));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%-020s|", t)));
	printf("  LENGTH printf : %d\n", (printf("|%20s|", t)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%1s|", "")));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%6.9s|", t)));
	printf("  LENGTH printf : %d\n", (printf("|%6.9s|", t)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%.2s|", t)));
	ft_printf("Pointer\n");
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%030p|", v)));
	printf("  LENGTH ft_printf : %d\n", (printf("|%30p|", v)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%-.1p|", 0)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%.1p|", 0)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%-20.8p|", v)));
	ft_printf("Decimal\n");
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%.0d|", 0)));
	printf("  LENGTH ft_printf : %d\n", (printf("|%030d|", 2312)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%-6.3d|", 32)));
	printf("  LENGTH printf : %d\n", (printf("|%2.3d|", -32)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%04d|", 32)));
	printf("  LENGTH printf : %d\n", (printf("|%-4.3d|", 32)));
	ft_printf("Return:%d\n", (ft_printf("|%d|", -1)));
	ft_printf("Unsigned\n");
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%-6.3u|", 32)));
	printf("  LENGTH printf : %d\n", (printf("|%-6.3d|", 2312)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%.0u|", 0)));
	printf("  LENGTH printf : %d\n", (printf("|%5.0d|", 2312)));
	ft_printf("Hexadecimal\n");
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%010x|", 2312)));
	printf("  LENGTH printf : %d\n", (printf("|%-10.6x|", 2312)));
	ft_printf("  LENGTH ft_printf : %d\n", (ft_printf("|%010x|", 0)));
	printf("  LENGTH printf : %d\n", (printf("|%10.0x|", 0)));
	ft_printf("|%10.6x|\n", 2312);
	ft_printf("|%x|\n", 2312);
	ft_printf("|%X|\n", 2312);
	ft_printf("Percent\n");
	ft_printf("|%%|\n");
	printf("|%%|\n");
	return (0);
}
