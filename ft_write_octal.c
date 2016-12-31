/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:18:25 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/31 15:51:17 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_size_oct(t_env *arg, unsigned long long int nbr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_nbrlen_uns(nbr);
	if (arg->flags.flag[LESS] == 1 || (arg->flags.flag[LESS] == 1 && arg->flags.flag[ZERO] == 1))
	{
		if (arg->flags.flag[DIESE] == 1)
		{
			ft_putchar('0');
			len++;
		}
		ft_putnbr_base(nbr, OCTAL);
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
	}
	else
	{
		if (arg->flags.flag[DIESE] == 1)
			len++;
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
		if (arg->flags.flag[DIESE] == 1)
			ft_putchar('0');
		ft_putnbr_base(nbr, OCTAL);
	}
	len += i;
	return (len);
}


static int	ft_write_flag_precision(t_env *arg, unsigned long long int nbr)
{
	int		i;
	int		len;

	i = 0;
	len = ft_nbrlen_uns(nbr);
	if (arg->flags.flag[LESS] == 1 || (arg->flags.flag[LESS] == 1 && arg->flags.flag[ZERO] == 1))
	{
		while (i < arg->precision - len)
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr_base(nbr, OCTAL);
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
		len = ft_nbrlen_uns(nbr);
		while (i < arg->precision - len)
		{
			ft_putchar('0');
			i++;
		}
		ft_putnbr_base(nbr, OCTAL);
		len += i;
	}
	return (ft_nbcmp(ft_nbcmp(arg->precision, len), ft_nbcmp(arg->precision, arg->size)));
}

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	int		len;

	len = ft_nbrlen_uns(nbr);
	if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
		len += ft_write_flag_zero_arg_size(arg, len);
	else if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] == 1)
		return (ft_write_size_oct(arg, nbr));
	if (arg->flags.flag[DIESE] == 1)
		ft_putchar('0');
	ft_putnbr_base(nbr, OCTAL);
	return (ft_nbcmp(arg->size, len));
}

int	ft_write_octal(t_env *arg, va_list ap)
{
	int						len;
	unsigned long long int	nbr;

	len = 0;
	if (!(arg->modif))
		nbr = va_arg(ap, unsigned long long int);
	else if (arg->modif == HH)
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == H)
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == LL)
		nbr = va_arg(ap, unsigned long long int);
	else if (arg->modif == L)
		nbr = va_arg(ap, unsigned long int);
	else if (arg->modif == J)
		nbr = va_arg(ap, uintmax_t);
	else if (arg->modif == Z)
		nbr = va_arg(ap, size_t);
//	if(arg->precision)
//		return (ft_write_flag_precision(arg, nbr));
	if (arg->flags.flag[ZERO] == 1)
		return (ft_write_flag(arg, nbr));
	if(arg->size)
		return (ft_write_size_oct(arg, nbr));
	if (arg->flags.flag[DIESE] == 1)
	{
		ft_putchar('0');
		len++;
	}
	ft_putnbr_base(nbr, OCTAL);
	len = ft_nbrlen_uns(nbr);
	return (len);
}
