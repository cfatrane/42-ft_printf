/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 15:07:15 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/10 13:05:15 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_caste_unsigned(t_env *arg, va_list ap)
{
	if ((!arg->modif || arg->modif == HH || arg->modif == H) && arg->conv != 'O')
		return (va_arg(ap, unsigned int));
	else if (arg->modif == LL)
		return (va_arg(ap, unsigned long long int));
	else if (arg->modif == L || arg->conv == 'O')
		return (va_arg(ap, unsigned long int));
	else if (arg->modif == J)
		return (va_arg(ap, uintmax_t));
	else if (arg->modif == Z)
		return (va_arg(ap, size_t));
	return (0);
}

int	ft_caste_signed(t_env *arg, va_list ap)
{
	if (arg->modif == Z)
		return (va_arg(ap, size_t));
	else if (arg->modif == LL)
		return (va_arg(ap, unsigned long long int));
	else if (arg->modif == J)
		return (va_arg(ap, uintmax_t));
	else if (arg->modif == L || arg->conv == 'D')
		return (va_arg(ap, unsigned long int));
	else if ((!arg->modif || arg->modif == HH || arg->modif == H) && arg->conv != 'D')
		return (va_arg(ap, unsigned int));
	return (0);
}
