/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:46:05 by mmehran           #+#    #+#             */
/*   Updated: 2021/04/21 09:52:57 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_padd(int width, int slen, int flags)
{
	int		m;
	char	c;

	m = ft_max(width - slen, 0);
	c = ' ';
	if (flags & 0b100)
		c = '0';
	ft_putnchar(m, c, 1);
	return (m);
}

void	print_spe(t_spe *spe, va_list argptr)
{
	if (spe->type == '%')
		print_char('%', spe);
	if (spe->type == 'c')
		print_char(va_arg(argptr, int), spe);
	if (spe->type == 's')
		print_str(va_arg(argptr, char *), spe);
	if (spe->type == 'd' || spe->type == 'i')
		print_int((int)va_arg(argptr, int), spe);
	if (spe->type == 'u')
		print_uint((unsigned int)va_arg(argptr, int), "0123456789", spe);
	if (spe->type == 'p')
		print_pointer(va_arg(argptr, unsigned long long), spe);
	if (spe->type == 'x')
		print_uint((unsigned int)va_arg(argptr, int), "0123456789abcdef", spe);
	if (spe->type == 'X')
		print_uint((unsigned int)va_arg(argptr, int), "0123456789ABCDEF", spe);
}

int	ft_printf(const char *format, ...)
{
	t_spe	spe;
	va_list	argptr;
	int		printed_char;

	printed_char = 0;
	va_start(argptr, format);
	while (format && *format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			format++;
			printed_char++;
		}
		else
		{
			spe = parse_spe((char *)format, argptr);
			print_spe(&spe, argptr);
			format += spe.length;
			printed_char += spe.printed_char;
		}
	}
	va_end(argptr);
	return (printed_char);
}
