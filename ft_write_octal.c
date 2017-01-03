/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:18:25 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/03 15:12:26 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_write_justify_octal(t_env *arg, unsigned long long int nbr)
{
	int i;

	i = 0;
	if (!arg->precision)
	{
		if (arg->flags.flag[DIESE] == 1)
		{
			ft_putchar('0');
			arg->len++;
		}
		ft_putnbr_base(nbr, OCTAL);
		i += ft_write_flag_spaces(arg->size, arg->len);
		arg->len += i;
		return (arg->len);
	}
	else if (arg->precision)
	{
		if (arg->size > arg->precision/* && arg->precision > arg->len*/)
		{
			i += ft_write_flag_zero(arg->precision, arg->len);
			ft_putnbr_base(nbr, OCTAL);
			i = 0;
			i += ft_write_flag_spaces(arg->size, arg->precision);
			return (arg->size);
		}
		else
		{
			i += ft_write_flag_zero(arg->precision, arg->len);
			ft_putnbr_base(nbr, OCTAL);
			return (arg->precision);
		}
	}
	return (0);
}

static int	ft_write_size_oct(t_env *arg, unsigned long long int nbr)
{
	int	i;

	i = 0;
	if (arg->flags.flag[LESS])
		return (ft_write_justify_octal(arg, nbr));
	else
	{
		if (arg->flags.flag[DIESE] == 1)
			arg->len++;
		if (arg->flags.flag[ZERO] == 1/* && (arg->precision > arg->size || !arg->precision)*/)
			arg->len += ft_write_flag_zero(arg->size, arg->len);
		else
			i += ft_write_flag_spaces(arg->size, arg->len);
		//	if (arg->flags.flag[ZERO] == 1/* && (arg->precision > arg->size || !arg->precision)*/)
		//		arg->len += ft_write_flag_zero_arg_size(arg, arg->len);
		if (arg->flags.flag[DIESE] == 1)
			ft_putchar('0');
		ft_putnbr_base(nbr, OCTAL);
	}
	arg->len += i;
	return (arg->len);
}

static int	ft_write_flag_precision_oct(t_env *arg, unsigned long long int nbr)
{
	int		i;

	i = 0;
	if (arg->flags.flag[LESS] && arg->size)
		return (ft_write_justify_octal(arg, nbr));
	else
	{
		if (arg->size > arg->precision)
		{
			i += ft_write_flag_spaces(arg->size, arg->precision);
			//	arg->len += i;
			i = 0;
			//	arg->len = ft_nbrlen_uns(nbr);
			i += ft_write_flag_zero(arg->precision, arg->len);
			ft_putnbr_base(nbr, OCTAL);
			arg->len += i;
			return (arg->size);
			//	return (ft_nbcmp(arg->precision, len));
		}
		else
		{
			i += ft_write_flag_zero(arg->precision, arg->len);
			ft_putnbr_base(nbr, OCTAL);
			return (arg->precision);
		}
	}
	return (0);
}

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	//	int		len;

	//	len = ft_nbrlen_uns(nbr);
	//	if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
	//		arg->len += ft_write_flag_zero_arg_size(arg, arg->len);
	//	else if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] == 1)
	//		return (ft_write_size_oct(arg, nbr));
	if (arg->flags.flag[DIESE] == 1)
	{
		ft_putchar('0');
		arg->len++;
	}
	ft_putnbr_base(nbr, OCTAL);
	return (arg->len);
}

int	ft_write_octal(t_env *arg, va_list ap)
{
	//	int						len;
	unsigned long long int	nbr;

	//	len = 0;
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
	arg->len = ft_nbrlen_uns(nbr);
	//	if(arg->precision)
	//		return (ft_write_flag_precision(arg, nbr));
	//	printf("len = %d||\n prec = %d||\n size = %d||\n\n", arg->len, arg->precision, arg->size);
	if (arg->flags.flag[DIESE] == 1 && !arg->size && !arg->precision)
		return (ft_write_flag(arg, nbr));
	if(arg->size > arg->len && (arg->precision <= arg->len || !arg->precision))
		return (ft_write_size_oct(arg, nbr));
	if(arg->precision > arg->len)
	{
		//	printf("ICI\n");
		return (ft_write_flag_precision_oct(arg, nbr));
	}
	/*	if (arg->flags.flag[DIESE] == 1)
		{
		ft_putchar('0');
		len++;
		}
		*/	ft_putnbr_base(nbr, OCTAL);
	return (arg->len);
}
