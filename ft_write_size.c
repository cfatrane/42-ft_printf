/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:50:28 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 13:21:45 by cfatrane         ###   ########.fr       */
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
	if (arg->flags.options[LESS] == 1 || (arg->flags.options[LESS] == 1 && arg->flags.options[ZERO] == 1))
	{
		if (arg->conv == 'd' || arg->conv == 'i')
			ft_putnbr(nbr);
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
		if (arg->flags.options[DIESE] == 1)
			len += ft_write_flag_diese_min();
		if (arg->conv == 'd' || arg->conv == 'i')
			ft_putnbr(nbr);
	}
	len += i;
	return (len);
}
