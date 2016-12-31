/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 16:54:13 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/30 16:59:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_flag_more(t_env *arg)
{
	if ((arg->flags.flag[SPACE] != 1 && arg->flags.flag[MORE] == 1) || (arg->flags.flag[SPACE] == 1 && arg->flags.flag[MORE] == 1) || (arg->flags.flag[MORE] == 1))
	{
		ft_putchar('+');
		return (1);
	}
	else
		return (0);
}