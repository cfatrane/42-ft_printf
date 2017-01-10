/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int_neg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:40:56 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 18:57:13 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_D_d_i(t_env *arg, signed long long int nbr)
{
	ft_printf_putnbr(arg, nbr);
	arg->len += ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_D_d_i(t_env *arg, signed long long int nbr)
{
	if (arg->flag[ZERO])
	{
		ft_putchar('-');
		arg->len += ft_write_flag_zero(arg->size, arg->len);
	}
	else
		ft_write_flag_spaces(arg->size, arg->len);
	if (arg->flag[ZERO])
		ft_printf_putnbr(arg, ft_abs(nbr));
	else
		ft_printf_putnbr(arg, nbr);
	return (ft_nbcmp_max(arg->len, arg->size));
}

static int	ft_write_justify_prc_D_d_i(t_env *arg, signed long long int nbr)
{
	ft_putchar('-');
	ft_write_flag_zero(arg->precision.len, arg->len + 1);
	ft_printf_putnbr(arg, ft_abs(nbr));
	return (ft_nbcmp_max(arg->precision.len, arg->len));
}

static int	ft_write_prc_D_d_i(t_env *arg, signed long long int nbr)
{
	if (arg->size > arg->precision.len)
	{
		ft_write_flag_spaces(arg->size, arg->precision.len + 1);
		ft_putchar('-');
		ft_write_flag_zero(arg->precision.len, arg->len - 1);
		ft_printf_putnbr(arg, ft_abs(nbr));
		return (arg->size);
	}
	else
	{
		ft_putchar('-');
		arg->len += ft_write_flag_zero(arg->precision.len, arg->len - 1);
		ft_printf_putnbr(arg, ft_abs(nbr));
		return (ft_nbcmp_max(arg->len, arg->precision.len));
	}
	return (0);
}

int			ft_write_D_d_i_neg(t_env *arg, signed long long int nbr)
{
	if (arg->size > arg->len && arg->precision.len <= arg->len &&
			!arg->flag[LESS])
		return (ft_write_size_D_d_i(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len &&
			arg->flag[LESS])
		return (ft_write_justify_size_D_d_i(arg, nbr));
	if (arg->precision.len >= arg->len && !arg->flag[LESS])
		return (ft_write_prc_D_d_i(arg, nbr));
	else if (arg->precision.len >= arg->len && arg->flag[LESS])
		return (ft_write_justify_prc_D_d_i(arg, nbr));
	ft_printf_putnbr(arg, nbr);
	return (arg->len);
}
