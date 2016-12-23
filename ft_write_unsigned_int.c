/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:32:55 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/23 15:38:42 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_flag(t_env *arg, unsigned int nbr)
{
	int		len;

	len = 0;
	len += ft_nbrlen_uns(nbr);
	if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
		len += ft_write_flag_zero(arg, len);
	else if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] == 1)
		return (ft_write_size(arg, nbr));
	if (arg->flags.flag[DIESE] == 1)
		len += ft_write_flag_diese();
	ft_putnbr_uns(nbr);
	return (ft_nbcmp(arg->size, len));
}

int	ft_write_size_uns_nbr(t_env *arg, unsigned int nbr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len += ft_nbrlen_uns(nbr);
	if (arg->flags.flag[LESS] == 1)
	{
		ft_putnbr_uns(nbr);
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
		ft_putnbr_uns(nbr);
	}
	len += i;
	return (len);
}

int	ft_write_unsigned_int(t_env *arg, va_list ap)
{
	int				len;
	unsigned int	nbr;

	len = 0;
	nbr = va_arg(ap, unsigned int);
	if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
		return (ft_write_flag(arg, nbr));
	if(arg->size)
		return (ft_write_size_uns_nbr(arg, nbr));
	ft_putnbr_uns(nbr);
	len = ft_nbrlen_uns(nbr);
	return (len);
}
