/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:36:02 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/30 17:07:13 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_flag_space(void)
{
	ft_putchar(' ');
	return (1);
}
/*
int	ft_write_flag_spaces()
{
	int i;

	i = 0;

		while (i < arg->size - len)
		{
			ft_putchar (' ');
			i++;
		}


}*/
