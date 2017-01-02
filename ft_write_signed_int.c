/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_signed_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:49:39 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/02 17:38:42 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_signed_int(t_env *arg, long long int nbr)
{
	int	i;
	int	lenfin;

	i = 0;
	lenfin = 0;
	if (!arg->precision)
	{
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
			{
				ft_putchar('-');
	//		if (arg->flags.flag[ZERO] == 1)
				ft_putnbr(ft_abs(nbr));
			}
			else
				ft_putnbr(nbr);
			while (i < arg->size - arg->len)
			{
				ft_putchar (' ');
				i++;
			}
		}
		return (ft_nbcmp(arg->len, arg->size));
	}
	else if (arg->precision)
	{
		if (nbr >= 0)
		{
			lenfin += ft_write_flag_more(arg);
			if (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] != 1)
				lenfin += ft_write_flag_space();
			while (i < arg->precision - arg->len)
			{
				ft_putchar('0');
				i++;
			}
			ft_putnbr(nbr);
			i = 0;
			while (i < arg->size - arg->precision - lenfin)
			{
				ft_putchar (' ');
				i++;
			}
		}
		else
		{
				ft_putchar('-');
				ft_putnbr(nbr);


		}
		return (ft_nbcmp(arg->precision, arg->size));
	}
	//	arg->len += i;
	return (0);
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
			if (arg->flags.flag[ZERO] == 1 && (arg->precision > arg->size || !arg->precision))
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
			return (ft_write_justify_signed_int(arg, nbr));
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
			}
			else
			{
				lenfin += ft_write_flag_more(arg);
				if (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] != 1)
					lenfin += ft_write_flag_space();
				while (i < arg->precision - arg->len)
				{
					ft_putchar('0');
					i++;
				}
				ft_putnbr(nbr);
				arg->len += i + lenfin;
			}
		}
	}
	else
	{
		if (arg->flags.flag[LESS] && arg->size)
			return (ft_write_justify_signed_int(arg, nbr));
		else
		{
			if (arg->size > arg->precision/* && arg->precision > arg->len*/)
			{
				while (i < arg->size - arg->precision - 1)
				{
					ft_putchar (' ');
					i++;
				}
				ft_putchar('-');
				i = 0;
				while (i < arg->precision - arg->len + 1)
				{
					ft_putchar('0');
					i++;
				}
				ft_putnbr(ft_abs(nbr));
			}
			else
			{
				ft_putchar('-');
				//	arg->len += ft_write_flag_zero_arg_size(arg, arg->len);
				while (i < arg->precision - arg->len + 1)
				{
					ft_putchar('0');
					i++;
				}
				ft_putnbr(ft_abs(nbr));
				arg->len += i + lenfin;
			}
		}
	}
	//	printf("len = %d||\n prec = %d||\n size = %d||\n\n", arg->len, arg->precision, arg->size);
	return (ft_nbcmp(ft_nbcmp(arg->precision, arg->len), ft_nbcmp(arg->precision, arg->size)));
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
	if(arg->size > arg->len && arg->precision <= arg->len)
	{
		//		printf("ici1\n");
		return (ft_write_size_signed_int(arg, nbr));
	}
	if(arg->precision > arg->len)
	{
		//			printf("ici2\n");
		return (ft_write_flag_precision(arg, nbr));
	}
	if (arg->modif == HH)
		ft_putnbr((signed char)nbr);
	else if (arg->modif == H)
		ft_putnbr((short int)nbr);
	else
		ft_putnbr(nbr);
	return (arg->len);
}
