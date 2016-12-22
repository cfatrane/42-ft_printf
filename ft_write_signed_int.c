/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 20:46:27 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/22 18:27:28 by cfatrane         ###   ########.fr       */
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
	if (arg->flags.flag[DIESE] == 1)
		len += ft_write_flag_diese();
	ft_putnbr(nbr);
	return (ft_nbcmp(arg->size, len));
}

int	ft_write_signed_int(t_env *arg, va_list ap)
{
	int			len;
	signed int	nbr;

	len = 0;
	nbr = va_arg(ap, signed int);
	/*	printf("less vaut = %d\n", arg->flags.flag[LESS]);
		printf("more vaut = %d\n", arg->flags.flag[MORE]);
		printf("diese vaut = %d\n", arg->flags.flag[DIESE]);
		printf("zero vaut = %d\n", arg->flags.flag[ZERO]);
		printf("space vaut = %d\n", arg->flags.flag[SPACE]);*/
	if (arg->flags.flag[ZERO] == 1)
		return (ft_write_flag(arg, nbr));
	if(arg->size)
		return (ft_write_size(arg, nbr));
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
	//	if (arg->flags.flag[ZERO] == 1)
	//		return (ft_write_flag(arg, nbr));
	ft_putnbr(nbr);
	len += ft_nbrlen(nbr);
	return (len);
}
