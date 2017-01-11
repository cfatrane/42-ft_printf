/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:20:06 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 18:11:58 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_size_ws(t_env *arg, wchar_t *str)
{
	if (arg->flag[LESS])
	{
		ft_printf_putwstr(str);
		ft_write_flag_spaces(arg->size, arg->len);
		return (arg->size);
	}
	if (arg->flag[ZERO])
		ft_write_flag_zero(arg->size, arg->len);
	else
		ft_write_flag_spaces(arg->size, arg->len);
	ft_printf_putwstr(str);
	return (arg->size);
}

static int	ft_write_justify_precision_ws(t_env *arg, wchar_t *str)
{
	if (arg->size > arg->precision.len && arg->precision.len < arg->len)
	{
		ft_putwstr_n(str, arg->precision.len);
		ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
	else
	{
		ft_putwstr_n(str, arg->precision.len);
		return (ft_nbcmp_min(arg->precision.len, arg->len));
	}
	return (0);
}

static int	ft_write_precision_ws(t_env *arg, wchar_t *str)
{
	if (arg->size > arg->precision.len && arg->precision.len < arg->len)
	{
		if (arg->flag[ZERO])
			ft_write_flag_zero(arg->size, ft_strwlen_n(str, arg->precision.len));
		else
			ft_write_flag_spaces(arg->size, ft_strwlen_n(str, arg->precision.len));
		ft_putwstr_n(str, arg->precision.len);
		return (arg->size);
	}
	else if (arg->precision.len < arg->len)
		ft_putwstr_n(str, arg->precision.len);
	return (ft_nbcmp_min(arg->precision.len, ft_strwlen_n(str, arg->precision.len)));
}

static int	ft_write_precision_zero_ws(t_env *arg)
{
	if (!arg->size)
		return (0);
	else
	{
		if (arg->flag[ZERO])
			ft_write_flag_zero(arg->size, 0);
		else
			ft_write_flag_spaces(arg->size, 0);
		return (arg->size);
	}
}

int			ft_write_ws(t_env *arg, va_list ap)
{
	wchar_t	*str;

	str = va_arg(ap, wint_t *);
	arg->len = ft_printf_strwlen(str);
	if (arg->precision.actif && arg->precision.len == 0)
		return (ft_write_precision_zero_ws(arg));
	if (arg->size > arg->len &&
			(arg->precision.len >= arg->len || !arg->precision.actif))
		return (ft_write_size_ws(arg, str));
	if (arg->precision.actif && (arg->size > arg->len ||
				arg->precision.len < arg->len) && !arg->flag[LESS])
		return (ft_write_precision_ws(arg, str));
	if (arg->precision.actif && (arg->size > arg->len ||
				arg->precision.len < arg->len) && arg->flag[LESS])
		return (ft_write_justify_precision_ws(arg, str));
	ft_printf_putwstr(str);
	return (arg->len);
}
