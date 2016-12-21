/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:51:22 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/21 15:17:14 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_flag(t_env *arg, int nbr)
{
	int		len;

	len = 0;
	len += ft_nbrlen(nbr);
	if (arg->flag == ZERO)
		len += ft_write_flag_zero(arg, len);
	if (arg->conv == 'x')
	{
		if (arg->flag == DIESE)
			len += ft_write_flag_diese();
		ft_putnbr_base(nbr, "0123456789abcdef");
	}
	return (ft_nbcmp(arg->size, len));
}

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
		if (arg->flag == DIESE)
			len += ft_write_flag_diese();
		if (arg->flag == ZERO)
			return (ft_write_flag(arg, nbr));
		//		if(arg->size)
		//			return (ft_write_size(arg, nbr));
		/*	if (arg->modif == l)
			{
			return (ft_write_modif(arg, ap)); NE RENTRE PAS DANS LE UNSIGNED INT DE BASE
			}*/
		ft_putnbr_base(nbr, "0123456789abcdef");
	}
	else if (arg->conv == 'X')
	{
		if (arg->flag == DIESE)
		{
			ft_putstr("0X");
			len += 2;
		}
		ft_putnbr_base(nbr, "0123456789ABCDEF");
	}
	len += ft_nbrlen(nbr);
	return (len);
}
