/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:45:40 by mmehran           #+#    #+#             */
/*   Updated: 2021/04/21 12:10:50 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uint(unsigned long long nbr, char *base, t_spe *spe)
{
	if (!spe->precision && !nbr)
	{
		spe->printed_char += (width_padd(spe->width, 0, spe->flags));
		return ;
	}
	if (spe->flags & 0b1)
		printbaseprecision(nbr, base, spe);
	spe->printed_char += width_padd(spe->width, ft_max(
				ft_unbrlen(nbr, ft_strlen(base)), spe->precision), spe->flags);
	if (!(spe->flags & 0b1))
		printbaseprecision(nbr, base, spe);
}

void	print_int(int nbr, t_spe *spe)
{
	int	len;

	len = 0;
	if (!spe->precision && !nbr)
	{
		spe->printed_char += (width_padd(spe->width, 0, spe->flags));
		return ;
	}
	if (nbr < 0)
		len++;
	if (spe->flags & 0b100 && nbr < 0)
	{
		spe->precision += spe->width;
		spe->width = 0;
	}
	if (spe->flags & 0b1)
		printintprecision(nbr, spe);
	spe->printed_char += width_padd(spe->width,
			ft_max(ft_nbrlen(nbr), spe->precision + len), spe->flags);
	if (!(spe->flags & 0b1))
		printintprecision(nbr, spe);
}

void	print_pointer(unsigned long long nbr, t_spe *spe)
{
	spe->printed_char += ft_max(ft_unbrlen(nbr, 16) + 2, spe->precision);
	if (spe->flags & 0b1)
		ft_putptr_fd(nbr, 1);
	spe->printed_char += width_padd(spe->width, spe->printed_char, spe->flags);
	if (!(spe->flags & 0b1))
		ft_putptr_fd(nbr, 1);
}
