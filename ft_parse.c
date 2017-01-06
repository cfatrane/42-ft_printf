/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:10:05 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/06 11:26:05 by cfatrane         ###   ########.fr       */
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
	while (arg->str[arg->cur] == '-' || arg->str[arg->cur] == '+' ||
			arg->str[arg->cur] == '#' || arg->str[arg->cur] == '0' ||
			arg->str[arg->cur] == ' ' || arg->str[arg->cur] == 'h' || arg->str[arg->cur] == 'l' ||
			arg->str[arg->cur] == 'j' || arg->str[arg->cur] == 'z' || arg->str[arg->cur] == '.' || ft_isdigit(arg->str[arg->cur]))
	{
		if (arg->str[arg->cur] == '-' || arg->str[arg->cur] == '+' ||
				arg->str[arg->cur] == '#' || arg->str[arg->cur] == '0' ||
				arg->str[arg->cur] == ' ')
		{
			ft_parse_flag(arg);
		}
		if (ft_isdigit(arg->str[arg->cur]) && arg->str[arg->cur] != '0')
		{
			ft_parse_size(arg);
		}
		if (arg->str[arg->cur] == 'h' || arg->str[arg->cur] == 'l' ||
				arg->str[arg->cur] == 'j' || arg->str[arg->cur] == 'z')
		{
			ft_parse_modif(arg);
		}
		if (arg->str[arg->cur] == '.')
		{
			ft_parse_precision(arg);
		}
	}
	ft_parse_conv(arg);
//	printf("conv = %c||\tdiese = %d||\tzero = %d||\tless = %d||\tmore = %d||\tspace = %d||\tsize = %d||\tprecision = %d||\tmodif = %d||\t\n\n", arg->conv, arg->flags.options[DIESE], arg->flags.options[ZERO],arg->flags.options[LESS], 
//			arg->flags.options[MORE], arg->flags.options[SPACE], arg->size, arg->precision.len, arg->modif);
	return (len);
}
