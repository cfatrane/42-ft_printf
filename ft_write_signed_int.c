/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:46:27 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/21 14:16:11 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_flag(t_env *arg, int nbr)
{
	int		len;

	len = 0;
	len += ft_nbrlen(nbr);
	if (arg->flag == ZERO)
		len += ft_flag_zero(arg, len);
	if (arg->flag == DIESE)
		len += ft_write_flag_diese();
	ft_putnbr(nbr);
	return (ft_nbcmp(arg->size, len));
}

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
//	if (arg->flag == ZERO)
//		return (ft_write_flag(arg, nbr));
	ft_putnbr(nbr);
	len += ft_nbrlen(nbr);
	return (len);
}
