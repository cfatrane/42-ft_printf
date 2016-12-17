/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:19:27 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/17 14:43:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_dec(t_env *arg, va_list ap)
{
	unsigned int nbr;

	nbr = va_arg(ap, unsigned int);
	ft_putnbr(nbr);
}
