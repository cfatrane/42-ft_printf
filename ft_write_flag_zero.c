/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:31:48 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/21 14:32:01 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_flag_zero(t_env *arg, int len)
{
	int i;

	i = 0;
	while (i < arg->size - len)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}
