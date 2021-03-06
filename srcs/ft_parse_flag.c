/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:03:35 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 19:43:15 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_flag(t_env *arg)
{
	if (arg->str[arg->cur] == '#')
	{
		arg->flag[DIESE] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '0')
	{
		arg->flag[ZERO] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '-')
	{
		arg->flag[LESS] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '+')
	{
		arg->flag[MORE] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == ' ')
	{
		arg->flag[SPACE] = 1;
		arg->cur++;
	}
}
