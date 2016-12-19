/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:46:27 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/19 18:39:10 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_signed_int(t_env *arg, va_list ap)
{
	int len;
	signed int nbr;

	len = 0;
	nbr = va_arg(ap, signed int);
	ft_putnbr(nbr);
	len = ft_nbrlen(nbr);
	return (len);
}
