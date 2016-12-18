/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:03:35 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/18 16:42:12 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flag(t_env *arg)
{
	int i;

	i = 0;
	if (arg->str[i] == '-')
	{
		arg->flag = "MORE";
		i++;
	}
	else if (arg->str[i] == '+')
	{
		arg->flag = "LESS";
		i++;
	}
	else if (arg->str[i] == ' ')
	{
		arg->flag = "SPACE";
		i++;
	}
	else if (arg->str[i] == '#')
	{
		arg->flag = "DIESE";
		i++;
	}
	return (i);
}
