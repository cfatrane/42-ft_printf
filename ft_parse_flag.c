/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:03:35 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/19 16:25:58 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flag(t_env *arg)
{
	if (arg->str[arg->cur] == '-')
	{
		arg->flag = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '+')
	{
		arg->flag = 2;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == ' ')
	{
		arg->flag = 3;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '#')
	{
		arg->flag = 4;
		arg->cur++;
	}
}
