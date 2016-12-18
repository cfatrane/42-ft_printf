/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:35:57 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/18 16:46:55 by cfatrane         ###   ########.fr       */
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
			ft_parse(arg, ap);
			arg->cur++;
			ft_write_arg(arg, ap);
			arg->printcar++;
		}
		else
		{
			ft_putchar(arg->str[arg->cur]);
			arg->cur++;
			arg->printcar++;
		}
	}
	return (0);
}

int	ft_parse(t_env *arg, va_list ap)
{
	int	len;


	len = 0;
	if (arg->str[arg->cur] == '%' || arg->str == '\0')
	{
		ft_putchar('%');
		arg->printcar++;
	}
	ft_parse_conv(arg);
	ft_parse_flag(arg);
	ft_parse_size(arg);
	ft_parse_precision(arg);
	return (0);
}
