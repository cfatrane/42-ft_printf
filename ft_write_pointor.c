/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:26:54 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/08 15:37:07 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_write_justify_size_pointor(t_env *arg, void *pointor)
{
	int i;

	i = 0;
	ft_putstr("0x");
	ft_print_hex((size_t)pointor);
	i += ft_write_flag_spaces(arg->size, arg->len);
	arg->len += i;
	return (arg->size);
}

static int	ft_write_size_pointor(t_env *arg, void *pointor)
{
	int	i;

	i = 0;
	if (arg->flags.options[ZERO]/* && (arg->precision.len > arg->size || !arg->precision.len)*/)
	{
		ft_putstr("0x");
		if (arg->precision.actif)
			return (2);
		i += ft_write_flag_zero(arg->size, arg->len);
	}
	else
	{
		i += ft_write_flag_spaces(arg->size, arg->len);
		ft_putstr("0x");
		ft_print_hex((size_t)pointor);
	}
	//	arg->len += i;
	return (arg->size);
}

static int ft_write_justify_precision_pointor(t_env *arg, void *pointor)
{
	{
		int i;

		i = 0;
		if (arg->size > arg->precision.len/* && arg->precision.len > arg->len*/)
		{
			ft_putstr("0x");
			i += ft_write_flag_zero(arg->precision.len, arg->len - 2);
			ft_print_hex((size_t)pointor);
			i = 0;
			i += ft_write_flag_spaces(arg->size, arg->precision.len + 2);
			return (arg->size);
		}
		else
		{
			ft_putstr("0x");
			i += ft_write_flag_zero(arg->precision.len, arg->len);
			ft_print_hex((size_t)pointor);
			return (arg->precision.len);
		}
		return (0);
	}
}

static int	ft_write_precision_pointor(t_env *arg, void *pointor)
{
	int		i;

	i = 0;
	if (arg->size > arg->precision.len)
	{
		ft_write_flag_spaces(arg->size, arg->precision.len + 2);
		//	arg->len += i;
		//	arg->len = ft_nbrlen_uns(nbr);
		ft_putstr("0x");
		ft_write_flag_zero(arg->precision.len, arg->len - 2);
		ft_print_hex((size_t)pointor);
		return (arg->size);
		//	return (ft_nbcmp(arg->precision.len, len));
	}
	else
	{
		ft_putstr("0x");
		i += ft_write_flag_zero(arg->precision.len, arg->len - 2);
		ft_print_hex((size_t)pointor);
		return (arg->precision.len + 2);
	}
	return (0);
}

static int	ft_write_precision_zero_pointor(t_env *arg, void *pointor)
{
	if (!arg->size)
	{
		ft_putstr("0x");
		return (2);
	}
	return (0);
}

int	ft_write_pointor(t_env *arg, va_list ap)
{
	void	*pointor;

	pointor = va_arg(ap, void *);
	arg->len = ft_nbrlen_hexa((unsigned long long)pointor) + 2;
	if (pointor == 0 && arg->precision.actif == 1 && arg->precision.len == 0)
		return (ft_write_precision_zero_pointor(arg, pointor));
	if (arg->size > arg->len && arg->precision.len <= arg->len && !arg->flags.options[LESS])
		return (ft_write_size_pointor(arg, pointor));
	if (arg->size > arg->len && arg->precision.len <= arg->len && arg->flags.options[LESS])
		return (ft_write_justify_size_pointor(arg, pointor));
	if (arg->precision.len >= arg->len && !arg->flags.options[LESS])
		return (ft_write_precision_pointor(arg, pointor));
	if (arg->precision.len >= arg->len && arg->flags.options[LESS])
		return (ft_write_precision_pointor(arg, pointor));
	ft_putstr("0x");
	ft_print_hex((size_t)pointor);
	return (arg->len/*(ft_size_tab_base((size_t)pointor, 16)) + 2*/);
}
