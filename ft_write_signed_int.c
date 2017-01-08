/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:49:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/08 16:44:26 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_sgn_int(t_env *arg, signed long long int nbr)
{
	if (nbr >= 0)
	{
		arg->len += ft_write_flag_more(arg);
		arg->len += ft_write_flag_space(arg);
		ft_printf_putnbr(arg, nbr);
		ft_write_flag_spaces(arg->size, arg->len);
	}
	else
	{
		ft_printf_putnbr(arg, nbr);
		arg->len += ft_write_flag_spaces(arg->size, arg->len);
	}
	return (arg->size);
}

static int	ft_write_size_sgn_int(t_env *arg, signed long long int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 0)
	{
		if (arg->flags.options[ZERO] && !arg->precision.actif)
		{
			arg->len += ft_write_flag_more(arg);
			arg->len += ft_write_flag_space(arg);
			arg->len += ft_write_flag_zero(arg->size, arg->len);
		}
		else
		{
			if ((!arg->flags.options[SPACE] && arg->flags.options[MORE]) || (arg->flags.options[SPACE] && arg->flags.options[MORE]))
				arg->len++;
			i += ft_write_flag_spaces(arg->size, arg->len);
			if ((!arg->flags.options[SPACE] && arg->flags.options[MORE]) || (arg->flags.options[SPACE] && arg->flags.options[MORE]))
				ft_putchar('+');
		}
		ft_printf_putnbr(arg, nbr);
	}
	else
	{
		if (arg->flags.options[ZERO])
		{
			ft_putchar('-');
			arg->len += ft_write_flag_zero(arg->size, arg->len);
		}
		else
			i += ft_write_flag_spaces(arg->size, arg->len);
		if (arg->flags.options[ZERO])
			ft_printf_putnbr(arg, ft_abs(nbr));
		else
			ft_printf_putnbr(arg, nbr);
	}
	//	arg->len += i;
	return (ft_nbcmp_max(arg->len, arg->size));
}

static int	ft_write_justify_precision_sgn_int(t_env *arg, signed long long int nbr)
{
	int	i;
	int	lenfin;

	i = 0;
	lenfin = 0;
	if (nbr >= 0)
	{
		if (arg->size > arg->precision.len/* && arg->precision.len > arg->len*/)
		{
			lenfin += ft_write_flag_more(arg);
			lenfin += ft_write_flag_space(arg);
			i += ft_write_flag_zero(arg->precision.len, arg->len);
			ft_printf_putnbr(arg, nbr);
			i = 0;
			while (i < arg->size - arg->precision.len - lenfin)
			{
				ft_putchar (' ');
				i++;
			}
			return (arg->size);
		}
		else
		{
			lenfin += ft_write_flag_more(arg);
			lenfin += ft_write_flag_space(arg);
			i += ft_write_flag_zero(arg->precision.len, arg->len);
			ft_printf_putnbr(arg, nbr);
			arg->len += i + lenfin;
			return (ft_nbcmp_max(arg->len, arg->precision.len));
		}
	}
	else
	{
		ft_putchar('-');
		i += ft_write_flag_zero(arg->precision.len, arg->len + 1);
		ft_printf_putnbr(arg, ft_abs(nbr));
		return (ft_nbcmp_max(arg->precision.len, arg->len));
	}
	return (0);
}

static int	ft_write_precision_sng_int(t_env *arg, signed long long int nbr)
{
	int		i;
	int		lenfin;

	i = 0;
	lenfin = 0;
	if (nbr >= 0)
	{
		if (arg->size > arg->precision.len/* && arg->precision.len > arg->len*/)
		{
			if (arg->flags.options[MORE])
				lenfin = 1;
			ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
			if (arg->flags.options[MORE])
				ft_putchar('+');
			ft_write_flag_zero(arg->precision.len, arg->len);
			ft_putnbr(nbr);
			return (arg->size);
		}
		else
		{
			lenfin += ft_write_flag_more(arg);
			lenfin += ft_write_flag_space(arg);
			i += ft_write_flag_zero(arg->precision.len, arg->len);
			ft_printf_putnbr(arg, nbr);
			arg->len += i + lenfin;
			return (ft_nbcmp_max(arg->len, arg->precision.len));
		}
	}
	else
	{
		if (arg->size > arg->precision.len/* && arg->precision.len > arg->len*/)
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
			arg->len += lenfin;
			return (ft_nbcmp_max(arg->len, arg->precision.len));
		}
	}
	return (0);
}

static int	ft_write_flag_dec(t_env *arg, signed long long int nbr)
{
	arg->len += ft_write_flag_more(arg);
	arg->len += ft_write_flag_space(arg);
	ft_putnbr(nbr);
	return (arg->len);
}

static int	ft_write_precision_zero_signed_int(t_env *arg, signed long long int nbr)
{
	if (!arg->size)
		return (0);
	else
	{
		ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
}

int	ft_write_signed_int(t_env *arg, va_list ap)
{
	signed long long int	nbr;
	if (!arg->modif && arg->conv != 'D')
		nbr = va_arg(ap, signed int);
	else if (arg->modif == HH && arg->conv != 'D')
		nbr = va_arg(ap, signed int);
	else if (arg->modif == H && arg->conv != 'D')
		nbr = va_arg(ap, signed int);
	else if (arg->modif == LL)
		nbr = va_arg(ap, signed long long int);
	else if (arg->modif == L || arg->conv == 'D')
		nbr = va_arg(ap, signed long int);
	else if (arg->modif == J)
		nbr = va_arg(ap, intmax_t);
	else if (arg->modif == Z)
		nbr = va_arg(ap, size_t);
	arg->len = ft_printf_nbrlen(arg, nbr);
//		printf("nbr = %lld||len nbr = %d||prec = %d||actif = %d||size = %d|||\t\n", nbr, arg->len, arg->precision.len, arg->precision.actif, arg->size);
	if (nbr == 0 && arg->precision.actif == 1 && arg->precision.len == 0)
		return (ft_write_precision_zero_signed_int(arg, nbr));
	if ((nbr >= 0) && (arg->flags.options[MORE] || arg->flags.options[SPACE]) && (!arg->flags.options[LESS]) && arg->size < arg->len && !arg->precision.actif)
		return (ft_write_flag_dec(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len && !arg->flags.options[LESS])
		return (ft_write_size_sgn_int(arg, nbr));
	if (arg->size > arg->len && arg->precision.len <= arg->len && arg->flags.options[LESS])
		return (ft_write_justify_size_sgn_int(arg, nbr));
	if (arg->precision.len >= arg->len && !arg->flags.options[LESS])
		return (ft_write_precision_sng_int(arg, nbr));
	else if (arg->precision.len >= arg->len && arg->flags.options[LESS])
		return (ft_write_justify_precision_sgn_int(arg, nbr));
	ft_printf_putnbr(arg, nbr);
	return (arg->len);
}


//	printf("|||ICI|||\n");
