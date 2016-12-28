/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_flag_diese.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 18:48:05 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/28 18:16:20 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_flag_diese_min(void)
{
	ft_putstr("0x");
	return (2);
}

int	ft_write_flag_diese_maj(void)
{
	ft_putstr("0X");
	return (2);
}
