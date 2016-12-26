/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:51:22 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/26 17:58:21 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_flag(t_env *arg, int nbr)
{
	int		len;

	len = ft_nbrlen(nbr);
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

static int ft_write_size_hexa(t_env *arg, int nbr)
{
	int	i;
	int	len;

	len = 0;
	len += ft_nbrlen(nbr);
	if (arg->flags.flag[LESS] == 1 || (arg->flags.flag[LESS] == 1 && arg->flags.flag[ZERO] == 1))
	{
		if (arg->flags.flag[DIESE] == 1)
		{
			ft_putstr("0x");
			len += 2;
		}
		if (arg->conv == 'x')
			ft_putnbr_base(nbr, MIN_HEXA);
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
	}
	len += i;
	return (len);
}

int	ft_write_hexa(t_env *arg, va_list ap)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	nbr = va_arg(ap, unsigned int);
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (arg->conv == 'x')
	{
		if (arg->flags.flag[ZERO] == 1)
			return (ft_write_flag(arg, nbr));
		if(arg->size)
			return (ft_write_size_hexa(arg, nbr));
		if (arg->flags.flag[DIESE] == 1)
			len += ft_write_flag_diese();
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
	len += ft_nbrlen(nbr);
	return (len);
}
