/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:18:25 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/19 15:19:45 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_octal(t_env *arg, va_list ap)
{
	char	*str;
	int		len;
	int		nbr;

	len = 0;
	nbr = va_arg(ap, unsigned int);
	if (arg->conv == 'o')
	{
		ft_putnbr_base(nbr, "01234567");
	}
	len = ft_nbrlen(nbr);
	return (len);
}
