/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:45:25 by mmehran           #+#    #+#             */
/*   Updated: 2021/04/21 10:08:06 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, t_spe *spe)
{
	if (spe->flags & 0b1)
		ft_putchar_fd(c, 1);
	spe->printed_char += width_padd(spe->width, 1, spe->flags);
	if (!(spe->flags & 0b1))
		ft_putchar_fd(c, 1);
	spe->printed_char++;
}

void	print_str(char *str, t_spe *spe)
{
	char	*t;

	if (!str)
		str = "(null)";
	t = ft_substr(str, 0, spe->precision);
	if (spe->flags & 0b1)
		ft_putstr_fd(t, 1);
	spe->printed_char += width_padd(spe->width, ft_strlen(t), spe->flags);
	if (!(spe->flags & 0b1))
		ft_putstr_fd(t, 1);
	spe->printed_char += ft_strlen(t);
	free(t);
}
