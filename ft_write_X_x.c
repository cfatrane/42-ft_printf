/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:51:22 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 11:18:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_X_x(t_env *arg, unsigned long long nbr)
{
	arg->len += ft_write_flag_diese(arg);
	ft_printf_putnbr(arg, nbr);
	ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_X_x(t_env *arg, unsigned long long nbr)
{
	if (arg->flags.options[DIESE])
		arg->len += 2;
	if (arg->flags.options[ZERO] && !arg->precision.actif)
	{
		ft_write_flag_diese(arg);
		ft_write_flag_zero(arg->size, arg->len);
		ft_printf_putnbr(arg, nbr);
	}
	else
	{
		ft_write_flag_spaces(arg->size, arg->len);
		ft_write_flag_diese(arg);
		ft_printf_putnbr(arg, nbr);
	}
	return (ft_nbcmp_max(arg->len, arg->size));
}

static int	ft_write_justify_precision_X_x(t_env *arg, unsigned long long nbr)
{
	int		lenfin;

	lenfin = 0;
	if (arg->size > arg->precision.len)
	{
		lenfin += ft_write_flag_diese(arg);
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
		return (arg->size);
	}
	else
	{
		lenfin += ft_write_flag_diese(arg);
		lenfin += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		arg->len += lenfin;
		return (ft_nbcmp_max(arg->len, arg->precision.len));
	}
	return (0);
}

static int	ft_write_precision_X_x(t_env *arg, unsigned long long nbr)
{
	int		lenfin;

	lenfin = 0;
	if (arg->size > arg->precision.len)
	{
		if (arg->flags.options[DIESE])
			lenfin = 2;
		ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
		ft_write_flag_diese(arg);
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		return (arg->size);
	}
	else
	{
		lenfin += ft_write_flag_diese(arg);
		lenfin += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		arg->len += lenfin;
		return (ft_nbcmp_max(arg->len, arg->precision.len));
	}
	return (0);
}

static int	ft_write_flag(t_env *arg, unsigned long long nbr)
{
	arg->len += ft_write_flag_diese(arg);
	ft_printf_putnbr(arg, nbr);
	return (arg->len);
}

static int	ft_write_precision_zero_X_x(t_env *arg, unsigned long long nbr)
{
	if (nbr == 0 && !arg->size && arg->precision.actif == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else if (nbr == 0 && arg->precision.actif == 1)
	{
		if (!arg->size)
			return (0);
		else
		{
			ft_write_flag_spaces(arg->size, arg->precision.len);
			return (arg->size);
		}
	}
	return (0);
}

int			ft_write_X_x(t_env *arg, va_list ap)
{
	unsigned long long int	nbr;

	if (!arg->modif || arg->modif == HH || arg->modif == H)
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == LL)
		nbr = va_arg(ap, unsigned long long int);
	else if (arg->modif == L)
		nbr = va_arg(ap, unsigned long int);
	else if (arg->modif == J)
		nbr = va_arg(ap, uintmax_t);
	else if (arg->modif == Z)
		nbr = va_arg(ap, size_t);
	if (nbr == 0)
		return (ft_write_precision_zero_X_x(arg, nbr));
	arg->len = ft_printf_nbrlen(arg, nbr);
	if (arg->flags.options[DIESE] && !arg->size && !arg->precision.actif)
		return (ft_write_flag(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len &&
			!arg->flags.options[LESS])
		return (ft_write_size_X_x(arg, nbr));
	else if (arg->size > arg->len && arg->precision.len <= arg->len &&
			arg->flags.options[LESS])
		return (ft_write_justify_size_X_x(arg, nbr));
	if (arg->precision.len >= arg->len && !arg->flags.options[LESS])
		return (ft_write_precision_X_x(arg, nbr));
	else if (arg->precision.len >= arg->len && arg->flags.options[LESS])
		return (ft_write_justify_precision_X_x(arg, nbr));
	ft_printf_putnbr(arg, nbr);
	return (arg->len);
}
