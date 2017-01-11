/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:35:57 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 17:50:56 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_reader(t_env *arg, va_list ap)
{
	size_t	len;

	len = 0;
	while (arg->str[arg->cur] != '\0')
	{
		if (arg->str[arg->cur] == '%')
		{
			arg->cur++;
			arg->ret = ft_parse(arg);
			if (arg->ret == 1)
				len += ft_write_arg(arg, ap);
			if (!arg->conv && arg->conv != '%' && arg->ret == 1)
				return (0);
		}
		else
		{
			ft_putchar(arg->str[arg->cur]);
			arg->cur++;
			len++;
		}
	}
	return (len + arg->printcar);
}
