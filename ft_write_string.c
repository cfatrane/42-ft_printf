/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:35 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/27 19:19:18 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_size_str(t_env *arg, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (arg->flags.flag[LESS] == 1)
	{
		ft_putstr(str);
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
	}
	else
	{
		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}
		ft_putstr(str);
	}
	len += i;
	return (len);
}

static int	ft_write_flag_string(t_env *arg, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (arg->flags.flag[ZERO] == 1 && arg->flags.flag[LESS] != 1)
		len += ft_write_flag_zero(arg, len);
	else
		return (ft_write_size_str(arg, str));
	ft_putstr(str);
	return (ft_nbcmp(arg->size, len));
}

int	ft_write_string(t_env *arg, va_list ap)
{
	void	*str;
	size_t	len;

	len = 0;
	str = va_arg(ap, char *);
	if (arg->flags.flag[ZERO] == 1 || arg->flags.flag[LESS] == 1)
		return (ft_write_flag_string(arg, str));
	if(arg->size)
		return (ft_write_size_str(arg, str));
	if (arg->conv == 's')
	{
		ft_putstr(str);
		len = ft_strlen(str);
	}
	return (len);
}
