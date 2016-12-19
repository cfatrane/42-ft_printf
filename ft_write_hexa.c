/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:51:22 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/19 16:38:36 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hexa(t_env *arg, va_list ap)
{
	int		nbr;
	int		len;

	len = 0;
	nbr = va_arg(ap, unsigned int);
	if (arg->conv == 'x')
	{
		if (arg->flag == 4)
		{
			ft_putstr("0x");
			len += 2;
		}
		ft_putnbr_base(nbr, "0123456789abcdef");
	}
	else if (arg->conv == 'X')
	{
		if (arg->flag == 4)
		{
			ft_putstr("0x");
			len += 2;
		}
		ft_putnbr_base(nbr, "0123456789ABCDEF");
	}
	len += ft_nbrlen(nbr);
	return (len);
}
