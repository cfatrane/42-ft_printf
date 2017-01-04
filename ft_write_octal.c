/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:18:25 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 20:25:56 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_write_justify_size_octal(t_env *arg, unsigned long long int nbr)
{
	int i;

	i = 0;
	if (arg->flags.options[DIESE] == 1)
	{
		ft_putchar('0');
		arg->len++;
	}
	ft_putnbr_base(nbr, OCTAL);
	i += ft_write_flag_spaces(arg->size, arg->len);
	arg->len += i;
	return (arg->size);
}

static int	ft_write_size_oct(t_env *arg, unsigned long long int nbr)
{
	int	i;

	i = 0;
	if (arg->flags.options[LESS])
		return (ft_write_justify_size_octal(arg, nbr));
	else
	{
		if (arg->flags.options[DIESE] == 1)
			arg->len++;
		if (arg->flags.options[ZERO] == 1/* && (arg->precision.len > arg->size || !arg->precision.len)*/)
			arg->len += ft_write_flag_zero(arg->size, arg->len);
		else
			i += ft_write_flag_spaces(arg->size, arg->len);
		if (arg->flags.options[DIESE] == 1)
			ft_putchar('0');
		ft_putnbr_base(nbr, OCTAL);
	}
	//	arg->len += i;
	return (arg->size);
}

static int ft_write_justify_precision_octal(t_env *arg, unsigned long long int nbr)
{
	int i;

	i = 0;
	if (arg->size > arg->precision.len/* && arg->precision.len > arg->len*/)
	{
		i += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_putnbr_base(nbr, OCTAL);
		i = 0;
		i += ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
	else
	{
		i += ft_write_flag_zero(arg->precision.len, arg->len);
		ft_putnbr_base(nbr, OCTAL);
		return (arg->precision.len);
	}
	return (0);
}

static int	ft_write_precision_oct(t_env *arg, unsigned long long int nbr)
{
	int		i;

	i = 0;
	if (arg->flags.options[LESS] && arg->size)
		return (ft_write_justify_precision_octal(arg, nbr));
	else
	{
		if (arg->size > arg->precision.len)
		{
			i += ft_write_flag_spaces(arg->size, arg->precision.len);
			//	arg->len += i;
			i = 0;
			//	arg->len = ft_nbrlen_uns(nbr);
			i += ft_write_flag_zero(arg->precision.len, arg->len);
			ft_putnbr_base(nbr, OCTAL);
			arg->len += i;
			return (arg->size);
			//	return (ft_nbcmp(arg->precision.len, len));
		}
		else
		{
			i += ft_write_flag_zero(arg->precision.len, arg->len);
			ft_putnbr_base(nbr, OCTAL);
			return (arg->precision.len);
		}
	}
	return (0);
}

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	if (arg->flags.options[DIESE] == 1)
	{
		ft_putchar('0');
		arg->len++;
	}
	ft_putnbr_base(nbr, OCTAL);
	return (arg->len);
}

static int ft_write_precision_zero_oct(t_env *arg, unsigned long long int nbr)
{
	if (!arg->flags.options[DIESE])
	{
		if (!arg->size)
		{
			ft_putchar(0);
			return (0);
		}
		else
		{
			ft_write_flag_spaces(arg->size, arg->precision.len);
			return (arg->size);
		}
	}
	else if (arg->flags.options[DIESE])
	{
		if (!arg->size)
		{
			ft_putchar('0');
			return (1);
		}
		else
		{
			if (arg->flags.options[LESS])
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

int	ft_write_octal(t_env *arg, va_list ap)
{
	unsigned long long int	nbr;

	if (!(arg->modif))
		nbr = va_arg(ap, unsigned long long int);
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
	arg->len = ft_nbrlen_octal(nbr);
	//	printf("len = %d||\n prec = %d||\n size = %d||\n\n", arg->len, arg->precision.len, arg->size);
	if (nbr == 0 && arg->precision.actif == 1)
		return (ft_write_precision_zero_oct(arg, nbr));
	if (nbr > 0 && arg->flags.options[DIESE] == 1 && !arg->size && arg->precision.actif == 0)
		return (ft_write_flag(arg, nbr));
	if(arg->size > arg->len && (arg->precision.len <= arg->len || !arg->precision.len))
		return (ft_write_size_oct(arg, nbr));
	if(arg->precision.len > arg->len)
		return (ft_write_precision_oct(arg, nbr));
	ft_putnbr_base(nbr, OCTAL);
	return (arg->len);
}
