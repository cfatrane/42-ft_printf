/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrlen_sgn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:30:54 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 10:31:27 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbrlen_sgn(t_env *arg, signed long long int nbr)
{
	if (!arg->modif && arg->conv != 'D')
		return (ft_nbrlen((signed int)nbr));
	else if (arg->modif == HH && arg->conv != 'D')
		return (ft_nbrlen((signed char)nbr));
	else if (arg->modif == H && arg->conv != 'D')
		return (ft_nbrlen((signed short)nbr));
	else if (arg->modif == LL)
		return (ft_nbrlen((signed long long int)nbr));
	else if (arg->modif == L || arg->conv == 'D')
		return (ft_nbrlen((signed long int)nbr));
	else if (arg->modif == J)
		return (ft_nbrlen((intmax_t)nbr));
	else if (arg->modif == Z)
		return (ft_nbrlen((size_t)nbr));
	return (0);
}
