/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:03:35 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/23 17:38:00 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flag(t_env *arg)
{
	while (arg->str[arg->cur] == '-' || arg->str[arg->cur] == '+' || arg->str[arg->cur] == '#' ||
			arg->str[arg->cur] == '0' || arg->str[arg->cur] == ' ')
	{
		if (arg->str[arg->cur] == '-')
		{
			arg->flags.flag[LESS] = 1;
			arg->cur++;
		}
		else if (arg->str[arg->cur] == '+')
		{
			arg->flags.flag[MORE] = 1;
			arg->cur++;
		}
		else if (arg->str[arg->cur] == '#')
		{
			arg->flags.flag[DIESE] = 1;
			arg->cur++;
		}
		else if (arg->str[arg->cur] == '0')
		{
			arg->flags.flag[ZERO] = 1;
			arg->cur++;
		}
		else if (arg->str[arg->cur] == ' ')
		{
			arg->flags.flag[SPACE] = 1;
			arg->cur++;
		}
	}
}
