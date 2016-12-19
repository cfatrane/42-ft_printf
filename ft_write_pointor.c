/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:26:54 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/19 16:30:49 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_pointor(t_env *arg, va_list ap)
{
	void	*pointor;

	pointor = va_arg(ap, void *);
	ft_putstr("0x");
	ft_putnbr_base((size_t)pointor, "0123456789abcdef");
	return (size_tab_base((int)pointor + 2, 16));
}
