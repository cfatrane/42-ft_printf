/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:26:54 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 20:24:16 by cfatrane         ###   ########.fr       */
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
	if (arg->flags.options[LESS])
		return (ft_write_justify_size_pointor(arg, pointor));
	else
	{
		if (arg->flags.options[ZERO] == 1/* && (arg->precision.len > arg->size || !arg->precision.len)*/)
		{
			ft_putstr("0x");
			i += ft_write_flag_zero(arg->size, arg->len);
		}
		else
		{
			i += ft_write_flag_spaces(arg->size, arg->len);
			ft_putstr("0x");
			ft_print_hex((size_t)pointor);
		}
		//	if (arg->flags.options[ZERO] == 1/* && (arg->precision.len > arg->size || !arg->precision.len)*/)
		//		arg->len += ft_write_flag_zero_arg_size(arg, arg->len);
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
	if (arg->flags.options[LESS] && arg->size)
		return (ft_write_justify_precision_pointor(arg, pointor));
	else
	{
		if (arg->size > arg->precision.len)
		{
			i += ft_write_flag_spaces(arg->size, arg->precision.len + 2);
			//	arg->len += i;
			i = 0;
			//	arg->len = ft_nbrlen_uns(nbr);
			ft_putstr("0x");
			i += ft_write_flag_zero(arg->precision.len, arg->len - 2);
			ft_print_hex((size_t)pointor);
			arg->len += i;
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
	}
	return (0);
}

int	ft_write_pointor(t_env *arg, va_list ap)
{
	void	*pointor;

	pointor = va_arg(ap, void *);
	arg->len = ft_nbrlen_hexa((unsigned long long)pointor) + 2;
	if(arg->size > arg->len && (arg->precision.len <= arg->len || !arg->precision.len))
		return (ft_write_size_pointor(arg, pointor));
	if(arg->precision.len > arg->len)
		return (ft_write_precision_pointor(arg, pointor));
	ft_putstr("0x");
	ft_print_hex((size_t)pointor);
	return (arg->len/*(ft_size_tab_base((size_t)pointor, 16)) + 2*/);
}
