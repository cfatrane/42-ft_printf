/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:32:55 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/20 17:30:12 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_unsigned_int(t_env *arg, va_list ap)
{
	int len;
	signed int nbr;

	len = 0;
	nbr = va_arg(ap, unsigned int);
	ft_putnbr_uns(nbr);
	len = ft_nbrlen_uns(nbr);
	return (len);
}
