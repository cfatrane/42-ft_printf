/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:32:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 10:44:40 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_uns(t_env *arg, unsigned long long nbr)
{
	ft_printf_putnbr_uns(arg, nbr);
	ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_uns(t_env *arg, unsigned long long nbr)
{
	if (arg->flag[ZERO] && !arg->precision.actif)
		ft_write_flag_zero(arg->size, arg->len);
	else
		ft_write_flag_spaces(arg->size, arg->len);
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->size);
}

static int	ft_write_justify_prc_uns(t_env *arg, unsigned long long nbr)
{
	if (arg->size > arg->precision.len)
	{
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
	else
	{
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		return (arg->precision.len);
	}
	return (0);
}

static int	ft_write_prc_uns(t_env *arg, unsigned long long nbr)
{
	if (arg->size > arg->precision.len)
	{
		ft_write_flag_spaces(arg->size, arg->precision.len);
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_putnbr_uns(nbr);
		return (arg->size);
	}
	else
	{
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		return (arg->precision.len);
	}
	return (0);
}

static int	ft_write_flag(t_env *arg, unsigned long long nbr)
{
	int		len;

	len = ft_nbrlen_uns(nbr);
	if (arg->flag[ZERO] == 1 && arg->flag[LESS] != 1)
		len += ft_write_flag_zero(arg->size, len);
	else if (arg->flag[ZERO] == 1 && arg->flag[LESS] == 1)
		return (ft_write_size(arg, nbr));
	ft_printf_putnbr_uns(arg, nbr);
	return (ft_nbcmp_max(arg->size, len));
}

static int	ft_write_precision_zero_uns_int(t_env *arg, unsigned long long nbr)
{
	if (!arg->size)
		return (0);
	else
	{
		ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
}

int			ft_write_uns(t_env *arg, va_list ap)
{
	unsigned long long int	nbr;

	if ((!arg->modif || arg->modif == HH || arg->modif == H) && arg->conv != 'U')
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == LL)
		nbr = va_arg(ap, unsigned long long int);
	else if (arg->modif == L || arg->conv == 'U')
		nbr = va_arg(ap, unsigned long int);
	else if (arg->modif == J)
		nbr = va_arg(ap, uintmax_t);
	else if (arg->modif == Z)
		nbr = va_arg(ap, size_t);
	arg->len = ft_printf_nbrlen_uns(arg, nbr);
	if (nbr == 0 && arg->precision.actif == 1)
		return (ft_write_precision_zero_uns_int(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len && !arg->flag[LESS])
		return (ft_write_size_uns(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len && arg->flag[LESS])
		return (ft_write_justify_size_uns(arg, nbr));
	if (arg->precision.len >= arg->len && !arg->flag[LESS])
		return (ft_write_prc_uns(arg, nbr));
	if (arg->precision.len >= arg->len && arg->flag[LESS])
		return (ft_write_justify_prc_uns(arg, nbr));
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->len);
}
