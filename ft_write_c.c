/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:16 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 18:57:03 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_c(t_env *arg, char c)
{
	int	i;

	i = 0;
	ft_putchar(c);
	i += ft_write_flag_spaces(arg->size, 1);
	return (arg->size);
}

static int	ft_write_size_c(t_env *arg, char c)
{
	int	i;

	i = 0;
	if (arg->flag[LESS])
		return (ft_write_justify_size_c(arg, c));
	else
	{
		if (arg->flag[ZERO])
			arg->len += ft_write_flag_zero(arg->size, arg->len);
		else
			i += ft_write_flag_spaces(arg->size, 1);
		ft_putchar(c);
	}
	return (arg->size);
}

int			ft_write_c(t_env *arg, va_list ap)
{
	unsigned char	c;

	if (!arg->modif)
		c = va_arg(ap, int);
	else if (arg-> modif == L)
		return (ft_write_wc(arg, ap));
	arg->len = 1;
	if (arg->size > arg->len && (!arg->precision.actif || arg->precision.actif))
		return (ft_write_size_c(arg, c));
	ft_putchar(c);
	return (1);
}
