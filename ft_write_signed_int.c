/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:49:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 19:32:05 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** GERER CE CAS
Lorsque 0 est converti avec une précision valant 0, la sortie est vide.
**/

static int	ft_write_justify_size_signed_int(t_env *arg, long long int nbr)
{
	int	i;
	int	lenfin;

	i = 0;
	lenfin = 0;
	if (nbr >= 0)
	{
		arg->len += ft_write_flag_more(arg);
		if (arg->flags.options[SPACE] == 1 && arg->flags.options[MORE] != 1)
			arg->len += ft_write_flag_space(arg);
		ft_putnbr(nbr);
		i += ft_write_flag_spaces(arg->size, arg->len);
	}
	else
	{
		if (arg->flags.options[ZERO] == 1)
		{
			ft_putchar('-');
			ft_putnbr(ft_abs(nbr));
		}
		else
			ft_putnbr(nbr);
		arg->len += ft_write_flag_spaces(arg->size, arg->len);
	}
	return (arg->size);
}

static int	ft_write_size_signed_int(t_env *arg, long long int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 0)
	{
		if (arg->flags.options[LESS])
			return (ft_write_justify_size_signed_int(arg, nbr));
		else
		{
			if (arg->flags.options[ZERO])
			{
				if (arg->flags.options[MORE])
				{
					ft_putchar('+');
					arg->len++;
				}
				arg->len += ft_write_flag_zero(arg->size, arg->len);
			}
			else
			{
				if ((arg->flags.options[SPACE] != 1 && arg->flags.options[MORE] == 1) || (arg->flags.options[SPACE] == 1 && arg->flags.options[MORE] == 1))
					arg->len++;
				i += ft_write_flag_spaces(arg->size, arg->len);
				if ((arg->flags.options[SPACE] != 1 && arg->flags.options[MORE] == 1) || (arg->flags.options[SPACE] == 1 && arg->flags.options[MORE] == 1))
					ft_putchar('+');
			}
			ft_putnbr(nbr);
		}
	}
	else
	{
		if (arg->flags.options[LESS])
			return (ft_write_justify_size_signed_int(arg, nbr));
		else
		{
			if (arg->flags.options[ZERO])
			{
				ft_putchar('-');
				arg->len += ft_write_flag_zero(arg->size, arg->len);
			}
			else
			{
				i += ft_write_flag_spaces(arg->size, arg->len);
			}
			if (arg->flags.options[ZERO])
				ft_putnbr(ft_abs(nbr));
			else
				ft_putnbr(nbr);
		}
	}
	//	arg->len += i;
	return (ft_nbcmp_max(arg->len, arg->size));
}

static int	ft_write_justify_precision_signed_int(t_env *arg, long long int nbr)
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
			ft_putnbr(nbr);
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
			ft_putnbr(nbr);
			arg->len += i + lenfin;
			return (ft_nbcmp_max(arg->len, arg->precision.len));
		}
	}
	else
	{
		ft_putchar('-');
		i += ft_write_flag_zero(arg->precision.len, arg->len + 1);
		ft_putnbr(ft_abs(nbr));
		return (ft_nbcmp_max(arg->precision.len, arg->len));
	}
	return (0);
}

static int	ft_write_flag_precision(t_env *arg, long long int nbr)
{
	int		i;
	int		lenfin;

	i = 0;
	lenfin = 0;
	if (nbr >= 0)
	{
		if (arg->flags.options[LESS] && arg->size)
			return (ft_write_justify_precision_signed_int(arg, nbr));
		else
		{
			if (arg->size > arg->precision.len/* && arg->precision.len > arg->len*/)
			{
				if (arg->flags.options[MORE])
					lenfin = 1;
				while (i < arg->size - arg->precision.len - lenfin)
				{
					ft_putchar (' ');
					i++;
				}
				if (arg->flags.options[MORE])
					ft_putchar('+');
				i = 0;
				i += ft_write_flag_zero(arg->precision.len, arg->len);
				ft_putnbr(nbr);
				return (arg->size);
			}
			else
			{
				lenfin += ft_write_flag_more(arg);
				lenfin += ft_write_flag_space(arg);
				i += ft_write_flag_zero(arg->precision.len, arg->len);
				ft_putnbr(nbr);
				arg->len += i + lenfin;
				return (arg->precision.len);
			}
		}
	}
	else
	{
		if (arg->flags.options[LESS] && arg->size)
			return (ft_write_justify_precision_signed_int(arg, nbr));
		else
		{
			if (arg->size > arg->precision.len/* && arg->precision.len > arg->len*/)
			{
				i += ft_write_flag_spaces(arg->size, arg->precision.len + 1);
				ft_putchar('-');
				i = 0;
				i += ft_write_flag_zero(arg->precision.len, arg->len - 1);
				ft_putnbr(ft_abs(nbr));
				return (arg->size);
			}
			else
			{
				ft_putchar('-');
				arg->len += ft_write_flag_zero(arg->precision.len, arg->len - 1);
				ft_putnbr(ft_abs(nbr));
				arg->len += i + lenfin;
				return (ft_nbcmp_max(arg->len, arg->precision.len));
			}
		}
	}
	return (0);
}

static int	ft_write_flag_dec(t_env *arg, long long int nbr)
{
	arg->len += ft_write_flag_more(arg);
	arg->len += ft_write_flag_space(arg);
	ft_putnbr(nbr);
	return (arg->len);
}

static int	ft_write_precision_zero_signed_int(t_env *arg, long long int nbr)
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

int	ft_write_signed_int(t_env *arg, va_list ap)
{
	long long int	nbr;

	if (!(arg->modif))
		nbr = va_arg(ap, signed int);
	else if (arg->modif == HH)
		nbr = va_arg(ap, signed int);
	else if (arg->modif == H)
		nbr = va_arg(ap, signed int);
	else if (arg->modif == LL)
		nbr = va_arg(ap, long long int);
	else if (arg->modif == L)
		nbr = va_arg(ap, long int);
	else if (arg->modif == J)
		nbr = va_arg(ap, intmax_t);
	else if (arg->modif == Z)
		nbr = va_arg(ap, size_t);
	if (arg->modif == HH)
		arg->len = ft_nbrlen((signed char)nbr);
	else if (arg->modif == H)
		arg->len = ft_nbrlen((short int)nbr);
	else
		arg->len = ft_nbrlen(nbr);
	if (nbr == 0 && arg->precision.actif == 1)
		return (ft_write_precision_zero_signed_int(arg, nbr));
	if ((nbr >= 0) && (arg->flags.options[MORE] || arg->flags.options[SPACE]) && (!arg->flags.options[LESS]) && ((!arg->size) && (arg->precision.actif == 0)))
		return (ft_write_flag_dec(arg, nbr));
	if (arg->size > arg->len && (arg->precision.len <= arg->len || !arg->precision.actif))
		return (ft_write_size_signed_int(arg, nbr));
	if (arg->precision.len > arg->len)
		return (ft_write_flag_precision(arg, nbr));
		if (arg->modif == HH)
		ft_putnbr((signed char)nbr);
	else if (arg->modif == H)
		ft_putnbr((short int)nbr);
	else
		ft_putnbr(nbr);
	return (arg->len);
}
