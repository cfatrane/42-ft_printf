/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pointor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:26:54 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/30 12:21:21 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_pointor(t_env *arg, va_list ap)
{
	void	*pointor;

	pointor = va_arg(ap, void *);
	ft_putstr("0x");
	ft_print_hex((size_t)pointor);
	return ((ft_size_tab_base((size_t)pointor, 16)) + 2);
}
