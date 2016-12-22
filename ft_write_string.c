/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:35 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/22 19:21:15 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_size_str(t_env *arg, char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len += ft_strlen(str);
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
		if (arg->flags.flag[DIESE] == 1)
			len += ft_write_flag_diese();
		ft_putstr(str);
	}
	len += i;
	return (len);
}

int	ft_write_string(t_env *arg, va_list ap)
{
	char	*str;
	size_t	len;

	len = 0;
	str = va_arg(ap, char *);
	if(arg->size)
		return (ft_write_size_str(arg, str));
	if (arg->conv == 's')
	{
		ft_putstr(str);
		len = ft_strlen(str);
	}
	return (len);
}
