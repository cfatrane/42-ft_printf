/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:35:57 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 11:48:41 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_reader(t_env *arg, va_list ap)
{
	size_t	len;
	int		ret;

	len = 0;
	ret = 0;
	while (arg->str[arg->cur] != '\0')
	{
		if (arg->str[arg->cur] == '%')
		{
			arg->cur++;
			ret = ft_parse(arg);
			if (ret == 1)
				len += ft_write_arg(arg, ap);
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
