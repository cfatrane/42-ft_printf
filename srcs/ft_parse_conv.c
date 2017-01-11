/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:08 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 19:43:09 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_conv(t_env *arg)
{
	char	*tmp;
	char	*non_val;
	int		i;

	i = 0;
	tmp = "sSpdDioOuUxXcC";
	non_val = "%BHIJKMNPQRTVWYZ{}";
	while (tmp[i] != '\0')
	{
		if (tmp[i] == arg->str[arg->cur])
			arg->conv = tmp[i];
		i++;
	}
	i = 0;
	while (non_val[i] != '\0')
	{
		if (non_val[i] == arg->str[arg->cur])
			arg->conv = non_val[i];
		i++;
	}
	arg->cur++;
}
