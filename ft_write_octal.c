/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:18:25 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/23 16:10:48 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_flag(t_env *arg, int nbr)
{
	int		len;

	len = 0;
	len += ft_nbrlen(nbr);
	if (arg->flags.flag[ZERO] == 1)
		len += ft_write_flag_zero(arg, len);
	if (arg->conv == 'o')
	{
		if (arg->flags.flag[DIESE] == 1)
			ft_putchar('0');
		ft_putnbr_base(nbr, "01234567");
	}
	return (ft_nbcmp(arg->size, len));
}

static int	ft_write_size_u(t_env *arg, int nbr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_nbrlen(nbr);
	if (arg->flags.flag[LESS] == 1 || (arg->flags.flag[LESS] == 1 && arg->flags.flag[ZERO] == 1))
	{
		if (arg->flags.flag[DIESE] == 1)
		{
			ft_putchar('0');
			len++;
		}
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
		if (arg->flags.flag[DIESE] == 1)
			len++;
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
		if (arg->flags.flag[DIESE] == 1)
			ft_putchar('0');
		if (arg->conv == 'o')
			ft_putnbr_base(nbr, "01234567");
	}
	len += i;
	return (len);
}

int	ft_write_octal(t_env *arg, va_list ap)
{
	int		len;
	int		nbr;

	len = 0;
	nbr = va_arg(ap, unsigned int);
	if (arg->conv == 'o')
	{
		if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
			return (ft_write_flag(arg, nbr));
		if(arg->size)
			return (ft_write_size_u(arg, nbr));
		if (arg->flags.flag[DIESE] == 1)
		{
			ft_putchar('0');
			len++;
		}
		ft_putnbr_base(nbr, "01234567");
	}
	else if (arg->conv == 'O')
	{
		ft_putnbr_base(nbr, "01234567");
	}
	len = ft_nbrlen(nbr);
	return (len);
}
