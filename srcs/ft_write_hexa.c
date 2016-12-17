/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:51:22 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/17 15:32:22 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_hexa(t_env *arg, va_list ap)
{
	char	*str;
	int		nbr;

	nbr = va_arg(ap, int);
	str = ft_itoa_base(nbr, 16);
	ft_putstr(str);
}
