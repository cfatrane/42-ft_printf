/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:08 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/26 11:41:58 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_conv(t_env *arg)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = "sSpdDioOuUxXcC";
	while (*tmp)
	{
		if (*tmp == arg->str[arg->cur])
			arg->conv = *tmp;
		tmp++;
	}
	arg->cur++;
}
