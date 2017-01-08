/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:51:22 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/08 15:43:25 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_write_justify_size_hexa(t_env *arg, unsigned long long int nbr)
{
	arg->len += ft_write_flag_diese(arg);
	ft_printf_puthexa(arg, nbr);
	ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int ft_write_size_hexa(t_env *arg, unsigned long long int nbr)
{
	int	i;

	i = 0;
	if (arg->flags.options[DIESE])
		arg->len += 2;
	if (arg->flags.options[ZERO] && !arg->precision.actif)
	{
		if (arg->flags.options[DIESE])
			ft_write_flag_diese(arg);
		arg->len += ft_write_flag_zero(arg->size, arg->len);
		ft_printf_puthexa(arg, nbr);
		return (ft_nbcmp_max(arg->len, arg->size));
	}
	else
	{
		i += ft_write_flag_spaces(arg->size, arg->len);
		if (arg->flags.options[DIESE])
		{
			ft_write_flag_diese(arg);
			ft_printf_puthexa(arg, nbr);
		}
		else
			ft_printf_puthexa(arg, nbr);
		return (ft_nbcmp_max(arg->len, arg->size));
	}
	return (0);
}

static int ft_write_justify_precision_hexa(t_env *arg, unsigned long long int nbr)
{
	int		i;
	int		lenfin;

	i = 0;
	lenfin = 0;
	if (arg->size > arg->precision.len/* && arg->precision.len > arg->len*/)
	{
		lenfin += ft_write_flag_diese(arg);
		i += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_puthexa(arg, nbr);
		i = 0;
		i += ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
		return (arg->size);
	}
	else
	{
		lenfin += ft_write_flag_diese(arg);
		i += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_puthexa(arg, nbr);
		arg->len += i + lenfin;
		return (ft_nbcmp_max(arg->len, arg->precision.len));
	}
	return (0);
}

static int	ft_write_precision_hexa(t_env *arg, unsigned long long int nbr)
{
	int		i;
	int		lenfin;

	i = 0;
	lenfin = 0;
	if (arg->size > arg->precision.len)
	{
		if (arg->flags.options[DIESE])
			lenfin = 2;
		ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
		ft_write_flag_diese(arg);
		ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_puthexa(arg, nbr);
		return (arg->size);
	}
	else
	{
		lenfin += ft_write_flag_diese(arg);
		i += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_printf_puthexa(arg, nbr);
		arg->len += i + lenfin;
		return (ft_nbcmp_max(arg->len, arg->precision.len));
	}
	return (0);
}

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	arg->len += ft_write_flag_diese(arg);
	ft_printf_puthexa(arg, nbr);
	return (arg->len);
}

static int	ft_write_precision_zero_hexa(t_env *arg, unsigned long long int nbr)
{
	if (!arg->size)
		return (0);
	else
	{
		ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
}

int	ft_write_hexa(t_env *arg, va_list ap)
{
	unsigned long long int	nbr;

	if (!(arg->modif))
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == HH)
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == H)
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == LL)
		nbr = va_arg(ap, unsigned long long int);
	else if (arg->modif == L)
		nbr = va_arg(ap, unsigned long int);
	else if (arg->modif == J)
		nbr = va_arg(ap, uintmax_t);
	else if (arg->modif == Z)
		nbr = va_arg(ap, size_t);
	arg->len = ft_nbrlen_hexa(nbr);
	//	printf("nbr = %lld\t len = %d\t largeur = %d\t precision = %d\n", nbr, arg->len, arg->size, arg->precision.len);
	if (nbr == 0 && !arg->size && arg->precision.actif == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nbr == 0 && arg->precision.actif == 1)
		return (ft_write_precision_zero_hexa(arg, nbr));
	arg->len = ft_nbrlen_hexa(nbr);
	if (arg->flags.options[DIESE] && !arg->size && !arg->precision.actif)
		return (ft_write_flag(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len && !arg->flags.options[LESS])
		return (ft_write_size_hexa(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len && arg->flags.options[LESS])
		return (ft_write_justify_size_hexa(arg, nbr));
	if (arg->precision.len >= arg->len && !arg->flags.options[LESS])
		return (ft_write_precision_hexa(arg, nbr));
	if (arg->precision.len >= arg->len && arg->flags.options[LESS])
		return (ft_write_justify_precision_hexa(arg, nbr));
	ft_printf_puthexa(arg, nbr);
	return (arg->len);
}
