/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmehran <mmehran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:45:32 by mmehran           #+#    #+#             */
/*   Updated: 2021/04/21 09:52:51 by mmehran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./Libft/libft.h"
# include <stdarg.h>

typedef struct s_spe
{
	unsigned int	flags;
	int				width;
	int				precision;
	int				length;
	char			type;
	int				printed_char;
}	t_spe;

int				ft_printf(const char *format, ...);
unsigned int	ft_get_number(char **str);
int				ft_max(int a, int b);
int				ft_putnchar(int n, char c, int fd);
t_spe			parse_spe(char *str, va_list argptr);

void			print_char(char c, t_spe *spe);
void			print_str(char *str, t_spe *spe);

void			printbaseprecision(unsigned long long nbr,
					char *base, t_spe *spe);
void			printintprecision(int nbr, t_spe *spe);
void			printpointerprecision(unsigned long long nbr, t_spe *spe);

void			print_int(int nbr, t_spe *spe);
void			print_uint(unsigned long long nbr, char *base, t_spe *spe);
void			print_pointer(unsigned long long nbr, t_spe *spe);

int				ft_nbrlen(int nbr);
int				ft_unbrlen(unsigned long long nbr, int blen);

int				width_padd(int width, int slen, int flags);
#endif
