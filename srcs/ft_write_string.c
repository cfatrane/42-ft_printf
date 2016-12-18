/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:35 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/18 16:59:04 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_string(t_env *arg, va_list ap)
{
	char	*str;
	size_t	len;
	void	*pointor;

	if (arg->conv == 's')
	{
		str = va_arg(ap, char *);


	}
	else if (arg->conv == 'p')
	{
		pointor = va_arg(ap, void *);
		ft_putstr("0x");
		ft_itoa_base((int)pointor, 16);
		return (size_tab_base((int)pointor, 16));

	}
	return (0);
}
