/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:51:22 by msukri            #+#    #+#             */
/*   Updated: 2021/05/03 19:51:22 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strnew(size_t size);

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnchar(char c, int n);

char	*ft_strcpy(char *dst, char *src);
size_t	ft_strlen(const char *str);
int		ft_nbrlen(long long nbr);
int		ft_atoi(const char *str);
char	*ft_strncpy(char *dst, const char *src, size_t len);

#endif