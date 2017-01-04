/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:54:13 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/04 13:21:00 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_flag_more(t_env *arg)
{
	if ((arg->flags.options[SPACE] != 1 && arg->flags.options[MORE] == 1) || (arg->flags.options[SPACE] == 1 && arg->flags.options[MORE] == 1) || (arg->flags.options[MORE] == 1))
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}
