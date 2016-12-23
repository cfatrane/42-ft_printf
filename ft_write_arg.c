/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:36:40 by cfatrane          #+#    #+#             */
/*   Updated: 2016/12/23 14:46:58 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_min(t_env *arg, va_list ap)
{
	if (arg->conv == 's')
		return (ft_write_string(arg, ap));
	else if (arg->conv == 'p')
		return (ft_write_pointor(arg, ap));
	else if (arg->conv == 'd' || arg->conv == 'i')
		return (ft_write_signed_int(arg, ap));
	else if (arg->conv == 'o')
		return (ft_write_octal(arg, ap));
	else if (arg->conv == 'u')
		return (ft_write_unsigned_int(arg, ap));
	else if (arg->conv == 'x')
		return (ft_write_hexa(arg, ap));
	else if (arg->conv == 'c')
		return (ft_write_char(arg, ap));
	return (0);
}

int	ft_write_maj(t_env *arg, va_list ap)
{
	if (arg->conv == 'S')
		return (ft_write_string(arg, ap));
	else if (arg->conv == 'D')
		return (ft_write_long_int(arg, ap));
	else if (arg->conv == 'O')
		return (ft_write_octal(arg, ap));
	else if (arg->conv == 'U')
		return (ft_write_long_int(arg, ap));
	else if (arg->conv == 'X')
		return (ft_write_hexa(arg, ap));
	else if (arg->conv == 'C')
		return (ft_write_hexa(arg, ap));
	return (0);
}

int	ft_write_arg(t_env *arg, va_list ap)
{
	if ((arg->conv == 's') || (arg->conv == 'p') || (arg->conv == 'd') ||
			(arg->conv == 'i') || (arg->conv == 'o') || (arg->conv == 'u') || 
			(arg->conv == 'x') ||  (arg->conv == 'c'))
		return (ft_write_min(arg, ap));
	else if ((arg->conv == 'S') || (arg->conv == 'D') || (arg->conv == 'O') ||
			(arg->conv == 'U') || (arg->conv == 'X') || (arg->conv == 'C') || (arg->conv == '%'))
		return (ft_write_maj(arg, ap));
	return (0);
}



