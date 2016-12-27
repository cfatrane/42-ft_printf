/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:51:22 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/27 19:15:10 by cfatrane         ###   ########.fr       */
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
		if (arg->flags.flag[DIESE] == 1)
		{
			ft_putstr("0x");
			len += 2;
		}
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
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
		if (arg->flags.flag[DIESE] == 1)
			ft_putstr("0x");
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
	if (arg->conv == 'x')
	{
		if (arg->flags.flag[DIESE] == 1)
			len += ft_write_flag_diese();
		if (arg->flags.flag[ZERO] == 1)
			len += ft_write_flag_zero(arg, len);
		ft_putnbr_base(nbr, MIN_HEXA);
	}
	return (ft_nbcmp(arg->size, len));
}

int	ft_write_hexa(t_env *arg, va_list ap)
{
	int						len;
	unsigned long long int	nbr;

	len = 0;
	if (!(arg->modif))
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == hh)
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == h)
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == ll)
		nbr = va_arg(ap, unsigned long long int);
	else if (arg->modif == l)
		nbr = va_arg(ap, unsigned long int);
	else if (arg->modif == j)
		nbr = va_arg(ap, uintmax_t);
	else if (arg->modif == z)
		nbr = va_arg(ap, size_t);
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (arg->conv == 'x')
	{
		if (arg->flags.flag[DIESE] == 1 || arg->flags.flag[ZERO] == 1)
			return (ft_write_flag(arg, nbr));
		if(arg->size)
			return (ft_write_size_hexa(arg, nbr));
		/*	if (arg->modif == l)
			{
			return (ft_write_modif(arg, ap)); NE RENTRE PAS DANS LE UNSIGNED INT DE BASE
			}*/
		ft_putnbr_base(nbr, MIN_HEXA);
	}
	else if (arg->conv == 'X')
	{
		if (arg->flags.flag[DIESE] == 1)
		{
			ft_putstr("0X");
			len += 2;
		}
		ft_putnbr_base(nbr, MAJ_HEXA);
	}
	len += ft_nbrlen_uns(nbr);
	return (len);
}

/*
   int	ft_write_modif(t_env *arg, va_list ap)
   {
   int				len;
   unsigned int	nbr;

   len = 0;
   nbr = va_arg(ap, unsigned long int);
   if (arg->conv == 'x')
   {
   if (arg->flag == DIESE)
   len += ft_write_flag_diese();
   ft_putnbr_base(nbr, "0123456789");
   }
   len += ft_nbrlen(nbr);
   return (len);
   }
   */
