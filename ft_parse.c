/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:10:05 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/05 14:48:20 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_percent_percent(t_env *arg)
{
	if (arg->str[arg->cur] == '%')
	{
		ft_putchar('%');
//		arg->cur++;
	//	arg->written++;
		return (1);
	}
	else
		return (0);
}

int	ft_parse(t_env *arg, va_list ap)
{
	int	len;

	len = 0;
	if (arg->str[arg->cur] == '%' || arg->str[arg->cur] == '\0')
		len += check_percent_percent(arg);
//	{
//		ft_putchar('%');
//		len++;
//	}
	ft_parse_flag(arg);
	ft_parse_size(arg);
	ft_parse_precision(arg);
	ft_parse_modif(arg);
	ft_parse_conv(arg);
//	printf("conv = %c|||\n", arg->conv);
	return (len);
}
