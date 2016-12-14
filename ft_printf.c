/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:20:55 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/12 18:23:04 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf (const char *format, ...)
{
	size_t	ret;
	t_env	env;
	va_list ap;

	if (!format)
		return (-1);
	env.str = format;
	va_start(ap, format);
	ret = ft_reader(&env, ap);
	va_end(ap);
	return (ret);
}
