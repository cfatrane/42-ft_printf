/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:51:22 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 15:03:03 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_write_justify_size_hexa(t_env *arg, unsigned long long int nbr)
{
	int i;

	i = 0;
	if (arg->flags.options[DIESE] == 1 && arg->conv == 'x')
		arg->len += ft_write_flag_diese_min();
	if (arg->flags.options[DIESE] == 1 && arg->conv == 'X')
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
	if (arg->flags.options[LESS])
		return (ft_write_justify_size_hexa(arg, nbr));
	else
	{
		if (arg->flags.options[DIESE] == 1)
			arg->len += 2;
		if (arg->flags.options[ZERO] == 1/* && (arg->precision.len > arg->size || !arg->precision.len)*/)
		{
			if (arg->flags.options[DIESE] && arg->conv == 'x')
				ft_putstr("0x");
			if (arg->flags.options[DIESE] && arg->conv == 'X')
				ft_putstr("0X");
			arg->len += ft_write_flag_zero(arg->size, arg->len);
			if (arg->conv == 'x')
				ft_putnbr_base(nbr, MIN_HEXA);
			else if (arg->conv == 'X')
				ft_putnbr_base(nbr, MAJ_HEXA);
			return (arg->size);
		}
		else
		{
			i += ft_write_flag_spaces(arg->size, arg->len);
			if (arg->flags.options[DIESE])
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

static int ft_write_justify_precision_hexa(t_env *arg, unsigned long long int nbr)
{
	int		i;
	int		lenfin;

	i = 0;
	lenfin = 0;
	if (arg->size > arg->precision.len/* && arg->precision.len > arg->len*/)
	{
		if (arg->flags.options[DIESE])
			lenfin = 2;
		if (arg->flags.options[DIESE] && arg->conv == 'x')
			ft_putstr("0x");
		if (arg->flags.options[DIESE] && arg->conv == 'X')
			ft_putstr("0X");
		i += ft_write_flag_zero(arg->precision.len, arg->len);
		if (arg->conv == 'x')
			ft_putnbr_base(nbr, MIN_HEXA);
		else if (arg->conv == 'X')
			ft_putnbr_base(nbr, MAJ_HEXA);
		i = 0;
		i += ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
		return (arg->size);
	}
	else
	{
		if (arg->flags.options[DIESE])
			lenfin = 2;
		if (arg->flags.options[DIESE] && arg->conv == 'x')
			ft_putstr("0x");
		if (arg->flags.options[DIESE] && arg->conv == 'X')
			ft_putstr("0X");
		i += ft_write_flag_zero(arg->precision.len, arg->len);
		if (arg->conv == 'x')
			ft_putnbr_base(nbr, MIN_HEXA);
		else if (arg->conv == 'X')
			ft_putnbr_base(nbr, MAJ_HEXA);
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
	if (arg->flags.options[LESS] && arg->size)
		return (ft_write_justify_precision_hexa(arg, nbr));
	else
	{
		if (arg->size > arg->precision.len)
		{
			if (arg->flags.options[DIESE])
				lenfin = 2;
			i += ft_write_flag_spaces(arg->size, arg->precision.len + lenfin);
			i = 0;
			if (arg->flags.options[DIESE] && arg->conv == 'x')
				ft_putstr("0x");
			if (arg->flags.options[DIESE] && arg->conv == 'X')
				ft_putstr("0X");
			i += ft_write_flag_zero(arg->precision.len, arg->len);
			if (arg->conv == 'x')
				ft_putnbr_base(nbr, MIN_HEXA);
			else if (arg->conv == 'X')
				ft_putnbr_base(nbr, MAJ_HEXA);
			return (arg->size);
		}
		else
		{
			if (arg->flags.options[DIESE] && arg->conv == 'x')
				lenfin += ft_write_flag_diese_min();
			if (arg->flags.options[DIESE] && arg->conv == 'X')
				lenfin += ft_write_flag_diese_maj();
			i += ft_write_flag_zero(arg->precision.len, arg->len);
			if (arg->conv == 'x')
				ft_putnbr_base(nbr, MIN_HEXA);
			else if (arg->conv == 'X')
				ft_putnbr_base(nbr, MAJ_HEXA);
			arg->len += i + lenfin;
			return (ft_nbcmp_max(arg->len, arg->precision.len));
		}
	}
	return (0);
}

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	if (arg->conv == 'x')
	{
		arg->len += ft_write_flag_diese_min();
		ft_putnbr_base(nbr, MIN_HEXA);
	}
	if (arg->conv == 'X')
	{
		arg->len += ft_write_flag_diese_maj();
		ft_putnbr_base(nbr, MAJ_HEXA);
	}
	return (arg->len);
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
	{
		ft_putchar(0);
		return (0);
	}
/*	if (nbr == 0 && arg->precision.actif == 1)
	{
		ft_putchar(0);
		return (0);
	}
*/	arg->len = ft_nbrlen_hexa(nbr);
	if (arg->flags.options[DIESE] == 1 && !arg->size && arg->precision.actif == 0)
		return (ft_write_flag(arg, nbr));
	if(arg->size > arg->len && (arg->precision.len <= arg->len || !arg->precision.actif))
		return (ft_write_size_hexa(arg, nbr));
	if(arg->precision.len > arg->len)
		return (ft_write_precision_hexa(arg, nbr));
	if (arg->conv == 'x')
		ft_putnbr_base(nbr, MIN_HEXA);
	else if (arg->conv == 'X')
		ft_putnbr_base(nbr, MAJ_HEXA);
	return (arg->len);
}
