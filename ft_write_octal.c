/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:39:41 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 14:50:35 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_size_octal(t_env *arg, size_t nbr)
{
	if (arg->flag[LESS])
	{
		arg->len += ft_write_flag_diese(arg);
		ft_printf_putnbr_uns(arg, nbr);
		ft_write_flag_spaces(arg->size, arg->len);
		return (arg->size);
	}
	if (arg->flag[DIESE])
		arg->len++;
	if (arg->flag[ZERO] && !arg->precision.actif)
		ft_write_flag_zero(arg->size, arg->len);
	else
		ft_write_flag_spaces(arg->size, arg->len);
	ft_write_flag_diese(arg);
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->size);
}

static int	ft_write_justify_precision_octal(t_env *arg, size_t nbr)
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

static int	ft_write_precision_octal(t_env *arg, size_t nbr)
{
	if (arg->size > arg->precision.len)
	{
		ft_write_flag_spaces(arg->size, arg->precision.len);
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
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

static int	ft_write_flag(t_env *arg, size_t nbr)
{
	arg->len += ft_write_flag_diese(arg);
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->len);
}

static int	ft_write_precision_zero_octal(t_env *arg, size_t nbr)
{
	if (!arg->flag[DIESE])
	{
		if (!arg->size)
			return (0);
		else
		{
			ft_write_flag_spaces(arg->size, arg->precision.len);
			return (arg->size);
		}
	}
	else if (arg->flag[DIESE])
	{
		if (!arg->size)
			return (ft_write_flag_diese(arg));
		if (arg->flag[LESS])
		{
			ft_putchar('0');
			ft_write_flag_spaces(arg->size, arg->precision.len + 1);
		}
		else
		{
			ft_write_flag_spaces(arg->size, arg->precision.len + 1);
			ft_putchar('0');
		}
		return (arg->size);
	}
	return (0);
}

int			ft_write_octal(t_env *arg, size_t nbr)
{
	arg->len = ft_printf_nbrlen_uns(arg, nbr);
	if (nbr == 0 && arg->precision.actif && arg->precision.len == 0)
		return (ft_write_precision_zero_octal(arg, nbr));
	if (nbr > 0 && arg->flag[DIESE] && !arg->flag[LESS] &&
			arg->size < arg->len && arg->precision.len == 0)
		return (ft_write_flag(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len)
		return (ft_write_size_octal(arg, nbr));
	if (arg->precision.len >= arg->len && !arg->flag[LESS])
		return (ft_write_precision_octal(arg, nbr));
	if (arg->precision.len >= arg->len && arg->flag[LESS])
		return (ft_write_justify_precision_octal(arg, nbr));
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->len);
}
