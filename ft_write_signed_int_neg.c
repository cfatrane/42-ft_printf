/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int_neg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:40:56 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/09 20:07:10 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_sgn_int(t_env *arg, signed long long int nbr)
{
	ft_printf_putnbr(arg, nbr);
	arg->len += ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_sgn_int(t_env *arg, signed long long int nbr)
{
	if (arg->flags.options[ZERO])
	{
		ft_putchar('-');
		arg->len += ft_write_flag_zero(arg->size, arg->len);
	}
	else
		ft_write_flag_spaces(arg->size, arg->len);
	if (arg->flags.options[ZERO])
		ft_printf_putnbr(arg, ft_abs(nbr));
	else
		ft_printf_putnbr(arg, nbr);
	return (ft_nbcmp_max(arg->len, arg->size));
}

static int	ft_write_justify_prc_sgn_int(t_env *arg, signed long long int nbr)
{
	ft_putchar('-');
	ft_write_flag_zero(arg->precision.len, arg->len + 1);
	ft_printf_putnbr(arg, ft_abs(nbr));
	return (ft_nbcmp_max(arg->precision.len, arg->len));
}

static int	ft_write_prc_sng_int(t_env *arg, signed long long int nbr)
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

int			ft_write_signed_int_neg(t_env *arg, signed long long int nbr)
{
	if (arg->size > arg->len && arg->precision.len <= arg->len &&
			!arg->flags.options[LESS])
		return (ft_write_size_sgn_int(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len &&
			arg->flags.options[LESS])
		return (ft_write_justify_size_sgn_int(arg, nbr));
	if (arg->precision.len >= arg->len && !arg->flags.options[LESS])
		return (ft_write_prc_sng_int(arg, nbr));
	else if (arg->precision.len >= arg->len && arg->flags.options[LESS])
		return (ft_write_justify_prc_sgn_int(arg, nbr));
	ft_printf_putnbr(arg, nbr);
	return (arg->len);
}
