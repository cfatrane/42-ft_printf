/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:03:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/05 18:13:37 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_take_flag(t_env *arg)
{
	if (arg->str[arg->cur] == '#')
	{
		arg->flags.options[DIESE] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '0')
	{
		arg->flags.options[ZERO] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '-')
	{
		arg->flags.options[LESS] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '+')
	{
		arg->flags.options[MORE] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == ' ')
	{
		arg->flags.options[SPACE] = 1;
		arg->cur++;
	}
}

void	ft_parse_flag(t_env *arg)
{
	while (arg->str[arg->cur] == '-' || arg->str[arg->cur] == '+' ||
			arg->str[arg->cur] == '#' || arg->str[arg->cur] == '0' ||
			arg->str[arg->cur] == ' ')
	{
		ft_take_flag(arg);
//		ft_parse(arg);
	}
}
