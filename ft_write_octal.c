/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:18:25 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/20 14:08:20 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_octal(t_env *arg, va_list ap)
{
	char	*str;
	int		len;
	int		nbr;

	len = 0;
	if (arg->conv == 'o')
	{
		nbr = va_arg(ap, unsigned int);
		if (arg->flag == DIESE)
			ft_putchar('0');
		ft_putnbr_base(nbr, "01234567");
	}
	else if (arg->conv == 'O')
	{
		nbr = va_arg(ap, unsigned int);
		ft_putnbr_base(nbr, "01234567");
	}
	len = ft_nbrlen(nbr);
	return (len);
}
