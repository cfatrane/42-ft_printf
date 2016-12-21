/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:50:28 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/21 18:29:30 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_size(t_env *arg, int nbr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len += ft_nbrlen(nbr);
	if (arg->flag == LESS)
	{
		ft_putnbr_base(nbr, "0123456789abcdef");
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
	}
	else
	{
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
		ft_putnbr_base(nbr, "0123456789abcdef");
	}
	len += i;
	return (len);
}
