/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:09:50 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/09 17:31:14 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_char(t_env *arg, wchar_t c)
{
	int	i;

	i = 0;
	ft_putwchar(c);
	i += ft_write_flag_spaces(arg->size, 1);
	return (arg->size);
}

static int	ft_write_size_char(t_env *arg, wchar_t c)
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
		ft_putwchar(c);
	}
	return (arg->size);
}

int			ft_write_wchar(t_env *arg, va_list ap)
{
	wchar_t	c;

	c = va_arg(ap, wint_t);
	//	arg->len = ft_nbrlen(c);
	arg->len = ft_strwcharlen(c);
	if (arg->size > arg->len && (!arg->precision.actif || arg->precision.actif))
		return (ft_write_size_char(arg, c));
	ft_putwchar(c);
	//	ft_printf_putchar(arg, c);
	return (arg->len);
}
