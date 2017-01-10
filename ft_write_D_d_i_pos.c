/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int_pos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:34:25 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 18:57:18 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_D_d_i(t_env *arg, signed long long int nbr)
{
	arg->len += ft_write_flag_more(arg);
	arg->len += ft_write_flag_space(arg);
	ft_printf_putnbr(arg, nbr);
	ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_D_d_i(t_env *arg, signed long long int nbr)
{
	if (arg->flag[ZERO] && !arg->precision.actif)
	{
		arg->len += ft_write_flag_more(arg);
		arg->len += ft_write_flag_space(arg);
		arg->len += ft_write_flag_zero(arg->size, arg->len);
	}
	else
	{
		if (arg->flag[MORE])
			arg->len++;
		ft_write_flag_spaces(arg->size, arg->len);
		if (arg->flag[MORE])
			ft_putchar('+');
	}
	ft_printf_putnbr(arg, nbr);
	return (ft_nbcmp_max(arg->len, arg->size));
}

static int	ft_write_justify_prc_D_d_i(t_env *arg, signed long long int nbr)
{
	int	lenfin;

	lenfin = 0;
	if (arg->size > arg->precision.len)
	{
		lenfin += ft_write_flag_more(arg);
		lenfin += ft_write_flag_space(arg);
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
		return (arg->size);
	}
	else
	{
		lenfin += ft_write_flag_more(arg);
		lenfin += ft_write_flag_space(arg);
		lenfin += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		arg->len += lenfin;
		return (ft_nbcmp_max(arg->len, arg->precision.len));
	}
	return (0);
}

static int	ft_write_prc_D_d_i(t_env *arg, signed long long int nbr)
{
	int		lenfin;

	lenfin = 0;
	if (arg->size > arg->precision.len)
	{
		if (arg->flag[MORE])
			lenfin = 1;
		ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
		if (arg->flag[MORE])
			ft_putchar('+');
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_putnbr(nbr);
		return (arg->size);
	}
	else
	{
		lenfin += ft_write_flag_more(arg);
		lenfin += ft_write_flag_space(arg);
		lenfin += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		arg->len += lenfin;
	}
	return (ft_nbcmp_max(arg->len, arg->precision.len));
}

int			ft_write_D_d_i_pos(t_env *arg, signed long long int nbr)
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
