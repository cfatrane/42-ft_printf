/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:49:39 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/31 17:24:20 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_signed_int(t_env *arg, long long int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 0)
	{
		arg->len += ft_write_flag_more(arg);
		if (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] != 1)
			arg->len += ft_write_flag_space();
		ft_putnbr(nbr);
		while (i < arg->size - arg->len)
		{
			ft_putchar (' ');
			i++;
		}
	}
	else
	{
		if (arg->flags.flag[ZERO] == 1)
			ft_putchar('-');
		if (arg->flags.flag[ZERO] == 1)
			ft_putnbr(ft_abs(nbr));
		else
			ft_putnbr(nbr);
		while (i < arg->size - arg->len)
		{
			ft_putchar (' ');
			i++;
		}
	}
	arg->len += i;
	return (arg->len);
}

static int	ft_write_size_signed_int(t_env *arg, long long int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 0)
	{
		if (arg->flags.flag[LESS])
			return (ft_write_justify_signed_int(arg, nbr));
		else
		{
			if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[MORE] == 1)
			{
				ft_putchar('+');
				arg->len++;
			}
			if (arg->flags.flag[ZERO] == 1)
				arg->len += ft_write_flag_zero_arg_size(arg, arg->len);
			if (((arg->flags.flag[SPACE] != 1 && arg->flags.flag[MORE] == 1) || (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] == 1)) && (arg->flags.flag[ZERO] != 1))
				arg->len++;
			while (i < arg->size - arg->len)
			{
				ft_putchar (' ');
				i++;
			}
			if (((arg->flags.flag[SPACE] != 1 && arg->flags.flag[MORE] == 1) || (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] == 1)) && (arg->flags.flag[ZERO] != 1))
				ft_putchar('+');
			ft_putnbr(nbr);
		}
	}
	else
	{
		if (arg->flags.flag[LESS])
			return (ft_write_justify_signed_int(arg, nbr));
		else
		{
			if (arg->flags.flag[ZERO] == 1)
			{
				ft_putchar('-');
				arg->len += ft_write_flag_zero_arg_size(arg, arg->len);
			}
			else
			{
				while (i < arg->size - arg->len)
				{
					ft_putchar (' ');
					i++;
				}
			}
			if (arg->flags.flag[ZERO] == 1)
				ft_putnbr(ft_abs(nbr));
			else
				ft_putnbr(nbr);
		}
	}
	arg->len += i;
	return (arg->len);
}

static int	ft_write_flag_precision(t_env *arg, long long int nbr)
{
	int		i;
	int		len;

	i = 0;
	len = ft_nbrlen(nbr);
	if (nbr >= 0)
	{
	//	if (arg->flags.flag[LESS])
	//		return (ft_write_justify_signed_int(arg, nbr));
		if (arg->flags.flag[LESS] == 1 || (arg->flags.flag[LESS] == 1 && arg->flags.flag[ZERO] == 1))
		{
			while (i < arg->precision - len)
			{
				ft_putchar('0');
				i++;
			}
			ft_putnbr(nbr);
			while (i < arg->size - len)
			{
				ft_putchar (' ');
				i++;
			}
		}
		else
		{
			/*
			if (arg->size > arg->precision)
			{
				while (i < arg->size - arg->precision)
				{
					ft_putchar (' ');
					i++;
				}
				//	return (ft_nbcmp(arg->precision, len));
			}
			len += i;
			i = 0;
			len = ft_nbrlen(nbr);
			while (i < arg->precision - len)
			{
				ft_putchar('0');
				i++;
			}
			ft_putnbr(nbr);
			len += i;*/
		}
	}
	else
	{



	}
	return (ft_nbcmp(ft_nbcmp(arg->precision, len), ft_nbcmp(arg->precision, arg->size)));
}

static int	ft_write_flag_dec(t_env *arg, long long int nbr)
{
	if (nbr >= 0)
	{
		arg->len += ft_write_flag_more(arg);
		if (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] != 1)
			arg->len += ft_write_flag_space();
	}
	ft_putnbr(nbr);
	return (ft_nbcmp(arg->size, arg->len));
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
	if ((arg->flags.flag[MORE] == 1 || arg->flags.flag[SPACE] == 1) && (!arg->flags.flag[LESS]) && ((!arg->size) && (!arg->precision)))
		return (ft_write_flag_dec(arg, nbr));
	if(arg->size > arg->len && !arg->precision)
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
