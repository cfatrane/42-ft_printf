/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:10:05 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/05 18:29:39 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(t_env *arg)
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
//	printf("conv = %c||\tdiese = %d||\tzero = %d||\tless = %d||\tmore = %d||\tspace = %d||\tsize = %d||\tprecision = %d||\t", arg->conv, arg->flags.options[DIESE], arg->flags.options[ZERO],arg->flags.options[LESS], 
//arg->flags.options[MORE], arg->flags.options[SPACE], arg->size, arg->precision.len);
//	printf("conv = %c|||\n", arg->conv);
	return (len);
}
