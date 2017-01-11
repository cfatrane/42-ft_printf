/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:32:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 15:31:50 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_size_uns(t_env *arg, size_t nbr)
{
	if (arg->flag[LESS])
	{
		ft_printf_putnbr_uns(arg, nbr);
		ft_write_flag_spaces(arg->size, arg->len);
		return (arg->size);
	}
	if (arg->flag[ZERO] && !arg->precision.actif)
		ft_write_flag_zero(arg->size, arg->len);
	else
		ft_write_flag_spaces(arg->size, arg->len);
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->size);
}

static int	ft_write_justify_prc_uns(t_env *arg, size_t nbr)
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

static int	ft_write_prc_uns(t_env *arg, size_t nbr)
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

static int	ft_write_precision_zero_uns_int(t_env *arg, size_t nbr)
{
	if (!arg->size)
		return (0);
	else
	{
		ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
}

int			ft_write_uns(t_env *arg, size_t nbr)
{
	arg->len = ft_printf_nbrlen_uns(arg, nbr);
	if (nbr == 0 && arg->precision.actif == 1)
		return (ft_write_precision_zero_uns_int(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len)
		return (ft_write_size_uns(arg, nbr));
	if (arg->precision.len >= arg->len && !arg->flag[LESS])
		return (ft_write_prc_uns(arg, nbr));
	if (arg->precision.len >= arg->len && arg->flag[LESS])
		return (ft_write_justify_prc_uns(arg, nbr));
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->len);
}
