/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:02:53 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/19 13:55:34 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_int(t_env *arg, va_list ap)
{
	int		nbr;
	size_t	len;
	nbr = va_arg(ap, int);
	ft_putnbr(nbr);
	len = ft_nbrlen(nbr);
	return (0);
}
