/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:49:39 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/29 18:39:36 by cfatrane         ###   ########.fr       */
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
		if ((arg->flags.flag[SPACE] != 1 && arg->flags.flag[MORE] == 1) || (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] == 1))
		{
			ft_putchar('+');
			len++;
		}
		else if (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] != 1)
			len += ft_write_flag_space();
	}
	/*	else
		ft_putchar('-');
		*/	
	if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
		len += ft_write_flag_zero_arg_size(arg, len);
	else if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] == 1)
		return (ft_write_size_signed_int(arg, nbr));
	ft_putnbr(nbr);
	return (ft_nbcmp(arg->size, len));
}

static int	ft_write_flag_precision(t_env *arg, long long int nbr)
{
	int		i;
	int		len;

	i = 0;
	len = ft_nbrlen(nbr);
	if (arg->flags.flag[LESS] == 1 || (arg->flags.flag[LESS] == 1 && arg->flags.flag[ZERO] == 1))
	{
		while (i < arg->precision - len)
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr(nbr);
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
	}
	else
	{
		if (arg->size > arg->precision)
		{
			while (i < arg->size - arg->precision)
			{
				ft_putchar (' ');
				i++;
			}
			//	return (ft_nbcmp(arg->precision, len));
		}
		len += i;
		i = 0;
		len = ft_nbrlen(nbr);
		while (i < arg->precision - len)
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr(nbr);
		len += i;
	}
	return (ft_nbcmp(ft_nbcmp(arg->precision, len), ft_nbcmp(arg->precision, arg->size)));
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
	if(arg->precision)
		return (ft_write_flag_precision(arg, nbr));
	if (arg->flags.flag[ZERO] == 1 || arg->flags.flag[MORE] == 1 || arg->flags.flag[SPACE] == 1)
		return (ft_write_flag_dec(arg, nbr));
	if(arg->size)
		return (ft_write_size_signed_int(arg, nbr));
	if (arg->modif == hh)
		ft_putnbr((signed char)nbr);
	else if (arg->modif == h)
		ft_putnbr((short int)nbr);
	else
		ft_putnbr(nbr);
	if (arg->modif == hh)
		len = ft_nbrlen((signed char)nbr);
	else if (arg->modif == h)
		len = ft_nbrlen((short int)nbr);
	else
		len = ft_nbrlen(nbr);
	return (len);
}
