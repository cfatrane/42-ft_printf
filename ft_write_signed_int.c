/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:46:27 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/26 13:24:18 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_size_dec(t_env *arg, int nbr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_nbrlen(nbr);
	if (arg->flags.flag[LESS] == 1 || (arg->flags.flag[LESS] == 1 && arg->flags.flag[ZERO] == 1))
	{
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
		ft_putnbr(nbr);
	}
	len += i;
	return (len);
}

static int	ft_write_flag_dec(t_env *arg, int nbr)
{
	int		len;

	len = 0;
	len += ft_nbrlen(nbr);
	if (arg->flags.flag[SPACE] != 1 && arg->flags.flag[MORE] == 1 && nbr >= 0)
	{
		ft_putchar('+');
		len++;
	}
	else if (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] == 1 && nbr >= 0)
	{
		ft_putchar('+');
		len++;
	}
	else if (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] != 1 && nbr >= 0)
		len += ft_write_flag_space();
	if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
		len += ft_write_flag_zero(arg, len);
	else if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] == 1)
		return (ft_write_size(arg, nbr));
	ft_putnbr(nbr);
	return (ft_nbcmp(arg->size, len));
}

int	ft_write_signed_int(t_env *arg, va_list ap)
{
	int			len;
	signed int	nbr;

	len = 0;
	nbr = va_arg(ap, signed int);
	if (arg->flags.flag[ZERO] == 1 || arg->flags.flag[LESS] == 1 || arg->flags.flag[MORE] == 1 ||  arg->flags.flag[SPACE] == 1)
		return (ft_write_flag_dec(arg, nbr));
	if(arg->size)
		return (ft_write_size_dec(arg, nbr));
	ft_putnbr(nbr);
	len += ft_nbrlen(nbr);
	return (len);
}
