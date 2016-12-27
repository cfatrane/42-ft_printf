/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:32:55 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/27 19:23:07 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_size_uns_nbr(t_env *arg, unsigned long long int nbr)
{
	int	i;
	int	len;

	i = 0;
	len = ft_nbrlen_uns(nbr);
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

static int	ft_write_flag(t_env *arg, unsigned long long int nbr)
{
	int		len;

	len = ft_nbrlen_uns(nbr);
	if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
		len += ft_write_flag_zero(arg, len);
	else if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] == 1)
		return (ft_write_size(arg, nbr));
	ft_putnbr_uns(nbr);
	return (ft_nbcmp(arg->size, len));
}

int	ft_write_unsigned_int(t_env *arg, va_list ap)
{
	int						len;
	unsigned long long int	nbr;

	len = 0;
	if (!(arg->modif))
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == hh)
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == h)
		nbr = va_arg(ap, unsigned int);
	else if (arg->modif == ll)
		nbr = va_arg(ap, unsigned long long int);
	else if (arg->modif == l)
		nbr = va_arg(ap, unsigned long int);
	else if (arg->modif == j)
		nbr = va_arg(ap, uintmax_t);
	else if (arg->modif == z)
		nbr = va_arg(ap, size_t);
	if (arg->flags.flag[ZERO] == 1)
		return (ft_write_flag(arg, nbr));
	if(arg->size)
		return (ft_write_size_uns_nbr(arg, nbr));
	ft_putnbr_uns(nbr);
	len = ft_nbrlen_uns(nbr);
	return (len);
}
