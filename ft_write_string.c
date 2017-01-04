/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 14:00:26 by cfatrane         ###   ########.fr       */
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

static int	ft_write_flag_string(t_env *arg, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (arg->flags.options[ZERO] == 1 && arg->flags.options[LESS] != 1)
		len += ft_write_flag_zero(arg->size, len);
	else
		return (ft_write_size_str(arg, str));
	ft_putstr(str);
	return (ft_nbcmp(arg->size, len));
}

static int	ft_write_flag_precision_str(t_env *arg, char *str)
{
	if (arg->precision.nbr > arg->len)
	{
		ft_putstr_n(str, arg->precision.nbr);
	}
	return (ft_nbcmp(arg->precision.nbr, arg->len));
}

int			ft_write_string(t_env *arg, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	arg->len = ft_strlen(str);
	if (arg->size > arg->len && (arg->precision.nbr <= arg->len || !arg->precision.nbr))
		return (ft_write_size_str(arg, str));
	if (arg->precision.nbr > arg->len)
		return (ft_write_flag_precision_str(arg, str));
//	if (arg->flags.options[ZERO] == 1 || arg->flags.options[LESS] == 1)
//		return (ft_write_flag_string(arg, str));
	ft_putstr(str);
	return (arg->len);
}
