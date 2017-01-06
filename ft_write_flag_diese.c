/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_diese.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:48:05 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/06 17:12:19 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_flag_diese(t_env *arg)
{
	if (arg->flags.options[DIESE])
	{
		if (arg->conv == 'x')
		{
			ft_putstr("0x");
			return (2);
		}
		else if (arg->conv == 'X')
		{
			ft_putstr("0X");
			return (2);
		}
	}
	return (0);
}
