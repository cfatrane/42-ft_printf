/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:32:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/03 18:14:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_write_justify_size_uns_nbr(t_env *arg, unsigned long long int nbr)
{
	int i;

	i = 0;
	ft_putnbr_uns(nbr);
	i += ft_write_flag_spaces(arg->size, arg->len);
	arg->len += i;
	return (arg->len);
}

static int	ft_write_size_uns_nbr(t_env *arg, unsigned long long int nbr)
{
	int	i;

	i = 0;
	if (arg->flags.flag[LESS])
		return (ft_write_justify_size_uns_nbr(arg, nbr));
	else
	{
		if (arg->flags.flag[ZERO] == 1/* && (arg->precision > arg->size || !arg->precision)*/)
			arg->len += ft_write_flag_zero(arg->size, arg->len);
		else
			arg->len += ft_write_flag_spaces(arg->size, arg->len);
		ft_putnbr_uns(nbr);
	}
//	arg->len += i;
	return (arg->size);
}

static int ft_write_justify_precision_uns_nbr(t_env *arg, unsigned long long int nbr)
{
	int i;

	i = 0;
	if (arg->size > arg->precision/* && arg->precision > arg->len*/)
	{
		i += ft_write_flag_zero(arg->precision, arg->len);
		ft_putnbr_uns(nbr);
		i = 0;
		i += ft_write_flag_spaces(arg->size, arg->precision);
		return (arg->size);
	}
	else
	{
		i += ft_write_flag_zero(arg->precision, arg->len);
		ft_putnbr_uns(nbr);
		return (arg->precision);
	}
	return (0);
}

static int	ft_write_precision_uns_nbr(t_env *arg, unsigned long long int nbr)
{
	int		i;

	i = 0;
	if (arg->flags.flag[LESS] && arg->size)
		return (ft_write_justify_precision_uns_nbr(arg, nbr));
	else
	{
		if (arg->size > arg->precision)
		{
			i += ft_write_flag_spaces(arg->size, arg->precision);
			//	arg->len += i;
			i = 0;
			//	arg->len = ft_nbrlen_uns(nbr);
			i += ft_write_flag_zero(arg->precision, arg->len);
			ft_putnbr_uns(nbr);
			arg->len += i;
			return (arg->size);
			//	return (ft_nbcmp(arg->precision, len));
		}
		else
		{
			i += ft_write_flag_zero(arg->precision, arg->len);
			ft_putnbr_uns(nbr);
			return (arg->precision);
		}
	}
	return (0);
}

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	int		len;

	len = ft_nbrlen_uns(nbr);
	if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
		len += ft_write_flag_zero(arg->size, len);
	else if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] == 1)
		return (ft_write_size(arg, nbr));
	ft_putnbr_uns(nbr);
	return (ft_nbcmp(arg->size, len));
}

int	ft_write_unsigned_int(t_env *arg, va_list ap)
{
	unsigned long long int	nbr;

	if (!(arg->modif))
		nbr = va_arg(ap, unsigned int);
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
	arg->len = ft_nbrlen_uns(nbr);
	if(arg->size > arg->len && (arg->precision <= arg->len || !arg->precision))
		return (ft_write_size_uns_nbr(arg, nbr));
	if(arg->precision > arg->len)
		return (ft_write_precision_uns_nbr(arg, nbr));
	ft_putnbr_uns(nbr);
	return (arg->len);
}
