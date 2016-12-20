/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:46:27 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/20 14:22:44 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_signed_int(t_env *arg, va_list ap)
{
	int			len;
	signed int	nbr;

	len = 0;
	nbr = va_arg(ap, signed int);
	if (arg->flag == MORE && nbr >= 0)
	{
		ft_putchar('+');
		len++;
	}
	ft_putnbr(nbr);
	len += ft_nbrlen(nbr);
	return (len);
}
