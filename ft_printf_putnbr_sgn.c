/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_sgn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:37:10 by cfatrane          #+#    #+#             */
/*   Updated: 2017/01/11 10:37:35 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putnbr_sgn(t_env *arg, signed long long nbr)
{
	if (arg->conv == 'D')
		ft_putnbr_lng((long int)nbr);
	else if (arg->modif == Z)
		ft_putnbr_lng((ssize_t)nbr);
	else if (arg->modif == LL)
		ft_putnbr_lng(nbr);
	else if (arg->modif == J)
		ft_putnbr_lng((intmax_t)nbr);
	else if (arg->modif == L)
		ft_putnbr_lng((long int)nbr);
	else if (arg->modif == H)
		ft_putnbr((short int)nbr);
	else if (arg->modif == HH)
		ft_putnbr((signed char)nbr);
	else
		ft_putnbr_lng(nbr);
}
