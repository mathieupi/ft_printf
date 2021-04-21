/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:30:09 by mmehran           #+#    #+#             */
/*   Updated: 2021/04/06 12:00:15 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(unsigned long long	nbr, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_putnbr_base_fd(nbr, 16, "0123456789abcdef", fd);
}
