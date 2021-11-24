/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:32:23 by msukri            #+#    #+#             */
/*   Updated: 2021/11/23 10:36:32 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long long nbr)
{
	int	nbrlen;

	nbrlen = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = nbr * (-1);
	while (nbr > 0)
	{
		nbrlen++;
		nbr /= 10;
	}
	return (nbrlen);
}
