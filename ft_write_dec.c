/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:46:27 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/19 13:38:39 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_dec(t_env *arg, va_list ap)
{
	int len;

	len = 0;
	if (arg->conv == 'd' || arg->conv == 'i')
	{
		signed int nbr;

		nbr = va_arg(ap, signed int);
		ft_putnbr(nbr);
		len = ft_nbrlen(nbr);
	}
	else if (arg->conv == 'u')
	{
		signed int nbr;

		nbr = va_arg(ap, unsigned int);
		ft_putnbr(nbr);
		len = ft_nbrlen(nbr);
	}
	else if (arg->conv == 'D')
	{
		long int nbr;

		nbr = va_arg(ap, signed int);
		ft_putnbr(nbr);
		len = ft_nbrlen(nbr);
	}
	else if (arg->conv == 'U')
	{
		long int nbr;

		nbr = va_arg(ap, unsigned int);
		ft_putnbr(nbr);
		len = ft_nbrlen(nbr);
	}
	return (len);
}
