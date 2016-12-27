/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_long_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:30:24 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/27 18:36:23 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_long_int(t_env *arg, va_list ap)
{
	int			len;
	long int	nbr;

	len = 0;
	if (arg->conv == 'D')
	{
		nbr = va_arg(ap, long int);
		ft_putnbr(nbr);
		len = ft_nbrlen(nbr);
	}
	else if (arg->conv == 'U')
	{
		nbr = va_arg(ap, unsigned long int);
		ft_putnbr_uns(nbr);
		len = ft_nbrlen_uns(nbr);
	}
	return (len);
}
