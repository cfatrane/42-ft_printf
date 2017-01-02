/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 13:01:55 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/02 17:27:50 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t	ret;
	t_env	arg;
	va_list	ap;

	if (!format)
		return (-1);
	ft_bzero(&arg, sizeof(t_env));
	arg.str = format;
	va_start(ap, format);
	ret = ft_reader(&arg, ap);
	va_end(ap);
	ft_bzero(&arg, sizeof(t_env));
	return (ret);
}
