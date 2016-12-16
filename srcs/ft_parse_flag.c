/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:03:35 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/16 17:18:32 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flag(t_env *arg)
{
	if (e->str[e->cur] == '-')
	{
		arg->flag = "MORE";
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '+')
	{
		arg->flag = "LESS";
		arg->cur++;
	}
	else if (arg->str[arg->cur] == ' ')
	{
		arg->flag = "SPACE";
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '#')
	{
		arg->flag = "DIESE";
		arg->cur++;
	}
	return (0);
}
