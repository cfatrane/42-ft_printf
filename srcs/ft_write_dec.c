/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:46:27 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/18 12:45:20 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_dec(t_env *arg, va_list ap)
{
	if (arg->conv == 'd' || arg->conv == 'i')
	{
		signed int nbr;

		nbr = va_arg(ap, signed int);
		ft_putnbr(nbr);
	}
	else if (arg->conv == 'u')
	{
		signed int nbr;

		nbr = va_arg(ap, unsigned int);
		ft_putnbr(nbr);
	}
	else if (arg->conv == 'D')
	{
		long int nbr;

		nbr = va_arg(ap, signed int);
		ft_putnbr(nbr);
	}
	else if (arg->conv == 'U')
	{
		long int nbr;

		nbr = va_arg(ap, unsigned int);
		ft_putnbr(nbr);
	}
}
