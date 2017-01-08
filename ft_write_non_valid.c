/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_non_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 17:26:48 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/08 17:28:37 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_non_valid(t_env *arg, char c)
{
	int	i;

	i = 0;
	ft_putchar(c);
	i += ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_non_valid(t_env *arg, char c)
{
	int	i;

	i = 0;
	if (arg->flags.options[LESS])
		return (ft_write_justify_size_non_valid(arg, c));
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

int	ft_write_non_valid(t_env *arg)
{
	unsigned char	c;

	c = arg->conv;
	arg->len = 1;
	if (arg->size > 1 && (!arg->precision.actif || arg->precision.actif))
		return (ft_write_size_non_valid(arg, c));
//	printf("ICI");
	ft_putchar(c);
	return (1);
}
