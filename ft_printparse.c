/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printparse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:45:45 by mmehran           #+#    #+#             */
/*   Updated: 2021/04/21 09:49:34 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_flags(char **str)
{
	unsigned int	flags;

	flags = 0;
	while (**str)
	{
		if (**str == '-')
			flags |= 0b1;
		else if (**str == '+')
			flags |= 0b10;
		else if (**str == '0')
			flags |= 0b100;
		else if (**str == ' ')
			flags |= 0b1000;
		else if (**str == '#')
			flags |= 0b10000;
		else
			break ;
		(*str)++;
	}
	return (flags);
}

static void	get_width(char **s, t_spe *spe, va_list argptr)
{
	if (**s == '*' && ++*s)
	{
		spe->width = va_arg(argptr, int);
		if (spe->width < 0)
		{
			spe->flags |= 0b1;
			spe->width = -spe->width;
		}
	}
	else
		spe->width = ft_get_number(s);
}

static void	get_precision(char **s, t_spe *spe, va_list argptr)
{
	if (**s == '.' && ++*s)
	{
		if (**s == '*' && ++*s)
		{
			spe->precision = va_arg(argptr, int);
			if (spe->precision < 0)
				spe->precision = -1;
		}
		else
			spe->precision = ft_get_number(s);
	}
}

t_spe	parse_spe(char *str, va_list argptr)
{
	char	*s;
	t_spe	spe;

	spe = (t_spe){0, 0, -1, 0, 0, 0};
	s = str + 1;
	spe.flags = get_flags(&s);
	get_width(&s, &spe, argptr);
	get_precision(&s, &spe, argptr);
	if (spe.precision >= 0 || spe.flags & 0b1)
		spe.flags &= 0b11011;
	spe.type = *(s++);
	spe.length = (s - str);
	return (spe);
}
