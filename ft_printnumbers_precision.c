/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers_precision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:45:36 by mmehran           #+#    #+#             */
/*   Updated: 2021/04/21 11:34:53 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printbaseprecision(unsigned long long nbr, char *base, t_spe *spe)
{
	ft_putnchar(spe->precision - ft_unbrlen(nbr, ft_strlen(base)), '0', 1);
	ft_putnbr_base_fd(nbr, ft_strlen(base), base, 1);
	spe->printed_char += ft_max(ft_unbrlen(nbr, ft_strlen(base)),
			spe->precision);
}

void	printintprecision(int nbr, t_spe *spe)
{
	unsigned int	unbr;

	unbr = nbr;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		unbr = -nbr;
		spe->printed_char++;
	}
	printbaseprecision(unbr, "0123456789", spe);
}

void	printpointerprecision(unsigned long long nbr, t_spe *spe)
{
	ft_putstr_fd("0x", 1);
	ft_putnchar(spe->precision - ft_unbrlen(nbr, 16) - 2, '0', 1);
	ft_putnbr_base_fd(nbr, 16, "0123456789abcdef", 1);
	spe->printed_char += ft_max(ft_unbrlen(nbr, 16) + 2, spe->precision);
}
