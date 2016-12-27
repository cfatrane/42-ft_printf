/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:49:39 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/27 19:18:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_size_signed_int(t_env *arg, long long int nbr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_nbrlen(nbr);
	if (arg->flags.flag[LESS] == 1 || (arg->flags.flag[LESS] == 1 && arg->flags.flag[ZERO] == 1))
	{
		ft_putnbr(nbr);
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
	}
	else
	{
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
		ft_putnbr(nbr);
	}
	len += i;
	return (len);
}

static int	ft_write_flag_dec(t_env *arg, long long int nbr)
{
	int		len;

	len = ft_nbrlen(nbr);
	if (nbr >= 0)
	{
		if (arg->flags.flag[SPACE] != 1 && arg->flags.flag[MORE] == 1)
		{
			ft_putchar('+');
			len++;
		}
		else if (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] == 1)
		{
			ft_putchar('+');
			len++;
		}
		else if (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] != 1)
			len += ft_write_flag_space();
	}
/*	else
		ft_putchar('-');
*/	if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
		len += ft_write_flag_zero(arg, len);
	else if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] == 1)
		return (ft_write_size_signed_int(arg, nbr));
	ft_putnbr(nbr);
	return (ft_nbcmp(arg->size, len));
}


int	ft_write_signed_int(t_env *arg, va_list ap)
{
	int				len;
	long long int	nbr;

	len = 0;
	if (!(arg->modif))
		nbr = va_arg(ap, signed int);
	else if (arg->modif == hh)
		nbr = va_arg(ap, signed int);
	else if (arg->modif == h)
		nbr = va_arg(ap, signed int);
	else if (arg->modif == ll)
		nbr = va_arg(ap, long long int);
	else if (arg->modif == l)
		nbr = va_arg(ap, long int);
	else if (arg->modif == j)
		nbr = va_arg(ap, intmax_t);
	else if (arg->modif == z)
		nbr = va_arg(ap, size_t);
	if (arg->flags.flag[ZERO] == 1 || arg->flags.flag[MORE] == 1 || arg->flags.flag[SPACE] == 1)
		return (ft_write_flag_dec(arg, nbr));
	if(arg->size)
		return (ft_write_size_signed_int(arg, nbr));
	ft_putnbr(nbr);
	len += ft_nbrlen(nbr);
	return (len);
}
