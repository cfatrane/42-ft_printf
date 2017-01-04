/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:32:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 15:02:50 by cfatrane         ###   ########.fr       */
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
	return (arg->size);
}

static int	ft_write_size_uns_nbr(t_env *arg, unsigned long long int nbr)
{
	int	i;

	i = 0;
	if (arg->flags.options[LESS])
		return (ft_write_justify_size_uns_nbr(arg, nbr));
	else
	{
		if (arg->flags.options[ZERO]/* && (arg->precision.len > arg->size || !arg->precision.len)*/)
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
	if (arg->size > arg->precision.len/* && arg->precision.len > arg->len*/)
	{
		i += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_putnbr_uns(nbr);
		i = 0;
		i += ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
	else
	{
		i += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_putnbr_uns(nbr);
		return (arg->precision.len);
	}
	return (0);
}

static int	ft_write_precision_uns_nbr(t_env *arg, unsigned long long int nbr)
{
	int		i;

	i = 0;
	if (arg->flags.options[LESS] && arg->size)
		return (ft_write_justify_precision_uns_nbr(arg, nbr));
	else
	{
		if (arg->size > arg->precision.len)
		{
			i += ft_write_flag_spaces(arg->size, arg->precision.len);
			//	arg->len += i;
			i = 0;
			//	arg->len = ft_nbrlen_uns(nbr);
			i += ft_write_flag_zero(arg->precision.len, arg->len);
			ft_putnbr_uns(nbr);
			arg->len += i;
			return (arg->size);
			//	return (ft_nbcmp(arg->precision.len, len));
		}
		else
		{
			i += ft_write_flag_zero(arg->precision.len, arg->len);
			ft_putnbr_uns(nbr);
			return (arg->precision.len);
		}
	}
	return (0);
}

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	int		len;

	len = ft_nbrlen_uns(nbr);
	if (arg->flags.options[ZERO] == 1 && arg->flags.options[LESS] != 1)
		len += ft_write_flag_zero(arg->size, len);
	else if (arg->flags.options[ZERO] == 1 && arg->flags.options[LESS] == 1)
		return (ft_write_size(arg, nbr));
	ft_putnbr_uns(nbr);
	return (ft_nbcmp_max(arg->size, len));
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
	if(arg->size > arg->len && (arg->precision.len <= arg->len || !arg->precision.actif))
		return (ft_write_size_uns_nbr(arg, nbr));
	if(arg->precision.len > arg->len)
		return (ft_write_precision_uns_nbr(arg, nbr));
	ft_putnbr_uns(nbr);
	return (arg->len);
}
