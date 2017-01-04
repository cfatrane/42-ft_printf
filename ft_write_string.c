/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 15:17:07 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_justify_size_str(t_env *arg, char *str)
{
	int	i;

	i = 0;
	ft_putstr(str);
	while (i < arg->size - arg->len)
	{
		ft_putchar(' ');
		i++;
	}
	return (arg->size);
}

static int	ft_write_size_str(t_env *arg, char *str)
{
	int	i;

	i = 0;
	if (arg->flags.options[LESS])
		return (ft_write_justify_size_str(arg, str));
	else
	{
		i += ft_write_flag_spaces(arg->size, arg->len);
		ft_putstr(str);
	}
	arg->len += i;
	return (arg->size);
}
/*
static int	ft_write_justify_precision_str(t_env *arg, char *str)
{



}
*/
static int	ft_write_precision_str(t_env *arg, char *str)
{
	int	i;

	i = 0;
//	if (arg->flags.options[LESS] && arg->size)
//		return (ft_write_justify_precision_str(arg, str));
	if (arg->size > arg->precision.len && arg->precision.len < arg->len/* && arg->precision.len > arg->len*/)
	{
		i+= ft_write_flag_spaces(arg->size, arg->precision.len);
		ft_putstr_n(str, arg->precision.len);
		return (arg->size);
	}
//	else if (arg->size > arg->.len && arg->precision.len < arg->len/* && arg->precision.len > arg->len*/)

	if (arg->precision.len < arg->len)
		ft_putstr_n(str, arg->precision.len);
	arg->len += i;
	return (ft_nbcmp_min(arg->precision.len, arg->len));
}

static int	ft_write_flag_string(t_env *arg, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (arg->flags.options[ZERO] == 1 && arg->flags.options[LESS] != 1)
		len += ft_write_flag_zero(arg->size, len);
	else
		return (ft_write_size_str(arg, str));
	ft_putstr(str);
	return (ft_nbcmp_max(arg->size, len));
}

int			ft_write_string(t_env *arg, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	arg->len = ft_strlen(str);
//	printf("str = %s||\tlen = %d||\t prec = %d||\t size = %d||\t\n", str, arg->len, arg->precision.len, arg->size);
	if (arg->size > arg->len && (arg->precision.len >= arg->len || !arg->precision.actif))
		return (ft_write_size_str(arg, str));
//	printf("ICI1\n");
	if (arg->precision.len < arg->len && arg->precision.actif)
		return (ft_write_precision_str(arg, str));
//	if (arg->flags.options[ZERO] == 1 || arg->flags.options[LESS] == 1)
//		return (ft_write_flag_string(arg, str));
	ft_putstr(str);
	return (arg->len);
}
