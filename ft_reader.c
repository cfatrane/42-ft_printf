/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:35:57 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/26 17:41:43 by cfatrane         ###   ########.fr       */
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
			len += ft_parse(arg, ap);
			len += ft_write_arg(arg, ap);
		}
		else
		{
			ft_putchar(arg->str[arg->cur]);
			arg->cur++;
			len++;
		}
	}
	return (len);
}
