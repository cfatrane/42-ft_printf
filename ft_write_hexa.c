/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:51:22 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/03 18:46:01 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_write_justify_size_hexa(t_env *arg, unsigned long long int nbr)
{
	int i;

	i = 0;
	/*	ft_putnbr_uns(nbr);
		i += ft_write_flag_spaces(arg->size, arg->len);
		arg->len += i;
		return (arg->len);*/
	if (arg->flags.flag[DIESE] == 1 && arg->conv == 'x')
		arg->len += ft_write_flag_diese_min();
	if (arg->flags.flag[DIESE] == 1 && arg->conv == 'X')
		arg->len += ft_write_flag_diese_maj();
	if (arg->conv == 'x')
		ft_putnbr_base(nbr, MIN_HEXA);
	if (arg->conv == 'X')
		ft_putnbr_base(nbr, MAJ_HEXA);
	i += ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int ft_write_size_hexa(t_env *arg, unsigned long long int nbr)
{
	int	i;

	i = 0;
	if (arg->flags.flag[LESS])
		return (ft_write_justify_size_hexa(arg, nbr));
	else
	{
		if (arg->flags.flag[DIESE])
			arg->len += 2;
		if (arg->flags.flag[ZERO] == 1/* && (arg->precision > arg->size || !arg->precision)*/)
		{
			if (arg->flags.flag[DIESE] && arg->conv == 'x')
				ft_putstr("0x");
			if (arg->flags.flag[DIESE] && arg->conv == 'X')
				ft_putstr("0X");
			arg->len += ft_write_flag_zero(arg->size, arg->len);
			ft_putnbr_base(nbr, MIN_HEXA);
			return (arg->size);
		}
		else
		{
			arg->len += ft_write_flag_spaces(arg->size, arg->len);
			if (arg->flags.flag[DIESE])
			{
				if (arg->conv == 'x')
				{
					ft_putstr("0x");
					ft_putnbr_base(nbr, MIN_HEXA);
				}
				else if (arg->conv == 'X')
				{
					ft_putstr("0X");
					ft_putnbr_base(nbr, MAJ_HEXA);
					exit (0);
				}
			}
			else
			{
				if (arg->conv == 'x')
					ft_putnbr_base(nbr, MIN_HEXA);
				else if (arg->conv == 'X')
					ft_putnbr_base(nbr, MAJ_HEXA);
			}
			return (arg->size);
		}

	}
	return (0);
}

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	if (arg->flags.flag[DIESE] && arg->conv == 'x')
		arg->len += ft_write_flag_diese_min();
	else if (arg->conv == 'x')
		ft_putnbr_base(nbr, MIN_HEXA);
	if (arg->flags.flag[DIESE] && arg->conv == 'X')
		arg->len += ft_write_flag_diese_maj();
	else if (arg->conv == 'X')
		ft_putnbr_base(nbr, MAJ_HEXA);
	return (ft_nbcmp(arg->size, arg->len));
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
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	arg->len = ft_nbrlen_hexa(nbr);
	if(arg->size > arg->len)
		return (ft_write_size_hexa(arg, nbr));
	if (arg->flags.flag[DIESE] == 1)
		return (ft_write_flag(arg, nbr));
	if (arg->conv == 'x')
		ft_putnbr_base(nbr, MIN_HEXA);
	else if (arg->conv == 'X')
		ft_putnbr_base(nbr, MAJ_HEXA);
	return (arg->len);
}
