/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:16 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/18 17:01:40 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_char(t_env *arg, va_list ap)
{
	unsigned char c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (0);
}
