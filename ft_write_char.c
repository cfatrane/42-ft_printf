/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:16 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/08 16:44:19 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_char(t_env *arg, char c)
{
	int	i;

	i = 0;
	ft_putchar(c);
	i += ft_write_flag_spaces(arg->size, 1);
	return (arg->size);
}

static int	ft_write_size_char(t_env *arg, char c)
{
	int	i;

	i = 0;
	if (arg->flags.options[LESS])
		return (ft_write_justify_size_char(arg, c));
	else
	{
		if (arg->flags.options[ZERO])
			arg->len += ft_write_flag_zero(arg->size, arg->len);
		else
			i += ft_write_flag_spaces(arg->size, 1);
		ft_putchar(c);
	}
	return (arg->size);
}

int			ft_write_char(t_env *arg, va_list ap)
{
	unsigned char	c;

/*	if (arg->conv == '%')
	{
		c = '%';
		if (arg->size > arg->len && !arg->precision.actif)
			return (ft_write_size_char(arg, c));
		ft_putchar(c);
		return (1);
	}*/
	//	return (ft_write_double_percent(arg));
	if (!arg->modif && arg->conv != 'C')
		c = va_arg(ap, int);
	else if (arg-> modif == L || arg->conv == 'C')
		c = va_arg(ap, wint_t);
//	arg->len = ft_nbrlen(c);
	arg->len = 1;
	if (arg->size > arg->len && (!arg->precision.actif || arg->precision.actif))
		return (ft_write_size_char(arg, c));
	ft_putchar(c);
	return (1);
}
