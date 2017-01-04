/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:36:02 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 13:20:55 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_flag_space(t_env *arg)
{
	if (arg->flags.options[SPACE] == 1 && arg->flags.options[MORE] != 1)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

int	ft_write_flag_spaces(int start, int end)
{
	int i;

	i = 0;
	while (i < start - end)
	{
		ft_putchar (' ');
		i++;
	}
	return (i);
}
