/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:45:48 by mmehran           #+#    #+#             */
/*   Updated: 2021/04/21 09:49:40 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_get_number(char **str)
{
	unsigned int	result;

	result = 0;
	while (ft_isdigit(**str))
		result = result * 10 + (*((*str)++) - '0');
	return (result);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_unbrlen(unsigned long long nbr, int blen)
{
	int	len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr && ++len)
		nbr /= blen;
	return (len);
}

int	ft_nbrlen(int nbr)
{
	int	len;

	if (!nbr)
		return (1);
	if (nbr == -2147483648)
		return (11);
	len = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	return (len + ft_unbrlen(nbr, 10));
}

int	ft_putnchar(int n, char c, int fd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, fd);
		i++;
	}
	return (i);
}
