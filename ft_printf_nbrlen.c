/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbrlen_uns.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 18:41:27 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/07 18:50:00 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbrlen(t_env *arg, unsigned long long int nbr)
{
	if (!(arg->modif))
		return (ft_nbrlen((signed int)nbr));
	else if (arg->modif == HH)
		return (ft_nbrlen((signed char)nbr));
	else if (arg->modif == H)
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

int	ft_printf_nbrlen_uns(t_env *arg, unsigned long long int nbr)
{
	if (!(arg->modif) && arg->conv != 'U')
		return (ft_nbrlen_uns((unsigned int)nbr));
	else if (arg->modif == HH)
		return (ft_nbrlen_uns((unsigned char)nbr));
	else if (arg->modif == H && arg->conv != 'U')
		return (ft_nbrlen_uns((unsigned short)nbr));
	else if (arg->modif == LL)
		return (ft_nbrlen_uns((unsigned long long int)nbr));
	else if (arg->modif == L || arg->conv == 'U')
		return (ft_nbrlen_uns((unsigned long int)nbr));
	else if (arg->modif == J)
		return (ft_nbrlen_uns((uintmax_t)nbr));
	else if (arg->modif == Z)
		return (ft_nbrlen_uns((size_t)nbr));
	return (0);
}
