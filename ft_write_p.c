/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:26:54 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 18:57:53 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_p(t_env *arg, void *pointor)
{
	ft_putstr("0x");
	ft_print_hex((size_t)pointor);
	ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_p(t_env *arg, void *pointor)
{
	if (arg->flag[ZERO])
	{
		ft_putstr("0x");
		if (arg->precision.actif)
			return (2);
		ft_write_flag_zero(arg->size, arg->len);
		ft_print_hex((size_t)pointor);
	}
	else
	{
		ft_write_flag_spaces(arg->size, arg->len);
		ft_putstr("0x");
		ft_print_hex((size_t)pointor);
	}
	return (arg->size);
}

static int	ft_write_justify_prc_p(t_env *arg, void *pointor)
{
	if (arg->size > arg->precision.len)
	{
		ft_putstr("0x");
		ft_write_flag_zero(arg->precision.len, arg->len - 2);
		ft_print_hex((size_t)pointor);
		ft_write_flag_spaces(arg->size, arg->precision.len + 2);
		return (arg->size);
	}
	else
	{
		ft_putstr("0x");
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_print_hex((size_t)pointor);
		return (arg->precision.len);
	}
	return (0);
}

static int	ft_write_prc_p(t_env *arg, void *pointor)
{
	if (arg->size > arg->precision.len)
	{
		ft_write_flag_spaces(arg->size, arg->precision.len + 2);
		ft_putstr("0x");
		ft_write_flag_zero(arg->precision.len, arg->len - 2);
		ft_print_hex((size_t)pointor);
		return (arg->size);
	}
	else
	{
		ft_putstr("0x");
		ft_write_flag_zero(arg->precision.len, arg->len - 2);
		ft_print_hex((size_t)pointor);
		return (arg->precision.len + 2);
	}
	return (0);
}

static int	ft_write_prc_zero_p(t_env *arg)
{
	if (!arg->size)
	{
		ft_putstr("0x");
		return (2);
	}
	else
	{
		ft_write_flag_spaces(arg->size, arg->precision.len + 2);
		ft_putstr("0x");
		return (arg->size);
	}
	return (0);
}

int			ft_write_p(t_env *arg, va_list ap)
{
	void	*pointor;

	pointor = va_arg(ap, void *);
	arg->len = ft_nbrlen_hexa((unsigned long long)pointor) + 2;
	if (pointor == 0 && arg->precision.actif == 1 && arg->precision.len == 0)
		return (ft_write_prc_zero_p(arg));
	if (arg->size > arg->len && arg->precision.len <= arg->len &&
			!arg->flag[LESS])
		return (ft_write_size_p(arg, pointor));
	if (arg->size > arg->len && arg->precision.len <= arg->len &&
			arg->flag[LESS])
		return (ft_write_justify_size_p(arg, pointor));
	if (arg->precision.len >= arg->len && !arg->flag[LESS])
		return (ft_write_prc_p(arg, pointor));
	if (arg->precision.len >= arg->len && arg->flag[LESS])
		return (ft_write_justify_prc_p(arg, pointor));
	ft_putstr("0x");
	ft_print_hex((size_t)pointor);
	return (arg->len);
}
//	printf("ptr = %p||len nbr = %d||prec = %d||actif = %d||size = %d|||\t\n", pointor, arg->len, arg->precision.len, arg->precision.actif, arg->size);
