/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:03:35 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/21 15:29:54 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flag(t_env *arg)
{
	while (arg->str[arg->cur] == '#')
	{
		arg->flag = DIESE;
		arg->cur++;
	}
	while (arg->str[arg->cur] == '0')
	{
		arg->flag = ZERO;
		arg->cur++;
	}
	while (arg->str[arg->cur] == '-')
	{
		arg->flag = LESS;
		arg->cur++;
	}
	while (arg->str[arg->cur] == '+')
	{
		arg->flag = MORE;
		arg->cur++;
	}
	while (arg->str[arg->cur] == ' ')
	{
		arg->flag = SPACE;
		arg->cur++;
	}
}
