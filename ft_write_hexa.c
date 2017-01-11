/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:03:19 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 14:12:18 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_hexa(t_env *arg, size_t nbr)
{
	arg->len += ft_write_flag_diese(arg);
	ft_printf_putnbr_uns(arg, nbr);
	ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_hexa(t_env *arg, size_t nbr)
{
	if (arg->flag[DIESE])
		arg->len += 2;
	if (arg->flag[ZERO] && !arg->precision.actif)
	{
		ft_write_flag_diese(arg);
		ft_write_flag_zero(arg->size, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
	}
	else
	{
		ft_write_flag_spaces(arg->size, arg->len);
		ft_write_flag_diese(arg);
		ft_printf_putnbr_uns(arg, nbr);
	}
	return (ft_nbcmp_max(arg->len, arg->size));
}

static int	ft_write_justify_precision_hexa(t_env *arg, size_t nbr)
{
	int		lenfin;

	lenfin = 0;
	if (arg->size > arg->precision.len)
	{
		lenfin += ft_write_flag_diese(arg);
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
		return (arg->size);
	}
	else
	{
		lenfin += ft_write_flag_diese(arg);
		lenfin += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		arg->len += lenfin;
		return (ft_nbcmp_max(arg->len, arg->precision.len));
	}
	return (0);
}

static int	ft_write_precision_hexa(t_env *arg, size_t nbr)
{
	int		lenfin;

	lenfin = 0;
	if (arg->size > arg->precision.len)
	{
		if (arg->flag[DIESE])
			lenfin = 2;
		ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
		ft_write_flag_diese(arg);
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		return (arg->size);
	}
	else
	{
		lenfin += ft_write_flag_diese(arg);
		lenfin += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		arg->len += lenfin;
		return (ft_nbcmp_max(arg->len, arg->precision.len));
	}
	return (0);
}

static int	ft_write_flag(t_env *arg, size_t nbr)
{
	arg->len += ft_write_flag_diese(arg);
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->len);
}

static int	ft_write_precision_zero_hexa(t_env *arg, size_t nbr)
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

int			ft_write_hexa(t_env *arg, size_t nbr)
{
	if (nbr == 0)
		return (ft_write_precision_zero_hexa(arg, nbr));
	arg->len = ft_nbrlen_hexa(nbr);
	if (arg->flag[DIESE] && !arg->size && !arg->precision.actif)
		return (ft_write_flag(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len &&
			!arg->flag[LESS])
		return (ft_write_size_hexa(arg, nbr));
	else if (arg->size > arg->len && arg->precision.len <= arg->len &&
			arg->flag[LESS])
		return (ft_write_justify_size_hexa(arg, nbr));
	if (arg->precision.len >= arg->len && !arg->flag[LESS])
		return (ft_write_precision_hexa(arg, nbr));
	else if (arg->precision.len >= arg->len && arg->flag[LESS])
		return (ft_write_justify_precision_hexa(arg, nbr));
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->len);
}
