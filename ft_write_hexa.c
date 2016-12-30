/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:51:22 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/30 12:22:40 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_write_size_hexa(t_env *arg, unsigned long long int nbr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_nbrlen_uns(nbr);
	if (arg->flags.flag[LESS] == 1 || (arg->flags.flag[LESS] == 1 && arg->flags.flag[ZERO] == 1))
	{
		if (arg->flags.flag[DIESE] == 1 && arg->conv == 'x')
			len += ft_write_flag_diese_min();
		if (arg->flags.flag[DIESE] == 1 && arg->conv == 'X')
			len += ft_write_flag_diese_maj();
		if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
			len += ft_write_flag_zero_arg_size(arg, len);
		if (arg->conv == 'x')
			ft_putnbr_base(nbr, MIN_HEXA);
		if (arg->conv == 'X')
			ft_putnbr_base(nbr, MAJ_HEXA);
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
	}
	else
	{
		if (arg->flags.flag[DIESE] == 1)
			len += 2;
		if (arg->flags.flag[ZERO] == 1)
			len += ft_write_flag_zero_arg_size(arg, len);
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
		if (arg->flags.flag[DIESE] == 1 && arg->conv == 'x')
			ft_putstr("0x");
		if (arg->flags.flag[DIESE] == 1 && arg->conv == 'X')
			ft_putstr("0X");
		if (arg->conv == 'x')
			ft_putnbr_base(nbr, MIN_HEXA);
		if (arg->conv == 'X')
			ft_putnbr_base(nbr, MAJ_HEXA);
	}
	len += i;
	return (len);
}

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	int		len;

	len = ft_nbrlen_uns(nbr);
	if (arg->flags.flag[DIESE] == 1 && arg->conv == 'x')
		len += ft_write_flag_diese_min();
	if (arg->flags.flag[DIESE] == 1 && arg->conv == 'X')
		len += ft_write_flag_diese_maj();
	if (arg->flags.flag[ZERO] == 1)
		len += ft_write_flag_zero_arg_size(arg, len);
	if (arg->conv == 'x')
		ft_putnbr_base(nbr, MIN_HEXA);
	if (arg->conv == 'X')
		ft_putnbr_base(nbr, MAJ_HEXA);
	return (ft_nbcmp(arg->size, len));
}

int	ft_write_hexa(t_env *arg, va_list ap)
{
	int						len;
	unsigned long long int	nbr;

	len = 0;
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
	if (arg->conv == 'x')
	{
		if(arg->size)
			return (ft_write_size_hexa(arg, nbr));
		if (arg->flags.flag[DIESE] == 1 || arg->flags.flag[ZERO] == 1)
			return (ft_write_flag(arg, nbr));
		ft_putnbr_base(nbr, MIN_HEXA);
		len += ft_strlen(ft_itoa_base(nbr, MIN_HEXA));
	}
	else if (arg->conv == 'X')
	{
		if(arg->size)
			return (ft_write_size_hexa(arg, nbr));
		if (arg->flags.flag[DIESE] == 1 || arg->flags.flag[ZERO] == 1)
			return (ft_write_flag(arg, nbr));
		ft_putnbr_base(nbr, MAJ_HEXA);
		len += ft_strlen(ft_itoa_base(nbr, MAJ_HEXA));
	}
	//	len += ft_nbrlen_uns(nbr);
	return (len);
}
