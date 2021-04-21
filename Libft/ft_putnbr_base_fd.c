/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:00:01 by mmehran           #+#    #+#             */
/*   Updated: 2021/04/06 12:00:06 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(unsigned long long unbr,
unsigned long long nbase, char *base, int fd)
{
	if (unbr >= nbase)
		ft_putnbr_base_fd(unbr / nbase, nbase, base, fd);
	ft_putchar_fd(base[unbr % nbase], fd);
}
