/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:10:05 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 11:47:47 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_double_percent(t_env *arg)
{
	if (arg->str[arg->cur] == '%')
	{
		ft_putchar('%');
		arg->printcar++;
		arg->cur++;
		return (1);
	}
	else
		return (0);
}

void	ft_parse_specifier(t_env *arg)
{
	if (arg->str[arg->cur] == '-' || arg->str[arg->cur] == '+' ||
			arg->str[arg->cur] == '#' || arg->str[arg->cur] == '0' ||
			arg->str[arg->cur] == ' ')
		ft_parse_flag(arg);
	if (ft_isdigit(arg->str[arg->cur]) && arg->str[arg->cur] != '0')
		ft_parse_size(arg);
	if (arg->str[arg->cur] == 'h' || arg->str[arg->cur] == 'l' ||
			arg->str[arg->cur] == 'j' || arg->str[arg->cur] == 'z')
		ft_parse_modif(arg);
	if (arg->str[arg->cur] == '.')
		ft_parse_precision(arg);
}

int		ft_parse(t_env *arg)
{
	int	len;

	len = 0;
	if (ft_parse_double_percent(arg) || arg->str[arg->cur] == '\0')
		return (0);
	while (arg->str[arg->cur] == '-' || arg->str[arg->cur] == '+' ||
			arg->str[arg->cur] == '#' || arg->str[arg->cur] == '0' ||
			arg->str[arg->cur] == ' ' || arg->str[arg->cur] == 'h' ||
			arg->str[arg->cur] == 'l' || arg->str[arg->cur] == 'j' ||
			arg->str[arg->cur] == 'z' || arg->str[arg->cur] == '.' ||
			ft_isdigit(arg->str[arg->cur]))
		ft_parse_specifier(arg);
	ft_parse_conv(arg);
	//	printf("conv = %c||diese = %d||zero = %d||less = %d||more = %d||space = %d||size = %d||actif = %d||precision = %d||modif = %d||\t\n\n\n", arg->conv, arg->flags.options[DIESE], arg->flags.options[ZERO],arg->flags.options[LESS], 
	//			arg->flags.options[MORE], arg->flags.options[SPACE], arg->size, arg->precision.actif, arg->precision.len, arg->modif);
	return (1);
}

