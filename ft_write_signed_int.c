/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:49:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/03 15:44:33 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_signed_int_size(t_env *arg, long long int nbr)
{
	int	i;
	int	lenfin;

	i = 0;
	lenfin = 0;
	if (nbr >= 0)
	{
		arg->len += ft_write_flag_more(arg);
		if (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] != 1)
			arg->len += ft_write_flag_space(arg);
		ft_putnbr(nbr);
		i += ft_write_flag_spaces(arg->size, arg->len);
	}
	else
	{
		if (arg->flags.flag[ZERO] == 1)
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

static int	ft_write_justify_signed_int_precison(t_env *arg, long long int nbr)
{
	int	i;
	int	lenfin;

	i = 0;
	lenfin = 0;
	if (nbr >= 0)
	{
		if (arg->size > arg->precision/* && arg->precision > arg->len*/)
		{
			lenfin += ft_write_flag_more(arg);
			lenfin += ft_write_flag_space(arg);
			i += ft_write_flag_zero(arg->precision, arg->len);
			ft_putnbr(nbr);
			i = 0;
			while (i < arg->size - arg->precision - lenfin)
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
			i += ft_write_flag_zero(arg->precision, arg->len);
			ft_putnbr(nbr);
			arg->len += i + lenfin;
			return (ft_nbcmp(arg->len, arg->precision));
		}
	}
	else
	{
		ft_putchar('-');
		arg->len += ft_write_flag_zero(arg->precision, arg->len - 1);
		ft_putnbr(ft_abs(nbr));
		return (ft_nbcmp(arg->precision, arg->len));
	}
	return (0);
}

static int	ft_write_size_signed_int(t_env *arg, long long int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 0)
	{
		if (arg->flags.flag[LESS])
			return (ft_write_justify_signed_int_size(arg, nbr));
		else
		{
			if (arg->flags.flag[ZERO])
			{
				if (arg->flags.flag[MORE])
				{
					ft_putchar('+');
					arg->len++;
				}
				arg->len += ft_write_flag_zero(arg->size, arg->len);
			}
			else
			{
				if ((arg->flags.flag[SPACE] != 1 && arg->flags.flag[MORE] == 1) || (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] == 1))
					arg->len++;
				while (i < arg->size - arg->len)
				{
					ft_putchar (' ');
					i++;
				}
				if ((arg->flags.flag[SPACE] != 1 && arg->flags.flag[MORE] == 1) || (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] == 1))
					ft_putchar('+');
			}
			ft_putnbr(nbr);
		}
	}
	else
	{
		if (arg->flags.flag[LESS])
			return (ft_write_justify_signed_int_size(arg, nbr));
		else
		{
			if (arg->flags.flag[ZERO])
			{
				ft_putchar('-');
				arg->len += ft_write_flag_zero(arg->size, arg->len);
			}
			else
			{
				while (i < arg->size - arg->len)
				{
					ft_putchar (' ');
					i++;
				}
			}
			if (arg->flags.flag[ZERO])
				ft_putnbr(ft_abs(nbr));
			else
				ft_putnbr(nbr);
		}
	}
	//	arg->len += i;
	return (ft_nbcmp(arg->len, arg->size));
}

static int	ft_write_flag_precision(t_env *arg, long long int nbr)
{
	int		i;
	int lenfin = 0;

	i = 0;
	if (nbr >= 0)
	{
		if (arg->flags.flag[LESS] && arg->size)
			return (ft_write_justify_signed_int_precison(arg, nbr));
		else
		{
			if (arg->size > arg->precision/* && arg->precision > arg->len*/)
			{
				if (arg->flags.flag[MORE])
					lenfin = 1;
				while (i < arg->size - arg->precision - lenfin)
				{
					ft_putchar (' ');
					i++;
				}
				if (arg->flags.flag[MORE])
					ft_putchar('+');
				i = 0;
				while (i < arg->precision - arg->len)
				{
					ft_putchar('0');
					i++;
				}
				ft_putnbr(nbr);
				return (arg->size);
			}
			else
			{
				lenfin += ft_write_flag_more(arg);
				lenfin += ft_write_flag_space(arg);
				while (i < arg->precision - arg->len)
				{
					ft_putchar('0');
					i++;
				}
				ft_putnbr(nbr);
				arg->len += i + lenfin;
				return (arg->precision);
			}
		}
	}
	else
	{
		if (arg->flags.flag[LESS] && arg->size)
			return (ft_write_justify_signed_int_precison(arg, nbr));
		else
		{
			if (arg->size > arg->precision/* && arg->precision > arg->len*/)
			{
				i += ft_write_flag_spaces(arg->size, arg->precision - 1);
				ft_putchar('-');
				i = 0;
				i += ft_write_flag_zero(arg->precision, arg->len + 1);
				ft_putnbr(ft_abs(nbr));
				return (arg->size);
			}
			else
			{
				ft_putchar('-');
				i += ft_write_flag_zero(arg->precision, arg->len + 1);
				ft_putnbr(ft_abs(nbr));
				arg->len += i + lenfin;
				return (arg->precision);
			}
		}
	}
	//	printf("len = %d||\n prec = %d||\n size = %d||\n\n", arg->len, arg->precision, arg->size);
	//	return (ft_nbcmp(ft_nbcmp(arg->precision, arg->len), ft_nbcmp(arg->precision, arg->size)));
	return (0);
}

static int	ft_write_flag_dec(t_env *arg, long long int nbr)
{
	arg->len += ft_write_flag_more(arg);
	arg->len += ft_write_flag_space(arg);
	ft_putnbr(nbr);
	return (arg->len);
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
	if ((nbr >= 0) && (arg->flags.flag[MORE] == 1 || arg->flags.flag[SPACE] == 1) && (!arg->flags.flag[LESS]) && ((!arg->size) && (!arg->precision)))
		return (ft_write_flag_dec(arg, nbr));
	if(arg->size > arg->len && (arg->precision <= arg->len || !arg->precision))
		return (ft_write_size_signed_int(arg, nbr));
	if(arg->precision > arg->len)
		return (ft_write_flag_precision(arg, nbr));
	if (arg->modif == HH)
		ft_putnbr((signed char)nbr);
	else if (arg->modif == H)
		ft_putnbr((short int)nbr);
	else
		ft_putnbr(nbr);
	return (arg->len);
}
