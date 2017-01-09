/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/09 18:31:12 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_str(t_env *arg, char *str)
{
	ft_printf_putstr(str);
	ft_write_flag_spaces(arg->size, arg->len);
	return (arg->size);
}

static int	ft_write_size_str(t_env *arg, char *str)
{
	if (arg->flags.options[ZERO])
		ft_write_flag_zero(arg->size, arg->len);
	else
		ft_write_flag_spaces(arg->size, arg->len);
	ft_printf_putstr(str);
	return (arg->size);
}

static int	ft_write_justify_precision_str(t_env *arg, char *str)
{
	if (arg->size > arg->precision.len && arg->precision.len < arg->len)
	{
		ft_putstr_n(str, arg->precision.len);
		ft_write_flag_spaces(arg->size, arg->precision.len);
		return (arg->size);
	}
	else
	{
		ft_putstr_n(str, arg->precision.len);
		return (ft_nbcmp_min(arg->precision.len, arg->len));
	}
	return (0);
}

static int	ft_write_precision_str(t_env *arg, char *str)
{
	int	i;

	i = 0;
	if (arg->size > arg->precision.len && arg->precision.len)
	{
		if (arg->flags.options[ZERO])
			i += ft_write_flag_zero(arg->size, arg->precision.len);
		else
			i+= ft_write_flag_spaces(arg->size, arg->precision.len);
		ft_putstr_n(str, arg->precision.len);
		return (arg->size);
	}
	else if (arg->precision.len < arg->len)
		ft_putstr_n(str, arg->precision.len);
	return (ft_nbcmp_min(arg->precision.len, arg->len));
}

static int	ft_write_precision_zero_str(t_env *arg)
{
	if (!arg->size)
		return (0);
	else
	{
		if (arg->flags.options[ZERO])
			ft_write_flag_zero(arg->size, 0);
		else
			ft_write_flag_spaces(arg->size, 0);
		return (arg->size);
	}
}

int			ft_write_string(t_env *arg, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	arg->len = ft_printf_strlen(str);
//			printf("str = %s||\tlen = %d||\t prec = %d||\t size = %d||\t\n", str, arg->len, arg->precision.len, arg->size);
//	if (str == 0 && arg->precision.actif == 1/* && arg->precision.len == 0*/)
//		return (ft_write_precision_zero_str(arg));
	if (arg->precision.actif == 1 && arg->precision.len == 0)
		return (ft_write_precision_zero_str(arg));
	if (arg->size > arg->len && (arg->precision.len >= arg->len || !arg->precision.actif) && !arg->flags.options[LESS])
		return (ft_write_size_str(arg, str));
	if (arg->size > arg->len && (arg->precision.len >= arg->len || !arg->precision.actif) && arg->flags.options[LESS])
		return (ft_write_justify_size_str(arg, str));
	if (arg->precision.actif && (arg->size > arg->len || arg->precision.len < arg->len) && !arg->flags.options[LESS])
		return (ft_write_precision_str(arg, str));
//	printf("ICI");
	if (arg->precision.actif && (arg->size > arg->len || arg->precision.len < arg->len) && arg->flags.options[LESS])
//	if (arg->precision.actif && arg->flags.options[LESS])
		return (ft_write_justify_precision_str(arg, str));
	ft_printf_putstr(str);
	return (arg->len);
}
