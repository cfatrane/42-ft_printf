/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:10:05 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/22 18:29:37 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(t_env *arg, va_list ap)
{
	int	len;

	len = 0;
	if (arg->str[arg->cur] == '%' || arg->str[arg->cur] == '\0')
	{
		ft_putchar('%');
		len++;
	}
	ft_parse_flag(arg);
	ft_parse_size(arg);
	ft_parse_precision(arg);
	ft_parse_modif(arg);
	ft_parse_conv(arg);
	return (len);
}
