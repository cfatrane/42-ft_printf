/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:35:57 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/15 15:48:28 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_reader(t_env *arg, va_list ap)
{
	while (arg->str[arg->cur] != '\0')
	{
		if (arg->str[arg->cur] == '%')
		{
			arg->cur++;
			ft_parse(arg, ap);
			arg->cur++;
			ft_write_arg(arg, ap);
		}
		else
		{
			ft_putchar(arg->str[arg->cur]);
			arg->printcar++;
			arg->cur++;
		}
	}
	return (0);
}


int	ft_parse(t_env *arg, va_list ap)
{
	ft_parse_conv(arg);
//	ft_parse_flag(arg);

	return (0);
}
