/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:31:48 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/03 14:28:27 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_flag_zero(int start, int end)
{
	int i;

	i = 0;
	while (i < start - end)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}
