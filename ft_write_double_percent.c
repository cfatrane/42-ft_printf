/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_double_percent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 14:08:22 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/06 15:04:34 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_double_percent(t_env *arg, char c)
{
	int	i;

	i = 0;
	ft_putchar(c);
	i += ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_double_percent(t_env *arg, char c)
{
	int	i;

	i = 0;
	if (arg->flags.options[LESS])
		return (ft_write_justify_size_double_percent(arg, c));
	else
	{
		if (arg->flags.options[ZERO])
			i += ft_write_flag_zero(arg->size, arg->len);
		else
			i += ft_write_flag_spaces(arg->size, arg->len);
		ft_putchar(c);
	}
	return (arg->size);
}

int	ft_write_double_percent(t_env *arg)
{
	unsigned char	c;

	c = '%';
	arg->len = 1;
	if (arg->size > 1 && (!arg->precision.actif || arg->precision.actif))
		return (ft_write_size_double_percent(arg, c));
//	printf("ICI");
	ft_putchar(c);
	return (1);
}
