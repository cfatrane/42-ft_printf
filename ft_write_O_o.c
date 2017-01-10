/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_O_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:50:17 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 18:57:48 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_O_o(t_env *arg, unsigned long long nbr)
{
	arg->len += ft_write_flag_diese(arg);
	ft_printf_putnbr(arg, nbr);
	ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_O_o(t_env *arg, unsigned long long nbr)
{
	if (arg->flag[DIESE])
		arg->len++;
	if (arg->flag[ZERO] && !arg->precision.actif)
		ft_write_flag_zero(arg->size, arg->len);
	else
		ft_write_flag_spaces(arg->size, arg->len);
	arg->len += ft_write_flag_diese(arg);
	ft_printf_putnbr(arg, nbr);
	return (arg->size);
}

static int	ft_write_justify_precision_O_o(t_env *arg, unsigned long long int nbr)
{
	if (arg->size > arg->precision.len)
	{
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
	else
	{
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		return (arg->precision.len);
	}
	return (0);
}

static int	ft_write_precision_O_o(t_env *arg, unsigned long long int nbr)
{
	if (arg->size > arg->precision.len)
	{
		ft_write_flag_spaces(arg->size, arg->precision.len);
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		return (arg->size);
	}
	else
	{
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_putnbr(arg, nbr);
		return (arg->precision.len);
	}
	return (0);
}

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	arg->len += ft_write_flag_diese(arg);
	ft_printf_putnbr(arg, nbr);
	return (arg->len);
}

static int	ft_write_precision_zero_O_o(t_env *arg, unsigned long long int nbr)
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
		{
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
	}
	return (0);
}

int			ft_write_O_o(t_env *arg, va_list ap)
{
	unsigned long long int	nbr;

/*	if ((!arg->modif || arg->modif == HH || arg->modif == H) && arg->conv != 'O')
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == LL)
		nbr = va_arg(ap, unsigned long long int);
	else if (arg->modif == L || arg->conv == 'O')
		nbr = va_arg(ap, unsigned long int);
	else if (arg->modif == J)
		nbr = va_arg(ap, uintmax_t);
	else if (arg->modif == Z)
		nbr = va_arg(ap, size_t);
*/	nbr = ft_caste_unsigned(arg, ap);
	arg->len = ft_printf_nbrlen(arg, nbr);
	if (nbr == 0 && arg->precision.actif && arg->precision.len == 0)
		return (ft_write_precision_zero_O_o(arg, nbr));
	if (nbr > 0 && arg->flag[DIESE] && !arg->flag[LESS] && arg->size < arg->len && arg->precision.len == 0)
		return (ft_write_flag(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len &&
			!arg->flag[LESS])
		return (ft_write_size_O_o(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len &&
			arg->flag[LESS])
		return (ft_write_justify_size_O_o(arg, nbr));
	if (arg->precision.len >= arg->len && !arg->flag[LESS])
		return (ft_write_precision_O_o(arg, nbr));
	if (arg->precision.len >= arg->len && arg->flag[LESS])
		return (ft_write_justify_precision_O_o(arg, nbr));
	ft_printf_putnbr(arg, nbr);
	return (arg->len);
}
