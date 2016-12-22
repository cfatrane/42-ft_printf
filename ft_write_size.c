/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:50:28 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/22 19:37:45 by cfatrane         ###   ########.fr       */
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
	if (arg->flags.flag[LESS] == 1)
	{
		if (arg->conv == 'd' || arg->conv == 'i')
			ft_putnbr(nbr);
		if (arg->conv == 'x')
			ft_putnbr_base(nbr, "0123456789abcdef");
		if (arg->conv == 'o')
			ft_putnbr_base(nbr, "01234567");
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
		if (arg->flags.flag[DIESE] == 1)
			len += ft_write_flag_diese();
		if (arg->conv == 'd' || arg->conv == 'i')
			ft_putnbr(nbr);
		if (arg->conv == 'x')
			ft_putnbr_base(nbr, "0123456789abcdef");
		if (arg->conv == 'o')
			ft_putnbr_base(nbr, "01234567");
	}
	len += i;
	return (len);
}
